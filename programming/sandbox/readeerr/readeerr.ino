

void setup() {
  SerialUSB.begin();
  Serial3.begin(9600);
      pinMode(BOARD_LED_PIN, OUTPUT);

}
void loop() {
  if(Serial3.available()){
    SerialUSB.println(Serial3.read());
  }
 }

