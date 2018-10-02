int led_white = 10;
int led_green = 11;
int led_red = 12;
int delay_time = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_white, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  run_blink();
}

void run_blink() {
  digitalWrite(led_white, HIGH);
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, HIGH);
  delay(delay_time);

  digitalWrite(led_white, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  delay(delay_time);
}
