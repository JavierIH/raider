#ifndef RAIDER_H
#define RAIDER_H

#include "../bones/bones.h"
#include "../eye/eye.h"
#include "../debug/debug.h"
#include "../imu/imu.h"


//Serial communication settings
#define SERIAL_PORT         "/dev/ttyS2"
#define BAUD_RATE           9600

//Camera settings
#define CAMERA_ID           1


//Beaglebone Black GPIOs settings


#define INFRARRED_R 0
#define INFRARRED_L 1

class Raider
{
private:

    //Estado de los sensores
    int rightIR;
    int leftIR;
    int compass;
    bool fall;

    IMU *imu;
    serialib *serial;

public:
    Raider();
    int getIR(bool);
    bool walk();
    bool turnLeft();
    bool turnRigt();
    bool stepLeft();
    bool stepRight();
    bool standUp();
/*
    findWay()
    findBall()
    isStand()
    getIR()


*/


    // TODO funciones que hay que quitar de aqui y poner en otro sitio
    int sendCommand(char);

};

#endif // RAIDER_H
