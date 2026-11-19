int code[3];
int tries = 0;

void newCode() {
  for (int i = 0; i < 3; i++) {
    code[i] = random(0, 10);
  }
  tries = 0;
}

void setup() {
  Serial.begin(115200);
  newCode();
  delay(2000);
  Serial.println("Crack the 3 digit code. Type three digits, like 482.");
}

void loop() {
  if (Serial.available()) {
    String guess = Serial.readStringUntil('\n');
    guess.trim();
    if (guess.length() != 3) {
      Serial.println("Type exactly three digits.");
      return;
    }
    tries++;
    int right = 0;
    for (int i = 0; i < 3; i++) {
      if (guess[i] - '0' == code[i]) right++;
    }
    Serial.println(String(right) + " digit(s) in the right place");
    if (right == 3) {
      Serial.println("Cracked in " + String(tries) + " tries! New code...");
      newCode();
    }
  }
}
