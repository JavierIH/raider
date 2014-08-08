#include "eye.h"
#include "../debug/debug.h"


using namespace cv;

VideoCapture capture;

bool openCamera(int device){
    VideoCapture cap(device);
    if(!cap.isOpened()) return false;
    else{
        capture=cap;
        return true;
    }
}

void cleanBuffer(){
    capture.grab();
    capture.grab();
    capture.grab();
    capture.grab();
}

Mat getFrame(){
    cleanBuffer();
    Mat frame;
    capture.read(frame);
    return frame;
}

cv::Mat extractChannel(Mat image, int channel){
    Mat out(image.size(),image.depth());
    int ch[] = { channel, 0 };
    mixChannels( &image, 1, &out, 1, ch, 1 );
    return out;
}

cv::Mat1b detectGreen(Mat image){

    Mat blue=extractChannel(image,0);
    Mat green=extractChannel(image,1);
    Mat red=extractChannel(image,2);

    Mat result=((green-red)+(green-blue));

    blue.release();
    green.release();
    red.release();

    GaussianBlur(result,result,Size(11,11),0,0);

    Mat1b out;
    threshold(result, out, 30 /*50*/, 255, THRESH_BINARY);

    return out;
}

cv::Mat1b dilation(Mat1b input, int level){
    Mat1b output;
    if(level>0)dilate(input, output, Mat(),Point(-1,-1),level);
    if(level<0)erode(input, output, Mat(),Point(-1,-1),-level);

    return output;
}

void thinningIteration(cv::Mat& img, int iter){
    CV_Assert(img.channels() == 1);
    CV_Assert(img.depth() != sizeof(uchar));
    CV_Assert(img.rows > 3 && img.cols > 3);

    cv::Mat marker = cv::Mat::zeros(img.size(), CV_8UC1);

    int nRows = img.rows;
    int nCols = img.cols;

    if (img.isContinuous()) {
        nCols *= nRows;
        nRows = 1;
    }

    int x, y;
    uchar *pAbove;
    uchar *pCurr;
    uchar *pBelow;
    uchar *nw, *no, *ne; // north (pAbove)
    uchar *we, *me, *ea;
    uchar *sw, *so, *se; // south (pBelow)

    uchar *pDst;

    // initialize row pointers
    pAbove = NULL;
    pCurr = img.ptr<uchar>(0);
    pBelow = img.ptr<uchar>(1);

    for (y = 1; y < img.rows-1; ++y) {
        // shift the rows up by one
        pAbove = pCurr;
        pCurr = pBelow;
        pBelow = img.ptr<uchar>(y+1);

        pDst = marker.ptr<uchar>(y);

        // initialize col pointers
        no = &(pAbove[0]);
        ne = &(pAbove[1]);
        me = &(pCurr[0]);
        ea = &(pCurr[1]);
        so = &(pBelow[0]);
        se = &(pBelow[1]);

        for (x = 1; x < img.cols-1; ++x) {
            // shift col pointers left by one (scan left to right)
            nw = no;
            no = ne;
            ne = &(pAbove[x+1]);
            we = me;
            me = ea;
            ea = &(pCurr[x+1]);
            sw = so;
            so = se;
            se = &(pBelow[x+1]);

            int A = (*no == 0 && *ne == 1) + (*ne == 0 && *ea == 1) +
                     (*ea == 0 && *se == 1) + (*se == 0 && *so == 1) +
                     (*so == 0 && *sw == 1) + (*sw == 0 && *we == 1) +
                     (*we == 0 && *nw == 1) + (*nw == 0 && *no == 1);
            int B = *no + *ne + *ea + *se + *so + *sw + *we + *nw;
            int m1 = iter == 0 ? (*no * *ea * *so) : (*no * *ea * *we);
            int m2 = iter == 0 ? (*ea * *so * *we) : (*no * *so * *we);

            if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
                pDst[x] = 1;
        }
    }

    img &= ~marker;
}

void voronoi(cv::Mat& im){ 
    im /= 255;

    cv::Mat prev = cv::Mat::zeros(im.size(), CV_8UC1);
    cv::Mat diff;

    do {
        thinningIteration(im, 0);
        thinningIteration(im, 1);
        cv::absdiff(im, prev, diff);
        im.copyTo(prev);
        /*Mat aux=im.clone();
        aux*=255;
        imshow("im",aux);
        waitKey(10);/**/
    }
    while (cv::countNonZero(diff) > 0);

    im *= 255;

    for (int i=0;i<im.cols;i++)
    im.at<uchar>(im.rows-1,i)=0;

    for (int i=0;i<im.cols;i++)
    im.at<uchar>(0,i)=0;
}

void drawLine( Mat &img, Point start, Point end )
{
  int thickness = 4;
  int lineType = 8;
  line( img,
        start,
        end,
        Scalar( 120, 0, 0 ),
        thickness,
        lineType );
}

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

Vec2i findWay(Mat image){

    Mat1b input=detectGreen(image);

    //imshow("Frame", image );

    threshold(input, input, 50 , 255, THRESH_BINARY);

    input=dilation(input,20);
    input=dilation(input,-10);

    //DIBUJAR LINEAS
    for (int i=0;i<input.rows;i++) input.at<uchar>(i,0)=0;
    for (int i=0;i<input.rows;i++) input.at<uchar>(i,input.cols-1)=0;

    Mat output=input.clone();

    voronoi(output);

    vector<vector<Point> > contours;
    findContours(output.clone(), contours,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);

    int way=0;
    Point top_max(0,output.rows);
    Point bot_max(0,0);
    Point mid_max;
    bool way_flag=false;
    if(contours.empty())return 'Z';
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

    float x=mid_max.x-bot_max.x;
    float y=bot_max.y-mid_max.y;
    float alfa;
    int d=-output.cols/2+bot_max.x;

    report(INFO,"Distance to way: "+to_string(d));
    if(x==0) alfa=0;
    else alfa=atan(x/y)*180/3.1415927;
    report(INFO,"Way angle: "+to_string(alfa));

    //drawLine(output,bot_max,mid_max); //debug
    //drawLine(output,Point(output.cols/2-param_dist,output.rows),
    //                Point(output.cols/2+param_dist,output.rows)); //debug
    //showMap(input,output); //debug

    return Vec2i(d,alfa);
    //SENDING MOVE COMMAND BASED ON GIVEN PARAMETERS
    /*if(abs(d)>param_dist){
        if(d>0){
            report(OK,"E -> Paso lateral a la derecha");
            return 'E';
        }
        if(d<0){
            report(OK,"Q -> Paso lateral a la izquierda");
            return 'Q';
        }
    }
    else{
        report("cerca del punto de inicio");

        if(abs(alfa)>param_alfa){
            if(alfa<0){
                report(OK,"D -> Girar a la izquierda");
                return 'D';
            }
            if(alfa>0){
                report(OK,"A -> Girar a la derecha");
                return 'A';
            }
        }
        else{
            report(OK,"W -> Avanza recto");
            return 'W';
        }
    }*/
}


Vec2i findLine(Mat image){

    Mat1b input=detectGreen(image);
    input=dilation(input,2); // TODO ajuste importante
    //imshow("original",input);// debug

    input=255-input; //Inversion de input

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
        report("A una distancia de: "+to_string(d));
        //imshow("Resultado", image); //debug
        return Vec2i(d,alfa);
    }
    else return Vec2i(-1,0); //No hay linea
}
