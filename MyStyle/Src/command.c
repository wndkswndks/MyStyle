//command.c
#include "command.h"
MODE_T m_mode;

extern Motor_drive_T m_PA;
extern Motor_drive_T m_RO;


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
	do{ CMD_ModePrintf(cmd.inst); }while(0);

		
	
	
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
			 CMD_Mode_PANO(cmd.inst);
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

}

void CMD_Mode_PANO(long panoMode)
{
	static uint8_t step;
	uint8_t ro_origin_ok, pa_origin_ok;

	m_mode.main_mode = panoMode;
	//CMD_PanoModePrintf(panoMode);
	switch(step)
	{

	     case STEP1:
			ro_origin_ok = MOTOR_RO_Origin();
			pa_origin_ok = MOTOR_PA_Origin();
			if(ro_origin_ok && pa_origin_ok) step = STEP2;
	     break;

	     case STEP2:
			MOTOR_OffsetMove(&m_PA,1000);
			MOTOR_OffsetMove(&m_RO,1000);
			if(m_PA.stop_flag && m_RO.stop_flag)step = STEP3;
	     break;

	     case STEP3:

	     break;

	     case STEP4:

	     break;

	     case STEP5:

	     break;

	}

}
void CMD_Mode_CEPH()
{

}
void CMD_Mode_PREC()
{

}

void CMD_ModePrintf(long panoMode)
{
	switch(panoMode)
	{

	     case CT:				UART_Pcput("CT");				break;
	     case CT_CHILD:			UART_Pcput("CT_CHILD");			break;
	     case PANO_STAN:		UART_Pcput("PANO_STAN");		break;
	     case PANO_BITEWING:	UART_Pcput("PANO_BITEWING");	break;
	     case PANO_SINUS:		UART_Pcput("PANO_SINUS");		break;
	     case PANO_TMJ2:		UART_Pcput("PANO_TMJ2");		break;
	     case SCAN_CEPH_LA:		UART_Pcput("SCAN_CEPH_LA");		break;
	     case SCAN_CEPH_PA:		UART_Pcput("SCAN_CEPH_PA");		break;
	     case PREC_COMPLETE:	UART_Pcput("PREC_COMPLETE");	break;

	}

}

