#include <iostream>
#include "../libraries/i2c/i2c.h"

using namespace std;

int main() {

    I2C con(1,0x69);

    cout<<con.read8(0x00);


}
