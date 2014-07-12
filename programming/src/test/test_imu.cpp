#include <iostream>
#include <string>
#include "../libraries/imu/imu.h"
#include "../libraries/debug/debug.h"


using namespace std;

// cout << "\033[1;33mCOLOR\033[0m\n";


int main() {

    report(INFO,"Beginning TEST_IMU\n");

    IMU imu;

    report("getting AX");

    for(int i=0; i<100;i++){
    int ax=imu.getAccelerometerX();
    if(65535==ax) report(WARNING, "Getting accelerometer may be not working on X axis");
    else cout<<ax<<endl;
    usleep(500000);
    }


}
