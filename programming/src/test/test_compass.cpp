#include <iostream>
#include <string>
#include <math.h>
#include "../libraries/raider/raider.h"
#include "../libraries/compass/compass.h"


using namespace std;
int main() {
    Raider raider;
    Compass compass(new I2C(I2C_BUS));
    while(1){
        report(INFO,"Compass X: "+to_string(65536-compass.getCompassX()));
        report(INFO,"Compass Y: "+to_string(65536-compass.getCompassY()));
        report(INFO,"Compass Z: "+to_string(65536-compass.getCompassZ()));

        float angle= atan2((double)compass.getCompassY(),(double)compass.getCompassX()) * (180 / 3.14159265) + 180;

        report(INFO,"\nCompass angle: "+to_string(angle));
        usleep(200000);

    }
}
