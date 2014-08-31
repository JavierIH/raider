#ifndef EYE_H
#define EYE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <zbar.h>


bool openCamera(int);
void cleanBuffer(cv::VideoCapture &);
cv::Mat getFrame();
cv::Mat extractChannel(cv::Mat,int);
cv::Mat1b detectGreen(cv::Mat);
void thinningIteration(cv::Mat&,int);
void zhangSuen(cv::Mat&);
cv::Mat1b dilation(cv::Mat1b, int level);
void drawLine(cv::Mat&, cv::Point, cv::Point);
void showMap(cv::Mat, cv::Mat);


#endif // EYE_H
