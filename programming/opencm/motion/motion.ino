#include <Servo.h>
#include "raider_motion.h"

//STATE SIGNALS
#define STOP_BUTTON 0
#define STATE_LED 1

//BAUD RATE FOR COMMUNICATION
#define BBB_BAUD_RATE 9600
#define BT_BAUD_RATE 9600

Robot raider;

  
void setup() {
 // Serial2.begin(BT_BAUD_RATE); //Bluetooth
    Serial3.begin(BBB_BAUD_RATE); //Beaglebone
    SerialUSB.begin();
 
    pinMode(BOARD_LED_PIN, OUTPUT);
    pinMode(STOP_BUTTON, INPUT);
    pinMode(STATE_LED, OUTPUT);

    raider.init();
}

void loop() {

      raider.defense();
      delay(4000);
      raider.lookR();
      raider.miniPunchR();
      
      delay(4000);
      raider.defense();
      delay(4000);
      raider.lookL();
      raider.miniPunchL();

     
     delay(4000); 
     
     
   //}
  //else{
   // digitalWrite(STATE_LED, LOW); 
   // if(Serial3.available()){
   //   char command=Serial3.read();
//      SerialUSB.println(command);
//      digitalWrite(BOARD_LED_PIN, LOW);
//      raider.controller(command);
//      Serial3.flush();
//    } 
//  }
}
