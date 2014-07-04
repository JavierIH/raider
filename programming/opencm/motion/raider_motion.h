#ifndef raider_motion_h
#define raider_motion_h

#include "wirish.h"
#include "Servo.h"

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

#define HEAD_PIN 9

class Robot{
    int currentPosition[21];
    int targetPosition[21];
    int TRIM[21];
    Servo head;
  public:
    Robot();
    void init(); //movimiento inicial
    void updateCurrentPosition();
    void setTargetPosition(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void move(float); //mueve todos los servos a goalPosition


    //char readCommand(){}
    //char sendCommand(){}

};



#endif
