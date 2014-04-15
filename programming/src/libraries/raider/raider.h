#ifndef RAIDER_H
#define RAIDER_H

#include "../bones/bones.h"

#define SERIAL_PORT 2
#define RIGHT_INFRARRED 0
#define LEFT_INFRARRED 1

class raider
{
private:
    int rightIR;
    int leftIR;
public:
    raider();
    int getIR(bool);
    int sendCommand(char);
    void walk();
    void turnLeft();
    void turnRigt();
    void stepLeft();
    void stepRight();
    void standUp();
};

#endif // RAIDER_H
