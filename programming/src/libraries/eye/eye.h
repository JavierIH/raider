#ifndef EYE_H
#define EYE_H

#include <opencv2/opencv.hpp>

//Vide

bool openCamera(int);
void cleanBuffer();
cv::Mat getFrame();


#endif // EYE_H
