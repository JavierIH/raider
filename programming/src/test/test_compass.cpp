#include <iostream>
#include <string>
#include "../libraries/raider/raider.h"
#include "../libraries/compass/compass.h"


using namespace std;

// cout << "\033[1;33mCOLOR\033[0m\n";


int main() {

    Raider raider;

    /*while(1){  // NO BORRAR, PARTE DEL PROGRAMA FINAL
        int state=raider.getFall();
        if (state==1){
            report(INFO, "FRONT fall  > ");
            raider.standUp();
        }
        else if (state==2){
            report(INFO, "BACK  fall  < ");
            raider.roll();
            raider.standUp();
        }
        else{
            report(INFO, "Standing up | ");
        }
        sleep(1);
    }*/

    Compass compass(new I2C(I2C_BUS));

    while(1){
        report(INFO,"Compass X: "+to_string(compass.getCompassX()));
        report(INFO,"Compass Y: "+to_string(compass.getCompassY()));
        report(INFO,"Compass Z: "+to_string(compass.getCompassZ()));
    usleep(200000);
    }

}
