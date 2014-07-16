/*
 * i2c.h
 *
 *  Created on: Jul 8, 2013
 *  Original author: mike
 *
 *  Customized on Jul 2, 2014
 *  Secondary author: JavierIH
 *
 */

#ifndef I2C_H_
#define I2C_H_

#include "../debug/debug.h"
#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> // open();
#include <unistd.h> // close();
#include <sys/ioctl.h> // ioctl();

class I2C {
private:
	int address;
	int bus;
	int file;
	char filename[20];
	bool openConnection();
	bool closeConnection();

public:
	I2C(int bus, __u16 address);
	~I2C();

    bool test();

	__s32 read8(__u8 reg);
	__s32 write8(__u8 reg, __u8 data);
	__s32 read16(__u8 reg);
	__s32 write16(__u8 reg, __u16 data);
};

#endif /* I2C_H_ */
