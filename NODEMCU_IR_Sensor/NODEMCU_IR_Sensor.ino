#define irpin D2

void setup() {
pinMode(irpin,INPUT);
Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(irpin));
  delay(100);
}
