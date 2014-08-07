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


    
float tiempo=1;
int altura_paso=10;
int avance=40;
int amplitud=30;


     raider.setTargetPosition(512,0,462,562,212,812,992,32,512,512,512,512,462,562,512,512,512+5,512-5,512,512);
     raider.movVertical(-120,-120);
     raider.setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
     raider.movLateral(20,-20);
     raider.move(0.1);
     
  
  
     raider.movLateral(avance,-avance);
     raider.setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40);
     raider.movVertical(0,-30);
     raider.move(0.1);
     
     raider.setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-20,0);
     raider.move(0.1);
     
     raider.movLateral(-avance,avance);
     raider.setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-40);
     raider.movVertical(-30,0);
     raider.move(0.1);


     


  delay(3000);

   


   
}
