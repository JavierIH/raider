#include <Servo.h>
#include "raider_motion.h"



void setup() {
}

void loop() {
    Robot raider;
    SerialUSB.begin();
    SerialUSB.println("ok");
    raider.init();

while(1){int amp=-150;
                         //   P  T  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18 
  //raider.setTargetPosition(510,0,512,512,212,812,662,362,512,512,512,512,332,692,162,862,512,512,512,512);
   raider.setTargetPosition(512,400,512,512,212,812,662,362,512,512,512,512,512,512,512,512,512,512,512,512);
   raider.move(1);
   raider.setTargetPosition(500,300,512,512,212,812,662,362,512,512,512,512,512,512,512,512,512,512,512,512);
   raider.move(1);

    
    
}
    
}
