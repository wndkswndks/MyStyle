//motor.c

#include "commonheader.h"
uint32_t qqwe;
Motor_drive_T m_PA;
Motor_drive_T m_RO;


void MOTOR_Init()
{
	m_PA.min_speed = 		PA_MIN_SPEED;
	m_PA.accel_step = 		ACCEL_STEP;
	m_PA.movetype=			MOVETYPE_NOTENTER;
	m_PA.pulse_cnt=			INIT_PULSE_CNT;	
	m_PA.position_cnt=		INIT_PULSE_CNT;
	m_PA.now_speed = 80;
}

void MOTOR_Value_reset(Motor_drive_T *motor)
{
	motor->dest_speed = 0;
	motor->now_speed = 0;
	motor->total_pulsecnt = 0;
	motor->pulse_cnt =0;
	motor->movetype = MOVETYPE_NOTENTER;
	motor->pulse_admit = NOTADMIT;
	motor->decrease_pulsecnt = 0;

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)  

{
	 	uint8_t crash_flag;
	 if(htim -> Instance == TIM10) 
	 {
		m_PA.pulse_cnt ++;
		
		if(m_PA.dir ==DIR_FORWARD) 
		{
			crash_flag = MOTOR_Crash_prevention(&m_PA, DIR_FORWARD,PA_P_MAX_PULSE);	
			if(crash_flag == CRASH_FLAG) 
			{
				MOTOR_Value_reset(&m_PA);
				return;
			}
			
		}
		else if(m_PA.dir ==DIR_BACKWARD) 
		{
			crash_flag = MOTOR_Crash_prevention(&m_PA, DIR_BACKWARD,PA_N_MAX_PULSE);
			if(crash_flag == CRASH_FLAG)
			{
				MOTOR_Value_reset(&m_PA);
				return;
			}
		}
		
		if(m_PA.total_pulsecnt < m_PA.pulse_cnt) 
		{
			MOTOR_Stop(&m_PA);
			m_PA.movetype = MOVETYPE_NOTENTER;
			MOTOR_Value_reset(&m_PA);
			return;
		}

		
		if(m_PA.movetype==MOVETYPE_NOMAL)
		{
			MOTOR_Speed_nomal_config(&m_PA);
		}
		else if(m_PA.movetype==MOVETYPE_SLOWSTOP)
		{
			MOTOR_Speed_slowstop_config(&m_PA);
		}
		
		else if(m_PA.movetype==MOVETYPE_UNCHANG) 
		{
			// speed unchang
		}

	}

}

void MOTOR_Speed_nomal_config(Motor_drive_T * motor)
{
	uint8_t Nextstep = motor->accel_step;
	uint32_t Pulse_cnt = motor->pulse_cnt;
	uint32_t Dest_speed = motor->dest_speed;
	uint32_t Min_speed = motor->min_speed;
	uint32_t Total_pulsecnt= motor->total_pulsecnt;
	static uint8_t speedstatus = SPEED_INCREASE ;

	switch(speedstatus)
	{

	     case SPEED_INCREASE:
	     
			if(Pulse_cnt == motor->now_speed)
			{
				motor->now_speed += Nextstep;
				if( motor->now_speed >= Dest_speed )
	 			{
	 				motor->now_speed = Dest_speed;
					speedstatus = SPEED_IMMOBILITY;				
	 			}
	 			MOTOR_Speed_set(motor);
			}	
			  
	     break;

	     case SPEED_IMMOBILITY:

	     	  if(Pulse_cnt == motor->decrease_pulsecnt - 1) speedstatus = SPEED_DECREASE;
	     	  
	     	  
	     break;

	     case SPEED_DECREASE:
	     	  if(Pulse_cnt == motor->decrease_pulsecnt)
	     	  {
	     	  	  motor->decrease_pulsecnt += Nextstep;
	     	  	  
				  motor->now_speed -= Nextstep;		  
				  if(motor->now_speed < Min_speed)
				  {
						motor->now_speed = Min_speed;
						motor->movetype = MOVETYPE_NOTENTER;
						speedstatus = SPEED_INCREASE;
				  }
				  MOTOR_Speed_set(motor);
	     	  }

	     break;
	}
	

}	
void MOTOR_Speed_slowstop_config(Motor_drive_T * motor)
{
	
	motor->now_speed -= motor->accel_step;	
	if(motor->now_speed < motor->min_speed) motor->now_speed = motor->min_speed;
	MOTOR_Speed_set(motor);
}


void MOTOR_Speed_set(Motor_drive_T * motor)
{
	
}

void MOTOR_Stop(Motor_drive_T * motor)
{
	motor->stop_flag = STOP_FLAG;
}
void MOTOR_Slow_stop(Motor_drive_T *motor, uint32_t totalpulse )
{
	motor->movetype = MOVETYPE_SLOWSTOP;
	motor->total_pulsecnt = totalpulse;
	MOTOR_Speed_set(motor);
}
uint8_t MOTOR_Crash_prevention(Motor_drive_T * motor ,int dir ,uint32_t MAX_pluse)
{
	if(dir == DIR_FORWARD)
	{
		motor->position_cnt++;
		if(motor->position_cnt >MAX_pluse)
		{
			MOTOR_Stop(&m_PA);
			return CRASH_FLAG;
		}		
	}
	else if(dir == DIR_BACKWARD)
	{
		motor->position_cnt--;
		if(motor->position_cnt <-MAX_pluse)
		{
			MOTOR_Stop(&m_PA);
			return CRASH_FLAG;
		}
	}
	return NONE_CRASH_FLAG ;
}

void MOTOR_Drive(Motor_drive_T * motor , uint8_t dir,uint32_t startspeed, uint32_t destspeed, uint32_t totalpulse )
{	
	
	if(destspeed > startspeed)
	{
		if(destspeed > totalpulse/2) 
		{
			destspeed = totalpulse/2-1;
			startspeed = totalpulse/4-1;
		}
		motor->movetype = MOVETYPE_NOMAL;
		motor->dir = dir;
		motor->now_speed = startspeed;
		motor->dest_speed = destspeed;
		motor->total_pulsecnt = totalpulse;
		motor->decrease_pulsecnt = totalpulse - destspeed;
		motor->pulse_cnt = INIT_PULSE_CNT;				
	}

	else if(destspeed == startspeed)
	{
		motor->movetype = MOVETYPE_UNCHANG;
		motor->now_speed = startspeed;
	}
	else if(destspeed < startspeed)
	{
		// not here go to MOTOR_Slow_stop()
	}
	MOTOR_Speed_set(motor);
	
}


uint8_t MOTOR_PA_Origin()
{
	static uint8_t step =STEP1;
	static uint8_t sensorRecode = 0;
	static uint8_t err= NO;

	
	switch(step)
	{
	     case STEP1:
	     	if(m_PA.sensor_flag) step = STEP4;
	     	else step = STEP2;
	     break;

	     case STEP2:
			if(MOTOR_SensorCheek(&m_PA , DIR_FORWARD,10,100, 300, YES)) 
			{
				MOTOR_Slow_stop(&m_PA, 300);
				step = STEP3;
			}
			else if(m_PA.stop_flag) err = YES;
	     break;

	     case STEP3:
			if(m_PA.stop_flag)
			{
				if(TIME_Passed(&m_PA.time[0],1000)) 
				{
					if(m_PA.sensor_flag) step =STEP4; 
					else err = YES;
				}
			}
	     break;

	     case STEP4:
			if(MOTOR_SensorCheek(&m_PA , DIR_BACKWARD,10,10, 300, NO)) 
			{
				MOTOR_Stop(&m_PA);
				step =STEP5;
			}
			else if(m_PA.stop_flag) err = YES;
	     break;

	     case STEP5:
		     if(m_PA.stop_flag) 
		     {
				step =STEP1;
				return ORG_SUCCESS;
			 }
		 break;		 		 	
	}

	return ORG_NOTYET;
}


uint8_t MOTOR_SensorCheek(Motor_drive_T * motor , uint8_t dir,uint32_t startspeed, uint32_t destspeed, uint32_t totalpulse,uint8_t sensorstate)
{
	static uint8_t step =STEP1;
	switch(step)
	{
	   case STEP1:
		MOTOR_Drive(motor,dir,startspeed,destspeed,totalpulse);	
		step = STEP2;
	   break;
	   case STEP2:
		if(motor->sensor_flag == sensorstate) 
		{
			step =STEP1;
			return YES;
		}
		else return NO;
	   break;
	}	
}

uint8_t MOTOR_StopCheek(Motor_drive_T * motor , uint8_t dir,uint32_t startspeed, uint32_t destspeed, uint32_t totalpulse,uint8_t sensorstate)
{
	static uint8_t step =STEP1;
	switch(step)
	{
	   case STEP1:
		MOTOR_Drive(motor,dir,startspeed,destspeed,totalpulse);	
		step = STEP2;
	   break;
	   case STEP2:
		if(motor->stop_flag == sensorstate) 
		{
			step =STEP1;
			return YES;
		}
		else return NO;
	   break;
	}	
}


uint8_t MOTOR_RO_Origin()
{
	static uint8_t step =STEP1;
	int nowAdcDegree;
	long moveDegree;
	static int prevAdcDegree = 0;

	
	switch(step)
	{

	     case STEP1:
			if(MOTOR_ReadDegree_RO(&nowAdcDegree) == YES)
			{
				if(nowAdcDegree < prevAdcDegree) 
				{
					moveDegree = prevAdcDegree - nowAdcDegree;
					moveDegree *= RO_1_DEGREE_PULSE; 
					MOTOR_Drive(&m_RO,DIR_FORWARD,10,100,moveDegree);
				}
				else if(nowAdcDegree >= prevAdcDegree) 
				{
					moveDegree = nowAdcDegree - nowAdcDegree;
					moveDegree *= RO_1_DEGREE_PULSE; 
					MOTOR_Drive(&m_RO,DIR_BACKWARD,10,100,moveDegree);
				}
				step = STEP2;
			}
	     break;

	     case STEP2:
	     	if(m_RO.stop_flag)
	     	{
				if(TIME_Passed(&m_RO.time[0],1000)) 
				{
					moveDegree = 100 * RO_1_DEGREE_PULSE; 
					MOTOR_Drive(&m_RO,DIR_BACKWARD,10,100,moveDegree);
					step = STEP3;
				}
	     	}
	     break;

	     case STEP3:
	     	if(m_RO.sensor_flag)
	     	{
				MOTOR_Stop(&m_RO);
				step = STEP4;
	     	}
	     break;

	     case STEP4:
	     	if(m_RO.stop_flag)
	     	{
				if(TIME_Passed(&m_RO.time[0],1000)) 
				{
					MOTOR_ReadDegree_RO(&prevAdcDegree);
					m_RO.org_complete_flag = YES;
					m_RO.position_cnt = 0;
					step = STEP1;
					return ORG_SUCCESS;
				}
	     	}
	     break;

	}

	return ORG_NOTYET;
}
uint8_t MOTOR_OffsetMove(Motor_drive_T *motor, uint32_t offset)
{
	if(offset >0) MOTOR_Drive(motor,DIR_FORWARD,10,100,offset);
	else if(offset<0) MOTOR_Drive(motor,DIR_BACKWARD,10,100,offset);	
	else {} //아무것도 안함 
}

int MOTOR_ReadDegree_RO(int *adcDegree)
{
	
}

