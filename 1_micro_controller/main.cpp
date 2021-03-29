#include "mbed.h"
#include "C12832.h"                             //Imports the library for the LCD screen

C12832 lcd(D11, D13, D12, D7, D10);             //Creates an LCD object from the LCD library

class LED                                           //LED class definition
{
protected:                                          
    DigitalOut outputSignal;                        
    bool status;                                    

public:                                             
    LED(PinName pin) : outputSignal(pin){off();}    

    void on(void)                                 
    {   outputSignal = 0;                           
        status = true;                             
    }
    void off(void)                                 
    {   outputSignal = 1;                          
        status = false;                           
    }
    void toggle(void)                               
    {   if (status)                                 
            off();                                 
        else                                        
            on();                                  
    }
    bool getStatus(void)                            
    {   return status;                             
    }
};

class Speaker                                        //Speaker class definition
{
protected:                                          
    DigitalOut outputSignal;                        
    bool status;                                   

public:                                            
    Speaker(PinName pin) : outputSignal(pin){off();} 
   
    void on(void)                                  
    {   outputSignal = 1;                          
        status = true;                              
    }
    void off(void)                                 
    {   outputSignal = 0;                           
        status = false;                             
    }
    void toggle(void)                              
    {   if (status)                                 
            off();                                 
        else                                      
            on();                                   
    }
    bool getStatus(void)                            
    {   return status;                             
    }
};
//Create object
Speaker speaker(D6);                         
Ticker buzzer_out;                          
LED redled(D5), greenled(D9);                 
InterruptIn up(A2),down(A3),centre(D4);       

float frequency = 2000;                     //frequency value can be changed
float period = 0;                           //Initialisation of Ticker period. 
char output_state = 1;                      //Variable to hold record of speakeris outputting or not. 

void updateScreen()                         //Function to update LCD screen data
{   lcd.cls();                              
    lcd.locate(0,0);                        
    lcd.printf("Frequency %f Hz", frequency); 
}

void updateWaittime()
{   period = 1.0/(2.0*frequency);           //Update the Ticker object to toggle at the new frequency
    buzzer_out.attach(callback(&speaker,&Speaker::toggle),period); 
    updateScreen();                         
}

void increaseFreq()                         //ISR to increase frequency by 200 Hz (Up button pressed)
{   frequency += 200;                       
    updateWaittime();                       
}

void decreaseFreq()                         //ISR to increase frequency by 200 Hz (Up button pressed)
{   frequency -=  200;                       
    updateWaittime();
}

void toggleOutput()                     //ISR To start/stop speaker output
{   if (output_state == 1) {           //Check if speaker is currently outputting
        buzzer_out.detach();            
        output_state = 0;               
        lcd.cls();                     
        lcd.locate(0,0);                
        lcd.printf("Buzzer: OFF");      
        redled.on();                   
        greenled.off();                 
    }
    else {                              //Otherwise the speaker is not currently outputting
        output_state = 1;              
        buzzer_out.attach(callback(&speaker,&Speaker::toggle),period); // Attach the callback to output at the current frequency
        updateScreen();                 
        redled.off();                   
        greenled.on();                  
    }
}

int main()
{
    redled.off();                       // Turn the red LED off 
    greenled.on();                      // Turn the green LED on
    period = 1.0/(2.0*frequency);       // Convert the default frequency to a time period
    updateScreen();                     // Display frequency on the LCD screen    

    buzzer_out.attach(callback(&speaker,&Speaker::toggle),period);    //Attach Ticker callback to toggle speaker and generate output

    // Attach ISR for 'up', 'down' and 'centre' buttons to increase, decrease and toggle frequency
    up.rise(&increaseFreq);            
    down.rise(&decreaseFreq);           
    centre.rise(&toggleOutput);       

    // Run an inifnite while loop 
    while(1) {                             
    }
}