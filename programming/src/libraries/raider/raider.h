#ifndef RAIDER_H
#define RAIDER_H

#define RIGHT_INFRARRED 0
#define LEFT_INFRARRED 1
#define SERIAL_PORT 2

class raider
{
private:
    int rightIR;
    int leftIR;
public:
    raider();
    int getIR(bool);
    void walk();
    void turnLeft();
    void turnRigt();
    void stepLeft();
    void stepRight();
    void standUp();
};

#endif // RAIDER_H
