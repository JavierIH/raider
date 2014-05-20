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
    image=cv::imread("../../../../../Imagenes/ceabot1.jpg");
    if(image.empty()) cout<<"ERRPR";
    imshow("AUX",image);

    vector<Mat> rgb;

    split(image, rgb);


    imshow("b", rgb[0]);
    imshow("g", rgb[1]);
    imshow("r", rgb[2]);

    waitKey();

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
    for(int i=0; i<500;i++){
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
    for(int i=0; i<10;i++){
        Mat image=getFrame();
        imshow("frame", image);
        waitKey(0);
    }
}

void test6(){
    Mat image;
    image=cv::imread("../../../../../Imagenes/ceabot1.jpg");
    if(image.empty()) cout<<"ERRPR";
    imshow("Imagen original",image);

    Mat red= extractChannel(image, 2);
    imshow("Canal rojo",red);
    waitKey();

}

void test7(){
    Mat image;
    image=cv::imread("../../../../../Imagenes/ceabot3.jpg");

    imshow("Imagen original",image);
    Mat red= extractChannel(image, 2);
    imshow("Canal rojo",red);
    Mat1b result;
    threshold(red, result, 120 , 255, THRESH_BINARY);
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

void test8(){
    Mat src;
    src=cv::imread("../../../../../Imagenes/ceabot3.jpg");

    Mat red= extractChannel(src, 2);
    Mat1b result;
    threshold(red, result, 120 , 255, THRESH_BINARY);

    raider Raider;

    getFrame();

    imshow("Canal rojo threshold", result);
    waitKey();

    erode(result, result, Mat(),Point(-1,-1),3);
    dilate(result, result, Mat(),Point(-1,-1),3);




    Mat dst;
    Canny(result, dst, 50, 200, 3);



    dilate(dst, dst, Mat(),Point(-1,-1),1);


    imshow("canny",dst);
    imshow("restachnga",dst+result);
    waitKey();


    vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50,10);
    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        line( dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(125), 5, CV_AA);
    }

    imshow("lineas", dst);


    //dilate(dst, dst, Mat(),Point(-1,-1),11);
    //erode(dst, dst, Mat(),Point(-1,-1),25);


    //imshow("source", src);
    //imshow("detected lines", dst);

    waitKey();
}

void test9(){
    openCamera(1);

    while(waitKey(10)!='\n'){
        Mat image=getFrame();
        imshow("frame", image);


        //EXTRACCION DE COLOR VERDE (funciona guay)
        Mat op1= extractChannel(image, 1); //1 GREEN
        op1-= extractChannel(image, 0); //0 BLUE
        //imshow("zona verde-azul",op1);

        Mat op2= extractChannel(image, 1); //1 GREEN
        op2-= extractChannel(image, 2); //2 RED
        //imshow("zona verde-rojo",op2);

        Mat operation=op2+op1;

        //zona (verde-rojo)+(verde-azul)
        operation=operation*3;
        imshow("extraccion verde",operation);

        //imshow("Canal rojo",red);
        Mat1b result;
        threshold(operation, result, 200 , 255, THRESH_BINARY);
        imshow("Threshold",result);

        //Mat1b aux=result.clone();

        //imshow("cerro",result);

        erode(result, result, Mat(),Point(-1,-1),3);


        dilate(result, result, Mat(),Point(-1,-1),3);



        imshow("limpia",result);

        //imshow("resta",aux-result);


        //waitKey(10);
    }

}



int main()
{
    cout<<"INICIO";
    test9();
    cout<<"FIN";
    return 0;
}




