int led_pins[] = {10, 11, 12};
char types[2][10] = {"HIGH", "LOW"};
int delay_time;

void setup() {
  // put your setup code here, to run once:
  delay_time = 500; // 0.5 seconds
  Serial.begin(9600);
  for(int i = 0; i < sizeof(led_pins); i++) {
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  run_blink();
}

void run_blink() {
  // loop to set all leds to HIGH
  for(int i = 0; i < sizeof(led_pins); i++) {
    digitalWrite(led_pins[i], types[0]);
  }
  delay(delay_time);

  // loop to set all leds to LOW
  for(int i = 0; i < sizeof(led_pins); i++) {
    digitalWrite(led_pins[i], types[1]);
  }
  delay(delay_time);
}
