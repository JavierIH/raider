#include "../../libraries/raider/raider.h"
#include <iostream>

#define FW_ANGLE 20
#define FW_DISTANCE 10
#define FL_ANGLE 20
#define FL_DISTANCE 30

using namespace std;
using namespace cv;

int main()
{
    //Setup
    Raider raider;
    int state=0;
    int flag_line=0;

    report(INFO,"¡Comienza la prueba!");

    //Algorithm
    while(1){
        // TODO meter inicializaciones, tiempo de espera, boton...
        Mat image = raider.getFrame();
        switch (state) {

        case 0:{
            //INICIO
            report(STATE, "Estado 0 (Inicio)");
            raider.yes();
            report(MOVE,"S -> Avanti avanti");
            raider.run();
            state=1;
        }break;

        case 1:{
            report(STATE, "Estado 1 (Avance)");
            Vec2i way_result = raider.findWay(image);

            if(abs(way_result[0])>=FW_DISTANCE){
                if(way_result[0]>0){
                    report(MOVE,"E -> Paso lateral a la derecha");
                    raider.stepRight();
                }
                else if(way_result[0]<0){
                    report(MOVE,"Q -> Paso lateral a la izquierda");
                    raider.stepLeft();
                }
            }
            else if(abs(way_result[1])>=FW_ANGLE){
                if(way_result[1]<0){
                    report(MOVE,"D -> Girar a la izquierda");
                    raider.turnLeft();
                }
                else if(way_result[1]>0){
                    report(MOVE,"A -> Girar a la derecha");
                    raider.turnRight();
                }
            }
            else{
                report(MOVE,"S -> Avanza rapido recto");
                raider.run();
            }
            if(!flag_line) state=2; // -> findLine
            else state=1; // -> findWay
        }break;

        case 2:{
            report(STATE, "Estado 2 (Busqueda de linea)");
            Vec2i line_result = raider.findLine(image);

            if (line_result[0]==-1){
                report("No se encuentra la linea");
                state=1; // -> findWay
                break;
            }
            else if(abs(line_result[1]<=FL_ANGLE)){
                report("Linea de frente (La cruzo)");
                raider.walk(); // TODO cerciorarse de que cruza
                raider.walk();
                flag_line=true;
                state=3; // -> turnBack
                break;
            }
            else{
                report("Me preparo para cruzar la linea");
                if(line_result[1]>0){
                    report(MOVE,"D -> Girar a la izquierda");
                    raider.turnLeft();
                }
                else if(line_result[1]<0){
                    report(MOVE,"A -> Girar a la derecha");
                    raider.turnRight();
                }
                if(line_result[0]<=FL_DISTANCE){
                    report("Linea cercana (La cruzo)");
                    report(MOVE,"W -> Avanzar recto");
                    raider.walk(); // TODO cerciorarse de que cruza
                    raider.walk();
                    flag_line=true;
                    state=3; // -> turnBack
                    break;
                }
                else{
                    report("No he cruzado, vuelvo a intentarlo");
                    state=2; // -> findLine
                    break;
                }
            }
        }break;

        case 3:
            report(STATE, "Estado 3 (Vuelta a casa)");
            report("Inicio secuencia para dar la vuelta");
            report(MOVE,"A -> Girar a la derecha X4");
            raider.turnRight();
            raider.turnRight();
            raider.turnRight();
            raider.turnRight(); // TODO meter brujula

            state=1;
            break;
        default:
            state=1;
            break;
        } //swicht
    }//while
}//main
