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
    bool turnLeft();
    bool turnRight();
    bool stepLeft();
    bool stepRight();
    bool standUp();
    bool roll();

    //FUNCIONES AUXILIARES
    bool sendCommand(char);

};

#endif // RAIDER_H
