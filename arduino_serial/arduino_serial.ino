int led_status[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
  while (!Serial) {}
}

void loop() {
  // put your main code here, to run repeatedly:
  char buf[15];
  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', buf, 15);

    for (int i = 2; i < 14; i++) {
      led_status[i] = buf[i] - '0';
    }
  }

  for (int i = 2; i < 14; i++) {
    digitalWrite(i, led_status[i]);
  }
  delay(10);
}