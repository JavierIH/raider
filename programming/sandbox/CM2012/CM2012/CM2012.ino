#include <Servo.h>

//TRIMS DE AJUSTE
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

//INPUTS PINS
#define IR1 10
#define IR2 9
#define US 18
#define CMPR 15
#define CMPL 14
#define CLR 13
#define FALL 12

//OUTPUTS PINS
#define HEAD 8
#define LED 16

//SERVO PWM
#define MID 94
#define LEFT 180
#define RIGHT 10

//CONTROL
#define DISTANCE 0
#define CRUCE 6


class Robot{
    int pos[19];
  public:
    //Robot();
    void setVel();
    void setPos(int,int);
    int getVel();
    int getPos(int);
    void readPos();
    void move(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,float);
    void init();
    void movLateral(int,float);
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
    void avanzar(int);
};




Robot Raider;
Servo head;

int mode=0;
int progress=0;
int back=0;

void setup()
{
      Dxl.begin(1); //Inicializacion
      SerialUSB.begin();
      Raider.init(); //Aqui hay que meter el neutro
      

      //WHILE !señal-ready, esperar
      
      mode=1;
      progress=0;
      
      pinMode(US,INPUT);
      pinMode(IR1,INPUT); //Este es el que da por saco, el 19 no vale y el 20 tampoco
      pinMode(IR2,INPUT);
      pinMode(CMPR,INPUT);
      pinMode(CMPL,INPUT);
      pinMode(CLR,INPUT);
      pinMode(FALL,INPUT);
      head.attach(HEAD); //10-94-180
      pinMode(BOARD_LED_PIN,OUTPUT);


      SerialUSB.println("GO!!!");delay(5000);


      
      
}


void loop()
{
  /*
  switch(mode){
  
    case 1: //AVANZAR
      head.write(MID); delay(1000);
      Raider.avanzar(3);
                                              //SerialUSB.println("Estoy en el modo 1 (andando)");delay(5000);
      progress++;
      mode=10;      
    break; 
    
    case 2: //ATRAS
      head.write(MID); delay(1000);
      mode=1;
    break;
    
    case 3: //IZQUIERDA
      head.write(LEFT); delay(1000);
      //SerialUSB.println("Estoy en el modo 3 (lateral izquierda)");delay(5000);
      //if (!US) Raider.stepL(1); 
      if (!digitalRead(US)) Raider.stepL(1);
      if(!digitalRead(IR1)&&!digitalRead(IR2)) mode=1;
      else if(digitalRead(US)) mode=4;

    break;
    
    case 4: //DERECHA
      head.write(RIGHT); delay(1000);
      //SerialUSB.println("Estoy en el modo 4 (lateral derecha)");delay(5000);

      if (!digitalRead(US)) Raider.stepR(1);
      if(!digitalRead(IR1)&&!digitalRead(IR2)) mode=1;
      else if(digitalRead(US)) mode=3;    
      break;
    
    case 10: //CONSULTA 1
                                                          // SerialUSB.println("Estoy en el modo 10 (consultando sensores)");delay(5000);

 
        if (!digitalRead(IR1)&&!digitalRead(IR2)) {mode=1; SerialUSB.println("IR1 Libre, IR2 Libre");}         
        else if (!digitalRead(IR1)&&digitalRead(IR2)){ mode=3; SerialUSB.println("IR1 Libre, IR2 Bloqueado");}        
        else if (digitalRead(IR1)&&!digitalRead(IR2)){ mode=4; SerialUSB.println("IR1 Bloqueado, IR2 Libre");}
        else if (digitalRead(IR1)&&digitalRead(IR2)){ SerialUSB.println("IR1 Bloqueado, IR2 Bloqueado");
          //MOVIDA DEL CONTADOR
          //SerialUSB.println("Los dos IR están bloqueados, miro a donde voy");delay(5000);
          head.write(LEFT); delay(1000);
          delay(500);
          if (!digitalRead(US)){ mode=3;} //SerialUSB.println("El US está libre a la izquierda, me voy al modo 3");delay(5000);} 
          else{
            head.write(RIGHT); delay(1000);
            delay(500);

            if (!digitalRead(US)) mode=4;
          }
        }
    break;
 }
    



if(progress>DISTANCE&&digitalRead(CLR)&&back==0){
  int ok=0;
  SerialUSB.println("CAPTADO!");
  for(int i=0;i<12;i++){
    if(digitalRead(CLR))ok++;
  }
  if (ok>6){
    Raider.rectificar();
    Raider.avanzar(CRUCE);
    //////CAMBIAR COMPASS/////
    Raider.rectificar();
    Raider.turnR(4);
    back=1;
    mode=2;
  }
}

/**/

//if(digitalRead(CMPL))SerialUSB.println("OK");
//else SerialUSB.println("NO");
//
//delay(1000);
//

Raider.avanzar(3);
}















void Robot::firstStep(){
  move(62,962,212,812,662,362,512,512,512,512,332,692,162,862,712,312,512,512,0.2);
  movInclinar(30,0.4);
  movLateral(20,0.9);
  movSeparar(14,0.8);
  movAvance(-15,15,0.05);
}
void Robot::step(int j){
  for(int i=0;i<j;i++){
    movLateral(-50,0.2);
    movLateral(10,0.2);
   
    movVertical(2,-60,0.05);
    movAvance(30,-30,0.05);
    movVertical(2,60,0.2);
   
    movLateral(50,0.2);
    movLateral(-10,0.2);
   
    movVertical(1,-60,0.05);
    movAvance(-30,30,0.05);
    movVertical(1,60,0.2);
  }
}
void Robot::lastStep(){
  movAvance(15,-15,0.05);
  movSeparar(-14,0.8);
  movLateral(-20,0.9);
  movInclinar(-30,0.4);

}


void Robot::stepR(int j){
  for(int i=0;i<j;i++){
    move(62,962,212,812,662,362,512,512,512,512,332-20,692+20,162,862,712,312,512,512,0.5); delay(100);
    movLateral(-30,0.5); 
   
    movVertical(2,-30,0.05);
    movSeparar(40,0.05);delay(200);
   
    movLateral(50,0.5); 
   
    movVertical(1,-30,0.05);
    movSeparar(-30,0.4);delay(80);
    movVertical(30,1);
  }
}

void Robot::stepL(int j){
  for(int i=0;i<j;i++){
    move(62,962,212,812,662,362,512,512,512,512,332-20,692+20,162,862,712,312,512,512,0.5); delay(100);
    movLateral(30,0.5); 
   
    movVertical(1,-30,0.05);
    movSeparar(40,0.05);delay(200);
   
    movLateral(-50,0.5); 
   
    movVertical(2,-30,0.05);
    movSeparar(-30,0.4);delay(80);
    movVertical(30,1);

  }
}

void Robot::avanzar(int pasos){
  firstStep();
  step(pasos);
  lastStep();
  rectificar();
}

void Robot::rectificar(){
  if(digitalRead(CMPL)){
    do{
      turnR(0.05);
    }
    while(digitalRead(CMPL));
  }
  if(digitalRead(CMPR)){
    do{
      turnL(0.05);
    }
    while(digitalRead(CMPR));
  }
}




//////FUNCIONES DE CONTROL////////


void Robot::movLateral(int amp, float t){
  move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9]+amp,pos[10]+amp,pos[11],pos[12],pos[13],pos[14],pos[15],pos[16],pos[17]-amp,pos[18]-amp,t);
}

void Robot::movInclinar(int amp, float t){
  move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10],pos[11]-amp,pos[12]+amp,pos[13],pos[14],pos[15],pos[16],pos[17],pos[18],t);
}

void Robot::movSeparar(int amp, float t){
  move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9]-amp,pos[10]+amp,pos[11],pos[12],pos[13],pos[14],pos[15],pos[16],pos[17]+amp,pos[18]-amp,t); 
}

void Robot::movSeparar(int pierna, int amp, float t){
  if(pierna==1) move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10]+amp,pos[11],pos[12],pos[13],pos[14],pos[15],pos[16],pos[17],pos[18]-amp,t); 
  else move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9]-amp,pos[10],pos[11],pos[12],pos[13],pos[14],pos[15],pos[16],pos[17]+amp,pos[18],t); 
}

void Robot::movVertical(int amp, float t){
  move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10],pos[11]+amp,pos[12]-amp,pos[13]+2*amp,pos[14]-2*amp,pos[15]-amp,pos[16]+amp,pos[17],pos[18],t); 
}

void Robot::movVertical(int pierna, int amp, float t){ 
  if(pierna==1) move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10],pos[11],pos[12]-amp,pos[13],pos[14]-2*amp,pos[15],pos[16]+amp,pos[17],pos[18],t);
  else move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10],pos[11]+amp,pos[12],pos[13]+2*amp,pos[14],pos[15]-amp,pos[16],pos[17],pos[18],t);
}

void Robot::movAvance(int ampI, int ampD, float t){
  move(pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9],pos[10],pos[11]+ampD,pos[12]-ampI,pos[13],pos[14],pos[15]+ampD,pos[16]-ampI,pos[17],pos[18],t);
}

void Robot::move(int uno, int dos, int tres, int cuatro, int cinco, int seis, int siete, int ocho, int nueve, int diez, int once, int doce, int trece, int catorce, int quince, int dieciseis, int diecisiete, int dieciocho, float tiempo){

  int goal[]={0,uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve,diez,once,doce,trece,catorce,quince,dieciseis,diecisiete,dieciocho};
  int TRIM[]={0,TRIM1,TRIM2,TRIM3,TRIM4,TRIM5,TRIM6,TRIM7,TRIM8,TRIM9,TRIM10,TRIM11,TRIM12,TRIM13,TRIM14,TRIM15,TRIM16,TRIM17,TRIM18};
  
  for(int i=1; i<19; i++){  
    if(getPos(i)!=goal[i]){ 
      Dxl.writeWord(i, 32,(abs(getPos(i)-goal[i])/tiempo)*0.7);   //Se escribe la velocidad en cada servo. El factor 0,65 es para que acorden las unidades.
      Dxl.writeWord(i, 30, goal[i]+TRIM[i]);  //Posicionamiento del servo i en posicion[i].
      setPos(i,goal[i]); //guardamos la posicion como posicion actual.
    }
  }
  
  delay(tiempo*500);
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
  pos[id]=nueva;
}


int Robot::getPos(int id){
  return pos[id];
}

void Robot::turnL(float t)
{
  int i=50;
//Recomendado t=0.2
  move(62,962,212,812,662,362,512,512,513,522,342-i,681+i,241,781,646,377,511,502,5*t);
  move(62,962,212,812,662,362,512,512,519,528,344-i,678+i,245,776,644,380,505,496,t);
  move(62,962,212,812,662,362,512,512,524,533,346-i,675+i,250,770,642,383,500,491,t);
  move(62,962,212,812,662,362,512,512,528,537,349-i,672+i,256,763,639,386,496,487,t);
  move(62,962,212,812,662,362,512,512,521,544,352-i,679+i,262,778,636,379,493,483,t);
  move(62,962,212,812,662,362,512,512,503,555,354-i,696+i,266,811,634,362,491,480,t);
  move(62,962,212,812,662,362,512,512,494,560,355-i,703+i,268,826,633,355,490,478,t);
  move(62,962,212,812,662,362,558,465,503,554,355-i,708+i,266,811,639,370,491,481,t);
  move(62,962,212,812,662,362,569,454,521,543,353-i,692+i,262,778,641,387,493,485,t);
  move(62,962,212,812,662,362,573,450,528,536,350-i,684+i,256,763,644,394,496,488,t);
  move(62,962,212,812,662,362,573,450,524,532,345-i,687+i,250,770,646,389,500,492,t);
  move(62,962,212,812,662,362,573,450,519,527,341-i,688+i,245,776,647,385,505,497,t);
  move(62,962,212,812,662,362,573,450,513,521,337-i,689+i,241,781,647,381,511,503,t);
  move(62,962,212,812,662,362,573,450,507,516,335-i,688+i,240,783,645,378,517,508,t);
  move(62,962,212,812,662,362,573,450,502,510,334-i,686+i,242,782,642,376,522,514,t);
  move(62,962,212,812,662,362,573,450,496,504,335-i,682+i,247,778,638,376,528,520,t);
  move(62,962,212,812,662,362,573,450,491,499,336-i,678+i,253,773,634,377,533,525,t);
  move(62,962,212,812,662,362,573,450,487,495,339-i,673+i,260,767,629,379,537,529,t);
  move(62,962,212,812,662,362,569,454,480,502,331-i,670+i,245,761,636,382,540,532,t);
  move(62,962,212,812,662,362,558,465,469,520,315-i,668+i,212,757,653,384,544,534,t);
  move(62,962,212,812,662,362,542,481,464,529,309-i,669+i,197,755,663,387,546,535,t);
  move(62,962,212,812,662,362,512,512,468,520,327-i,669+i,212,757,661,389,545,534,t);
  move(62,962,212,812,662,362,512,512,479,502,344-i,671+i,245,761,644,387,542,532,t);
  move(62,962,212,812,662,362,512,512,486,495,351-i,674+i,260,767,637,384,538,529,t);
  move(62,962,212,812,662,362,512,512,490,499,348-i,677+i,253,773,640,381,534,525,t);
  move(62,962,212,812,662,362,512,512,495,504,345-i,679+i,247,778,643,379,529,520,t);
  move(62,962,212,812,662,362,512,512,501,510,342-i,681+i,242,782,646,377,523,514,t);
  move(62,962,212,812,662,362,512,512,507,516,341-i,682+i,240,783,647,376,517,508,t);
}

void Robot::turnR(float t)
{
  int i=50;
//Recomendado t=0.2
  move(62,962,212,812,662,362,512,512,501,510,342-i,681+i,242,782,646,377,523,514,5*t);
  move(62,962,212,812,662,362,512,512,495,504,345-i,679+i,247,778,643,379,529,520,t);
  move(62,962,212,812,662,362,512,512,490,499,348-i,677+i,253,773,640,381,534,525,t);
  move(62,962,212,812,662,362,512,512,486,495,351-i,674+i,260,767,637,384,538,529,t);
  move(62,962,212,812,662,362,512,512,479,502,344-i,671+i,245,761,644,387,542,532,t);
  move(62,962,212,812,662,362,512,512,468,520,327-i,669+i,212,757,661,389,545,534,t);
  move(62,962,212,812,662,362,512,512,463,529,320-i,668+i,197,755,668,390,547,535,t);
  move(62,962,212,812,662,362,558,465,469,520,315-i,668+i,212,757,653,384,544,534,t);
  move(62,962,212,812,662,362,569,454,480,502,331-i,670+i,245,761,636,382,540,532,t);
  move(62,962,212,812,662,362,573,450,487,495,339-i,673+i,260,767,629,379,537,529,t);
  move(62,962,212,812,662,362,573,450,491,499,336-i,678+i,253,773,634,377,533,525,t);
  move(62,962,212,812,662,362,573,450,496,504,335-i,682+i,247,778,638,376,528,520,t);
  move(62,962,212,812,662,362,573,450,502,510,334-i,686+i,242,782,642,376,522,514,t);
  move(62,962,212,812,662,362,573,450,507,516,335-i,688+i,240,783,645,378,517,508,t);
  move(62,962,212,812,662,362,573,450,513,521,337-i,689+i,241,781,647,381,511,503,t);
  move(62,962,212,812,662,362,573,450,519,527,341-i,688+i,245,776,647,385,505,497,t);
  move(62,962,212,812,662,362,573,450,524,532,345-i,687+i,250,770,646,389,500,492,t);
  move(62,962,212,812,662,362,573,450,528,536,350-i,684+i,256,763,644,394,496,488,t);
  move(62,962,212,812,662,362,569,454,521,543,353-i,692+i,262,778,641,387,493,485,t);
  move(62,962,212,812,662,362,558,465,503,554,355-i,708+i,266,811,639,370,491,481,t);
  move(62,962,212,812,662,362,542,481,494,559,354-i,714+i,268,826,636,360,490,479,t);
  move(62,962,212,812,662,362,512,512,503,555,354-i,696+i,266,811,634,362,491,480,t);
  move(62,962,212,812,662,362,512,512,521,544,352-i,679+i,262,778,636,379,493,483,t);
  move(62,962,212,812,662,362,512,512,528,537,349-i,672+i,256,763,639,386,496,487,t);
  move(62,962,212,812,662,362,512,512,524,533,346-i,675+i,250,770,642,383,500,491,t);
  move(62,962,212,812,662,362,512,512,519,528,344-i,678+i,245,776,644,380,505,496,t);
  move(62,962,212,812,662,362,512,512,513,522,342-i,681+i,241,781,646,377,511,502,t);
  move(62,962,212,812,662,362,512,512,507,516,341-i,682+i,240,783,647,376,517,508,t);
}

