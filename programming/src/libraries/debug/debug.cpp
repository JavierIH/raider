#include "debug.h"

void report(int type, std::string msg){

    switch ( type ) {
    case ERROR:
        std::cout<<"\033[1;31m[ERROR] "+msg+"\033[0m"<<endl;
        break;
    case WARNING:
        std::cout<<"\033[1;30m[WARNING] "+msg+"\033[0m"<<endl;
        break;
    case OK:
        std::cout<<"\033[1;32m[OK] "+msg+"\033[0m"<<endl;
        break;
    case INFO:
        std::cout<<"\033[1;34m[INFO] "+msg+"\033[0m"<<endl;
        break;
    default:
        std::cout<<msg<<endl;
        break;
    }
}
void report(std::string msg){
    std::cout<<msg<<endl;
}



