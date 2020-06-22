//rcan.c

#include "rcan.h"

CAN_T m_canCo;
CAN_T m_canSd;

Motor_drive_T m_CO;
Motor_drive_T m_SD;
CAN_ADC_T m_canAdc;



void CAN_Ack()
{
	CAN_T can;
	CAN_Print_Master(can);
	switch(can.inst)
	{
        case CAN_AXIS_POS_DIR:       		CAN_Ack_Pos_Dir(can);				break;
        case CAN_AXIS_0_1_UNIT_PULSE:		CAN_Ack_0_1_Unit_Pulse(can);		break;
        case CAN_AXIS_P_MAX_PULSE:  		CAN_Ack_P_Max_Pulse_Dir(can);		break;
        case CAN_AXIS_N_MAX_PULSE:  		CAN_Ack_N_Max_Pulse_Dir	(can);		break;
        case CAN_AXIS_ACCEL_STEP:    		CAN_Ack_Accel_Step(can);			break;
        case CAN_AXIS_START_SPEED:   		CAN_Ack_Start_Speed(can);			break;
        case CAN_AXIS_MAX_SPEED:    		CAN_Ack_Max_Speed(can);				break;
        case CAN_AXIS_MOVE:         		CAN_Ack_Move(can);					break;

        case CAN_AXIS_MOVE_CONST:   		CAN_Ack_Move_Const(can);			break;
        case CAN_AXIS_CNT:           		CAN_Ack_cnt(can);					break;
        case CAN_AXIS_ERROR:         		CAN_Ack_Error(can);					break;
        case CAN_FW_REV_NUM:        		CAN_Ack_Fw_rev(can);				break;
        
        case CAN_LASER_CTRL:         		CAN_Ack_Laser_Ctrl(can);			break;
        case CAN_ADC_CTRL:          		CAN_Ack_Adc_Ctrl(can);				break;
	}
}

void CAN_Ack_Pos_Dir(CAN_T can)
{
	UART_Pcput("Positive Direc  ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==POS_DIR ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}
}
void CAN_Ack_0_1_Unit_Pulse(CAN_T can)
{
	UART_Pcput("0.1 Unit Pulse   ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==CO_0_1_MM_PULSE_C ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==SD_0_1_MM_PULSE ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}
}
void CAN_Ack_P_Max_Pulse_Dir(CAN_T can)
{
	UART_Pcput("P Max Pulse      ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==CO_P_MAX_PULSE_C ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==SD_P_MAX_PULSE ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}

}
void CAN_Ack_N_Max_Pulse_Dir(CAN_T can)
{
	UART_Pcput("N Max Pulse      ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==CO_N_MAX_PULSE_C ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==SD_N_MAX_PULSE ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}

}

void CAN_Ack_Accel_Step(CAN_T can)
{
	UART_Pcput("Accel Step       ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==CO_ACCEL_PULSE_C ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==SD_ACCEL_PULSE ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}

}
void CAN_Ack_Start_Speed(CAN_T can)
{
	UART_Pcput("Start Speed     ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==CO_START_PULSE_C ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==SD_START_PULSE ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}

}
void CAN_Ack_Max_Speed(CAN_T can)
{
	UART_Pcput("Max Speed        ");
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==CO_MAX_PULSE_C ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;

	     case SD_MOTOR:	 
	     if(can.value ==SD_MAX_PULSE ) UART_Pcput("OK\r\n");			
		 else UART_Pcput("Error!!!\r\n");
	     break;	    
	}

}
void CAN_Ack_Move(CAN_T can)
{
	uint8_t set_origin = 0;
	uint32_t temp;
	switch(can.msg)
	{
	     case CO_MOTOR:	 
		     if(can.value ==set_origin )
		     {
				m_canCo.org_complete_flag = YES;
				UART_Pcprintf("[rpm_comv_0000]  [co_end] \r\n"); 		
		     }			
		     else
		     {
				temp = can.value / CO_0_1_MM_PULSE_C;
				UART_Pcprintf("[rpm_comv_%04ld] \r\n", temp);
		     }
		     m_canCo.move_distance = temp;
		     m_canCo.stop_flag = YES;

	     break;

	     case SD_MOTOR:	 
	    	if(can.value ==set_origin )
		     {
				m_canSd.org_complete_flag = YES;
				UART_Pcprintf("[rpm_sdmv_0000]  [co_end] \r\n"); 		
		     }			
		     else
		     {
				temp = can.value / SD_0_1_MM_PULSE;
				UART_Pcprintf("[rpm_sdmv_%04ld] \r\n", temp);
		     }		
		     m_canSd.move_distance = temp;
		     m_canSd.stop_flag = YES;

	     break;	    
	}
}
void CAN_Ack_Move_Const(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value == 0 ) m_canCo.stop_flag = YES;			

	     break;

	     case SD_MOTOR:	 
	     if(can.value == 0 ) m_canSd.stop_flag = YES;		

	     break;	    
	}
}

void CAN_Ack_cnt(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     	UART_Pcprintf("CO Position Count : %ld \r\n", can.value);			
	     break;

	     case SD_MOTOR:	 
	     	UART_Pcprintf("SD Position Count : %ld \r\n", can.value);			
	     break;	    
	}
}
void CAN_Ack_Error(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 			

	     break;

	     case SD_MOTOR:	 		

	     break;	    
	}
}
void CAN_Ack_Fw_rev(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 			

	     break;

	     case SD_MOTOR:	 		

	     break;	    
	}
}
void CAN_Ack_Laser_Ctrl(CAN_T can)
{
	UART_Pcput("CAN LASER CTRL");
}
void CAN_Ack_Adc_Ctrl(CAN_T can)
{
	switch(can.msg)
	{
	     case RO_ADC:
			m_canAdc.ro_value = can.value;
			m_canAdc.is_adc_ok = YES;
	     break;

	     case PA_ADC:
			m_canAdc.pa_value = can.value;
			m_canAdc.is_adc_ok = YES;
	     break;

	}
}

void CAN_Print_Master(CAN_T can)
{
	if(can.msg == CO_MOTOR) UART_Pcput("CO ");
	else if(can.msg == SD_MOTOR) UART_Pcput("SD ");
}
