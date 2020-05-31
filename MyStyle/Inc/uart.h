//uart.h
#include "commonheader.h"
#ifndef __UART_H
#define __UART_H
/*  			include start  			*/
extern UART_HandleTypeDef huart2;

/*  			include end  			*/



/*  			define start  			*/
#define RX_BLOCK_MAX	5
#define RX_CNT_MAX	5
/*  			define end  			*/



/*  			enum start  			*/
typedef enum
{
	UART_CH_PC =0,
	UART_CH_MP3 =1,
	UART_CH_GEN =2,
	UART_CH_LCD =3,
	UART_CH_MAX =4,
} UART_CH_E;
/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	uint8_t Tx_buff[50];
	
	uint8_t Rx_buff[RX_BLOCK_MAX][RX_CNT_MAX];
	uint8_t Rx_byte[1];
	uint8_t Rx_cnt;
	uint8_t head;
	uint8_t tail;
	uint8_t startflag;
	uint8_t nextturn;
} UART_T;
/*  			stuct end  				*/



/*  			function start  		*/
void UART_Pop(uint8_t *, UART_CH_E, UART_T *);
void UART_Insert(UART_CH_E , UART_T *);
UART_HandleTypeDef * Uart_master(UART_CH_E);

/*  			function end  			*/




#endif
