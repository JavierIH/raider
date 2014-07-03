/**
 * Code for thinning a binary image using Zhang-Suen algorithm.
 */
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include <iostream>


using namespace cv;

void showMap(Mat input, Mat output){
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
}

void drawLine( Mat &img, Point start, Point end )
{
  int thickness = 40;
  int lineType = 8;
  line( img,
        start,
        end,
        Scalar( 200, 0, 0 ),
        thickness,
        lineType );
}


int main()
{
    openCamera(1);
    std::cout<<"\n\n\nGO!!!!!!!!!!!\n\n\n\n";
    //while(1){
      //  char c=waitKey(100);
      //  if (c=='\n'||c=='a') return 0;

//TOMAMOS UNA MUESTRA
    Mat image=getFrame();
    int size_factor=2;
    cv::Size size(160*size_factor,120*size_factor);
    resize(image,image,size);
    //imshow("camara",image);

//DETECCION DE VERDE
    Mat1b input=detectGreen(image);
    threshold(input, input, 50 , 255, THRESH_BINARY);
    input=dilation(input,10);

//QUITO LAS RAYAS HORIZONTALES DEL MARCO
    for (int i=0;i<input.rows;i++)
    input.at<uchar>(i,0)=0;
    for (int i=0;i<input.rows;i++)
    input.at<uchar>(i,input.cols-1)=0;

//VORONOI
    Mat output=input.clone();
    voronoi(output);
    output=dilation(output,2);
    //imshow("rayitas",output);

//BUSQUEDA DE CONTORNOS
    vector<vector<Point> > contours;
    findContours(output.clone(), contours,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);
    std::cout<<"\n\n\nContornos: "<<contours.size();

//ME CEPILLO EL CONTORNO MAS DEBIL
    int big_line=0;
    int high_max=output.rows;
    for(int i=0;i<contours.size();i++){
        int high=output.rows;
        for(int j=0;j<contours.at(i).size();j++){
            if(contours.at(i).at(j).y<high) high=contours.at(i).at(j).y;
        }
        std::cout<<"\nHartura: "<<high<<std::endl;
        if (high<high_max){ //Menor, es decir, mas cerca de arriba
            high_max=high;
            big_line=i;
        }
    }

//PINTO EL GORDO
    Mat drawing = Mat::zeros( output.size(), CV_8UC3 );
    Scalar color = Scalar(255,0,0);
    drawContours( drawing, contours, big_line, color, CV_FILLED);
    //imshow("El camino", drawing);



//RESULADO FINAL
    showMap(input,output);

    std::cout<<"\n***************************************";

    //}//while
    return 0;
}

