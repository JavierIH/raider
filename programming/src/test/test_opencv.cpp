#include<iostream>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <opencv2/opencv.hpp>
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
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened()) cout<<"\n\n\n\nERROR\n\n\n\n";
    for(int i=0; i<100;i++){
        Mat frame;
        cap >> frame; // get a new frame from camera
        Mat out;
        threshold(frame, out, 150 , 255, THRESH_BINARY);

        imshow("out", out);
        waitKey(10);
    }

}

void test3(){
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened()) cout<<"\n\n\n\nERROR\n\n\n\n";
    for(int i=0; i<100;i++){
        Mat frame;
        cap >> frame; // get a new frame from camera
        waitKey(5);

        Mat out;
        cap >> out; // get a new frame from camera


        imshow("out", out);
        imshow("frame", frame);
        imshow("resta",out-frame);
        waitKey(10);
    }
}



void test4(){
    VideoCapture cap(1);
    if(!cap.isOpened()) cout<<"\n\n\n\nERROR\n\n\n\n";
    for(int i=0; i<4;i++){
        Mat frame;
        //cap >> frame; // get a new frame from camera
        cap.grab();
        cap.grab();
        cap.grab();
        cap.grab();
        cap.read(frame);

        imshow("frame", frame);
        waitKey(0);
    }

}


void test5(){
    openCamera(1);
    for(int i=0; i<2;i++){
        Mat image=getFrame();
        imshow("frame", image);
        waitKey(0);
    }

}

int main(int, char**)
{
    test5();


    return 0;
}





