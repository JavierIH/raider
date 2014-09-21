#include "debug.h"

void report(int type, std::string msg){

    switch ( type ) {
    case ERROR:
        if(DEBUG_LEVEL<=5)std::cout<<"\033[1;31m[ERROR]   "+msg+"\033[0m"<<endl;
        break;
    case RAIDER:
        if(DEBUG_LEVEL<=5)std::cout<<"\033[1;31m[RAIDER]\033[0m  \033[3;31m"+msg+"\033[0m"<<endl;
        break;
    case WARNING:
        if(DEBUG_LEVEL<=2)std::cout<<"\033[1;33m[WARNING]\033[0m \033[0;33m"+msg+"\033[0m"<<endl;
        break;
    case OK:
        if(DEBUG_LEVEL<=3)std::cout<<"\033[1;32m[OK]      "+msg+"\033[0m"<<endl;
        break;
    case MOVE:
        if(DEBUG_LEVEL<=3)std::cout<<"\033[1;32m[MOVE]\033[0m    "+msg<<endl;
        break;
    case STATE:
        if(DEBUG_LEVEL<=4)std::cout<<"\033[1;35m[STATE]\033[0m   "+msg<<endl;
        break;
    case INFO:
        if(DEBUG_LEVEL<=4)std::cout<<"\033[1;34m[INFO]   \033[0m \033[0;34m"+msg+"\033[0m"<<endl;
        break;
    default:
        if(DEBUG_LEVEL<=1)std::cout<<msg<<endl;
        break;
    }
}
void report(std::string msg){
    if(DEBUG_LEVEL<=1)std::cout<<msg<<endl;
}

void standardShow(cv::Mat image, string nombre){

    cv::Size size(640,480);
    resize(image,image,size);
    cv::imshow(nombre,image);
}



