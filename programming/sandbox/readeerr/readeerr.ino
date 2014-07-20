

void setup() {
  SerialUSB.begin();
  Serial1.begin(9600);
  pinMode(BOARD_LED_PIN, OUTPUT);

}
void loop() {
       digitalWrite(BOARD_LED_PIN, HIGH);

  if(Serial1.available()){
    SerialUSB.println(Serial1.read());
   digitalWrite(BOARD_LED_PIN, LOW);
   delay(1000);
   digitalWrite(BOARD_LED_PIN, HIGH);
   delay(1000);
   Serial1.flush();
  }


 }

