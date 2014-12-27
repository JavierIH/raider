#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../libraries/debug/debug.h"

int configurePin(int pin, bool mode){

    FILE *file = NULL;
    char value[4], gpioID[4], gpioDirection[64];
    sprintf(gpioID, "%d", pin);
    sprintf(gpioDirection, "/sys/class/gpio/gpio%d/direction", pin);

    // Export the pin
    if ((file = fopen("/sys/class/gpio/export", "ab")) == NULL){
      report(ERROR,"Unable to export GPIO pin");
      return -1;
    }
    strcpy(value, gpioID);
    fwrite(&value, sizeof(char), 2, file);
    fclose(file);

    // Set direction of the pin to an output //mode
    if ((file = fopen(gpioDirection, "rb+")) == NULL){
      report(ERROR,"Unable to open direction handle");
      return -1;
    }
    
    if(mode){ 
        strcpy(value,"in");
        fwrite(&value, sizeof(char), 2, file);
    }
    else{
        strcpy(value,"out");
        fwrite(&value, sizeof(char), 3, file);
    }
    
    fclose(file);
}

int setPin(int pin, bool state){

    FILE *file = NULL;
    char value[4], gpioID[4], gpioState[4], gpioValue[64];
    sprintf(gpioID, "%d", pin);
    sprintf(gpioState, "%d", state);
    sprintf(gpioValue, "/sys/class/gpio/gpio%d/value", pin);

    // Set output to high
    if ((file = fopen(gpioValue, "rb+")) == NULL){
      report(ERROR,"Unable to open value handle\n");
      return 1;
    }
    
    strcpy(value, gpioState); // Set value high
    fwrite(&value, sizeof(char), 1, file);
    fclose(file);
}

int getPin(int pin){
    
    FILE *file = NULL;
    char value[4], gpioID[4], gpioState[4], gpioValue[64];
    sprintf(gpioID, "%d", pin);
    //sprintf(gpioState, "%d", state);
    sprintf(gpioValue, "/sys/class/gpio/gpio%d/value", pin);

    if ((file = fopen(gpioValue, "rb")) == NULL){
      report(ERROR,"Unable to open value handle\n");
      return 1;
    }
    

    fwrite(&value, sizeof(char), 1, file);
    fclose(file);
    
    return 0;
}
int destroyPin();

int main() {

  int GPIOPin=60, /* GPIO1_28 or pin 12 on the P9 header */ times=10;

  printf("\nStarting GPIO output program\n");
  FILE *myOutputHandle = NULL;
  char setValue[4], GPIOString[4], GPIOValue[64], GPIODirection[64];
  sprintf(GPIOString, "%d", GPIOPin);
  sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", GPIOPin);
  sprintf(GPIODirection, "/sys/class/gpio/gpio%d/direction", GPIOPin);

  // Export the pin
  if ((myOutputHandle = fopen("/sys/class/gpio/export", "ab")) == NULL){
    printf("Unable to export GPIO pin\n");
    return 1;
  }
  strcpy(setValue, GPIOString);
  fwrite(&setValue, sizeof(char), 2, myOutputHandle);
  fclose(myOutputHandle);

  // Set direction of the pin to an output
  if ((myOutputHandle = fopen(GPIODirection, "rb+")) == NULL){
    printf("Unable to open direction handle\n");
    return 1;
  }
  strcpy(setValue,"out");
  fwrite(&setValue, sizeof(char), 3, myOutputHandle);
  fclose(myOutputHandle);

  for(int i=0; i<times; i++){
    // Set output to high
    if ((myOutputHandle = fopen(GPIOValue, "rb+")) == NULL){
      printf("Unable to open value handle\n");
      return 1;
    }
    strcpy(setValue, "1"); // Set value high
    fwrite(&setValue, sizeof(char), 1, myOutputHandle);
    fclose(myOutputHandle);
    sleep(1); // wait for 1 sec

    // Set output to low
    if ((myOutputHandle = fopen(GPIOValue, "rb+")) == NULL){
      printf("Unable to open value handle\n");
      return 1;
    }
    strcpy(setValue, "0"); // Set value low
    fwrite(&setValue, sizeof(char), 1, myOutputHandle);
    fclose(myOutputHandle);
    sleep(1); // wait for 1 sec

  }

  // Unexport the pin
  if ((myOutputHandle = fopen("/sys/class/gpio/unexport", "ab")) == NULL) {
    printf("Unable to unexport GPIO pin\n");
    return 1;
  }
  strcpy(setValue, GPIOString);
  fwrite(&setValue, sizeof(char), 2, myOutputHandle);
  fclose(myOutputHandle);
  printf("\nCompleted GPIO output program\n");

  return 0;
}
