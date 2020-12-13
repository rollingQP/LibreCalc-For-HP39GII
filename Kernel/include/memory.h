
#ifndef _MEMORY_H
#define _MEMORY_H

typedef struct _MemoryBlockInfo {
    char isAvailable; // unsigned short isAvailable; // 0 or 1
    unsigned int size; // Size of the allocated space
    struct _MemoryBlockInfo* pointer; // If this is the first MemoryBlockInfo or isAvailable=1, pointer points to the next availavle MemoryBlokck; else, it points to the previous block.
} MemoryBlockInfo;
extern int __HEAP_START;
#define MEM_MIN 0x30000
#define MEM_MAX 0x67000
#define MEM_BLOCK_INFO_SIZE sizeof(MemoryBlockInfo)

void malloc_init();

void* malloc(unsigned int size);

void free(void* printer);

#endif

