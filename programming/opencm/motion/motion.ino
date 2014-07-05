#include <Servo.h>
#include "raider_motion.h"

    Robot raider;


void setup() {
      raider.init();

}

void loop() {
//    SerialUSB.begin();
//    SerialUSB.println("ok");

int amp=10;
                          //   P  T  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18 
   //raider.setTargetPosition(500,300,512,512,212,812,662,362,512,512,512,512,512+amp,512+amp,512,512,512,512,512-amp,512-amp);
   raider.movLateral(amp,amp);
   raider.move(1);
      raider.movLateral(-amp*2,-amp*2);
   raider.move(2);

   raider.setTargetPosition(512,0,512,512,212,812,662,362,512,512,512,512,512,512,512,512,512,512,512,512);
      raider.move(1);

    

    
}

