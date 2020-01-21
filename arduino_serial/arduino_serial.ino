int _length = 0;
int _pin_states[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  while(!Serial) {}

  _length = sizeof(_pin_states) / sizeof(int);
  
  for (int i = 2; i < _length; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  char buf[_length];
  if (Serial.available() > 0) {
    int s = Serial.readBytesUntil('\n', buf, _length);
    for (int i = 0; i < _length; i++) {
      _pin_states[i] = buf[i] - '0';
    }
  }
  
  for (int i = 2; i < _length; i++) {
    digitalWrite(i, _pin_states[i]);
  }
  delay(10);
}
