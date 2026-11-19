void setup() {
  Serial.begin(115200);   // open the line to the laptop
  delay(2000);            // wait 2 seconds so the Serial Monitor is ready
  Serial.println("Hello, board!");
}

void loop() {
  Serial.println("I am alive");
  delay(1000);            // wait 1 second
}
