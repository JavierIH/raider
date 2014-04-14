#include "raider.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

raider::raider(){

//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");
}

int raider::getAnalog(int pin){

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
