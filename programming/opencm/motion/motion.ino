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
  //digitalWrite(BOARD_LED_PIN, HIGH);

 // if(digitalRead(STOP_BUTTON)){
    //digitalWrite(STATE_LED, HIGH);
    //SerialUSB.println("stop");
    
/* Puñetazo con la derecha
    raider.setTargetPosition(512,0,512,512,312,712,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(4);
    raider.setTargetPosition(462,0,512,512,512,612,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(0.1);
    raider.setTargetPosition(712,0,512,512,512,712,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(0.4);
    raider.setTargetPosition(712,0,512,512,512,712,500,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(0.05);
*/

/* Puñetazo con la derecha
    raider.setTargetPosition(512,0,512,512,312,712,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(4);
    raider.setTargetPosition(662,0,512,512,412,512,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(0.1);
    raider.setTargetPosition(312,0,512,512,312,512,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(0.4);
    raider.setTargetPosition(312,0,512,512,312,512,977,524,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.move(0.05);
*/
/*Cangrejo asesino
    raider.setTargetPosition(512,0,512,512,512,512,812,212,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.movLateral(40,-40);
    raider.move(4);
    raider.setTargetOffset(150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(100);
    raider.setTargetOffset(-300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(100);
    raider.setTargetOffset(300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(100);
    raider.setTargetOffset(-300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(100);
    raider.setTargetOffset(300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(100);
    raider.setTargetOffset(-150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(100);
*/
/*reposo
    raider.setTargetPosition(512,0,512,512,512,512,812,212,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.movLateral(40,-40);
    raider.move(4);
*/
/*mirar izquierda
  raider.setTargetPosition(662,0,512,512,512,512,812,212,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);
    raider.movLateral(40,-40);
    raider.move(4);

*/
   //mirar derecha
    raider.setTargetPosition(362,0,512,512,312,712,977,47,512,512,512,512,477,547,512,512,512,512,512,512);
    raider.movVertical(-120,-120);

    raider.movLateral(40,-40);
    raider.move(4);
//mini derecha
   // raider.setTargetOffset(0,0,-100,0,0,0,-300,0,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.3); delay(0);
   // raider.setTargetOffset(0,0,300,0,0,0,0,0,0,0,0,0,0,0,-30,30,0,0,0,0); raider.move(0.1); delay(100);
   // raider.move(0.2);

//mini izquierda
    raider.setTargetOffset(0,0,0,100,0,0,0,300,0,0,0,0,0,0,0,0,0,0,0,0); raider.move(0.2); 
    raider.setTargetOffset(0,0,0,-300,0,0,0,0,0,0,0,0,0,0,-30,30,0,0,0,0); raider.move(0.05); delay(100);
    raider.move(0.2);

     
     delay(5000); 
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
