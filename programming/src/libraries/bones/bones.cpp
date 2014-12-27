#include "bones.h"

//using namespace std;

int getAIN(int pin){

    if(pin<0||pin>7){
        report(ERROR,"Bad analogic pin choice");
        return -1;
    }

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

Pin::Pin(int pin_id, int pin_mode){
    if((pin_mode==INPUT || pin_mode==OUTPUT) && (pin_id<0 || pin_id>127) ||
       (pin_mode==ANALOG && (pin_id<200 || pin_id>89)) ||
       (pin_mode==PWM &&
           !((pin_id==48)&&(pin_id==49)&&(pin_id==40)&&
           (pin_id==51)&&(pin_id==23)&&(pin_id==27)&&
           (pin_id==22)&&(pin_id==70)&&(pin_id==81)&&
           (pin_id==71)&&(pin_id==80))))
    {
        report(ERROR,"Invalid ID/mode");
        pin_id=-1;
        pin_mode=-1;
    }
    ID=pin_id;
    mode=pin_mode;
    report(OK,"Pin "+to_string(ID)+" set on mode "+to_string(mode));
}

int Pin::getAIN(){
    if (mode!=ANALOG){
        report(ERROR,"Pin "+to_string(ID)+" is not set on mode ANALOG, is set on mode "+to_string(mode));
        return -1;
    }
}

int Pin::setPWM(int pulse){
    if (mode!=PWM){
        report(ERROR,"Pin "+to_string(ID)+" is not set on mode PWM, is set on mode "+to_string(mode));
        return -1;
    }
}

int Pin::set(int state){
    if (mode!=OUTPUT){
        report(ERROR,"Pin "+to_string(ID)+" is not set on mode OUTPUT, is set on mode "+to_string(mode));
        return -1;
    }
}


int Pin::get(){
    if (mode!=OUTPUT&&mode!=INPUT){
        report(ERROR,"Pin "+to_string(ID)+" is not set on mode OUTPUT or INPUT, is set on mode "+to_string(mode));
        return -1;
    }
}
