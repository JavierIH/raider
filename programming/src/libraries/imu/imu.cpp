#include "imu.h"
#include "../i2c/i2c.h"
#include "../debug/debug.h"
#include <iostream>
using namespace std;

IMU::IMU() {
    i2c = new I2C(2, 0x69);

    //Despertar
    if(i2c->write8(0x6B,0)<0) report(ERROR, "IMU connection failed (not waking up)");
    else report(OK, "IMU connected");
}

IMU::~IMU() {
    report("Disconnecting IMU...");
	delete i2c;
	i2c = 0;
    report(OK, "IMU disconnected");
}

__u16 IMU::getAccelerometerX() {
	return (i2c->read8(0x3B) << 8) | i2c->read8(0x3C);
}

__u16 IMU::getAccelerometerY() {
	return (i2c->read8(0x3D) << 8) | i2c->read8(0x3E);
}

__u16 IMU::getAccelerometerZ() {
	return (i2c->read8(0x3F) << 8) | i2c->read8(0x40);
}

__u32 IMU::getGyroscopeX() {
	return (i2c->read8(0x43) << 8) | i2c->read8(0x44);
}

__u32 IMU::getGyroscopeY() {
	return (i2c->read8(0x45) << 8) | i2c->read8(0x46);
}

__u32 IMU::getGyroscopeZ() {
	return (i2c->read8(0x47) << 8) | i2c->read8(0x48);
}

__u32 IMU::getMagnetometerX() {
	return (i2c->read8(0x04) << 8) | i2c->read8(0x03);
}

__u32 IMU::getMagnetometerY() {
	return (i2c->read8(0x06) << 8) | i2c->read8(0x05);
}

__u32 IMU::getMagnetometerZ() {
	return (i2c->read8(0x08) << 8) | i2c->read8(0x07);
}

__u32 IMU::getTemp() {
	return (i2c->read8(0x41) << 8) | i2c->read8(0x42);
}
