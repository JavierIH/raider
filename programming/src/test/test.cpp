#include<iostream>

#include "../libraries/raider/raider.h"

using namespace std;


int main(){

    cout<<"\nGO!";
    raider Raider;
    Raider.getIR(1);
    //while(1){
        Raider.sendCommand('w');
        //sleep(1);
    //}
    return 0;
}
