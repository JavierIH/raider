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
  digitalWrite(BOARD_LED_PIN, HIGH);

  if(digitalRead(STOP_BUTTON)){
    digitalWrite(1, HIGH);
    SerialUSB.println("stop");
     raider.setTargetPosition(512,0,512,512,212,812,992,32,512,512,512,512,512,512,512,512,512,512,512,512);
     //movVertical(-120,-120);
     raider.move(5);
   }
  else{
    digitalWrite(1, LOW); 
    if(Serial3.available()){
      char command=Serial3.read();
      SerialUSB.println(command);
      digitalWrite(BOARD_LED_PIN, LOW);
      raider.controller(command);
      Serial3.flush();
    } 
  }
}
