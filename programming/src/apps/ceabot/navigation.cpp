#include "../../libraries/raider/raider.h"
#include <iostream>
#define FW_ANGLE 20
#define FW_DISTANCE 16
#define FL_ANGLE 15
#define FL_DISTANCE 30
using namespace std;
using namespace cv;
int main()
{
    //Setup
    Raider raider;
    int state=0;
    int flag_line=0;
    int contador=0;
    raider.setCompassTolerance(500);
    raider.waitStart();
    const int reference_angle=raider.getCompass();
    int target_direction=reference_angle;
    report(INFO,"Cuenta atrás!");
    report(INFO,"5...");
    usleep(1000000);
    report(INFO,"4...");
    usleep(1000000);
    report(INFO,"3...");
    usleep(1000000);
    report(INFO,"2...");
    usleep(1000000);
    report(INFO,"1...");
    usleep(1000000);
    report(INFO,"¡Comienza la prueba!");
    //Algorithm
    while(1){
        // TODO meter inicializaciones, tiempo de espera, boton...
        raider.look();
        usleep(300000);
        Mat image = raider.getFrame();
        //imshow("image",image);
        cv::Size size(160,120);
        resize(image,image,size);
        switch (state) {
        case 0:{
            //INICIO
            report(STATE, "Estado 0 (Inicio)");
            raider.yes();
            report(MOVE,"S -> Avanti avanti");
            raider.getUp();
            raider.run();
            state=1;
        }break;
        case 1:{
            report(STATE, "Estado 1 (Avance)");
            Vec2i way_result = raider.findWay(image);
            if(abs(way_result[0])>=FW_DISTANCE){
                if(way_result[0]>0){
                    report(MOVE,"E -> Paso lateral a la derecha");
                    raider.getUp();
                    raider.stepR();
                    contador=0;
                }
                else if(way_result[0]<0){
                    report(MOVE,"Q -> Paso lateral a la izquierda");
                    raider.getUp();
                    raider.stepL();
                    contador=0;
                }
            }
            else if(abs(way_result[1])>=FW_ANGLE){
                if(way_result[1]<0){
                    report(MOVE,"D -> Girar a la izquierda");
                    raider.getUp();
                    raider.turnL();
                    contador=0;
                }
                else if(way_result[1]>0){
                    report(MOVE,"A -> Girar a la derecha");
                    raider.getUp();
                    raider.turnR();
                    contador=0;
                }
            }
            else{
                report(MOVE,"S -> Avanza rapido recto");
                raider.getUp();
                raider.run();
                contador++;
                if(contador==3) while(!raider.setDirection(target_direction));
            }
            if(!flag_line) state=2; // -> findLine
            else state=1; // -> findWay
        }break;
        case 2:{
            report(STATE, "Estado 2 (Busqueda de linea)");
            raider.getUp();
            raider.look();
            Vec2i line_result = raider.findLine(image);
            report(OK, "LINEA result "+to_string(line_result[0])+"__"+to_string(line_result[1]));
            if (line_result[0]==-1){
                report("No se encuentra la linea");
                state=1; // -> findWay
                break;
            }
            else{
                report(RAIDER,"Voy a cruzar la linea");
                while(!raider.setDirection(target_direction));
                raider.run();
                raider.run();
                raider.run();
                raider.run();
                state=3;
            }
        }break;
        case 3:
            report(STATE, "Estado 3 (Vuelta a casa)");
            report("Inicio secuencia para dar la vuelta");
            report(MOVE,"A -> Girar a la derecha");
            raider.getUp();
            raider.turnL();
            raider.turnL();
            raider.turnL();
            raider.turnL();
            target_direction=reference_angle+1800;
            if(target_direction>3600) target_direction-=3600;
            while(!raider.setDirection(target_direction));
            raider.turnR(); // TODO meter brujula
            flag_line=1;
            state=1;
            break;
        default:
            state=1;
            break;
        } //swicht
        //waitKey(0);
    }//while
}//main
