#include <opencv2/highgui/highgui.hpp>
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

        cvtColor(frame,frame,CV_BGR2GRAY);
        uchar *pointer = (uchar *)frame.data;

        Image image(frame.cols, frame.rows, "Y800", pointer, frame.cols*frame.rows);

        scanner.scan(image);

        string command;

        for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            command=symbol->get_data();
            report(INFO,"Marcador: "+command);
        }

        if(command.empty()) report(ERROR, "No detectado");
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

        imshow("MyVideo", frame); //show the frame in "MyVideo" window
    }
    return 0;
}

