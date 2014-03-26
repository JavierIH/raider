#include <Servo.h>

//TRIMS DE AJUSTE
#define TRIMP 0
#define TRIMT 0
#define TRIM1 0
#define TRIM2 0
#define TRIM3 0
#define TRIM4 0
#define TRIM5 0
#define TRIM6 0
#define TRIM7 0
#define TRIM8 0
#define TRIM9 0
#define TRIM10 0
#define TRIM11 0   
#define TRIM12 0
#define TRIM13 0
#define TRIM14 0
#define TRIM15 0
#define TRIM16 0
#define TRIM17 0
#define TRIM18 0


class Robot{
    int pos[20];
    Servo head;
  public:
    //Robot();
    void setVel();
    void setPos(int,int);
    int getVel();
    int getPos(int);
    void readPos();
    void move(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,float);
    void init();
    void movLateral(int,float);
    /*void movInclinar(int,float);
    void movSeparar(int,float);
    void movSeparar(int,int,float);
    void movVertical(int,float); //pierna
    void movVertical(int,int,float); //pierna
    void movAvance(int,int,float);
    void firstStep();
    void step(int);
    void lastStep();
    void turnR(float);
    void turnL(float);
    void stepR(int);
    void stepL(int);
    void rectificar();
    void avanzar(int);*/
};




Robot Raider;

int mode=0;
int progress=0;
int back=0;

void setup()
{      
      Dxl.begin(1);
      SerialUSB.begin();
      //Raider.init();

      SerialUSB.println("GO!!!");delay(2000);     
}

  int i=0;

void loop()
{
        int x=40;
        int y=40;
        //           P   T   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
        Raider.move(512,512,412,612,262+y,762-y,612-y,412+y,512,512,512-x,512+x,492,532,512,512,512,512,512+x,512-x,0.05);
        Raider.move(512,512,412,612,262,762,612,412,512,512,512-x,512+x,492,532,512,512,512,512,512+x,512-x,0.05);
        //Raider.move(512,512,412,612,262,762,612,412,512,512,512,512,492,532,512,512,512,512,512,512,0.5);
        //Raider.move(512,512,412,612,512,512,612,412,512,512,512,512,492,532,512,512,512,512,512,512,0.5);
        
        //i++;
        //SerialUSB.println(i);   
        //Raider.movLateral(40,1);
        //Raider.movLateral(-80,2);

}



void Robot::move(int pan, int tilt, int uno, int dos, int tres, int cuatro, int cinco, int seis, int siete, int ocho, int nueve, int diez, int once, int doce, int trece, int catorce, int quince, int dieciseis, int diecisiete, int dieciocho, float tiempo){

  int goal[]={pan,tilt,uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve,diez,once,doce,trece,catorce,quince,dieciseis,diecisiete,dieciocho};
  int TRIM[]={TRIMP,TRIMT,TRIM1,TRIM2,TRIM3,TRIM4,TRIM5,TRIM6,TRIM7,TRIM8,TRIM9,TRIM10,TRIM11,TRIM12,TRIM13,TRIM14,TRIM15,TRIM16,TRIM17,TRIM18};
  //float temp=millis();

  for(int i=0; i<20; i++){      
      if(i==0){
        Dxl.setPosition(25,goal[i]+TRIM[i],(abs(getPos(i)-goal[i])/tiempo)*0.7); //Esta nueva funcion hace lo mismo que las dos antiguas
        //SerialUSB.print("P:25 en ");
        //SerialUSB.println(goal[i]+TRIM[i]);
      }
      else if(i==1)
      {
        //head.writeMicroseconds(goal[i]+1000); //Valor entre 1000 y 2024
        //SerialUSB.print("T:S en ");
        //SerialUSB.println(goal[i]);
      }
      else{
        Dxl.setPosition(i-1,goal[i]+TRIM[i],(abs(getPos(i)-goal[i])/tiempo)*0.7); //Esta nueva funcion hace lo mismo que las dos antiguas
        //SerialUSB.print("ID:");
        //SerialUSB.print(i-1);
        //SerialUSB.print(" en ");
        //SerialUSB.println(goal[i]+TRIM[i]);
      }
      setPos(i,goal[i]); //guardamos la posicion como posicion actual.     
  }  
  //temp=millis()-temp;
  //SerialUSB.print("Tiempo de ejecucion: ");
  //SerialUSB.print(temp);
  //SerialUSB.println(" ms");
  delay(tiempo*1000);
}

void Robot::init(){   

  int goal[]={512,512,62,962,212,812,662,362,512,512,512,512,332,692,162,862,712,312,512,512};
  int TRIM[]={TRIMP,TRIMT,TRIM1,TRIM2,TRIM3,TRIM4,TRIM5,TRIM6,TRIM7,TRIM8,TRIM9,TRIM10,TRIM11,TRIM12,TRIM13,TRIM14,TRIM15,TRIM16,TRIM17,TRIM18};
  
  //float temp=millis();

  for(int i=0; i<20; i++){      
      if(i==0){
        Dxl.setPosition(25,goal[i]+TRIM[i],100); //Esta nueva funcion hace lo mismo que las dos antiguas
        //SerialUSB.print("P:25 en ");
        //SerialUSB.println(goal[i]+TRIM[i]);
      }
      else if(i==1)
      {
        //head.writeMicroseconds(goal[i]+1000); //Valor entre 1000 y 2024
        //SerialUSB.print("T:S en ");
        //SerialUSB.println(goal[i]);
      }
      else{
        Dxl.setPosition(i-1,goal[i]+TRIM[i],100); //Esta nueva funcion hace lo mismo que las dos antiguas
        //SerialUSB.print("ID:");
        //SerialUSB.print(i-1);
        //SerialUSB.print(" en ");
        //SerialUSB.println(goal[i]+TRIM[i]);
      }
      setPos(i,goal[i]); //guardamos la posicion como posicion actual.     
  }  
  //temp=millis()-temp;
  //SerialUSB.print("Tiempo de ejecucion: ");
  //SerialUSB.print(temp);
  //SerialUSB.println(" ms");
  delay(10000); 
}

void Robot::movLateral(int amp, float t){
  move(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10]+amp,pos[11]+amp,pos[12],pos[13],pos[14],pos[15],pos[16],pos[17],pos[18]-amp,pos[19]-amp,t);

}


void Robot::setPos(int id, int nueva){
  if(id>=0&&id<=19)pos[id]=nueva;
}


int Robot::getPos(int id){
  return pos[id];
}


