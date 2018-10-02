int serial_monitor_baud = 9600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serial_monitor_baud);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
