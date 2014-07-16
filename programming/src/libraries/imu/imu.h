#ifndef IMU_H_
#define IMU_H_

#include "../i2c/i2c.h"

class IMU {
private:
	I2C *i2c;
public:
    IMU(I2C *connection);
    ~IMU();

    bool openIMU();

    __u16 getAccelerometerX();
    __u16 getAccelerometerY();
    __u16 getAccelerometerZ();

    __u32 getGyroscopeX();
    __u32 getGyroscopeY();
    __u32 getGyroscopeZ();

    __u32 getMagnetometerX();
    __u32 getMagnetometerY();
    __u32 getMagnetometerZ();

    __u32 getTemp();
};

#endif /* IMU_H_ */
