/**
 * Code for thinning a binary image using Zhang-Suen algorithm.
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <iostream>


using namespace cv;

int main()
{
//OPENING THE BUS
    int file;
    char *filename = "/dev/i2c-2";
    if ((file = open(filename, O_RDWR)) < 0) {
        std::cout<<"Failed to open the i2c bus";
        exit(1);
    }
    else std::cout<<"\nOpen is OK\n";
    return 0;
}

