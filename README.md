RGB_Leds
========

This sample code shows control of the RGB LED on the FRDM-KL25 board.

This sample code uses the following modules:<br><br>
-	LPTimer: Used as system tick to create SW timers<br>
-	TPM: Used to generate PWM for the RGB control<br>
-	GPIO: For different modules<br>

The RGB control module initializes the PWM channels for control. The application changes the new RGB value every 100 ms.


