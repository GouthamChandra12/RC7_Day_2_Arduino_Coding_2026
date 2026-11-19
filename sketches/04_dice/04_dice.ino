void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  delay(2000);
  Serial.println("Press BOOT to roll the dice");
}

void loop() {
  if (digitalRead(0) == LOW) {
    Serial.print("You rolled: ");
    Serial.println(random(1, 7));
    delay(300);
    while (digitalRead(0) == LOW) {}
  }
}
