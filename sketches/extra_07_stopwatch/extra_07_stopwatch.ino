bool running = false;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  delay(2000);
  Serial.println("Press BOOT to start and stop the stopwatch");
}

void loop() {
  if (digitalRead(0) == LOW) {
    if (!running) {
      running = true;
      startTime = millis();
      Serial.println("Started");
    } else {
      running = false;
      unsigned long elapsed = millis() - startTime;
      Serial.println("Time: " + String(elapsed / 1000.0, 2) + " s");
    }
    delay(300);
    while (digitalRead(0) == LOW) {}
  }
}
