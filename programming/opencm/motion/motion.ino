#include <Servo.h>
#include "raider_motion.h"


Robot raider;

void setup() {
    pinMode(BOARD_LED_PIN, OUTPUT);
      SerialUSB.begin();
    SerialUSB.println("Hello World!!");

    raider.init();
}

void loop() {
    
    digitalWrite(BOARD_LED_PIN, HIGH);
    delay(100);          // Wait for 1 second (1000 milliseconds)
    digitalWrite(BOARD_LED_PIN, LOW);
    delay(100);          // Wait for 1 second (1000 milliseconds)
    raider.move(1);
    raider.setTargetPosition(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
}
