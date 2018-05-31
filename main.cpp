#include "mbed.h"
#include "ultrasonic.h" //library 

DigitalOut close (p28); 
DigitalOut closer (p26); 
DigitalOut led1 (LED1); 
DigitalOut led2 (LED2); 
DigitalOut led3 (LED3); 

AnalogIn trig (p17); // trig pin of ultrasonic sensor
AnalogOut echo (p18); // echo pin of ultrasonic sensor

 void dist(int distance)
{
    
       
     if(distance < 50) 
            {
               
              led = 1;
              wait(3); //wait for 3 seconds the distance will print out
              printf("\n distance %d", distance);
              led = 0;
              } 
              
         else if(distance > 50 && distance < 100 ) // within this range the leds will on
            {
              
              led = 1;
              led2 = 1;
              wait(3);
              printf("\n distance %d", distance);
              led = 0;
              led2 = 0;
              } 
            else if(distance > 100 && distance < 200) // within this range the leds will on
               
              led = 1;
              led2 = 1;
              led3 = 1;
              wait(3);
              printf("\n distance %d", distance);
              led = 0;
              led2 = 0;
              led3 =0;
              } 
   }                         
    
ultrasonic mu(p17, p18, 0.1, 1, &dist);   
ultrasonic mu1(p15, p16, 0.1, 1, &dist);                                       
                                        

int main()
{
    mu.startUpdates();
    mu1.startUpdates();//start mesuring the distance
    while(1)
    {
        
        mu.checkDistance();
        mu1.checkDistance();     //call checkDistance() as much as possible, as this is where
                                //the class checks if dist needs to be called.
    }
}