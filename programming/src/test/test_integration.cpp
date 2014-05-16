#include<iostream>

#include "../libraries/raider/raider.h"

using namespace std;

int main(){

    raider Raider;
    Raider.getIR(1);
    imshow("OK",getFrame());
    cv::waitKey(0);
    return 0;
}
