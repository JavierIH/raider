#ifndef IMU_H_
#define IMU_H_

#include "../i2c/i2c.h"

#define IMU_I2C_ADDRESS 0x69

class IMU {
private:
	I2C *i2c;
public:
    IMU(I2C *connection);
    ~IMU();

    __u16 getAccelerometerX();
    __u16 getAccelerometerY();
    __u16 getAccelerometerZ();

    __u32 getGyroscopeX();
    __u32 getGyroscopeY();
    __u32 getGyroscopeZ();

    __u32 getTemp();
};

#endif /* IMU_H_ */
