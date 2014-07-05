#ifndef raider_motion_h
#define raider_motion_h

#include "wirish.h"
#include "Servo.h"

#define TRIMP 0
#define TRIMT -60
#define TRIM1 0
#define TRIM2 0
#define TRIM3 0
#define TRIM4 0
#define TRIM5 0
#define TRIM6 0
#define TRIM7 0
#define TRIM8 0
#define TRIM9 -5
#define TRIM10 10
#define TRIM11 0   
#define TRIM12 -5
#define TRIM13 0
#define TRIM14 -5
#define TRIM15 0
#define TRIM16 -3
#define TRIM17 0
#define TRIM18 0

#define HEAD_PIN 9

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
    void move(float); //mueve todos los servos a goalPosition
    void movVertical(int,int);
    void movLateral(int,int);
    void movFrontal(int,int);
    void movOffset(int,int);


    //char readCommand(){}
    //char sendCommand(){}

};



#endif

