//uart.c
#include "commonheader.h"


UART_T m_uart[UART_CH_MAX]={0,};

uint8_t qwe;
uint8_t qwerty[5][5];
uint8_t qwertycnt=0;






//
void UART_Cmd()
{
	char buff[20]={0,};
	static UART_CMD_T cmd={0,};
	UART_Pop(buff, &m_uart[UART_CH_PC]);
	if(strlen(buff) != 0) cmd= UART_Passing_data(buff);

	
	if(cmd.type == UART_TYPE_CTRL) CMD_Ctrl(cmd);
	 
	else if(cmd.type == UART_TYPE_MODE) CMD_Mode(cmd);
	 

}

void UART_IS_Getdata(UART_T *uart)
{
	if((uart ->head - uart ->tail <=0) && (!uart ->nextturn) ) return;
}

void UART_Pop(uint8_t *buff , UART_T *uart)
{
	if((uart ->head - uart ->tail <=0) && (!uart ->nextturn) ) return;
	
	memcpy(buff, uart ->Rx_buff[uart ->tail], RX_CNT_MAX );
	uart ->tail++;
	if(uart ->tail >= RX_BLOCK_MAX)
	{
		uart ->tail = 0;
		uart ->nextturn = 0;
	}
}

 UART_CMD_T UART_Passing_data(char *buff)
 {
	UART_CMD_T cmd;
	char strValue[8] = {0};
	if( !strncmp(buff,UART_STRING_MODE , 3) ) cmd.type = UART_TYPE_MODE;
	else if ( !strncmp(buff,UART_STRING_CTRL , 3) ) cmd.type = UART_TYPE_CTRL;
	else cmd.type = 3;

	cmd.inst =  (((long)buff[4] << 24) & 0xff000000);
	cmd.inst |= (((long)buff[5] << 16) & 0x00ff0000);
	cmd.inst |= (((long)buff[6] << 8 ) & 0x0000ff00);
	cmd.inst |= (((long)buff[7] ) & 0x000000ff);

		
	for(int j = 9 ; j < 16 ; j++) strValue[j-9] = buff[j];
	cmd.value = atol(strValue);

	return cmd;
		
 }
UART_HandleTypeDef * UART_master(UART_CH_E ch)
{
	if(ch == 0) return &huart2;
	else return 0;
	
}
void UART_Insert(UART_CH_E ch, UART_T *uart)
{

	HAL_UART_Receive_IT(UART_master(ch),(uint8_t*)uart ->Rx_byte,1);
	
	if(uart ->Rx_byte[0]=='[') 
  	{
		uart ->Rx_cnt =0;
		uart ->startflag = 1;
		memset(uart ->Rx_buff[uart ->head] , 0, 20);
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
			memset(uart ->Rx_buff[uart ->head] , 0, 20);
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

