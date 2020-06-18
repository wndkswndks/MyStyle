//commonheader.h

#ifndef __COMMONHEADER_H
#define __COMMONHEADER_H

#include <stdint.h> 
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"


#include "uart.h"
#include "motor.h"

extern Motor_drive_T m_PA;
extern UART_T m_uart[UART_CH_MAX];


typedef enum
{ 
	STEP0, STEP1, STEP2, STEP3, STEP4, STEP5, STEP6, STEP7, STEP8, STEP9, STEP10, 
	STEP11, STEP12, STEP13, STEP14, STEP15, STEP16, STEP17, STEP18, STEP19, STEP20,
	STEP_END,
} STEP_T;



#endif
