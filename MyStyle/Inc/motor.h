//motor.h
#ifndef __HEAD_H
#define __HEAD_H
/*  			include start  			*/
#include "commonheader.h"
/*  			include end  			*/



/*  			define start  			*/
#define MOTOR_RO		0
#define MOTOR_PA		1
#define MOTOR_MAX		2

#define SPEED_INCREASE			1
#define SPEED_IMMOBILITY		2
#define SPEED_DECREASE			3

#define ACCEL_STEP			2
#define PA_MIN_SPEED		5
#define PA_TOTAL_PULSECNT	300
#define PA_FIRST_SPEED		30
#define PA_DEST_SPEED		80

#define DIR_FORWARD			1
#define DIR_BACKWARD		2

#define PA_N_MAX_PULSE	300 
#define PA_P_MAX_PULSE	300

#define CRASH_FLAG		1
#define NONE_CRASH_FLAG	0

#define INIT_PULSE_CNT	-1

#define STOP_FLAG	1
#define NOSTOP_FLAG	2

#define ADMIT	1
#define NOTADMIT	0


#define RO_1_DEGREE_PULSE		426

/*  			define end  			*/



/*  			enum start  			*/
typedef enum
{
	MOVETYPE_NOMAL = 0,
	MOVETYPE_UNCHANG,
	MOVETYPE_SLOWSTOP,
	MOVETYPE_NOTENTER,
	
} MOVETYPE_E;
/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	uint16_t ct_offset;
	uint16_t pano_offset;
	uint16_t ceph_offset;
} Motor_Material_T;

typedef struct
{	
	uint8_t accel_step;
	uint8_t dir;
	uint8_t stop_flag;
	uint8_t pulse_admit;
	uint8_t sensor_flag;
	uint8_t org_complete_flag;
	
	uint32_t now_speed;
	uint32_t start_speed;
	uint32_t dest_speed;
	uint32_t min_speed;

	uint32_t time[5];

	int pulse_cnt;
	int position_cnt;
	uint32_t decrease_pulsecnt;
	uint32_t total_pulsecnt;
	MOVETYPE_E movetype;
}Motor_drive_T;
/*  			stuct end  				*/



/*  			function start  		*/

void MOTOR_Speed_set(Motor_drive_T *);
void MOTOR_Speed_nomal_config(Motor_drive_T * );
void MOTOR_Speed_slowstop_config(Motor_drive_T * );

void MOTOR_Stop(Motor_drive_T *);
void MOTOR_Slow_stop(Motor_drive_T *, uint32_t  );
void MOTOR_Drive(Motor_drive_T * ,uint8_t ,uint32_t , uint32_t, uint32_t  );
void MOTOR_Value_reset(Motor_drive_T *);
void MOTOR_PA_Origin();
void MOTOR_RO_Origin();
uint8_t MOTOR_SensorCheek(Motor_drive_T *, uint8_t ,uint32_t , uint32_t , uint32_t ,uint8_t );
uint8_t MOTOR_StopCheek(Motor_drive_T *, uint8_t ,uint32_t , uint32_t , uint32_t ,uint8_t );
uint8_t MOTOR_Crash_prevention(Motor_drive_T * ,int ,uint32_t );
int MOTOR_ReadDegree_RO(int *adcDegree);
/*  			function end  			*/
#endif