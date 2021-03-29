This code is designed for STM32F401RE Microcontroller and can be run
on the Mbed homepage.


About the code
=================
This program uses timers and callbacks to produce an audible tone using 
the speaker, and interrupts to enable use of the up and down buttons of 
the joystick to update the frequency at runtime.
The frequency is constantly displayed on the LCD screen. The fire pin
when pressed will toggle the speaker on and off, and will display either 
a green LED in the case when the speaker is running or a red LED when 
it is not.