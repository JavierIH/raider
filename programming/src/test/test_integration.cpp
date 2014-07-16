#include "../libraries/raider/raider.h"

#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    Raider raider;

    raider.walk();
    raider.isStanding();
    std::cout<<"analog 0:  "<<getAnalog(0)<<endl;
    std::cout<<"analog 1:  "<<getAnalog(1)<<endl;
    std::cout<<"analog 2:  "<<getAnalog(2)<<endl;
    std::cout<<"analog 3:  "<<getAnalog(3)<<endl;



    return 0;
}
