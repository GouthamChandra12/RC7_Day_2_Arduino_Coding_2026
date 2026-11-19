String letters = "abcdefghijklmnopqrstuvwxyz";
String morse[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Type some words and press Enter");
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    text.trim();
    text.toLowerCase();
    for (int i = 0; i < text.length(); i++) {
      char c = text[i];
      int place = letters.indexOf(c);
      if (place >= 0) {
        Serial.print(morse[place] + " ");
      } else if (c == ' ') {
        Serial.print(" /  ");
      }
    }
    Serial.println();
  }
}
