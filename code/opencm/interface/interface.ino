#include "Servo.h"


byte input[3];
double init_time;
//double time;
int rw, id, reg, val=0;
char recv;

Servo head;


void setup(){
  Dxl.begin(1);
  head.attach(7);
  Serial3.begin(460800);
}

void loop(){
  if(Serial3.available()){   
    //init_time = micros();
    init_time=micros();
    while(Serial3.read() != 'M');
    for(int i=0; i<3 || (micros()-init_time)>100; ){
      if (Serial3.available()){
        input[i]=Serial3.read();
        i++;
      }
    }
    rw = input[0]>>7;
    id = input[0] % 128;
    reg = input[1]>>2;
    val = (input[1]%4)*256 + input[2];
    //time=micros() - init_time;
    
    if(rw==1){
      if (id==1) head.writeMicroseconds(val+1000);
      else Dxl.writeWord(id, reg, val);
    } 
    else{
      recv = Dxl.readByte(id, reg);
      Serial3.print(recv);
    }
  }
}
