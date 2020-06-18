//timer.c
#include "commonheader.h"
uint32_t TIME_Now()
{
	
}
uint8_t TIME_Passed(uint32_t *prev, uint32_t delay)
{
	uint32_t now = HAL_GetTick();
	
	if(!*prev) *prev = now;
	
	if(now - *prev >delay)
	{
		*prev = 0;
		return 1;
	}
	
	return 0;
	
	
}