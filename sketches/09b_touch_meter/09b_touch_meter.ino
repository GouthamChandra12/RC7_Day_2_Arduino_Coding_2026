int baseline;

void setup() {
  Serial.begin(115200);
  delay(2000);
  // measure the untouched value 20 times and take the average
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Untouched value: " + String(baseline));
}

void loop() {
  int drop = baseline - touchRead(4);
  drop = constrain(drop, 0, baseline);
  int length = map(drop, 0, baseline, 0, 40);
  String bar = "";
  for (int i = 0; i < length; i++) {
    bar += "#";
  }
  Serial.println(bar);
  delay(100);
}
