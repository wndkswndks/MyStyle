//rcan.h
#ifndef __RCAN_H
#define __RCAN_H

/*  			include start  			*/
#include "commonheader.h"
/*  			include end  			*/



/*  			define start  			*/

#define  ADC_CANINE		91
#define  PA_ADC			95
#define  RO_ADC			96
#define	CAN_AXIS_POS_DIR			0x9101
#define	CAN_AXIS_0_1_UNIT_PULSE		0x9102
#define	CAN_AXIS_P_MAX_PULSE		0x9103
#define	CAN_AXIS_N_MAX_PULSE		0x9104
#define	CAN_AXIS_ACCEL_STEP			0x9105
#define	CAN_AXIS_START_SPEED		0x9106
#define	CAN_AXIS_MAX_SPEED			0x9107
#define	CAN_AXIS_MOVE_CONST			0x9108
#define	CAN_AXIS_MOVE				0x9109
#define	CAN_AXIS_SLOW_STOP			0x9110
#define	CAN_AXIS_CNT				0x9111	
#define	CAN_AXIS_MOVE_ACK_REQ		0x9114

#define	CAN_FW_REV_NUM				0x9191
#define	CAN_AXIS_ERROR				0x9199
#define	CAN_TEST					0x9999
	
#define	CAN_LASER_CTRL				0x1300
#define	CAN_ADC_CTRL				0x4700 

#define	CO_MOTOR		13
#define	SD_MOTOR		22

#define	POS_DIR				1
#define	NEG_DIR				0




#define	CO_P_MAX_PULSE_C		301600
#define	CO_N_MAX_PULSE_C		8160	
#define	CO_ACCEL_PULSE_C		2
#define	CO_START_PULSE_C		9000
#define	CO_MAX_PULSE_C			20000
#define CO_0_1_MM_PULSE_C		320	

#define	SD_P_MAX_PULSE		89362
#define	SD_N_MAX_PULSE		55130
#define	SD_ACCEL_PULSE		4
#define	SD_START_PULSE		3000
#define	SD_MAX_PULSE		10491
#define	SD_0_1_MM_PULSE		27



/*  			define end  			*/



/*  			enum start  			*/

/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	uint16_t inst;
	uint32_t value;
	uint16_t msg;

	uint8_t stop_flag;
	uint8_t org_complete_flag;
	uint16_t move_distance;

	uint16_t ct_offset;
	uint16_t pano_offset;
	uint16_t ceph_offset;
} CAN_T;

typedef struct
{
	uint32_t pa_value;
	uint32_t ro_value;
	uint8_t is_adc_ok;
} CAN_ADC_T;
/*  			stuct end  				*/



/*  			function start  		*/
void CAN_Ack();
void CAN_Ack_Pos_Dir(CAN_T);
void CAN_Ack_0_1_Unit_Pulse(CAN_T);
void CAN_Ack_P_Max_Pulse_Dir(CAN_T);
void CAN_Ack_N_Max_Pulse_Dir(CAN_T);
void CAN_Ack_Accel_Step(CAN_T);
void CAN_Ack_Start_Speed(CAN_T);
void CAN_Ack_Max_Speed(CAN_T);
void CAN_Ack_Move(CAN_T);
void CAN_Ack_Move_Const(CAN_T);
void CAN_Ack_cnt(CAN_T);
void CAN_Ack_Error(CAN_T);
void CAN_Ack_Fw_rev(CAN_T);
void CAN_Ack_Laser_Ctrl(CAN_T);
void CAN_Ack_Adc_Ctrl(CAN_T);
void CAN_Print_Master(CAN_T);
/*  			function end  			*/

#endif