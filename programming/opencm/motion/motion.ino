#include <Servo.h>
#include "raider_motion.h"


Robot raider;

void setup() {
   // pinMode(BOARD_LED_PIN, OUTPUT);
      SerialUSB.begin();

    raider.init();
}

void loop() {
        //SerialUSB.println("Hello World!!");

//    digitalWrite(BOARD_LED_PIN, HIGH);
//    delay(100);          // Wait for 1 second (1000 milliseconds)
//    digitalWrite(BOARD_LED_PIN, LOW);
//    delay(100);          // Wait for 1 second (1000 milliseconds)

int amp=-150;
                         //   P  T  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18 
  //raider.setTargetPosition(510,0,512,512,212,812,662,362,512,512,512,512,332,692,162,862,512,512,512,512);
    raider.setTargetPosition(512,0,512,512,212,812,662,362,512,512,512,512,512,512,512,512,512,512,512,512);
    raider.move(20);
    raider.movVertical(-100,-100);
    raider.move(20);
    
}
