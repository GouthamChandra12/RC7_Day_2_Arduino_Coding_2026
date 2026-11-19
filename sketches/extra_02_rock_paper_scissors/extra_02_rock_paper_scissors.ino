String names[] = {"rock", "paper", "scissors"};

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type r, p or s and press Enter");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    int you = -1;
    if (input == "r") you = 0;
    else if (input == "p") you = 1;
    else if (input == "s") you = 2;
    if (you == -1) {
      Serial.println("Type r, p or s");
      return;
    }
    int board = random(0, 3);
    Serial.println("You: " + names[you] + "   Board: " + names[board]);
    if (you == board) {
      Serial.println("Draw");
    } else if ((you + 1) % 3 == board) {
      Serial.println("Board wins");
    } else {
      Serial.println("You win");
    }
  }
}
