
/*HEADER******************************************************************************************
*
* Comments:
*
*
**END********************************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Includes Section                        
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include "derivative.h"
#include "GPIO_Mux.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Defines & Macros Section                   
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
//                                       Typedef Section                        
///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Function Prototypes Section                 
///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Global Constants Section                   
///////////////////////////////////////////////////////////////////////////////////////////////////
//! Corresponding clock gate masks for all the GPIO Ports modules.
const uint32_t GPIO_gadwPortGPIOClockGateMask[GPIO_PORT_MAX] =
{
		SIM_SCGC5_PORTA_MASK,
		SIM_SCGC5_PORTB_MASK,
		SIM_SCGC5_PORTC_MASK,
		SIM_SCGC5_PORTD_MASK,
		SIM_SCGC5_PORTE_MASK
};

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Static Constants Section                   
///////////////////////////////////////////////////////////////////////////////////////////////////
//! Registers address of first pin of each port.
static volatile uint32_t * const GPIO_gadwPortGPIO[GPIO_PORT_MAX] =
{
		&PORTA_PCR0,
		&PORTB_PCR0,
		&PORTC_PCR0,
		&PORTD_PCR0,
		&PORTE_PCR0,
};


///////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Global Variables Section                   
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Static Variables Section                   
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Functions Section                       
///////////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_vfnPinMux(uint8_t ePort, uint8_t bPin, uint8_t bMuxSelection)
{
	uint32_t * pdwPortRegister;
	/* confirm there port is available */
	if(ePort < GPIO_PORT_MAX)
	{
		/* enable port clock gate */
		SIM_SCGC5 |= GPIO_gadwPortGPIOClockGateMask[ePort];
		
		/* take the PORTx_PCR0 address */
		/* the bPin is used as offset to access the proper address*/
		pdwPortRegister = (uint32_t*)GPIO_gadwPortGPIO[ePort];
		pdwPortRegister[bPin] = PORT_PCR_MUX(bMuxSelection);
		
	}
}
