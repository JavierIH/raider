

void setup() {
  SerialUSB.begin();
  Serial3.begin(9600);
  pinMode(BOARD_LED_PIN, OUTPUT);

}
void loop() {
       digitalWrite(BOARD_LED_PIN, HIGH);

  if(Serial3.available()){
    SerialUSB.println((char)Serial3.read());
   digitalWrite(BOARD_LED_PIN, LOW);
   delay(1000);
   digitalWrite(BOARD_LED_PIN, HIGH);
   delay(1000);
   Serial3.flush();
  }


 }

