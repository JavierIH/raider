#include "raider.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <bones.h>


using namespace std;

raider::raider(){

//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");


}

int raider::getIR(bool side){
    if(side){
        rightIR=getAnalog(RIGHT_INFRARRED);
        return rightIR;

    }
    else{
        leftIR=getAnalog(LEFT_INFRARRED);
        return leftIR;
    }
}


void raider::walk(){}
void raider::turnLeft(){}
void raider::turnRigt(){}
void raider::stepLeft(){}
void raider::stepRight(){}
void raider::standUp(){}


