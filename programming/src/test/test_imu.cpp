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

    if(65535==imu.getAccelerometerX()) report(WARNING, "Getting accelerometer may be not working on X axis");


}
