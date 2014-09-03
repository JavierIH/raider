#include "../../libraries/raider/raider.h"
#include <iostream>
#include <zbar.h>

using namespace cv;

int main()
{

    Raider raider;

    raider.waitStart();

    raider.setCompassTolerance(200);

    int compass_reference=raider.getCompass();
    int compass_target=compass_reference;

    report("Referencia inicial: "+to_string(compass_reference));

    int cont=0;

    while(1){

        Mat input=raider.getFrame();

        raider.lookUp();
        usleep(300000);
        string command=raider.findQR(input);
        raider.endLookUp();

        if(command.empty()){
            report(INFO, "No detectado");
            command=raider.findQR(input);
            cont++;
            if(cont>5){
                cont=0;
                raider.turnL();
                raider.setDirection(compass_target);
            }
        }
        else if (command == "Turn45R"){
            raider.yes();
            report(RAIDER,"Código de 45 grados a la derecha");
            compass_target+=450;   // TODO revisar todos los signos
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(1,compass_target));
        }
        else if (command == "Turn45L"){
            raider.yes();
            report(OK,"Código de 45 grados a la izquierda");
            compass_target-=450;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(0,compass_target));
        }
        else if (command == "Turn90R"){
            raider.yes();
            report(RAIDER,"Código de 90 grados a la derecha");
            compass_target+=900;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(1,compass_target));
        }
        else if (command == "Turn90L"){
            raider.yes();
            report(RAIDER,"Código de 90 grados a la izquierda");
            compass_target-=900;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(0,compass_target));
        }
        else if (command == "Turn135R"){
            raider.yes();
            report(RAIDER,"Código de 135 grados a la derecha");
            compass_target+=1350;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(1,compass_target));
        }
        else if (command == "Turn135L"){
            raider.yes();
            report(RAIDER,"Código de 135 grados a la izquierda");
            compass_target-=1350;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(0,compass_target));
        }
        else if (command == "Turn180R"){
            raider.yes();
            report(RAIDER,"Código de 180 grados a la derecha");
            compass_target+=1800;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(1,compass_target));
        }
        else if (command == "Turn180L"){
            raider.yes();
            report(RAIDER,"Código de 180 grados a la izquierda");
            compass_target-=1800;
            if(compass_target>3600) compass_target-=3600;
            if(compass_target<0) compass_target+=3600;
            while(!raider.setDirection(0,compass_target));
        }
    }
}
