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
       
       
   } 
  }
  /*
                     
                            //   P  T   1   2   3   4   5 6 7 8 9 10 11 12 13 14 15 16 17 18
     raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
          raider.move(3);
          
          raider.yes();
     while(1);     
          delay(500);
          float t=2;
     //raider.movVertical(-50,-50);
                             //P  T  1   2   3   4   5  6   7   8   9   10  11  12  13  14  15  16  17  18
     raider.setTargetPosition(512,0,732,282,212,812,962,62,512,512,512,512,82,942,112,912,712,312,512,512); raider.move(0.2);  
   
          raider.setTargetPosition(512,0,732,282,212,812,962,62,512,512,512,512,82,942,112,912,712,312,512,512); raider.move(0.05);  


     raider.setTargetPosition(512,0,822,202,202,822,512,512,512,512,512,512,82,942,62,962,712,312,512,512); raider.move(0.02);  
     raider.setTargetPosition(512,0,732,282,202,822,512,512,512,512,512,512,82,942,62,962,712,312,512,512); raider.move(1.4);  
     raider.setTargetPosition(512,0,732,282,202,822,512,512,512,512,512,512,212,812,62,962,712,312,512,512); raider.move(0.5);  
     raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,212,812,62,962,712,312,512,512); raider.move(0.1);  
          raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
          raider.move(1.2);
while(1);
     //raider.setTargetPosition(512,0,822,202,202,822,512,512,612,412,512,512,82,942,82,942,712,312,512,512); raider.move(1*t); 
     
     raider.setTargetPosition(512,0,822,202,462,812,812,512,512,512,512,512,82,942,82,942,712,312,512,512); raider.move(2*t);

     raider.setTargetPosition(762,0,822,202,412,512,512,512,512,512,512,512,82,942,82,942,712,312,512,512); raider.move(0.2*t); 
     raider.setTargetPosition(762,0,822,202,412,512,512,512,512,512,512,512,82,942,82,942,662,362,512,512); raider.move(1*t);
     raider.setTargetPosition(512,0,822,202,212,812,512,512,512,512,512,512,82,942,82,942,662,362,512,512); raider.move(1*t);
     raider.setTargetPosition(512,0,822,202,212,812,512,512,512,512,512,512,182,842,82,942,662,362,512,512); raider.move(0.5*t);
     
     raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
     raider.move(1);
          while(1);
  /*        
     raider.walk(5);
     
     raider.turnL();
     raider.turnL();
     raider.turnL();
 */
}
