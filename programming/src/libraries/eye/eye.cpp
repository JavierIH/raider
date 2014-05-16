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

cv::Mat extractChannel(Mat image, int channel){
    Mat out(image.size(),image.depth());
    int ch[] = { channel, 0 };
    mixChannels( &image, 1, &out, 1, ch, 1 );
    return out;
}




