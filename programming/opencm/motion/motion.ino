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
       
       
   } 
  }
                          //   P  T  1   2   3   4   5  6   7   8   9  10  11  12  13  14  15  16  17  18
/*
     raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
     raider.move(0.5);
          delay(500);
          
          

     raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);     raider.move(1);
     */
     
                          //   P  T  1   2   3   4   5  6   7   8   9  10  11  12  13  14  15  16  17  18
    /* raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,112,912,512,512,512,512,512,512);     raider.move(1);

     raider.setTargetPosition(512,0,212,562,512,812,512,32,512,512,512,512,112,912,512,512,512,512,512,512);     raider.move(1);

     //raider.setTargetPosition(512,0,212,562,512,612,512,32,512,512,512,512,112,912,512,512,512,512,512,512);     raider.move(1);
     raider.setTargetPosition(512,0,212,112,512,512,512,512,512,512,512,512,112,912,512,512,512,512,512,512);     raider.move(1);
     
     raider.setTargetPosition(312,0,212,112,312,712,512,512,512,512,512,512,112,912,512,512,512,512,512,512);     raider.move(1);*/
/*     raider.setTargetPosition(312,0,512,112,312,712,512,512,512,512,512,512,512,912,512,512,512,512,512,512);     raider.move(1);
            
                          //   P  T  1   2   3   4   5  6    7   8   9  10  11  12  13  14  15  16  17  18
   */raider.setTargetPosition(512,0,812,000,312,812,512,512,512,512,562,512,562,912,312,512,512,512,512,512);     raider.move(1);
     raider.setTargetPosition(712,0,812,000,312,812,512,512,512,512,412,512,562,912,312,512,512,512,512,512);     raider.move(1);
     raider.setTargetPosition(712,0,812,000,312,812,512,512,512,512,412,512,412,512,312,512,512,512,512,512);     raider.move(1);
     raider.setTargetPosition(512,0,812,000,312,812,512,512,512,512,412,512,412,512,312,512,512,512,512,512);     raider.move(1);
     
      raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
     raider.move(2);




                    while(1);


     
   



}
