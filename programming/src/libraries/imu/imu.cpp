#include "imu.h"
#include "../i2c/i2c.h"
#include "../debug/debug.h"
#include <iostream>
using namespace std;

IMU::IMU(I2C *connection) {
    i2c = connection;

    //Despertar
    if(i2c->write8(IMU_I2C_ADDRESS,0x6B,0x00)<0) report(ERROR, "IMU connection failed (not waking up)");
}

IMU::~IMU() {
    report("Disconnecting IMU...");
	delete i2c;
	i2c = 0;
    report(OK, "IMU disconnected");
}


__u16 IMU::getAccelerometerX() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x3B) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x3C);
}

__u16 IMU::getAccelerometerY() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x3D) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x3E);
}

__u16 IMU::getAccelerometerZ() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x3F) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x40);
}

__u32 IMU::getGyroscopeX() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x43) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x44);
}

__u32 IMU::getGyroscopeY() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x45) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x46);
}

__u32 IMU::getGyroscopeZ() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x47) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x48);
}

__u32 IMU::getTemp() {
    return (i2c->read8(IMU_I2C_ADDRESS,0x41) << 8) | i2c->read8(IMU_I2C_ADDRESS,0x42);
}
