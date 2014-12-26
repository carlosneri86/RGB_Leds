RGB_Leds
========

This sample code shows control of the RGB LED on the FRDM-KL25 board.

This sample code uses the following modules:
	* LPTimer: Used as system tick to create SW timers
	* TPM: Used to generate PWM for the RGB control
	* GPIO: For different modules

The RGB control module initializes the PWM channels for control. The application changes the new RGB value every 100 ms.


