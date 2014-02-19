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
#define TRIM11 5   
#define TRIM12 -4
#define TRIM13 19
#define TRIM14 -8
#define TRIM15 -7
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
    /*void movLateral(int,float);
    void movInclinar(int,float);
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
      Raider.init();

      SerialUSB.println("GO!!!");delay(2000);     
}


void loop()
{
}



void Robot::move(int pan, int tilt, int uno, int dos, int tres, int cuatro, int cinco, int seis, int siete, int ocho, int nueve, int diez, int once, int doce, int trece, int catorce, int quince, int dieciseis, int diecisiete, int dieciocho, float tiempo){

  int goal[]={pan,tilt,uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve,diez,once,doce,trece,catorce,quince,dieciseis,diecisiete,dieciocho};
  int TRIM[]={TRIMP,TRIMT,TRIM1,TRIM2,TRIM3,TRIM4,TRIM5,TRIM6,TRIM7,TRIM8,TRIM9,TRIM10,TRIM11,TRIM12,TRIM13,TRIM14,TRIM15,TRIM16,TRIM17,TRIM18};
  
  for(int i=0; i<=20; i++){      
    if(getPos(i)!=goal[i]){
      if(i==0){
        Dxl.setPosition(25,goal[i]+TRIM[i],(abs(getPos(i)-goal[i])/tiempo)*0.7); //Esta nueva funcion hace lo mismo que las dos antiguas
        SerialUSB.print("dsvjfv");
      }
      if(i==1)
      {
        head.writeMicroseconds(goal[i]+1000); //Valor entre 1000 y 2024
      }
      else{
        Dxl.setPosition(i-1,goal[i]+TRIM[i],(abs(getPos(i)-goal[i])/tiempo)*0.7); //Esta nueva funcion hace lo mismo que las dos antiguas
      }
      setPos(i,goal[i]); //guardamos la posicion como posicion actual.     
    }  
  }
  delay(tiempo*1000);
}

void Robot::readPos(){
  for(int i=1;i<19;i++)
  {    
    SerialUSB.print("  ");
    SerialUSB.print(i);
    SerialUSB.print(": ");
    SerialUSB.print(pos[i]);
  }
      SerialUSB.print("\n");

}

void Robot::init(){

  int goal[]={0,62,962,212,812,662,362,512,512,512,512,332,692,162,862,712,312,512,512};
  int TRIM[]={0,TRIM1,TRIM2,TRIM3,TRIM4,TRIM5,TRIM6,TRIM7,TRIM8,TRIM9,TRIM10,TRIM11,TRIM12,TRIM13,TRIM14,TRIM15,TRIM16,TRIM17,TRIM18};

  
  for(int i=1; i<19; i++){   
    Dxl.writeWord(i, 32, 200);   //Velocidad fija para servos (no hay referencia).
    Dxl.writeWord(i, 30, goal[i]+TRIM[i]);  //Posicionamiento del servo i en posicion[i].
    setPos(i,goal[i]); //guardamos la posicion como posicion actual.
  }
  delay(3000);
}

void Robot::setPos(int id, int nueva){
  if(id>=0&&id<=19)pos[id]=nueva;
}


int Robot::getPos(int id){
  return pos[id];
}


