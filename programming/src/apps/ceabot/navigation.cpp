#include "../../libraries/raider/raider.h"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    //Setup
    Raider raider;
    int state=0;


    //Ini

    //Algorithm
    while(1){
        Mat image = raider.getFrame();
        Vec2i way_result = raider.findWay(image);

        if(abs(way_result[0])>10){ // PARAMETRO DISTANCIA
            if(way_result[0]>0){
                report(OK,"E -> Paso lateral a la derecha");
                raider.stepRight();
            }
            if(way_result[0]<0){
                report(OK,"Q -> Paso lateral a la izquierda");
                raider.stepLeft();
            }
        }
        else{
            if(abs(way_result[1])>20){ // PARAMETRO ANGULO
                if(way_result[1]<0){
                    report(OK,"D -> Girar a la izquierda");
                    raider.turnLeft();
                }
                if(way_result[1]>0){
                    report(OK,"A -> Girar a la derecha");
                    raider.turnRight();
                }
            }
            else{
                report(OK,"S -> Avanza rapido recto");
                raider.run();
            }
        }
    }
}

