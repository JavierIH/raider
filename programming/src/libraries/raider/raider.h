#ifndef RAIDER_H
#define RAIDER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "../bones/bones.h"
#include "../eye/eye.h"
#include "../debug/debug.h"
#include "../imu/imu.h"
#include "../compass/compass.h"
#include "../serialib/serialib.h"

//Serial communication settings
#define SERIAL_PORT         "/dev/ttyO2"
#define BAUD_RATE           9600

//I2C sensors settings
#define I2C_BUS             1
#define IMU_ADDRESS         0x69
#define COMPASS_ADDRESS     0x1E

//Camera settings
#define CAMERA_ID           -1

//Beaglebone Black GPIOs settings
#define AIN3                3
#define AIN5                5

//General configuration
#define FALL_DEGREES        60
#define INFRARED_LOW        500
#define INFRARED_HIGH       1000

//Movements delay time (us)
#define RUN                 2500000
#define WALK                1200000
#define TURNR               1450000
#define TURNL               1450000
#define STEPR               1050000
#define STEPL               1050000
#define YES                 900000
#define HELLO               7000000
#define GETUP               5450000
#define ROLL                7750000
#define PUNCHL              1200000
#define PUNCHR              1200000
#define CRAB                4600000
#define MINIPUNCHR          900000
#define MINIPUNCHL          900000
#define DEFENSE             600000
#define LOOKL               500000
#define LOOKR               500000
#define LOOK                400000


class Raider
{
private:
    I2C *i2c;
    IMU *imu;
    Compass *compass;
    Serial *serial;
    cv::VideoCapture *camera;


    //ESTADO DE LOS SENSORES
    int rightIR;
    int leftIR;
    //int compass;


public:
    Raider();

    //FUNCIONES DE ESTADO
    int getFall();
    int getLeftIR();
    int getRightIR();

    //FUNCIONES DE VISION
    cv::Mat getFrame();
    cv::Vec2i findWay(cv::Mat);
    cv::Vec2i findLine(cv::Mat);
    //    findBall();

    //MOVIMIENTOS
    bool walk();
    bool run();
    bool turnL();
    bool turnR();
    bool stepL();
    bool stepR();
    bool getUp();
    bool roll();
    bool yes();
    bool punchL();
    bool punchR();
    bool crab();
    bool miniPunchL();
    bool miniPunchR();
    bool defense();
    bool lookL();
    bool lookR();
    bool look();

    //FUNCIONES AUXILIARES
    bool sendCommand(char);

};

#endif // RAIDER_H
