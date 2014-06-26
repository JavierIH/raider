/**
 * Code for thinning a binary image using Zhang-Suen algorithm.
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <iostream>


using namespace cv;

void showMap(Mat input, Mat output){
    int type = CV_8UC3;
    Scalar red(0,0,255); //debug
    Scalar black(0,0,0); //debug
    Mat way(input.rows,input.cols, type, Scalar(0,0,0)); //debug
    way.setTo(red,output); //debug
    Mat obstacles(input.rows,input.cols, type, Scalar(255,255,255)); //debug
    obstacles.setTo(black,input); //debug
    Mat ground(input.rows,input.cols, type, Scalar(0,255,0)); //debug
    Mat result=obstacles.clone()+ground.clone();
    result.setTo(red,output);
    imshow("Mapa",result);
}


int main()
{
    //openCamera(1);
    //Mat image=getFrame();
    Mat image=imread("../../../../../Imagenes/bloques2.png");

    Mat1b input=image.clone();
    threshold(input, input, 50 , 255, THRESH_BINARY);

    imshow("original",input);
    waitKey();

    Mat output=input.clone();
    voronoi(output);
    dilate(output, output, Mat(),Point(-1,-1),3);

    showMap(input,output);
    waitKey();

    return 0;
}
