#include "raider.h"

using namespace std;
using namespace cv;

Raider::Raider(){

//Javi del futuro, echa un ojo a esto
//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");

    report(INFO, "Wake up Raider!");

//SERIAL COMMUNICATION
    report("Setting serial communication...");
    serial = new serialib();
    int serial_flag=serial->Open(SERIAL_PORT, BAUD_RATE); // TODO revisar bool char
    if (serial_flag==1) report(OK, "Serial communication connected!");
    else if (serial_flag==-2)report(ERROR, "Serial communication failed (at opening device)");
    else if (serial_flag==-4)report(ERROR, "Serial communication failed (check baud rate)");
    else report(ERROR, "Serial communication failed (unknown error)");

//I2C BUS CONNECTION
    report("Setting I2C bus...");
    i2c = new I2C(I2C_BUS, IMU_ADDRESS);
    if (i2c->test()) report(OK, "I2C bus connected!");
    else report(ERROR, "I2C doesn't work!");

//IMU SENSOR
    report("Setting imu sensor...");
    imu = new IMU(i2c);
    if(4294967295==imu->getMagnetometerX()) report(ERROR, "IMU sensor connection FAILED");
    else if(65535==imu->getMagnetometerX()) report(WARNING, "Accelerometer may be not working (please check)");
    else report(OK, "IMU sensor connected!");

//INFRARRED SENSORS
    report("Setting infrarred sensors...");
    if(getAnalog(0)<=0) report(ERROR, "Error in infrarred sensors (pin 0)");
    else if(getAnalog(1)<=0) report(ERROR, "Error in infrarred sensors (pin 1)");
    else report(OK,"Infrarred sensors are working fine!");

//CAMERA
    report("Setting camera...");
    camera = new VideoCapture(CAMERA_ID);
    if(!camera->isOpened()) report(ERROR, "Camera failed at opening, wrong device id?");
    else report(OK, "Camera initialized");



}

bool Raider::getLeftIR(){
    leftIR=getAnalog(AIN5);
    if(leftIR>INFRARED_MAX) return 1;
    else return 0;

}

bool Raider::getRightIR(){
    rightIR=getAnalog(AIN3);
    if(rightIR>INFRARED_MAX) return 1;
    else return 0;
}

int Raider::getFall(){

    int ay=imu->getAccelerometerY()*360/65355;
    if(ay<=90&&ay>FALL_DEGREES){
        return 1;
    }
    else if(ay>=270&&ay<360-FALL_DEGREES){
        return 2;
    }
    else{
        return 0;
    }
}

bool Raider::walk(){

    char command= 'W';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (walk)");
        return 0;
    }
    usleep(WALK);
    return 1;
}

bool Raider::run(){

    char command= 'S';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (run)");
        return 0;
    }
    usleep(RUN);
    return 1;
}

bool Raider::getUp(){ // TODO revisar comando

    char command= 'U';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (standUp)");
        return 0;
    }
    usleep(GETUP);
    return 1;
}

bool Raider::turnL(){

    char command= 'A';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (turnLeft)");
        return 0;
    }
    usleep(TURNL);
    return 1;
}
bool Raider::turnR(){

    char command= 'D';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (turnRight)");
        return 0;
    }
    usleep(TURNR);
    return 1;
}

bool Raider::stepL(){

    char command= 'Q';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (stepLeft)");
        return 0;
    }
    usleep(STEPL);
    return 1;
}
bool Raider::stepR(){

    char command= 'E';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (stepRight)");
        return 0;
    }
    usleep(STEPR);
    return 1;
}

bool Raider::roll(){

    char command= 'R';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (roll)");
        return 0;
    }
    usleep(ROLL);
    return 1;
}

bool Raider::yes(){

    char command= 'Y';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (roll)");
        return 0;
    }
    usleep(YES);
    return 1;
}

bool Raider::sendCommand(char command){

    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command");
        return 0;
    }
    return 1;
}

Mat Raider::getFrame(){
    for(int i=0; i<5; i++) camera->grab(); // TODO quizas haya alguna forma mas elegante TODO
    Mat frame;
    camera->read(frame);
    return frame;
}

Vec2i Raider::findWay(Mat image){

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

    report("Distance to way: "+to_string(d));
    if(x==0) alfa=0;
    else alfa=atan(x/y)*180/3.1415927;
    report("Way angle: "+to_string(alfa));

    //drawLine(output,bot_max,mid_max); //debug
    //drawLine(output,Point(output.cols/2-param_dist,output.rows),
    //                Point(output.cols/2+param_dist,output.rows)); //debug
    //showMap(input,output); //debug

    return Vec2i(d,alfa);
}


Vec2i Raider::findLine(Mat image){

    Mat1b input=detectGreen(image);

    Canny(input, input, 50, 200, 5);

    input=dilation(input,8);
    input=dilation(input,-9);

    //imshow("original",input);// debug

    vector<Vec4i> lines;
    HoughLinesP(input, lines, 1, CV_PI/180, 80,40, 30 );// TODO ajustar
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
        report(INFO,"Linea a un angulo de: "+to_string(alfa));
        report(INFO,"A una distancia de: "+to_string(d));
       // imshow("Resultado", image);
        Vec2i result(d,alfa);
        return result;


    }
    else return Vec2i(-1,0); //No hay linea
}

