#include "raider.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


using namespace std;

Raider::Raider(){

//Javi del futuro, echa un ojo a esto
//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");


    /*error=openSerial(SERIAL_PORT);
    if(error==0){
        cout<<"("<<error<<")"<<"FALLO en openSerial";
    }

    error=openCamera(CAMERA_ID);
    if(error==0){
        cout<<"("<<error<<")"<<"FALLO en openCamera";
    }
*/


    report(INFO, "Wake up Raider!");

    report("Settint serial communication...");

    serial= new serialib();
    int serial_flag=serial->Open(SERIAL_PORT, BAUD_RATE); // TODO revisar bool char

    if (serial_flag==1) report(OK, "Serial communication connected");
    else if (serial_flag==-2)report(ERROR, "Serial communication failed (at opening device)");
    else if (serial_flag==-4)report(ERROR, "Serial communication failed (check baud rate)");
    else report(ERROR, "Serial communication failed (unknown error)");

    report("Settint infrarred sensors...");

    report("Settint imu sensor...");

    report("Settint camera...");


}

int Raider::getIR(bool side){
    if(side){
        rightIR=getAnalog(INFRARRED_R);
        return rightIR;
    }
    else{
        leftIR=getAnalog(INFRARRED_L);
        return leftIR;
    }
}

int Raider::sendCommand(char command){

    //int error=sendSerial(command);
    //return error;

}

void Raider::walk(){

//    int error=0;
//    error=SC.WriteChar(command);

//    error=serial->WriteChar();

//    if (error!=1) return 0;
//    return 1;

}
void Raider::turnLeft(){}
void Raider::turnRigt(){}
void Raider::stepLeft(){}
void Raider::stepRight(){}
void Raider::standUp(){}


