#include "bones.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <serialib.h>

using namespace std;

serialib SC;

int getAnalog(int pin){

    if(pin<0||pin>7) return -1;

    string path="/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN";
    path+=(char)pin+'0';
    ifstream AIN ("../fichero.txt"); //path
    if(!AIN) return -1;

    int value;
    char a1 [5];
    AIN.read(a1,5);
    value = atoi(a1);
    AIN.close();

    return value;
}

int openSerial(int port){

    int error=0;
    char Buffer[128];

    cout<<DEVICE_PORT;
    SC.Open(DEVICE_PORT,115200);

    if (error!=1) {
        printf ("Error while opening port. Permission problem ?\n");
        return error;
    }
    return error;
}

