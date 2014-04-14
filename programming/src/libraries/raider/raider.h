#ifndef RAIDER_H
#define RAIDER_H


class raider
{

public:
    raider();
    int getAnalog(int);
    void walk();
    void turnLeft();
    void turnRigt();
    void stepLeft();
    void stepRight();
    void standUp();
};

#endif // RAIDER_H
