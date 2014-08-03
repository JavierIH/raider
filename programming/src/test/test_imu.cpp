#include <iostream>
#include <string>
#include "../libraries/raider/raider.h"
#include "../libraries/imu/imu.h"


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

    IMU mpu9150(new I2C(I2C_BUS, IMU_ADDRESS));


    cout<<"Compass:"<<endl;
    cout<<mpu9150.getMagnetometerX()<<endl;
    cout<<mpu9150.getMagnetometerY()<<endl;
    cout<<mpu9150.getMagnetometerZ()<<endl<<endl;

}
