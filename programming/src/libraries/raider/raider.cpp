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

    // TODO inicialización de cámara
}

bool Raider::getLeftIR(){
    leftIR=getAnalog(AIN5);
    if(leftIR>INFRARED_MAX) return 1;
    else return 0;

}

bool Raider::getRightIR(){
    rightIR=getAnalog(AIN3);
    if(rightIR>INFRARED_MAX) return 1;
    else return 0;
}

bool Raider::isStanding(){ // TODO pa un lao y pal otro cmabiar eje

    int ax=imu->getAccelerometerX()*360/65355;
    if(ax>360-FALL_DEGREES||ax<FALL_DEGREES) return 1;
    else{
        report(WARNING, "DANGER!!! Raider fell!!!");
        return 0;
    }
    cout<<ax<<endl;
}

bool Raider::fall(){ // TODO pa un lao y pal otro cmabiar eje

    int ay=imu->getAccelerometerY()*360/65355;
    if(ay<360-FALL_DEGREES){
        return 1;
    }
    else if(ay>FALL_DEGREES){
        return 2;
    }
    else{
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

bool Raider::roll(){

    char command= 'R';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (roll)");
        return 0;
    }
    return 1;
}



bool Raider::sendCommand(char command){

    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command");
        return 0;
    }
    return 1;
}
