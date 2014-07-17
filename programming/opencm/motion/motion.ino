#include <Servo.h>
#include "raider_motion.h"

    Robot raider;
    bool manual_mode=false;

    int amp=60;
    float tiempo=0.03;
    int altura_paso=10;
    int balanceo=0;
    int tiempo_balanceo=0;
    int avance=10;
    int m=30; 
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
   
   switch (command){
     
     case 70:
    
    raider.movHead(0);
    raider.move(0);
     
     break;
          
     case 71: 
     
         raider.movHead(200);
    raider.move(0);
     break;
          
     case 72: 
     
         raider.movHead(400);
    raider.move(0);
     break;
     
   }
   
   
   digitalWrite(BOARD_LED_PIN, HIGH);
   Serial2.flush();
  }

                     
                     
                     
                     
                     
                            // P  T  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
    // raider.setTargetPosition(512,250,512,512,212,812,662,362,512,512,512,512,512-60,512+60,512,512,512,512,512,512);
    // raider.movVertical(-120,-120);
     //raider.movLateral(-15,15);
     //     raider.move(tiempo); 
       //   delay(500);
          
    

//while(1);
/*
//PASO INICIAL IZQUIERDO
//proofi

   raider.movVertical(-altura_paso,0); //Subir pie
   raider.movFrontal(avance/2,-avance/2);
   raider.move(tiempo/2); 
   raider.movVertical(altura_paso,0);//Bajar pie
   raider.move(tiempo); 

   
   for (int i=0;i<200;i++){
//PASO DERECHO 

   raider.move(tiempo_balanceo); 
   raider.movVertical(0,-altura_paso); //subir pie
   raider.movFrontal(-avance,avance);
   raider.move(tiempo/2);
   delay(100);
 
   raider.movVertical(0,altura_paso);
   raider.move(tiempo);


//PASO IZQUIERDO 

   raider.movVertical(-altura_paso,0); //subir pie
   raider.movFrontal(avance,-avance);
   raider.move(tiempo/2); 
   delay(100);
   
   raider.movVertical(altura_paso,0);
   raider.move(tiempo);

   }
   
//PASO INICIAL IZQUIERDO

   raider.movVertical(0,-altura_paso); //Subir pie
   raider.movFrontal(-avance/2,avance/2);
   raider.move(tiempo/2); 
   raider.movVertical(0,0+altura_paso);//Bajar pie
   raider.move(tiempo); 

   delay(5000);
     


*/

   

    
}

