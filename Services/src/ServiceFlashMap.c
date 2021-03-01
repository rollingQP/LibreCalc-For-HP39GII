#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "memory_map.h"
#include "mmu.h"
#include "nand.h"
#include "raw_flash.h"
#include "tusb.h"

/* System serive includes. */
#include "ServiceFlashMap.h"
#include "ServiceRawFlash.h"
#include "ServiceSTMPPartition.h"

/* Library includes. */
#include "display.h"
#include "irq.h"
#include "regsuartdbg.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

#define TIMEOUT_MS 1000

//#define MAP_DEBUG

struct dhara_map map;
struct dhara_nand nandinf;

unsigned char page_buf[2048] ;//__attribute__((aligned(0x1000)));
unsigned char dhara_page_buf[2048];// __attribute__((aligned(0x1000)));
unsigned int dataRegonStartBlock = 0;
extern unsigned char address_page_data[5];
extern unsigned int dma_error;

extern unsigned char ecc_res[4];

extern volatile unsigned int dmaOperationCompleted;
extern volatile unsigned int eccOperationCompleted;

extern SemaphoreHandle_t flashLock;
bool mapLock = 0;

unsigned char readBackMetaData[200] __attribute__((aligned(0x200)));

int readDataRegonPage(unsigned int page, void *buffer) {
    unsigned int startTick = 0;
    rawFlashStatus result = NO_ERROR;
    //printf("buffer %08x\n",buffer);
    /*
	if((unsigned int)buffer > KHEAP_MEMORY_VIR_START){
		buffer = buffer - KHEAP_MEMORY_VIR_START + KHEAP_MAP_PHY_START;
	}
	*/

    if (xSemaphoreTake(flashLock, TIMEOUT_MS) == pdFALSE) {
        return DEVICE_BUSY;
    }

    startTick = xTaskGetTickCount();
    //printf("read buffer Addr:%08x\n",buffer);
    taskENTER_CRITICAL();
    set_page_address_data(page + dataRegonStartBlock * 64);
    GPMI_read_block_with_ecc8(NAND_CMD_READ0, NAND_CMD_READSTART, address_page_data, buffer, (unsigned int *)readBackMetaData, 4);

    flush_cache();

    if (ecc_res[0] == 0xE ||
        ecc_res[1] == 0xE ||
        ecc_res[2] == 0xE ||
        ecc_res[3] == 0xE) {
        result = BAD;
    }

    taskEXIT_CRITICAL();

    while (!dmaOperationCompleted || !eccOperationCompleted) {
        if (xTaskGetTickCount() - startTick > TIMEOUT_MS) {
            xSemaphoreGive(flashLock);
            return TIMEOUT;
        }
    }
    xSemaphoreGive(flashLock);

    return result;
}

int writeDataRegonPage(unsigned int page, void *meta_buffer, void *data_buffer) {
    unsigned int startTick = 0;

    //printf("data_buffer %08x, meta_buffer %08x\n",data_buffer,meta_buffer);
    /*
	if((unsigned int)data_buffer > KHEAP_MEMORY_VIR_START){
		data_buffer = data_buffer - KHEAP_MEMORY_VIR_START + KHEAP_MAP_PHY_START;
	}
	
	if((unsigned int)meta_buffer > KHEAP_MEMORY_VIR_START){
		meta_buffer = meta_buffer - KHEAP_MEMORY_VIR_START + KHEAP_MAP_PHY_START;
	}
	*/

#ifdef MAP_DEBUG
    //printf("    write page: %d start\n",page + dataRegonStartBlock * 64);
#endif

    if (xSemaphoreTake(flashLock, TIMEOUT_MS) == pdFALSE) {
        return DEVICE_BUSY;
    }

    startTick = xTaskGetTickCount();

#ifdef MAP_DEBUG
    //printf("    write page: %d call\n",page + dataRegonStartBlock * 64);
#endif
    //printf("meta_buffer %08x\n, data_buffer %08x\n",meta_buffer,data_buffer);
    //taskENTER_CRITICAL();
    flush_cache();
    GPMI_write_block_with_ecc8(NAND_CMD_SEQIN, NAND_CMD_PAGEPROG, NAND_CMD_STATUS,
                               page + dataRegonStartBlock * 64, data_buffer, meta_buffer);
    //taskEXIT_CRITICAL();

    while (!dmaOperationCompleted) {

        if (xTaskGetTickCount() - startTick > TIMEOUT_MS) {
            xSemaphoreGive(flashLock);
            return TIMEOUT;
        }
    }

    if (dma_error) {
        xSemaphoreGive(flashLock);
        return OPERATION_FAIL;
    }
#ifdef MAP_DEBUG
    printf("wr %d\n", page + dataRegonStartBlock * 64);
#endif
    xSemaphoreGive(flashLock);
    return NO_ERROR;
}

int eraseDataRegonBlock(unsigned int block) {

#ifdef MAP_DEBUG
    printf("    erase block: %d start\n", block);
#endif

    unsigned int startTick = 0;
    if (xSemaphoreTake(flashLock, TIMEOUT_MS) == pdFALSE) {
        return DEVICE_BUSY;
    }

    startTick = xTaskGetTickCount();

    //taskENTER_CRITICAL();
    GPMI_erase_block_cmd(NAND_CMD_ERASE1, NAND_CMD_ERASE2, NAND_CMD_STATUS, block + dataRegonStartBlock);
    //taskEXIT_CRITICAL();
    flush_cache();

    while (!dmaOperationCompleted) {
        if (xTaskGetTickCount() - startTick > TIMEOUT_MS) {
            xSemaphoreGive(flashLock);
            return TIMEOUT;
        }
    }

    if (dma_error) {
        xSemaphoreGive(flashLock);
        return OPERATION_FAIL;
    }

    xSemaphoreGive(flashLock);

#ifdef MAP_DEBUG
    printf("    erase block: %d end\n", block);
#endif

    return NO_ERROR;
}

int dhara_nand_is_bad(const struct dhara_nand *n, dhara_block_t b) {

#ifdef MAP_DEBUG
    printf("Test %d is bad? \n", b);
#endif

    if (readDataRegonPage(b * 64, page_buf) == BAD) {
        printf("    bad block at %d.\n", b);
        return 1;
    }

    /*if(readBackMetaData[0] != 0xFF){

		
		printf("    bad block at %d.\n",b);
		return 1;
	}*/

    return 0;
}

unsigned char A1META[19] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
void dhara_nand_mark_bad(const struct dhara_nand *n, dhara_block_t b) {

    readDataRegonPage(b * 64, page_buf);
    A1META[0] = 0;
    writeDataRegonPage(b * 64, A1META, page_buf);
    A1META[0] = 0xFF;
}

int dhara_nand_erase(const struct dhara_nand *n, dhara_block_t b,
                     dhara_error_t *err) {
    int status;

#ifdef MAP_DEBUG
    printf("   erasing:%d\n", b);
#endif
    status = eraseDataRegonBlock(b);
    if (status == NO_ERROR) {
        return 0;
    } else {
#ifdef MAP_DEBUG
        printf("   erase error:%d\n", b);
#endif

        *err = DHARA_E_BAD_BLOCK;
        return -1;
    }
}

extern unsigned char NMETA[19];
int dhara_nand_prog(const struct dhara_nand *n, dhara_page_t p,
                    const uint8_t *data,
                    dhara_error_t *err) {
    int status;
    status = writeDataRegonPage(p, NMETA, (uint8_t *)data);
    if (status == NO_ERROR) {
        *err = DHARA_E_NONE;
        return 0;
    } else {
        *err = DHARA_E_BAD_BLOCK;
        return -1;
    }
}

int dhara_nand_is_free(const struct dhara_nand *n, dhara_page_t p) {

    readDataRegonPage(p, page_buf);
    if (
        (ecc_res[0] == 0xF) &&
        (ecc_res[1] == 0xF) &&
        (ecc_res[2] == 0xF) &&
        (ecc_res[3] == 0xF)) {
        return 1;
    }
    return 0;
}

int dhara_nand_read(const struct dhara_nand *n, dhara_page_t p,
                    size_t offset, size_t length,
                    uint8_t *data,
                    dhara_error_t *err) {
    int status = 0;
    if ((offset > 2048) || (length > 2048) || (offset + length > 2048)) {
        return -1;
    }
#ifdef MAP_DEBUG
    //printf("    reading %d\n",p);
#endif
    status = readDataRegonPage(p, page_buf);
    if (status != NO_ERROR) {
        return -1;
    }
    memcpy(data, page_buf + offset, length);
    if (err != NULL) {
        *err = DHARA_E_NONE;
    }

    return 0;
}

int dhara_nand_copy(const struct dhara_nand *n,
                    dhara_page_t src, dhara_page_t dst,
                    dhara_error_t *err) {
    int status = 0;
    status = readDataRegonPage(src, page_buf);
    if (status != 0) {
        return -1;
    }
    status = writeDataRegonPage(dst, NMETA, page_buf);
    if (status != 0) {
        return -1;
    }
    *err = DHARA_E_NONE;
    return 0;
}

void vServiceFlashSync() {

    for (;;) {
        vTaskDelay(30000);
        if (!isRawFlash()) {
            dhara_map_sync(&map, NULL);
        }
    }
}

void flashSyncNow() {
    dhara_map_sync(&map, NULL);
}

bool isMaplock() {
    return mapLock;
}

void lockFmap(bool lock) {
    mapLock = lock;
}

void flashMapClear() {

    dhara_map_clear(&map);
}

void flashMapReset() {
    unsigned int status = 0;
    dhara_error_t err = 0;
    nandinf.log2_page_size = 11; //2^11 = 2048
    nandinf.log2_ppb = 6;        //2^6 = 64
    nandinf.num_blocks = getDataRegonTotalBlocks();
    dataRegonStartBlock = getDataRegonStartBlock();
    dhara_map_init(&map, &nandinf, dhara_page_buf, GC_RATIO);
    err = 0;
    status = dhara_map_resume(&map, &err);
    printf("flashMapReset resume: %d, err:%d \n", status, err);
    err = 0;
    status = dhara_map_sync(&map, &err);
    printf("flashMapReset sync: %d, err:%d \n", status, err);
}

unsigned int FlashMapInited = 0;
unsigned int isFlashMapInited() {
    return FlashMapInited;
}

void vServiceFlashMap(void *pvParameters) {
    unsigned int status = 0;
    dhara_error_t err = 0;
    unsigned char *buffer;

    while (!isSTMPDiskInited()) {
        vTaskDelay(5);
    }

    if (isRawFlash()) {
        printf("ERROR: error format flash.\n");
        vTaskDelete(NULL);
    }

    nandinf.log2_page_size = 11; //2^11 = 2048
    nandinf.log2_ppb = 6;        //2^6 = 64
    nandinf.num_blocks = getDataRegonTotalBlocks();
    dataRegonStartBlock = getDataRegonStartBlock();

    printf("num_blocks: %d, StartBlock: %d\n", nandinf.num_blocks, dataRegonStartBlock);
    err = 0;

    //dhara_page_buf = pvPortMalloc(2048);

    dhara_map_init(&map, &nandinf, dhara_page_buf, GC_RATIO);

    status = dhara_map_resume(&map, &err);
    printf("resume: %d, err:%d \n", status, err);
    printf("  flash capacity: %d\n", dhara_map_capacity(&map));
    err = 0;
    status = dhara_map_sync(&map, &err);
    printf("map sync done :%d err:%d \n", status, err);

#ifdef MAP_DEBUG
/*
	buffer = pvPortMalloc(2048);
	
	printf("\nWrite Test\n");
	for(int i=0;i<20;i++){
		dhara_map_write(&map, i, buffer, NULL);
	}
	printf("\nWrite done\n");
	err = 0;
	status = dhara_map_sync(&map, &err);
	printf("map sync done :%d err:%d \n",status,err);
	vPortFree(buffer);*/
#endif

    xTaskCreate(vServiceFlashSync, "Flash Sync Svc", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

    FlashMapInited = 1;

    vTaskDelete(NULL);

    for (;;) {
        vTaskSuspend(NULL);
    }
}