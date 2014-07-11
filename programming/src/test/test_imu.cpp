/**
 * Code for thinning a binary image using Zhang-Suen algorithm.
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <iostream>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>



using namespace cv;

//Direccion del imu: 69 (1000101)

int main()
{
    bool error;

//ABRIMOS EL PUERTO
    int file;
    char *filename = "/dev/i2c-1";
    if ((file = open(filename, O_RDWR)) < 0) error=1;
    else error=0;

    std::cout<<"\nApertura del puerto: "<<error<<std::endl;

    int addr = 0b01000101;          // TODO poner direccion
    if (ioctl(file, I2C_SLAVE, addr) < 0) error=1;
    else error=0;

    std::cout<<"\nLectura de direccion: "<<error<<std::endl;

}

