#include<iostream>

#include "../libraries/raider/raider.h"

using namespace std;


int main(){

    cout<<"\nGO!";
    raider Raider;
    Raider.getIR(1);
    while(1){
    int error=Raider.sendCommand(3);
	cout<<"\n\n\nEnviado un 3 ("<<error<<")"<<endl;
        sleep(1);
    }
    return 0;
}
