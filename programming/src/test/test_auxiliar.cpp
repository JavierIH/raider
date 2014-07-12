
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../libraries/raider/raider.h"
#include "../libraries/eye/eye.h"
#include "../libraries/debug/debug.h"
#include <iostream>

int main()
{
    report(INFO,"Mensaje de informacion de color azul :|");
    report(ERROR,"Mensaje de error de color rojo :(");
    report(OK,"Mensaje de ok de color verde :)");
    report(WARNING,"Mensaje de warning de color amarillo :O");
    report("mensaje comun y moliente");

}

