#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

VideoCapture capture;

bool openCamera(int device){
    VideoCapture cap(device);
    if(!cap.isOpened()) return false;
    else{
        capture=cap;
        return true;
    }
}

void cleanBuffer(){
    capture.grab();
    capture.grab();
    capture.grab();
    capture.grab();
}

Mat getFrame(){
    cleanBuffer();
    Mat frame;
    capture.read(frame);
    return frame;
}



