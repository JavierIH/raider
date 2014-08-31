#include "../../libraries/raider/raider.h"
#include <iostream>
#include <zbar.h>

using namespace cv;

int main()
{

    Raider raider;

    int compass_reference=raider.getCompass();
    int compass_target=compass_reference;


    while(1){

        Mat input=raider.getFrame();

        string command=raider.findQR(input);

        if(command.empty()){
            report(ERROR, "No detectado");
            // TODO
        }
        else if (command == "Turn45R"){
            raider.yes();
            report(OK,"Girar 45 grados a la derecha");
            compass_target+=450;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(1,compass_target);
        }
        else if (command == "Turn45L"){
            raider.yes();
            report(OK,"Girar 45 grados a la izquierda");
            compass_target-=450;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(0,compass_target);
        }
        else if (command == "Turn90R"){
            raider.yes();
            report(OK,"Girar 90 grados a la derecha");
            compass_target+=900;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(1,compass_target);
        }
        else if (command == "Turn90L"){
            raider.yes();
            report(OK,"Girar 90 grados a la izquierda");
            compass_target-=900;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(0,compass_target);
        }
        else if (command == "Turn135R"){
            raider.yes();
            report(OK,"Girar 135 grados a la derecha");
            compass_target+=1350;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(1,compass_target);
        }
        else if (command == "Turn135L"){
            raider.yes();
            report(OK,"Girar 135 grados a la izquierda");
            compass_target-=1350;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(0,compass_target);
        }
        else if (command == "Turn180R"){
            raider.yes();
            report(OK,"Girar 180 grados a la derecha");
            compass_target+=1800;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(1,compass_target);
        }
        else if (command == "Turn180L"){
            raider.yes();
            report(OK,"Girar 180 grados a la izquierda");
            compass_target-=1800;
            if(compass_target>3600) compass_target-=3600;
            raider.setDirection(0,compass_target);
        }
    }
}
