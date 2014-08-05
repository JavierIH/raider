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

    while(1){
        char c=waitKey(50);
        if (c=='\n'||c=='a') return 0;

    Mat image=getFrame();

    int size_factor=1;
    cv::Size size(160*size_factor,120*size_factor);
    resize(image,image,size);

   /* Mat1b input=detectGreen(image);

//-----------------------------PREPARAR INPUT
    threshold(input, input, 50 , 255, THRESH_BINARY);

    input=dilation(input,20);
    input=dilation(input,-10);


    for (int i=0;i<input.rows;i++)
    input.at<uchar>(i,0)=0;

    for (int i=0;i<input.rows;i++)
    input.at<uchar>(i,input.cols-1)=0;

    Mat output=input.clone();
//------------------------------------------

    voronoi(output);

//BUSCAR CAMINO
    vector<vector<Point> > contours;
    findContours(output.clone(), contours,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);

    for(int i=0; i<contours.size(); i++) std::cout<<"\n\n\nContorno "<<i<<": "<<contours.at(i).size();

    int way=0;
    Point top_max(0,output.rows);
    Point bot_max(0,0);
    Point mid_max;
    bool way_flag=false;

    for(int i=0; i<contours.size(); i++){
        Point top(0,output.rows);
        Point bot(0,0);

        for(int j=0; j<contours.at(i).size(); j++){
            if(contours.at(i).at(j).y<top.y){
                top=contours.at(i).at(j);
            }
            if(contours.at(i).at(j).y>bot.y){
                bot=contours.at(i).at(j);
            }

        }
        cout<<"\nthis way: "<<i<<endl;
        cout<<"Empieza en y: "<<bot.y<<endl;
        cout<<"Termina en y: "<<top.y<<endl<<endl<<endl;

        if((top.y<top_max.y)&&(bot.y>output.rows*0.9)){
            way=i;
            way_flag=true;
            top_max=top;
            bot_max=bot;
        }
    }

    for(int j=0; j<contours.at(way).size(); j++){
        if(contours.at(way).at(j).y>output.rows*0.8&&contours.at(way).at(j).y<output.rows*0.9){
            mid_max=contours.at(way).at(j);
        }
    }

    report(INFO,"El mejor camino es el "+to_string(way));
    report(INFO,"Va de "+to_string(bot_max));
    report(INFO,"a "+to_string(top_max));

    float x=mid_max.x-bot_max.x;
    float y=bot_max.y-mid_max.y;
    float alfa;

    report(INFO,"El punto de partida se aleja del centro: "+to_string(-output.cols/2+bot_max.x));
    if(x==0) alfa=0;
    else alfa=atan(x/y)*180/3.1415927;

    report(INFO,"Con una inclinacion de: "+to_string(alfa));

    drawLine(output,bot_max,mid_max);
    drawLine(output,bot_max,top_max);

    imshow("rayitas",output);

    showMap(input,output);
}*/


    char command=findWay(image,10,20);

    report(INFO,"Command: "+to_string(command));

    }
}
