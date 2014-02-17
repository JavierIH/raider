#include <iostream>
#include <fstream>

using namespace std;

int main(){

	cout<<"Hola, Raider"<<endl;
	ifstream AIN0 ("/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN0");
	char a1 [10];
	AIN0.getline(a1,6);
	cout<<a1<<endl;
}
