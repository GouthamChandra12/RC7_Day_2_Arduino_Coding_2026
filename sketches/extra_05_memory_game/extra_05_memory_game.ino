int sequenceLen = 3;
String sequence = "";

void newRound() {
  sequence = "";
  for (int i = 0; i < sequenceLen; i++) {
    sequence += String(random(1, 10));
  }
  Serial.println("Remember: " + sequence);
  delay(2000 + sequenceLen * 500);
  for (int i = 0; i < 30; i++) {
    Serial.println();   // push the numbers off the screen
  }
  Serial.println("Type the digits you saw:");
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Memory game");
  newRound();
}

void loop() {
  if (Serial.available()) {
    String answer = Serial.readStringUntil('\n');
    answer.trim();
    if (answer == sequence) {
      Serial.println("Correct! One digit longer.");
      sequenceLen++;
    } else {
      Serial.println("Wrong. It was " + sequence + ". Back to 3.");
      sequenceLen = 3;
    }
    newRound();
  }
}
