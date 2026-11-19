void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type a number and press Enter");
}

void loop() {
  if (Serial.available()) {
    int n = Serial.parseInt();
    while (Serial.available()) Serial.read();
    for (int i = 1; i <= 10; i++) {
      Serial.println(String(n) + " x " + String(i) + " = " + String(n * i));
    }
  }
}
