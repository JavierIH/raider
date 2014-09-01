/**
 * Code for thinning a binary image using Zhang-Suen algorithm.
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <iostream>
#include <math.h>


using namespace cv;

int test_hough(){
    openCamera(-1);

    while(1){
        char c=waitKey(0);
        if (c=='\n'||c=='a') return 0;

    Mat image=getFrame();

    int size_factor=3;
    cv::Size size(160*size_factor,120*size_factor);
    resize(image,image,size);


    imshow("camara",image);

    Mat input=detectGreen(image);
    imshow("original",input);

    Mat output;

     Canny(input, output, 50, 200, 3);
     imshow("original",output);


     vector<Vec2f> lines;

    HoughLines(output,lines,1,CV_PI/180,100,0,0);

    report("Lineas -> "+to_string(lines.size()));

    for( size_t i = 0; i < lines.size(); i++ )
    {
      float rho = lines[i][0], theta = lines[i][1];
      Point pt1, pt2;
      double a = cos(theta), b = sin(theta);
      double x0 = a*rho, y0 = b*rho;
      pt1.x = cvRound(x0 + 1000*(-b));
      pt1.y = cvRound(y0 + 1000*(a));
      pt2.x = cvRound(x0 - 1000*(-b));
      pt2.y = cvRound(y0 - 1000*(a));
      line( image, pt1, pt2, Scalar(0,0,255), 5, CV_AA);
    }


    imshow("fin",image);
}
    return 0;
}


Vec2i funcion_findLine(Mat image){
    Mat1b input=detectGreen(image);



    Canny(input, input, 50, 200, 3);

    input=dilation(input,5);
    input=dilation(input,-6);


    imshow("original",input);// debug



    vector<Vec4i> lines;
    HoughLinesP(input, lines, 1, CV_PI/180, 80, 50, 40 );// TODO ajustar
    int max_length=0;
    int max_line=0;
    if(lines.size()>0){
        for( size_t i = 0; i < lines.size(); i++ )
        {
            Vec4i l = lines[i];
            int length=sqrt(pow((l[2]-l[0]),2)+pow((l[3]-l[1]),2));
            if(length>max_length){
                max_length=length;
                max_line=i;
            }
        }
        line( image,
              Point(lines.at(max_line)[0], lines.at(max_line)[1]),
                Point(lines.at(max_line)[2], lines.at(max_line)[3]),
                Scalar(255,0,0), 1, CV_AA);

        float y=lines.at(max_line)[2]-lines.at(max_line)[0];
        float x=lines.at(max_line)[3]-lines.at(max_line)[1];
        int alfa;
        if(y==0)alfa=90;
        else alfa=atan(x/y)*180/CV_PI;
        int d=input.rows-(lines.at(max_line)[3]+lines.at(max_line)[1])/2;

        report("Numero de lineas: "+to_string(lines.size()));
        report("La mas larga mide: "+to_string(max_length));
        report("Está a un angulo de: "+to_string(alfa));
        report(INFO,"A una distancia de: "+to_string(d));
        imshow("Resultado", image);
        Vec2i result(d,alfa);
        return result;

    }
    else return Vec2i(-1,0); //No hay linea
}

int main(){
    openCamera(1);

    while(1){
        char c=waitKey(0);
        if (c=='\n'||c=='a') return 0;

        Mat image=getFrame();

        Rect rect(0,image.rows/2,image.cols,image.rows/2);

        imshow("camsdfdgara",image);
        imshow("camara",image(rect));
    }
}
