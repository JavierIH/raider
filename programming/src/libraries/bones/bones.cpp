#include "bones.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

serialib SC;

int getAnalog(int pin){

    if(pin<0||pin>7) return -1;

    string path="/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN";
    path+=(char)pin+'0';
    ifstream AIN ("/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN1");
    if(!AIN) return -1;

    int value;
    char a1 [5];
    AIN.read(a1,5);
    value = atoi(a1);
    AIN.close();

    return value;
}

int openSerial(int port){

    if(port<0||port>5) return -1;

    string path="dev/ttyO";
    path+=(char)port+'0';

    int error=1;
    error=SC.Open("/dev/ttyO2",115200);
	cout<<"\n\nTras SC.Open error es"<<error<<endl;
    if (error!=1) return -1;
    return 1;
}

int sendSerial(char command){

    int error=0;
    error=SC.WriteChar(command);

    if (error!=1) return -1;
    return 1;
}



