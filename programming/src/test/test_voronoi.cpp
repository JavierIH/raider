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
    threshold(input, input, 50 , 255, THRESH_BINARY);
    //imshow("original",input);
    //waitKey();
    input=dilation(input,20);
int dist=300;
/*
    for (int i=input.cols/2+dist;i<input.cols;i++)
    input.at<uchar>(input.rows-1,i)=0;

    for (int i=0;i<input.cols/2-dist;i++)
    input.at<uchar>(input.rows-1,i)=0;*/

    for (int i=0;i<input.rows;i++)
    input.at<uchar>(i,0)=0;

    for (int i=0;i<input.rows;i++)
    input.at<uchar>(i,input.cols-1)=0;



    //imshow("dilation",input);
    //waitKey();

    Mat output=input.clone();
    voronoi(output);
    //output=dilation(output,2);

    imshow("rayitas",output);

    vector<vector<Point> > contours;
    findContours(output.clone(), contours,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);

    for(int i=0; i<contours.size(); i++) std::cout<<"\n\n\nContorno "<<i<<": "<<contours.at(i).size();

    int way=0;
    int y_top=500; // TODO arreglar valor
    int y_top_max=500; // TODO arreglar valor
    int inicio_del_camino=0;
    int y_bot=0;
    int y_bot_max=0;
    bool way_flag=false;


    for(int i=0; i<contours.size(); i++){
        for(int j=0; j<contours.at(i).size(); j++){
            if(contours.at(i).at(j).y<y_top){
                y_top=contours.at(i).at(j).y;
            }
            if(contours.at(i).at(j).y>y_bot){
                y_bot=contours.at(i).at(j).y;
            }
        }
        cout<<"\nthis way: "<<i<<endl;
        cout<<"Empieza en y: "<<y_bot<<endl;
        cout<<"Termina en y: "<<y_top<<endl<<endl<<endl;

        if((y_top<y_top_max)&&(y_bot>output.rows*0.9)){
            way=i;
            way_flag=true;
        }
    }



    showMap(input,output);
//    waitKey();
}
    return 0;
}
