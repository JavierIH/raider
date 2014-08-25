#include <iostream>
#include <string>
#include "../libraries/raider/raider.h"
#include "../libraries/compass/compass.h"


using namespace std;
int main() {
    Raider raider;
    Compass compass(new I2C(I2C_BUS));
    while(1){
        report(INFO,"Compass X: "+to_string(compass.getCompassX()));
        report(INFO,"Compass Y: "+to_string(compass.getCompassY()));
        report(INFO,"Compass Z: "+to_string(compass.getCompassZ()));
        usleep(200000);
    }
}
