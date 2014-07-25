#include <Servo.h>
#include "raider_motion.h"

    Robot raider;
    bool manual_mode=false;

int command;

    
void setup() {
    Serial2.begin(9600); //Bluetooth
   // Serial3.begin(9600); //Beaglebone
    pinMode(BOARD_LED_PIN, OUTPUT);

    //  raider.init();


}

void loop() {
//    SerialUSB.begin();
//    SerialUSB.println("ok");


       digitalWrite(BOARD_LED_PIN, HIGH);

  if(Serial2.available()){
    command=Serial2.read();
    SerialUSB.println(command);
   digitalWrite(BOARD_LED_PIN, LOW);
   Serial2.flush();
   switch (command){ 
     case 'W':
       raider.walk(5);
       break; 
     case 'A':
       raider.turnL();
       break; 
     case 'D':
       raider.turnR();
       break; 
     case 'K':
       raider.kick();
       break;
     case 'Y':
       raider.yes();
       break;
     case 'G':
       raider.getUp();
       break;
     case 'H':
       raider.hello();
       break;
     case 'R':
       raider.roll();
       break;
       
   } 
  }
}
