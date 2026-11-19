void shout(String word, int times) {
  for (int i = 0; i < times; i++) {
    Serial.println(word + "!");
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  shout("hello", 3);
  shout("architecture", 2);
}

void loop() {}
