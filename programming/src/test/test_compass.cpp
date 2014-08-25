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

        report(OK, "CRUDOS:");
        report(OK,"Compass X: "+to_string(mx));
        report(OK,"Compass Y: "+to_string(my));
        report(OK,"Compass Z: "+to_string(mz));

        if(mx>50000)mx-=65535;
        if(my>50000)my-=65535;
        if(mz>50000)mz-=65535;

        report(INFO,"Compass X: "+to_string(mx));
        report(INFO,"Compass Y: "+to_string(my));
        report(INFO,"Compass Z: "+to_string(mz));



        float angle= atan2(mx,my) * (180 / 3.14159265);
        float angle2= atan2(mx,mz) * (180 / 3.14159265);

        report(ERROR,"Compass angle1: "+to_string(angle));
        report(ERROR,"Compass angle2: "+to_string(angle2));
        usleep(1000000);
    }
}
