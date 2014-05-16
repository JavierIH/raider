#include "raider.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

raider::raider(){

//Javi del futuro, echa un ojo a esto
//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");

    bool error;

    error=openSerial(SERIAL_PORT);
    if(error==0){
        cout<<"("<<error<<")"<<"FALLO en openSerial";
    }

    error=openCamera(CAMERA_ID);
    if(error==0){
        cout<<"("<<error<<")"<<"FALLO en openCamera";
    }


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


