#ifndef BONES_H
#define BONES_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../debug/debug.h"

//GPIO P8.1
#define GPIO1_6             38
#define GPIO1_2             34
#define GPIO2_2             66
#define GPIO2_5             69
#define GPIO1_13            45
#define GPIO0_23            23
#define GPIO1_15            47
#define GPIO0_27            27
#define GPIO0_22            22
#define GPIO1_30            62
#define GPIO1_4             36
#define GPIO1_0             32
#define GPIO2_22            86
#define GPIO2_23            87
#define GPIO0_10            10
#define GPIO0_9             9
#define GPIO0_8             8
#define GPIO2_14            78
#define GPIO2_12            76
#define GPIO2_10            74
#define GPIO2_8             72
#define GPIO2_6             70

//GPIO P8.2
#define GPIO1_7             39
#define GPIO1_3             35
#define GPIO2_3             67
#define GPIO2_4             68
#define GPIO1_12            44
#define GPIO0_26            26
#define GPIO1_14            46
#define GPIO2_1             65
#define GPIO1_31            63
#define GPIO1_5             37
#define GPIO1_1             33
#define GPIO1_29            61
#define GPIO2_24            88
#define GPIO2_25            89
#define GPIO0_11            11
#define GPIO2_17            81
#define GPIO2_16            80
#define GPIO2_15            79
#define GPIO2_13            77
#define GPIO2_11            75
#define GPIO2_9             73
#define GPIO2_7             71

//GPIO P9.1
#define PWR_BUT //TODO
#define GPIO0_30            30
#define GPIO0_31            31
#define GPIO1_16            48
#define GPIO0_4             4
#define GPIO0_13            13
#define GPIO0_3             3
#define GPIO1_17            49
#define GPIO3_21            117
#define GPIO3_19            125
#define GPIO3_15            121
#define GPIO3_14            120
//#define AIN4                204
//#define AIN6                206
//#define AIN2                202
//#define AIN0                200
#define GPIO0_20            20

//GPIO P9.2
#define SYS_RESTn //TODO
#define GPIO1_28            60
#define GPIO1_18            40
#define GPIO1_19            51
#define GPIO0_5             5
#define GPIO0_12            12
#define GPIO0_2             2
#define GPIO0_15            15
#define GPIO0_14            14
#define GPIO3_17            123
#define GPIO3_16            122
//#define AIN5                205
//#define AIN3                203
//#define AIN1                201
#define GPIO0_7             7

//Special names
#define I2C1_SDA            5
#define I2C1_SCL            4
#define I2C2_SDA            12
#define I2C2_SCL            13
#define UART1_RTSN          13
#define UART1_CTSN          12
#define UART1_TXD           15
#define UART1_RXD           14
#define UART2_TXD           3
#define UART2_RXD           2
#define UART3_RTSN          81
#define UART3_CTSN          80
#define UART3_TXD           7
#define UART4_RTSN          9
#define UART4_CTSN          8
#define UART4_TXD           31
#define UART4_RXD           30
#define UART5_RTSN          11
#define UART5_CTSN          10
#define UART5_TXD           78
#define UART5_RXD           79

//Possible pin modes
#define OUTPUT              0
#define INPUT               1
#define PWM                 2
#define ANALOG              3



class Pin{
private:
    int ID;
    int mode;

public:
    Pin(int,int);
    int set(int);
    int get();
    int setPWM(int);
    int getAIN();
};

int getAIN(int);



#endif // BONES_H
