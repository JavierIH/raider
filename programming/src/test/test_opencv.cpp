#include<iostream>
#include "../libraries/raider/raider.h"
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>

using namespace std;
using namespace cv;

void test1(){
    Mat image;
    image=cv::imread("../../../../Imagenes/ceabot1.jpg");
    if(image.empty()) cout<<"ERRPR";
    imshow("AUX",image);

    vector<Mat> rgb;

    split(image, rgb);


    //imshow("b", rgb[0]);
    //imshow("g", rgb[1]);
    imshow("r", rgb[2]);

    Mat out;
    Mat out2;
    threshold(rgb[2], out, 150 , 255, THRESH_BINARY);
    threshold(rgb[2], out2, 200 , 255, THRESH_BINARY);

    imshow("out",out);


    waitKey();
}

void test2(){
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened()) cout<<"\n\n\n\nERROR\n\n\n\n";
    for(int i=0; i<100;i++){
        Mat frame;
        cap >> frame; // get a new frame from camera
        Mat out;
        //threshold(frame, out, 150 , 255, THRESH_BINARY);

        if (!frame.empty())imshow("out", out);
        waitKey(10);
    }

}




int main(int, char**)
{
    test2();

    return 0;
}





