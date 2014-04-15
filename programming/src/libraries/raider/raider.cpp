#include "raider.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

raider::raider(){

//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");

    int error;
    error=openSerial(SERIAL_PORT);
    if(error==-1) cout<<"FALLO en openSerial";

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

int raider::sendCommand(char command){

    int error=sendSerial(command);
    return error;

}

void raider::walk(){}
void raider::turnLeft(){}
void raider::turnRigt(){}
void raider::stepLeft(){}
void raider::stepRight(){}
void raider::standUp(){}


