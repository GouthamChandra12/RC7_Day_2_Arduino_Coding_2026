void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("What is your name?");
}

void loop() {
  if (Serial.available()) {
    String name = Serial.readStringUntil('\n');
    name.trim();
    Serial.println("Hello, " + name + "!");
    int n = name.length();
    Serial.print("Your name has ");
    Serial.print(n);
    Serial.println(" letters.");
  }
}
