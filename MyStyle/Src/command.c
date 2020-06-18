//command.c
#include "command.h"


void CMD_Ctrl(UART_CMD_T cmd)
{
	uint16_t value = cmd.value;

	switch(cmd.inst)
	{

	     case 3:

	     break;

	}
	
	  
}
void CMD_Mode(UART_CMD_T cmd)
{
	uint16_t value = cmd.value;
	
	switch(cmd.inst)
	{

	    case CT:					
		case CT_CHILD:		
			CMD_Mode_CT();
		break;

		case PANO_STAN:		
		case PANO_BITEWING:	
		case PANO_TMJ1:		
		case PANO_SINUS:	
			 CMD_Mode_PANO();
		break;

		case PANO_TMJ2:	

		break;

		case SCAN_CEPH_LA:
		case SCAN_CEPH_PA:
			CMD_Mode_CEPH();
		break;

		case PREC_COMPLETE:	
			CMD_Mode_PREC();
		break;



	 } 
}
uint8_t txtxdata[5]="qwer";

void CMD_Mode_CT()
{
	//HAL_UART_Transmit_IT(&huart2, txtxdata, 4);
}
void CMD_Mode_PANO()
{

}
void CMD_Mode_CEPH()
{

}
void CMD_Mode_PREC()
{

}
