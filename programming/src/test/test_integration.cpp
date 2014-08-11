#include "../libraries/raider/raider.h"

#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    openCamera(0);
    cv::imshow("hola",getFrame());
    cv::waitKey();
}
