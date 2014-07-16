#ifndef RAIDER_H
#define RAIDER_H

#include "../bones/bones.h"
#include "../eye/eye.h"
#include "../debug/debug.h"
#include "../imu/imu.h"
#include "../serialib/serialib.h"


//Serial communication settings
#define SERIAL_PORT         "/dev/ttyO2"
#define BAUD_RATE           9600

//MPU9150 IMU I2C sensor settings
#define I2C_BUS             1
#define IMU_ADDRESS         0x69
#define COMPASS_ADDRES      0x0C

//Camera settings
#define CAMERA_ID           1

//Beaglebone Black GPIOs settings
#define AIN3                3
#define AIN5                5

//General configuration
#define FALL_DEGREES        60
#define INFRARED_MAX        1500



class Raider
{
private:
    I2C *i2c;
    IMU *imu;
    serialib *serial;

    //ESTADO DE LOS SENSORES
    int rightIR;
    int leftIR;
    int compass;
    bool fall;


public:
    Raider();

    //FUNCIONES DE ESTADO
    bool isStanding();
    bool getLeftIR();
    bool getRightIR();

    //FUNCIONES DE VISION
//    findWay();
//    findBall();

    //MOVIMIENTOS
    bool walk();
    bool turnLeft();
    bool turnRigt();
    bool stepLeft();
    bool stepRight();
    bool standUp();

};

#endif // RAIDER_H
