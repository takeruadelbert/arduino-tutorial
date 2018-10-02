int ledPin, delayTime;
void setup() {
  // put your setup code here, to run once:
  ledPin = 13;
  delayTime = 1000;
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}
