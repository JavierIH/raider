#ifndef EYE_H
#define EYE_H

#include <opencv2/opencv.hpp>

bool openCamera(int);
void cleanBuffer();
cv::Mat getFrame();
cv::Mat extractChannel(cv::Mat,int);
cv::Mat1b detectGreen(cv::Mat);
void thinningIteration(cv::Mat&,int);
void voronoi(cv::Mat&);
cv::Mat1b dilation(cv::Mat1b, int level);


#endif // EYE_H
