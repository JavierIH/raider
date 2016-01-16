#include <iostream>
#include <string>
#include "../libraries/raider/raider.h"
#include "../libraries/imu/imu.h"


using namespace std;

// cout << "\033[1;33mCOLOR\033[0m\n";


int main() {

    Raider raider;

    while(1){  // NO BORRAR, PARTE DEL PROGRAMA FINAL
        int state_vertical=raider.getFall();
        if (state_vertical==1){
            report(INFO, "FRONT fall  > ");
            raider.getUp();
        }
        else if (state_vertical==2){
            report(INFO, "BACK  fall  < ");
            raider.roll();
            raider.getUp();
        }
        else{
            report(INFO, "Standing up | ");
        }
        usleep(100000);
    }
}

