String answers[] = {
  "Yes", "No", "Ask again",
  "Definitely", "Very doubtful",
  "Build it", "Make a model first"
};
const int N = 7;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Ask a question, press Enter");
}

void loop() {
  if (Serial.available()) {
    Serial.readStringUntil('\n');
    Serial.println(answers[random(0, N)]);
  }
}
