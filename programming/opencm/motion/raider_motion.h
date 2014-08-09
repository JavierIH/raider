#ifndef raider_motion_h
#define raider_motion_h

#include "Servo.h"

#define TRIMP 0
#define TRIMT -60
#define TRIM1 0
#define TRIM2 0
#define TRIM3 -4
#define TRIM4 -10
#define TRIM5 0
#define TRIM6 0
#define TRIM7 0
#define TRIM8 0
#define TRIM9 -5
#define TRIM10 10
#define TRIM11 0   
#define TRIM12 -8
#define TRIM13 0
#define TRIM14 -5
#define TRIM15 -1
#define TRIM16 1
#define TRIM17 10
#define TRIM18 -10

#define HEAD_PIN 7

class Robot{
    int currentPosition[20];
    int targetPosition[20];
    int TRIM[20];
    Servo head;
  public:
    Robot();
    void init(); //movimiento inicial
    void updateCurrentPosition();
    void setTargetPosition(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void setTargetOffset(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void move(float); //mueve todos los servos a goalPosition
    void movHead(int);
    void movVertical(int,int);
    void movLateral(int,int);
    void movFrontal(int,int);
    void movOffset(int,int);
    
    void run(int);
    void walk(int);
    void turnL();
    void turnR();
    void stepL();
    void stepR();
    void kick();
    void getUp();
    void hello();
    void yes();
    void roll();
    
    void controller(char);
    
    

    //char readCommand(){}
    //char sendCommand(){}

};



#endif

