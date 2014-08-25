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

        float mx=compass.getCompassX();
        float my=compass.getCompassY();
        float mz=compass.getCompassZ();
        report(INFO,"Compass X: "+to_string(mx));
        report(INFO,"Compass Y: "+to_string(my));
        report(INFO,"Compass Z: "+to_string(mz));



        float angle= atan2(mx,my) * (180 / 3.14159265);

        report(INFO,"\nCompass angle: "+to_string(angle));
        usleep(200000);
    }
}
