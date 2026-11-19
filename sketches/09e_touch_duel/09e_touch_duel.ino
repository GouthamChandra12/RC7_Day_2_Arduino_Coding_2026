int baseA;
int baseB;

int calibrate(int pin) {
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(pin);
    delay(20);
  }
  return sum / 20;
}

bool touchedA() { return touchRead(4) < baseA * 0.7; }
bool touchedB() { return touchRead(13) < baseB * 0.7; }

void setup() {
  Serial.begin(115200);
  delay(2000);
  baseA = calibrate(4);
  baseB = calibrate(13);
  Serial.println("Touch duel. Player A: pin 4. Player B: pin 13.");
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  if (touchedA() || touchedB()) {
    Serial.println("Foul! Someone touched too early.");
    delay(2000);
    return;
  }
  Serial.println("GO!");
  unsigned long start = millis();
  while (!touchedA() && !touchedB()) {}
  unsigned long t = millis() - start;
  if (touchedA() && touchedB()) {
    Serial.println("Draw!");
  } else if (touchedA()) {
    Serial.println("Player A wins in " + String(t) + " ms");
  } else {
    Serial.println("Player B wins in " + String(t) + " ms");
  }
  delay(2000);
}
