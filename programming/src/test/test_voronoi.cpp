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

/*void showMap(Mat input, Mat output){
    int type = CV_8UC3;
    Scalar red(0,0,255); //debug
    Scalar black(0,0,0); //debug
    Mat way(input.rows,input.cols, type, Scalar(0,0,0)); //debug
    way.setTo(red,output); //debug
    Mat obstacles(input.rows,input.cols, type, Scalar(255,255,255)); //debug
    obstacles.setTo(black,input); //debug
    Mat ground(input.rows,input.cols, type, Scalar(0,255,0)); //debug
    Mat result=obstacles.clone()+ground.clone();
    result.setTo(red,output);
    imshow("Mapa",result);
}*/

/*void drawLine( Mat &img, Point start, Point end )
{
  int thickness = 4;
  int lineType = 8;
  line( img,
        start,
        end,
        Scalar( 120, 0, 0 ),
        thickness,
        lineType );
}*/


int main()
{
    openCamera(0);

    int contador=0;
    while(contador<20){
        char c=waitKey(50);
        if (c=='\n'||c=='a') return 0;

        Mat image=getFrame();
        int size_factor=1;
        cv::Size size(160*size_factor,120*size_factor);
        resize(image,image,size);

        Vec2i way_result=findWay(image);//,10*size_factor,20);

        if(abs(way_result[0])>10*size_factor){ // PARAMETRO DISTANCIA
            if(way_result[0]>0) report(OK,"E -> Paso lateral a la derecha");
            if(way_result[0]<0) report(OK,"Q -> Paso lateral a la izquierda");
        }
        else{
            if(abs(way_result[1])>20){ // PARAMETRO ANGULO
                if(way_result[1]<0) report(OK,"D -> Girar a la izquierda");
                if(way_result[1]>0) report(OK,"A -> Girar a la derecha");
            }
            else report(OK,"W -> Avanza recto");
        }
        contador++;
    }
}
