#include "bones.h"

//using namespace std;

int getAnalog(int pin){

    if(pin<0||pin>7) return -1;

    string path="/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN";
    path+=(char)pin+'0';

    ifstream AIN (path.c_str());
    if(!AIN) return -1;

    int value;
    char a1 [5];
    AIN.read(a1,5);
    value = atoi(a1);
    AIN.close();

    return value;
}
