#include <iostream>
#include <string>
#include <math.h>
#include "../libraries/raider/raider.h"
#include "../libraries/compass/compass.h"


using namespace std;
int main() {
    Compass compass(new I2C(I2C_BUS));
    while(1){
        report(INFO,"Brujula: "+to_string(compass.getCompass()));
        usleep(100000);
    }
}
