void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Launch in...");
  for (int i = 10; i > 0; i--) {
    Serial.println(i);
    delay(500);
  }
  Serial.println("LIFT OFF!");
}

void loop() {}
