#include <Servo.h>
#include "raider_motion.h"

    Robot raider;
    bool manual_mode=false;

int command;

    
void setup() {
    Serial2.begin(9600); //Bluetooth
   // Serial3.begin(9600); //Beaglebone
    pinMode(BOARD_LED_PIN, OUTPUT);

      raider.init();


}

void loop() {
//    SerialUSB.begin();
//    SerialUSB.println("ok");


       digitalWrite(BOARD_LED_PIN, HIGH);

  if(Serial2.available()){
    command=Serial2.read();
    SerialUSB.println(command);
   digitalWrite(BOARD_LED_PIN, LOW);
   switch (command){ 
     case 70:
     break; 
   } 
   Serial2.flush();
  }

                     
                     
                            // P T 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
     raider.setTargetPosition(512,0,512,512,212,812,662,362,512,512,512,512,512-60,512+60,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
     //raider.movLateral(-15,15);
          raider.move(2);
          delay(50);
          
     raider.run(50);

 
}
