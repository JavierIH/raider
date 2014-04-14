//Testing

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){

	int value;
	char a1 [5];
	for(int i=0; i<20; i++){
		ifstream AIN0 ("/sys/bus/platform/drivers/bone-iio-helper/helper.15/AIN0");
		AIN0.read(a1,5);
		value = atoi(a1);
		cout<<value<<endl;
		AIN0.close();
		sleep(1);
	}
}
