/*#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../libraries/eye/eye.h"
#include "../libraries/debug/debug.h"

#include <zbar.h>
#include <iostream>

using namespace cv;
using namespace std;
using namespace zbar;

int main()
{
    openCamera(0);
    ImageScanner scanner;
    scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);

    while (1)
    {
        char c=waitKey(0);
        if (c=='\n'||c=='a') return 0;

        Mat frame=getFrame();

        ImageScanner scanner;
        scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);


        cvtColor(frame,frame,CV_BGR2GRAY);
        uchar *pointer = (uchar *)frame.data;

        Image image(frame.cols, frame.rows, "Y800", pointer, frame.cols*frame.rows);

        scanner.scan(image);

        string command;
        int distance;
        int distance_min=frame.cols/2;
        int i=0;

        for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            distance=abs(symbol->get_location_x(i) - frame.cols/2);
            report(INFO,"Marcador: "+symbol->get_data()+ "     Distance: "+to_string(distance));

            symbol.

            if(distance<distance_min){
                distance_min=distance;
                command=symbol->get_data();
            }
            i++;
        }

        if(command.empty()){
            report(ERROR, "No detectado");
        }
        else if (command == "Turn45R"){
            report(OK,"Girar 45 grados a la derecha");
        }
        else if (command == "Turn45L"){
            report(OK,"Girar 45 grados a la izquierda");
        }
        else if (command == "Turn90R"){
            report(OK,"Girar 90 grados a la derecha");
        }
        else if (command == "Turn90L"){
            report(OK,"Girar 90 grados a la izquierda");
        }
        else if (command == "Turn135R"){
            report(OK,"Girar 135 grados a la derecha");
        }
        else if (command == "Turn135L"){
            report(OK,"Girar 135 grados a la izquierda");
        }
        else if (command == "Turn180R"){
            report(OK,"Girar 180 grados a la derecha");
        }
        else if (command == "Turn180L"){
            report(OK,"Girar 180 grados a la izquierda");
        }
    }
}
*/

#include <opencv2/highgui/highgui.hpp>
 #include <opencv2/imgproc/imgproc.hpp>
 #include <zbar.h>
 #include <iostream>
 using namespace cv;
 using namespace std;
 using namespace zbar;
 //g++ main.cpp /usr/local/include/ /usr/local/lib/ -lopencv_highgui.2.4.8 -lopencv_core.2.4.8
 int main(int argc, char* argv[])
 {
   VideoCapture cap(0); // open the video camera no. 0
   // cap.set(CV_CAP_PROP_FRAME_WIDTH,800);
   // cap.set(CV_CAP_PROP_FRAME_HEIGHT,640);
   if (!cap.isOpened()) // if not success, exit program
   {
     cout << "Cannot open the video cam" << endl;
     return -1;
   }
   ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
   cout << "Frame size : " << dWidth << " x " << dHeight << endl;
   namedWindow("Camara de RAIDER",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
   while (1)
   {
     Mat frame;
     bool bSuccess = cap.read(frame); // read a new frame from video
      if (!bSuccess) //if not success, break loop
     {
        cout << "Cannot read a frame from video stream" << endl;
        break;
     }
     Mat grey;
     cvtColor(frame,grey,CV_BGR2GRAY);
     int width = frame.cols;
     int height = frame.rows;
     uchar *raw = (uchar *)grey.data;
     // wrap image data
     Image image(width, height, "Y800", raw, width * height);
     // scan the image for barcodes
     int n = scanner.scan(image);
     // extract results
     for(Image::SymbolIterator symbol = image.symbol_begin();
     symbol != image.symbol_end();
     ++symbol) {
         vector<Point> vp;
     // do something useful with results
         cout << "Codigo detectado en posicion: ("<<symbol->get_location_x(0)<<","<<symbol->get_location_y(0)<<")\nMensaje: "<< symbol->get_data()<<endl;
       int n = symbol->get_location_size();
       for(int i=0;i<n;i++){
         vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
       }
       RotatedRect r = minAreaRect(vp);
       Point2f pts[4];
       r.points(pts);
       for(int i=0;i<4;i++){
         line(frame,pts[i],pts[(i+1)%4],Scalar(0,255,0),3);
       }
       //cout<<"Angle: "<<r.angle<<endl;
     }
     imshow("Camara de RAIDER", frame); //show the frame in "MyVideo" window
     if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
     {
       cout << "esc key is pressed by user" << endl;
       break;
     }
   }
   return 0;
 }
