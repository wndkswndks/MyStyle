//rcan.c

#include "rcan.h"

CAN_T m_can;


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
	
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==POS_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_0_1_Unit_Pulse(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_P_Max_Pulse_Dir(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_N_Max_Pulse_Dir(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}

void CAN_Ack_Accel_Step(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}	
}
void CAN_Ack_Start_Speed(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Max_Speed(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Move(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Move_Const(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}

void CAN_Ack_cnt(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Error(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Fw_rev(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Laser_Ctrl(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}
void CAN_Ack_Adc_Ctrl(CAN_T can)
{
	switch(can.msg)
	{
	     case CO_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;

	     case SD_MOTOR:	 
	     if(can.value ==NEG_DIR ){}			

	     break;	    
	}
}

void CAN_Print_Master(CAN_T can)
{
	if(can.msg == CO_MOTOR) UART_Pcput("CO ");
	else if(can.msg == SD_MOTOR) UART_Pcput("SD ");
}