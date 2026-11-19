int baseline;
bool wasTouched = false;

bool touched() {
  return touchRead(4) < baseline * 0.7;
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Touch pin 4 to roll the dice");
}

void loop() {
  bool now = touched();
  if (now && !wasTouched) {
    Serial.println("You rolled: " + String(random(1, 7)));
  }
  wasTouched = now;
  delay(50);
}
