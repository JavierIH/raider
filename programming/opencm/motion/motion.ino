#include <Servo.h>
#include "raider_motion.h"

    Robot raider;


void setup() {
      raider.init();

}

void loop() {
//    SerialUSB.begin();
//    SerialUSB.println("ok");

//while(1);
int amp=60;
float tiempo=0.2;
int altura_paso=80;
int balanceo=35;
                          //   P  T  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18 
     raider.setTargetPosition(512,0,512,512,212,812,662,362,512,512,512,512,492,532,512,512,512,512,512,512);
     //raider.movLateral(-15,15);
          raider.move(tiempo); 

     


  
   raider.movVertical(-40,-40);
   raider.move(tiempo); 

   raider.movLateral(balanceo,balanceo);
   raider.move(tiempo); 

   raider.movVertical(-altura_paso,40); //Subir pie
   raider.movFrontal(10,-10);
   raider.move(tiempo/2); 
   raider.movVertical(40+altura_paso,0);//Bajar pie
   raider.move(tiempo*2); 
   raider.movLateral(-balanceo,-balanceo);
   raider.move(tiempo*2); 
   delay(50);
   
   raider.movVertical(-40,-40);
   raider.move(tiempo); 

   raider.movLateral(-balanceo,-balanceo);
   raider.move(tiempo*2); 


      
   raider.movVertical(40,-altura_paso); //subir pie
   raider.movFrontal(-20,20);
   raider.move(tiempo/2); 
   raider.movVertical(0,40+altura_paso);
   raider.move(tiempo*2);
   raider.movLateral(balanceo,balanceo);
   raider.move(tiempo*2);
     delay(50);
     




   

    
}

