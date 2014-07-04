/*
 Blink

 Turns on the built-in LED on for one second, then off for one second,
 repeatedly.

 Ported to CM9 Series from the Arduino example 27 May 2011
 By ROBOTIS,.LTD.
*/

#include"raider_motion.h"
    ok tolai;


void setup() {
    // Set up the built-in LED pin as an output:
    pinMode(BOARD_LED_PIN, OUTPUT);
}

void loop() {
    
    tolai.ak=5;
    digitalWrite(BOARD_LED_PIN, HIGH);
    delay(100);          // Wait for 1 second (1000 milliseconds)
    digitalWrite(BOARD_LED_PIN, LOW);
    delay(100);          // Wait for 1 second (1000 milliseconds)
}
