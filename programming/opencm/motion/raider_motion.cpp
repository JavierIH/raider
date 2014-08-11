#include "wirish.h"
#include "raider_motion.h"


Robot::Robot(){
  
  Dxl.begin(1);

  head.attach(HEAD_PIN);
//  SerialUSB.print("Servo");
//  SerialUSB.println(HEAD_PIN);
  
    
  TRIM[0]=TRIMP;
  TRIM[1]=TRIMT;
  TRIM[2]=TRIM1;
  TRIM[3]=TRIM2;  
  TRIM[4]=TRIM3;
  TRIM[5]=TRIM4; 
  TRIM[6]=TRIM5;
  TRIM[7]=TRIM6;  
  TRIM[8]=TRIM7;
  TRIM[9]=TRIM8;  
  TRIM[10]=TRIM9;  
  TRIM[11]=TRIM10;  
  TRIM[12]=TRIM11;  
  TRIM[13]=TRIM12;  
  TRIM[14]=TRIM13;  
  TRIM[15]=TRIM14;  
  TRIM[16]=TRIM15;  
  TRIM[17]=TRIM16;  
  TRIM[18]=TRIM17;  
  TRIM[19]=TRIM18;  

}

void Robot::controller(char command){
   switch (command){
case 'W':
walk(3);
break;
case 'A':
turnL();
break;
case 'D':
turnR();
break;
case 'Q':
stepL();
break;
case 'E':
stepR();
break;
case 'S':
run(3);
break;
case 'K':
kick();
break;
case 'Y':
yes();
break;
case 'G':
getUp();
break;
case 'H':
hello();
break;
case 'R':
roll();
break;
} 
}

void Robot::init(){
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,472,552,512,512,512,512,512,512);
     movVertical(-120,-120);

  for (int i=0; i<=19; i++){
    currentPosition[i]=targetPosition[i]-100; //Un valor cercano para el primer movimiento TODO capuza 
  }
        //SerialUSB.println("dentro de init!!");

  move(2); //ejecutamos movimiento
  updateCurrentPosition();
  //delay(3000);  //esperamos
}



void Robot::updateCurrentPosition(){ 
  for(int i=0; i<=19; i++) currentPosition[i]=targetPosition[i];
}

void Robot::setTargetPosition(int pan, int tilt, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9, int s10, int s11, int s12, int s13, int s14, int s15, int s16, int s17, int s18){
  targetPosition[0]=pan;
  targetPosition[1]=tilt;
  targetPosition[2]=s1;
  targetPosition[3]=s2;
  targetPosition[4]=s3;
  targetPosition[5]=s4;
  targetPosition[6]=s5;
  targetPosition[7]=s6;
  targetPosition[8]=s7;
  targetPosition[9]=s8;
  targetPosition[10]=s9;
  targetPosition[11]=s10;
  targetPosition[12]=s11;
  targetPosition[13]=s12;
  targetPosition[14]=s13;
  targetPosition[15]=s14;
  targetPosition[16]=s15;
  targetPosition[17]=s16;
  targetPosition[18]=s17;
  targetPosition[19]=s18;
}

void Robot::setTargetOffset(int pan, int tilt, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9, int s10, int s11, int s12, int s13, int s14, int s15, int s16, int s17, int s18){
  targetPosition[0]+=pan;
  targetPosition[1]+=tilt;
  targetPosition[2]+=s1;
  targetPosition[3]+=s2;
  targetPosition[4]+=s3;
  targetPosition[5]+=s4;
  targetPosition[6]+=s5;
  targetPosition[7]+=s6;
  targetPosition[8]+=s7;
  targetPosition[9]+=s8;
  targetPosition[10]+=s9;
  targetPosition[11]+=s10;
  targetPosition[12]+=s11;
  targetPosition[13]+=s12;
  targetPosition[14]+=s13;
  targetPosition[15]+=s14;
  targetPosition[16]+=s15;
  targetPosition[17]+=s16;
  targetPosition[18]+=s17;
  targetPosition[19]+=s18;
}


void Robot::move(float tiempo){

//  Dxl.setPosition(25,targetPosition[0]+TRIM[0],(abs(currentPosition[0]-targetPosition[0])/tiempo)*0.5); // TODO volver a la función antigua
  Dxl.writeWord(25, 32, (abs(currentPosition[0]-targetPosition[0])/tiempo)*0.5); //Velocidad fija para servos (no hay referencia). 
  Dxl.writeWord(25, 30, targetPosition[0]+TRIM[0]); //Posicionamiento del servo i en posicion[i].
//  SerialUSB.print("P:25 en ");
//  SerialUSB.println(targetPosition[0]+TRIM[0]);
  
  head.writeMicroseconds(targetPosition[1]+1000+TRIM[1]); //Valor entre 1000 y 2024
//  SerialUSB.print("T:S en ");
//  SerialUSB.println(targetPosition[1]+1000);
  
  for(int i=1; i<=18; i++){  // TODO resvisar
    //Dxl.setPosition(i,targetPosition[i+1]+TRIM[i+1],(abs(currentPosition[i+1]-targetPosition[i+1])/tiempo)*0.5);
    Dxl.writeWord(i, 32,(abs(currentPosition[i+1]-targetPosition[i+1])/tiempo)*0.5); //Velocidad fija para servos (no hay referencia). 
    Dxl.writeWord(i, 30, targetPosition[i+1]+TRIM[i+1]); //Posicionamiento del servo i en posicion[i].
//    SerialUSB.print("ID:");
//    SerialUSB.print(i);
//    SerialUSB.print(" en ");
//    SerialUSB.println(targetPosition[i]+TRIM[i]);
  }

  updateCurrentPosition();
  //temp=millis()-temp;
  //SerialUSB.print("Tiempo de ejecucion: ");
  //SerialUSB.print(temp);
  //SerialUSB.println(" ms");
  delay(tiempo*1000); // TODO a lo mejor puede cambiarse por isMoving
}

void Robot::movOffset(int id, int offset){
//targePosition[id+1]+=offset;
}

void Robot::movVertical(int left_amp, int right_amp){
      setTargetPosition(targetPosition[0],
                        targetPosition[1],
                        targetPosition[2],
                        targetPosition[3],
                        targetPosition[4],
                        targetPosition[5],
                        targetPosition[6],
                        targetPosition[7],
                        targetPosition[8],
                        targetPosition[9],
                        targetPosition[10],
                        targetPosition[11],
                        targetPosition[12]+right_amp, //11
                        targetPosition[13]-left_amp,
                        targetPosition[14]+2*right_amp,
                        targetPosition[15]-2*left_amp,
                        targetPosition[16]-right_amp,
                        targetPosition[17]+left_amp,
                        targetPosition[18],
                        targetPosition[19]);
}

void Robot::movLateral(int left_amp, int right_amp){
      setTargetPosition(targetPosition[0],
                        targetPosition[1],
                        targetPosition[2],
                        targetPosition[3],
                        targetPosition[4],
                        targetPosition[5],
                        targetPosition[6],
                        targetPosition[7],
                        targetPosition[8],
                        targetPosition[9],
                        targetPosition[10]+right_amp,
                        targetPosition[11]+left_amp,
                        targetPosition[12], //11
                        targetPosition[13],
                        targetPosition[14],
                        targetPosition[15],
                        targetPosition[16],
                        targetPosition[17],
                        targetPosition[18]-right_amp,
                        targetPosition[19]-left_amp);
}

void Robot::movFrontal(int left_amp, int right_amp){
      setTargetPosition(targetPosition[0],
                        targetPosition[1],
                        targetPosition[2],
                        targetPosition[3],
                        targetPosition[4],
                        targetPosition[5],
                        targetPosition[6],
                        targetPosition[7],
                        targetPosition[8],
                        targetPosition[9],
                        targetPosition[10],
                        targetPosition[11],
                        targetPosition[12]-right_amp, //11
                        targetPosition[13]+left_amp,
                        targetPosition[14],
                        targetPosition[15],
                        targetPosition[16]-right_amp,
                        targetPosition[17]+left_amp,
                        targetPosition[18],
                        targetPosition[19]);
}

void Robot::movHead(int degrees){
      setTargetPosition(targetPosition[0],
                        degrees,
                        targetPosition[2],
                        targetPosition[3],
                        targetPosition[4],
                        targetPosition[5],
                        targetPosition[6],
                        targetPosition[7],
                        targetPosition[8],
                        targetPosition[9],
                        targetPosition[10],
                        targetPosition[11],
                        targetPosition[12], //11
                        targetPosition[13],
                        targetPosition[14],
                        targetPosition[15],
                        targetPosition[16],
                        targetPosition[17],
                        targetPosition[18],
                        targetPosition[19]);
}

void Robot::run(int pasos){
  
float tiempo=0.07;
int altura_paso=20;
int avance=15;

     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,462,562,512,512,512+5,512-5,512,512);
     movVertical(-120,-120);
     movLateral(10,-10);
     move(0.2);
          
    
  //PRE-PASO INICIAL
   movVertical(0,-altura_paso); //Subir pie
   //movFrontal(avance/2,-avance/2);
   move(tiempo/2);
   movVertical(0,altura_paso);//Bajar pie
   move(tiempo);
   
//PASO INICIAL IZQUIERDO
   
   movVertical(-altura_paso,0); //Subir pie
   movFrontal(avance/2,-avance/2);
   move(tiempo/2);
   movVertical(altura_paso,0);//Bajar pie
   move(tiempo);
   
   
   
   
   for (int i=0;i<pasos;i++){
//PASO DERECHO
   movVertical(0,-altura_paso); //subir pie
   movFrontal(-avance,avance);
   move(tiempo/2);
   delay(100);
   movVertical(0,altura_paso);
   move(tiempo);
//PASO IZQUIERDO
   movVertical(-altura_paso,0); //subir pie
   movFrontal(avance,-avance);
   move(tiempo/2);
   delay(100);
   movVertical(altura_paso,0);
   move(tiempo);
   }
//PASO FINAL DERECHO

   setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-5,5,0,0);
   move(0.2);

   movVertical(0,-altura_paso); //Subir pie
   movFrontal(-avance/2,avance/2);
   move(tiempo/2);
   movVertical(0,0+altura_paso);//Bajar pie
   move(tiempo*5);
}

void Robot::walk(int pasos){

float tiempo=0.015;
int altura_paso=15; //10
int avance=10; //10   

     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     movVertical(-120,-120);
     move(tiempo);
          
  //PASO INICIAL IZQUIERDO
   movVertical(-altura_paso,0); //Subir pie
   movFrontal(avance/2,-avance/2);
   move(tiempo/2);
   movVertical(altura_paso,0);//Bajar pie
   move(tiempo);
   for (int i=0;i<pasos;i++){
//PASO DERECHO
   movVertical(0,-altura_paso); //subir pie
   movFrontal(-avance,avance);
   move(tiempo/2);
   delay(100);
   movVertical(0,altura_paso);
   move(tiempo);
//PASO IZQUIERDO
   movVertical(-altura_paso,0); //subir pie
   movFrontal(avance,-avance);
   move(tiempo/2);
   delay(100);
   movVertical(altura_paso,0);
   move(tiempo);
   }
//PASO FINAL DERECHO
   movVertical(0,-altura_paso); //Subir pie
   movFrontal(-avance/2,avance/2);
   move(tiempo/2);
   movVertical(0,0+altura_paso);//Bajar pie
   move(tiempo);
}

void Robot::kick(){
                          //   P  T  1   2   3   4   5  6   7   8   9  10  11  12  13  14  15  16  17  18
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,332,692,272,752,632,392,512,512);
     move(0.2);
     movLateral(20,20);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-100);
     move(0.2);
     movFrontal(40,0);
     move(0.0);
     delay(500);
     movFrontal(-40,0);
     move(0.3);
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,332,692,272,752,632,392,512,512);
     move(0.3);
}

void Robot::getUp(){
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     movVertical(-120,-120);
     move(0.5);
          delay(500);
                             //P  T  1   2   3   4   5  6   7   8   9   10  11  12  13  14  15  16  17  18
     setTargetPosition(512,512,732,282,212,812,962,62,512,512,512,512,82,942,112,912,712,312,512,512); move(0.2);  
     setTargetPosition(512,512,732,282,212,812,962,62,512,512,512,512,82,942,112,912,712,312,512,512); move(0.05);  
     setTargetPosition(512,512,822,202,202,822,512,512,512,512,512,512,82,942,62,962,712,312,512,512); move(0.02);  
     setTargetPosition(512,512,732,282,202,822,512,512,512,512,512,512,82,942,62,962,712,312,512,512); move(1.4);  
     setTargetPosition(512,512,732,282,202,822,512,512,512,512,512,512,212,812,62,962,712,312,512,512); move(0.5);  
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,212,812,62,962,712,312,512,512); move(0.1);  
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     movVertical(-120,-120);
     move(1.2);
     yes();
}

void Robot::yes(){
     setTargetOffset(0,300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); move(0.07);
     setTargetOffset(0,-300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); move(0.07);
     setTargetOffset(0,300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); move(0.07);
     setTargetOffset(0,-300,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); move(0.07);

}

void Robot::hello(){
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,482,542,512,512,512,512,512,512); move(0.5);
     setTargetPosition(512,512,462,562,412,612,992,32,512,512,512,512,482,542,512,512,512,512,512,512); move(0.3);
     setTargetPosition(512,300,712,312,412,612,912,112,512,512,512,512,482,542,512,512,512,512,512,512); move(0.3);
     setTargetPosition(512,300,812,212,412,612,912,112,512,512,512,512,482,542,512,512,512,512,512,512); move(0.5);
     setTargetPosition(512,300,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.5);
     setTargetPosition(612,0,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.2);
     setTargetPosition(612,0,1012,12,312,712,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(612,0,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(612,0,1012,12,312,712,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(612,0,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(412,300,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.4);
     setTargetPosition(412,0,1012,12,312,712,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(412,0,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(412,0,1012,12,312,712,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(412,0,1012,12,212,812,612,412,512,512,512,512,482,542,512,512,512,512,512,512); move(0.15);
     setTargetPosition(512,300,712,312,412,612,912,112,512,512,512,512,482,542,512,512,512,512,512,512); move(1); 
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,482,542,512,512,512,512,512,512);
     movVertical(-120,-120);
     move(1);
     yes();
}

void Robot::roll(){
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     movVertical(-120,-120);
     move(0.5);
     
     setTargetPosition(512,512,212,112,512,512,512,512,512,512,512,512,112,912,512,512,512,512,512,512);     move(0.8);
     setTargetPosition(312,0,212,112,312,712,512,512,512,512,512,512,112,912,512,512,512,512,512,512);     move(0.8);
     setTargetPosition(312,0,512,112,312,712,512,512,512,512,512,512,512,912,512,512,512,512,512,512);     move(0.8);         
     setTargetPosition(512,512,812,000,312,812,512,512,512,512,562,512,562,912,312,512,512,512,512,512);     move(0.8);
     setTargetPosition(712,0,812,000,312,812,512,512,512,512,412,512,562,912,312,512,512,512,512,512);     move(0.8);
     setTargetPosition(712,0,812,000,312,812,512,512,512,512,412,512,412,512,312,512,512,512,512,512);     move(0.8);
     setTargetPosition(512,512,812,000,312,812,512,512,512,512,412,512,412,512,312,512,512,512,512,512);     move(0.8);
     
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,452,572,512,512,512,512,512,512);
     movVertical(-120,-120);
     move(1);
}

void Robot::turnL()
{
  int i=20;
  float t=0.02;
//Recomendado t=0.2
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,513,522,342-i,681+i,241,781,646,377,511,502); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,519,528,344-i,678+i,245,776,644,380,505,496); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,524,533,346-i,675+i,250,770,642,383,500,491); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,528,537,349-i,672+i,256,763,639,386,496,487); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,521,544,352-i,679+i,262,778,636,379,493,483); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,503,555,354-i,696+i,266,811,634,362,491,480); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,494,560,355-i,703+i,268,826,633,355,490,478); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,558,465,503,554,355-i,708+i,266,811,639,370,491,481); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,569,454,521,543,353-i,692+i,262,778,641,387,493,485); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,528,536,350-i,684+i,256,763,644,394,496,488); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,524,532,345-i,687+i,250,770,646,389,500,492); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,519,527,341-i,688+i,245,776,647,385,505,497); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,513,521,337-i,689+i,241,781,647,381,511,503); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,507,516,335-i,688+i,240,783,645,378,517,508); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,502,510,334-i,686+i,242,782,642,376,522,514); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,496,504,335-i,682+i,247,778,638,376,528,520); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,491,499,336-i,678+i,253,773,634,377,533,525); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,487,495,339-i,673+i,260,767,629,379,537,529); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,569,454,480,502,331-i,670+i,245,761,636,382,540,532); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,558,465,469,520,315-i,668+i,212,757,653,384,544,534); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,542,481,464,529,309-i,669+i,197,755,663,387,546,535); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,468,520,327-i,669+i,212,757,661,389,545,534); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,479,502,344-i,671+i,245,761,644,387,542,532); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,486,495,351-i,674+i,260,767,637,384,538,529); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,490,499,348-i,677+i,253,773,640,381,534,525); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,495,504,345-i,679+i,247,778,643,379,529,520); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,501,510,342-i,681+i,242,782,646,377,523,514); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,507,516,341-i,682+i,240,783,647,376,517,508); move(t);
}

void Robot::turnR()
{
  int i=20;
  float t=0.02;

//Recomendado t=0.2
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,501,510,342-i,681+i,242,782,646,377,523,514); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,495,504,345-i,679+i,247,778,643,379,529,520); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,490,499,348-i,677+i,253,773,640,381,534,525); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,486,495,351-i,674+i,260,767,637,384,538,529); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,479,502,344-i,671+i,245,761,644,387,542,532); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,468,520,327-i,669+i,212,757,661,389,545,534); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,463,529,320-i,668+i,197,755,668,390,547,535); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,558,465,469,520,315-i,668+i,212,757,653,384,544,534); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,569,454,480,502,331-i,670+i,245,761,636,382,540,532); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,487,495,339-i,673+i,260,767,629,379,537,529); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,491,499,336-i,678+i,253,773,634,377,533,525); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,496,504,335-i,682+i,247,778,638,376,528,520); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,502,510,334-i,686+i,242,782,642,376,522,514); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,507,516,335-i,688+i,240,783,645,378,517,508); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,513,521,337-i,689+i,241,781,647,381,511,503); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,519,527,341-i,688+i,245,776,647,385,505,497); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,524,532,345-i,687+i,250,770,646,389,500,492); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,573,450,528,536,350-i,684+i,256,763,644,394,496,488); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,569,454,521,543,353-i,692+i,262,778,641,387,493,485); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,558,465,503,554,355-i,708+i,266,811,639,370,491,481); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,542,481,494,559,354-i,714+i,268,826,636,360,490,479); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,503,555,354-i,696+i,266,811,634,362,491,480); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,521,544,352-i,679+i,262,778,636,379,493,483); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,528,537,349-i,672+i,256,763,639,386,496,487); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,524,533,346-i,675+i,250,770,642,383,500,491); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,519,528,344-i,678+i,245,776,644,380,505,496); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,513,522,342-i,681+i,241,781,646,377,511,502); move(t);
  setTargetPosition(512,512,462,562,212,812,992,32,512,512,507,516,341-i,682+i,240,783,647,376,517,508); move(t);
}

void Robot::stepL()
{
  
int avance=40;
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,482,542,512,512,512+5,512-5,512,512);
     movVertical(-120,-120);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
     movLateral(20,-20);
     move(0.1);
     
     movLateral(avance,-avance);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-40,0);
     movVertical(-30,0);
     movFrontal(-20,0);
     move(0.1); 
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20);
     move(0.1);  
     movLateral(-avance,avance);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40,0);
     movVertical(0,-30);
     move(0.1);
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,482,542,512,512,512+5,512-5,512,512);
     movVertical(-120,-120);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
     movLateral(20,-20);
     move(0.1);
  
  
  
  
}
void Robot::stepR()
{
  //bueno
int avance=40;
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,482,542,512,512,512+5,512-5,512,512);
     movVertical(-120,-120);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
     movLateral(20,-20);
     move(0.1);
     
     movLateral(avance,-avance);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,40);
     movVertical(0,-30);
     movFrontal(0,-20);
     move(0.1); 
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-20,0);
     move(0.1);  
     movLateral(-avance,avance);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-40);
     movVertical(-30,0);
     move(0.1);
     setTargetPosition(512,512,462,562,212,812,992,32,512,512,512,512,482,542,512,512,512+5,512-5,512,512);
     movVertical(-120,-120);
     setTargetOffset(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
     movLateral(20,-20);
     move(0.1);
}

