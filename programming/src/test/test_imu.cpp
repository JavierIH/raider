#include <iostream>
#include <string>
#include "../libraries/raider/raider.h"
#include "../libraries/imu/imu.h"


using namespace std;

// cout << "\033[1;33mCOLOR\033[0m\n";


int main() {

    Raider raider;

    while(1){
        int state=raider.fall();
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
    }
}
