#include "imu.h"
#include "../i2c/i2c.h"
#include "../debug/debug.h"
#include <iostream>
using namespace std;

IMU::IMU(I2C *connection) {
    i2c = connection;

    //Despertar
    if(i2c->write8(0x6B,0)<0) report(ERROR, "IMU connection failed (not waking up)");

    i2c->write8(0x37,0x02); //Habilitar brujula

    i2c->setAddress(0x0C);      //change Address to Compass

    i2c->write8(0x0A, 0x00); //PowerDownMode
    i2c->write8(0x0A, 0x0F); //SelfTest
    i2c->write8(0x0A, 0x00); //PowerDownMode

    i2c->setAddress(0x69);      //change Address to MPU


    i2c->write8(0x24, 0x40); //Wait for Data at Slave0
    i2c->write8(0x25, 0x8C); //Set i2c address at slave0 at 0x0C
    i2c->write8(0x26, 0x02); //Set where reading at slave 0 starts
    i2c->write8(0x27, 0x88); //set offset at start reading and enable
    i2c->write8(0x28, 0x0C); //set i2c address at slv1 at 0x0C
    i2c->write8(0x29, 0x0A); //Set where reading at slave 1 starts
    i2c->write8(0x2A, 0x81); //Enable at set length to 1
    i2c->write8(0x64, 0x01); //overvride register
    i2c->write8(0x67, 0x03); //set delay rate
    i2c->write8(0x01, 0x80);

    i2c->write8(0x34, 0x04); //set i2c slv4 delay
    i2c->write8(0x64, 0x00); //override register
    i2c->write8(0x6A, 0x00); //clear usr setting
    i2c->write8(0x64, 0x01); //override register
    i2c->write8(0x6A, 0x20); //enable master i2c mode
    i2c->write8(0x34, 0x13); //disable slv4


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
    return (i2c->read8(0x4B) << 8) | i2c->read8(0x4A);
}

__u32 IMU::getMagnetometerY() {
    return (i2c->read8(0x4D) << 8) | i2c->read8(0x4C);
}

__u32 IMU::getMagnetometerZ() {
    return (i2c->read8(0x4F) << 8) | i2c->read8(0x4E);
}

__u32 IMU::getTemp() {
	return (i2c->read8(0x41) << 8) | i2c->read8(0x42);
}
