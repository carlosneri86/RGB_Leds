/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "BoardConfig.h"
#include "RGB_Control.h"
#include "SW_Timer.h"

#define RED_INIT_VALUE		(0x00)
#define GREEN_INIT_VALUE	(0x80)
#define BLUE_INIT_VALUE		(0xFF)
#define CHANGE_COLOR_TIMER	(100/SWTIMER_BASE_TIME)

void vfnChangeColorTimerCallback (void);


int main(void)
{
	uint8_t bChangeColorCounter = 0;
	
	BoardConfig_vfnInit();
	
	RGB_vfnInit();
	
	SWTimer_vfnInit();
	/* The color will change based on this timer */
	bChangeColorCounter = SWTimer_vfnAllocateChannel(CHANGE_COLOR_TIMER,vfnChangeColorTimerCallback);
	/* Start the SW timer */
	SWTimer_vfnEnableTimer(bChangeColorCounter);
	
	for(;;) 
	{	   
		SWTimer_vfnServiceTimers();
	}
	
	return 0;
}

void vfnChangeColorTimerCallback (void)
{
	static uint8_t bRedColor = RED_INIT_VALUE;
	static uint8_t bGreenColor = GREEN_INIT_VALUE;
	static uint8_t bBlueColor = BLUE_INIT_VALUE;
	
	/* Get a new color */
	bRedColor++;
	bGreenColor++;
	bBlueColor++;
	
	RGB_vfnChangeColor(bRedColor,bGreenColor,bBlueColor);
}
