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

//SERIAL COMMUNICATION
    report("Setting serial communication...");
    serial = new serialib();
    int serial_flag=serial->Open(SERIAL_PORT, BAUD_RATE); // TODO revisar bool char
    if (serial_flag==1) report(OK, "Serial communication connected!");
    else if (serial_flag==-2)report(ERROR, "Serial communication failed (at opening device)");
    else if (serial_flag==-4)report(ERROR, "Serial communication failed (check baud rate)");
    else report(ERROR, "Serial communication failed (unknown error)");

//I2C BUS CONNECTION
    report("Setting I2C bus...");
    i2c = new I2C(I2C_BUS, IMU_ADDRESS);
    if (i2c->test()) report(OK, "I2C bus connected!");
    else report(ERROR, "I2C doesn't work!");

//IMU SENSOR
    report("Setting imu sensor...");
    imu = new IMU(i2c);
    if(4294967295==imu->getMagnetometerX()) report(ERROR, "IMU sensor connection FAILED");
    else if(65535==imu->getMagnetometerX()) report(WARNING, "Accelerometer may be not working (please check)");
    else report(OK, "IMU sensor connected!");

//INFRARRED SENSORS
    report("Setting infrarred sensors...");
    if(getAnalog(0)<=0) report(ERROR, "Error in infrarred sensors (pin 0)");
    else if(getAnalog(1)<=0) report(ERROR, "Error in infrarred sensors (pin 1)");
    else report(OK,"Infrarred sensors are working fine!");





    report("Setting camera...");


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




bool Raider::isStanding(){

    int ax=imu->getAccelerometerX()*360/65355;
    if(ax>360-FALL_DEGREES||ax<FALL_DEGREES) return 1;
    else{
        report(WARNING, "DANGER!!! Raider fell!!!");
        return 0;
    }
}

bool Raider::walk(){

    char command= 'w';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (walk)");
        return 0;
    }
    return 1;
}

bool Raider::turnLeft(){}
bool Raider::turnRigt(){}
bool Raider::stepLeft(){}
bool Raider::stepRight(){}
bool Raider::standUp(){}


