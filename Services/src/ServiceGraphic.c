#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* System serive includes. */
#include "ServiceGraphic.h"

/* Library includes. */
#include "regsuartdbg.h"
#include "irq.h"
#include "display.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


unsigned int tmp[8];

void vServiceGraphic( void *pvParameters )
{
	GraphicMessage *CurrentGraphicMessage;
	GraphicTextOutArgs *CurrentGraphicTextOutInfo;
	
	bool RealTimeFlush = 0;
	GraphicQueue = xQueueCreate(64, sizeof(GraphicMessage *));
	
	LCD_init();
	LCD_clear_completely();
	LCD_clear_buffer();
	LCD_dma_flush_buffer(); 
	
	for(;;){
		if(xQueueReceive( GraphicQueue, (&CurrentGraphicMessage), ( TickType_t ) portMAX_DELAY ) == pdTRUE ){
			switch(CurrentGraphicMessage->type){
				case GRAPHIC_MSG_TYPE_CLEAR:
					LCD_clear_buffer();
					break;
				case GRAPHIC_MSG_TYPE_TEXTOUT:
					CurrentGraphicTextOutInfo = (GraphicTextOutArgs *)(CurrentGraphicMessage->argsList);
					LCD_show_string( CurrentGraphicTextOutInfo->x, 
									 CurrentGraphicTextOutInfo->y, 
									 CurrentGraphicTextOutInfo->area_width, 
									 CurrentGraphicTextOutInfo->area_height, 
									 CurrentGraphicTextOutInfo->font_size, 
									 CurrentGraphicTextOutInfo->font_color, 
									 (uint8_t *)CurrentGraphicTextOutInfo->text);
					break;
				case GRAPHIC_MSG_TYPE_FLUSH:
					LCD_dma_flush_buffer();
					break;
				case GRAPHIC_MSG_TYPE_REALTIME_FLUSH_ON:
					LCD_dma_flush_auto_buffer_start();
					break;
				case GRAPHIC_MSG_TYPE_REALTIME_FLUSH_OFF:
					LCD_dma_flush_auto_buffer_stop();
					break;
			}
			if(RealTimeFlush == 0)
				LCD_dma_flush_buffer();
		}
		
		
	}
	
	
}

