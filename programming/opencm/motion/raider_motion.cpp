#include "wirish.h"
#include "raider_motion.h"


Robot::Robot(){
  
  head.attach(HEAD_PIN);
  
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
  TRIM[12]=TRIM10;  
  TRIM[13]=TRIM11;  
  TRIM[14]=TRIM12;  
  TRIM[15]=TRIM13;  
  TRIM[16]=TRIM14;  
  TRIM[17]=TRIM15;  
  TRIM[18]=TRIM16;  
  TRIM[19]=TRIM17;  
  TRIM[20]=TRIM18;

}


void Robot::init(){
  targetPosition[0]=512;
  targetPosition[1]=512;
  targetPosition[2]=62;
  targetPosition[3]=962;
  targetPosition[4]=212;
  targetPosition[5]=812;
  targetPosition[6]=662;
  targetPosition[7]=362;
  targetPosition[8]=512;
  targetPosition[9]=512;
  targetPosition[10]=512;
  targetPosition[11]=512;
  targetPosition[12]=332;
  targetPosition[13]=692;
  targetPosition[14]=162;
  targetPosition[15]=862;
  targetPosition[16]=712;
  targetPosition[17]=312;
  targetPosition[18]=512;
  targetPosition[19]=512;
  
  for (int i=0; i<=19; i++){
    currentPosition[i]=targetPosition[i]-50; //Un valor cercano para el primer movimiento 
  }

  move(1.5); //ejecutamos movimiento
  delay(3000);  //esperamos
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


void Robot::move(float tiempo){
  Dxl.setPosition(25,targetPosition[0]+TRIM[0],(abs(currentPosition[0]-targetPosition[0])/tiempo)*0.7);
  SerialUSB.print("P:25 en ");
  SerialUSB.println(targetPosition[0]+TRIM[0]);
  head.writeMicroseconds(targetPosition[1]+1000); //Valor entre 1000 y 2024
  SerialUSB.print("T:S en ");
  SerialUSB.println(targetPosition[1]);
  for(int i=1; i<=18; i++){      
    Dxl.setPosition(i,targetPosition[i+1]+TRIM[i+1],(abs(currentPosition[i+1]-targetPosition[i+1])/tiempo)*0.7);
    SerialUSB.print("ID:");
    SerialUSB.print(i+1);
    SerialUSB.print(" en ");
    SerialUSB.println(targetPosition[i]+TRIM[i]);
  }
  updateCurrentPosition();
  //temp=millis()-temp;
  //SerialUSB.print("Tiempo de ejecucion: ");
  //SerialUSB.print(temp);
  //SerialUSB.println(" ms");
  delay(tiempo*1000); // TODO a lo mejor puede cambiarse por isMoving
}




/*void Robot::setPos(int id, int nueva){
  if(id>=0&&id<=19)pos[id]=nueva;
}


int Robot::getPos(int id){
  return pos[id];
}*/


