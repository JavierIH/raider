#ifndef EYE_H
#define EYE_H

#include <opencv2/opencv.hpp>

//Vide

bool openCamera(int);
void cleanBuffer();
cv::Mat getFrame();
cv::Mat extractChannel(cv::Mat,int);


#endif // EYE_H
