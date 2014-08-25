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
        report(INFO,"Compass X: "+to_string(compass.getCompassX()-65536));
        report(INFO,"Compass Y: "+to_string(compass.getCompassY()-65536));
        report(INFO,"Compass Z: "+to_string(compass.getCompassZ()-65536));


    double x=compass.getCompassX();
    double y=compass.getCompassY();
        float angle= atan2(x,y) * (180 / 3.14159265);

        report(INFO,"\nCompass angle: "+to_string(angle));
        usleep(200000);

    }
}
