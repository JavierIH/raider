#ifndef COMPASS_H_
#define COMPASS_H_

#include "../i2c/i2c.h"

#define COMPASS_I2C_ADDRESS 0x1E

class Compass {
private:
	I2C *i2c;
public:
    Compass(I2C *connection);
    ~Compass();

    int getCompassX();
    int getCompassY();
    int getCompassZ();

};

#endif /* COMPASS_H_ */
