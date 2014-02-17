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

    while(1){

        if(65535==imu.getMagnetometerX()) report(WARNING, "Getting accelerometer may be not working on X axis");
        else{
            //cout<<"Magnetometer X: "<<imu.getMagnetometerX()<<endl;
            //cout<<"Magnetometer Y: "<<imu.getMagnetometerY()<<endl;
            //cout<<"Magnetometer Z: "<<imu.getMagnetometerZ()<<endl<<endl;

	    int ax=imu.getAccelerometerX()*360/65355;

            cout<<"Acceleration X: "<<ax<<endl;
            cout<<"Acceleration Y: "<<imu.getAccelerometerY()*360/65355<<endl;
            cout<<"Acceleration Z: "<<imu. getAccelerometerZ()*360/65335<<endl<<endl;

	    if(ax>300||ax<60) report(OK,"En pie");
	    else report(ERROR,"Caida");

            //cout<<"Gyroscope X: "<<imu.getGyroscopeX()<<endl;
            //cout<<"Gyroscope Y: "<<imu.getGyroscopeY()<<endl;
            //cout<<"Gyroscope Z: "<<imu.getGyroscopeZ()<<endl<<endl;

            //cout<<"Temperature: "<<imu.getTemp()<<endl<<endl;

            usleep(100000);
        }
    }
}
