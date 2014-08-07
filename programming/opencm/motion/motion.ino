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

     raider.stepL();

  delay(300);

   


   
}
