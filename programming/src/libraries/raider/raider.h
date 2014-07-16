#ifndef RAIDER_H
#define RAIDER_H

#include "../bones/bones.h"
#include "../eye/eye.h"
#include "../debug/debug.h"
#include "../imu/imu.h"


//Serial communication settings
#define SERIAL_PORT         "/dev/ttyO2"
#define BAUD_RATE           9600

//MPU9150 IMU I2C sensor settings
#define I2C_BUS             1
#define IMU_ADDRESS         0x69

//Camera settings
#define CAMERA_ID           1

//Beaglebone Black GPIOs settings
#define INFRARRED_R         0
#define INFRARRED_L         1


//General configuration
#define FALL_DEGREES        60



class Raider
{
private:

    //Estado de los sensores
    int rightIR;
    int leftIR;
    int compass;
    bool fall;

    I2C *i2c;
    IMU *imu;
    serialib *serial;

public:
    Raider();
    int getIR(bool);


    bool isStanding();


    //MOVIMIENTOS
    bool walk();
    bool turnLeft();
    bool turnRigt();
    bool stepLeft();
    bool stepRight();
    bool standUp();


/*
    findWay()
    findBall()
    getIR()


*/


    // TODO funciones que hay que quitar de aqui y poner en otro sitio
   // int sendCommand(char);

};

#endif // RAIDER_H
