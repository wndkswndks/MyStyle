//uart.c
#include "uart.h"

UART_T m_uart[UART_CH_MAX]={0,};

uint8_t qwe;
uint8_t qwerty[5][5];
uint8_t qwertycnt=0;

void UART_Pop(uint8_t *buff, UART_CH_E ch, UART_T *uart)
{
	if((uart ->head - uart ->tail <=0) && (!uart ->nextturn) ) return;
	
	memcpy(buff,uart ->Rx_buff[uart ->tail],RX_CNT_MAX );
	uart ->tail++;
	if(uart ->tail >= RX_BLOCK_MAX)
	{
		uart ->tail = 0;
		uart ->nextturn = 0;
	}
}
UART_HandleTypeDef * Uart_master(UART_CH_E ch)
{
	if(ch == 0) return &huart2;
	else return 0;
	
}
void UART_Insert(UART_CH_E ch, UART_T *uart)
{

	HAL_UART_Receive_IT(Uart_master(ch),(uint8_t*)uart ->Rx_byte,1);
	
	if(uart ->Rx_byte[0]=='[') 
  	{
		uart ->Rx_cnt =0;
		uart ->startflag = 1;
	
  	}
  	else if (uart ->Rx_byte[0]==']')
  	{
		uart ->head ++;	
		if(uart ->head >= RX_BLOCK_MAX) 
		{
			uart ->head = 0;	
			uart ->nextturn = 1;
		}
		uart ->Rx_cnt =0;
		uart ->startflag = 0;
  	}
  	else if((uart ->startflag == 1) &&(uart ->Rx_byte[0] != ']') )
  	{
  		uart ->Rx_buff[uart ->head][uart ->Rx_cnt] = uart ->Rx_byte[0];
		uart ->Rx_cnt++;	
		if(uart ->Rx_cnt >=RX_CNT_MAX)
		{
			uart ->Rx_cnt = 0;
			memset(uart ->Rx_buff[uart ->head] , 0, RX_CNT_MAX);
		}
		
	}
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{


	
	  if(huart ->Instance == USART2)
	  {
		UART_Insert(UART_CH_PC,&m_uart[UART_CH_PC] );
 	  }

 } 