#include<iostream>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>

using namespace std;
using namespace cv;


void test_resta(){
    Mat image;
    image=cv::imread("../../../../../Imagenes/ceabot3.jpg");

    imshow("Imagen original",image);
    Mat red= extractChannel(image, 2);
    imshow("Canal rojo",red);
    Mat1b result;
    threshold(red, result, 40 , 255, THRESH_BINARY);
    imshow("Threshold",result);

    Mat1b aux=result.clone();
    //erode(result, result, Mat(),Point(-1,-1),10);
    //dilate(result, result, Mat(),Point(-1,-1),10);

    erode(result, result, Mat(),Point(-1,-1),3);
    dilate(result, result, Mat(),Point(-1,-1),3);


    imshow("cerro",result);

    imshow("resta",aux-result);



    waitKey();
}

void test_lineas(){
    openCamera(1);

    int i=0;
    while(waitKey(10)!='\n'){


        cout<<i<<endl;

        Mat image=getFrame();
        imshow("frame", image);

        Mat red=extractChannel(image,2);
        Mat blue=extractChannel(image,0);
        Mat green=extractChannel(image,1);

        //Extraccion de verde
        Mat result=(green-red)+(green-blue);
        //imshow("(green-red)+(green-blue)", result);

        GaussianBlur(result,result,Size(11,11),0,0);
        imshow("blur", result);

        Mat1b thresh;
        threshold(result, thresh, 50 , 255, THRESH_BINARY_INV);
        imshow("Thresholdbinary",thresh);
    Mat dst;
    Canny(thresh, dst, 50, 150, 5);
    dilate(dst, dst, Mat(),Point(-1,-1),1);

    imshow("CANNY",dst);

    Mat lineas=imread("../../../../../Imagenes/cielo.JPG");


    image.copyTo(lineas, thresh);

    //lineas=lineas*0;
    //imshow("lineasss",lineas);
    Scalar calor(0,0,255);
    vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI/180, 50, 5,5);
    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        line( lineas, Point(l[0], l[1]), Point(l[2], l[3]), calor, 5, CV_AA);
    }

    //imshow("lineas", lineas);
}
}

void test_verde(){
    openCamera(-1);

    while(waitKey(10)!='\n'){
        Mat image=getFrame();
        imshow("frame", image);

        Mat red=extractChannel(image,2);
        Mat blue=extractChannel(image,0);
        Mat green=extractChannel(image,1);

        //Extraccion de verde
        Mat result=(green-red)+(green-blue);
        imshow("(green-red)+(green-blue)", result);

        GaussianBlur(result,result,Size(11,11),0,0);
        imshow("blur", result);

        Mat1b thresh;
        threshold(result, thresh, 50 , 255, THRESH_BINARY_INV);
        imshow("Thresholdbinary",thresh);

    }

}


void test_rango_hsv(){

    openCamera(-1);

    int i=0;
    int increment=30;
    while(1){
        char c=waitKey(0);
        if(c=='\n') break;
        if(c=='a') i+=2;
        if(c=='s') i-=2;

        cout<<"From "<<i<<" To "<<i+increment<<endl;
        //Mat image=imread("../../../../../Imagenes/hsv.jpg");
        Mat image=getFrame();

        imshow("frame", image);




        //HSV
        Mat hsv;
        cvtColor(image,hsv,CV_RGB2HSV);
        //imshow("HSV",hsv);
        Mat im=image.clone();
        im=hsv;
        //imshow("im",im);

        Mat v=extractChannel(im,2);
        Mat h=extractChannel(im,0);
        Mat s=extractChannel(im,1);
        //imshow("h",h);
        //imshow("s",s);
        //imshow("v",v);/**/

        Mat1b thresh1;
        threshold(h, thresh1, i , 255, THRESH_BINARY);
        //imshow("Thresholdbinary1",thresh1);
        Mat1b thresh2;
        threshold(h, thresh2,i+increment , 255, THRESH_BINARY);
        //imshow("Thresholdbinary2",thresh2);
        Mat1b thresh=thresh1-thresh2;
        imshow("Thresholdbinary+",thresh);
    }

}

void test_hsv(){
    openCamera(-1);
    int i=0;
    int increment=20;

    while(1){
        char c=waitKey(0);
        if(c=='\n') break;
        if(c=='a') i+=2;
        if(c=='s') i-=2;

        cout<<"From "<<i<<" To "<<i+increment<<endl;
        Mat image=getFrame();
        imshow("frame", image);




        //HSV
        Mat hsv;
        cvtColor(image,hsv,CV_RGB2HSV);
        //imshow("HSV",hsv);
        Mat im=image.clone();
        im=hsv;
        //imshow("im",im);

        Mat v=extractChannel(im,2);
        Mat s=extractChannel(im,0);
        Mat h=extractChannel(im,1);
        imshow("h",h);
        //imshow("s",s);
        //imshow("v",v);/**/

        Mat1b thresh1;
        threshold(h, thresh1, i , 255, THRESH_BINARY);
        imshow("Thresholdbinary1",thresh1);
        Mat1b thresh2;
        threshold(h, thresh2,i+increment , 255, THRESH_BINARY);
        imshow("Thresholdbinary2",thresh2);
        Mat1b thresh=thresh2+thresh1;
        imshow("Thresholdbinary+",thresh);
    }

}


int main()
{
    cout<<"INICIO\n";
    test_lineas();
    cout<<"\nFIN";
    //waitKey(0);

    return 0;
}




