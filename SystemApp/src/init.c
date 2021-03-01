#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
#include "ff.h"
#include "init.h"
#include "keyboard.h"
#include "rtc.h"
#include "startup_info.h"

#include "ServiceFatFs.h"
#include "ServiceFlashMap.h"
#include "ServiceGraphic.h"
#include "ServiceRawFlash.h"
#include "ServiceSTMPPartition.h"
#include "ServiceSwap.h"
#include "ServiceUSBDevice.h"

#include "base_shell.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

#include "pageman.h"

unsigned char *vbuf;

GraphicMessage GM;
GraphicTextOutArgs text1; 

void vInit() {
    vTaskDelay(200);

    

    GM.selfAddr = &GM;
    GM.type = GRAPHIC_MSG_TYPE_CLEAR;
    xQueueSend(GraphicQueue, &(GM.selfAddr), (TickType_t)0);

    GM.selfAddr = &GM;
    GM.type = GRAPHIC_MSG_TYPE_CLEAR;
    xQueueSend(GraphicQueue, &(GM.selfAddr), (TickType_t)0);
    //modifyRegion(0,22,49);
    //saveRegionTable();

    GM.type = GRAPHIC_MSG_TYPE_TEXTOUT;
    GM.argsList = &text1;
    text1.x = 1;
    text1.y = 1;
    text1.area_width = 100;
    text1.area_height = 16;
    text1.font_size = 12;
    text1.font_color = 255;
    text1.text = "Booting stage 2...";
    xQueueSend(GraphicQueue, &(GM.selfAddr), (TickType_t)0);

    xTaskCreate(base_shell_main, "Basic Shell", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    
    malloc_stats();
 

    //asm volatile ("swi #1001");
/*
    FIL config_file;
    FRESULT fr;
    unsigned char *Config_line_buf = pvPortMalloc(1024);
    unsigned int arg = 0;

    fr = f_open(&config_file, "config", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);
    printf("Read config:%d\n", fr);

    while (f_gets(Config_line_buf, 1024, &config_file)) {
        unsigned int equ_pos = 0;
        unsigned int p = 0;
        while (Config_line_buf[p] != 0) {
            if (Config_line_buf[p++] == '=') {
                equ_pos = p - 1;
                break;
            }
        }
        if (equ_pos > 0) {
            if (memcmp("swap_mb", Config_line_buf, equ_pos) == 0) {
                p = equ_pos + 1;
                arg = atoi(&Config_line_buf[p]);
                swapSizeMB = arg;
                printf("swap size=%d MB\n", arg);
            }
        }
        memset(Config_line_buf, 0, 1024);
    }
    f_close(&config_file);

    vPortFree(Config_line_buf);
*/
    xTaskCreate(vServiceUSBDevice, "USB Device Service", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

    if (!isfatFsInited()) {
        vTaskDelete(NULL);
    }

    if(swapSizeMB == 0){
        swapSizeMB = 16;
    }

    //xTaskCreate(vServiceSwap, "Swap Svc", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
    int res;
    printf("init vm...\n");
    res = pageman_init(20,swapSizeMB);
    printf("init vm:%d\n",res);
    
     
    void vm_test();

    vm_test();

    vTaskDelete(NULL);
    for (;;) {
    }
}

