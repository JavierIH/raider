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
#include "../serialib/serialib.h"


//Serial communication settings
#define SERIAL_PORT         "/dev/ttyO2"
#define BAUD_RATE           9600

//MPU9150 IMU I2C sensor settings
#define I2C_BUS             1
#define IMU_ADDRESS         0x69
#define COMPASS_ADDRESS     0x0C

//Camera settings
#define CAMERA_ID           -1

//Beaglebone Black GPIOs settings
#define AIN3                3
#define AIN5                5

//General configuration
#define FALL_DEGREES        60
#define INFRARED_MAX        1500

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




class Raider
{
private:
    I2C *i2c;
    IMU *imu;
    serialib *serial;
    cv::VideoCapture *camera;


    //ESTADO DE LOS SENSORES
    int rightIR;
    int leftIR;
    int compass;


public:
    Raider();

    //FUNCIONES DE ESTADO
    int getFall();
    bool getLeftIR();
    bool getRightIR();

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

    //FUNCIONES AUXILIARES
    bool sendCommand(char);

};

#endif // RAIDER_H
