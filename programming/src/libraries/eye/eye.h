#ifndef EYE_H
#define EYE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

bool openCamera(int);
void cleanBuffer();
cv::Mat getFrame();
cv::Mat extractChannel(cv::Mat,int);
cv::Mat1b detectGreen(cv::Mat);
void thinningIteration(cv::Mat&,int);
void voronoi(cv::Mat&);
cv::Mat1b dilation(cv::Mat1b, int level);


#endif // EYE_H
