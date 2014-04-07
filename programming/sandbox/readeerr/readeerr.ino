

void setup() {
  SerialUSB.begin();
  Serial3.begin(115200);
}
void loop() {
  if(Serial3.available()){
    SerialUSB.println(Serial3.read());
  }
  SerialUSB.println("ok");
  delay(3000);
}

