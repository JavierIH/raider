#include "../../libraries/raider/raider.h"
#include <iostream>
#include <zbar.h>

using namespace cv;

int main()
{

    Raider raider;

    raider.waitStart();


    int compass_reference=raider.getCompass();
    int compass_target=compass_reference;

    report("Referencia inicial: "+to_string(compass_reference));

    while(1){

        Mat input=raider.getFrame();

        string command=raider.findQR(input);

        if(command.empty()){
            report(INFO, "No detectado");
            // TODO
        }
        else if (command == "Turn45R"){
            raider.yes();
            report(RAIDER,"Código de 45 grados a la derecha");
            compass_target+=450;   // TODO revisar todos los signos
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(1,compass_target));
        }
        else if (command == "Turn45L"){
            raider.yes();
            report(OK,"Código de 45 grados a la izquierda");
            compass_target-=450;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(0,compass_target));
        }
        else if (command == "Turn90R"){
            raider.yes();
            report(RAIDER,"Código de 90 grados a la derecha");
            compass_target+=900;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(1,compass_target));
        }
        else if (command == "Turn90L"){
            raider.yes();
            report(RAIDER,"Código de 90 grados a la izquierda");
            compass_target-=900;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(0,compass_target));
        }
        else if (command == "Turn135R"){
            raider.yes();
            report(RAIDER,"Código de 135 grados a la derecha");
            compass_target+=1350;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(1,compass_target));
        }
        else if (command == "Turn135L"){
            raider.yes();
            report(RAIDER,"Código de 135 grados a la izquierda");
            compass_target-=1350;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(0,compass_target));
        }
        else if (command == "Turn180R"){
            raider.yes();
            report(RAIDER,"Código de 180 grados a la derecha");
            compass_target+=1800;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(1,compass_target));
        }
        else if (command == "Turn180L"){
            raider.yes();
            report(RAIDER,"Código de 180 grados a la izquierda");
            compass_target-=1800;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(raider.setDirection(0,compass_target));
        }
    }
}
