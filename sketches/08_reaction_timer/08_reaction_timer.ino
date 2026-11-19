void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  Serial.println("GO! Press BOOT");
  unsigned long start = millis();
  while (digitalRead(0) == HIGH) {}
  unsigned long t = millis() - start;
  Serial.print("Reaction time: ");
  Serial.print(t);
  Serial.println(" ms");
  delay(2000);
}
