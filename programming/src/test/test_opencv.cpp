/**
 * Code for thinning a binary image using Zhang-Suen algorithm.
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <iostream>


using namespace cv;


int main()
{
    openCamera(0);

    while(1){
        char c=waitKey(0);
        if (c=='\n'||c=='a') return 0;

    Mat image=getFrame();

    int size_factor=3;
    cv::Size size(160*size_factor,120*size_factor);
    resize(image,image,size);


    imshow("camara",image);
  //  waitKey();


    Mat1b input=detectGreen(image);




    imshow("original",input);

    //waitKey();
    vector<vector<Point> > contours;

   findContours(input.clone(), contours,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);

    std::cout<<"\n\n\nContornos: "<<contours.size();





}
    return 0;
}


