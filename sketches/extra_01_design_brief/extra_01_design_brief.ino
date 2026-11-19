String sites[] = {"a car park", "a rooftop", "a canal bank", "a railway arch", "a school playground"};
String programmes[] = {"a library", "a public bath", "a weather station", "a market hall", "a night shelter"};
String ideas[] = {"made only of timber", "that works without electricity", "that changes with the seasons", "with no walls", "that you can carry"};

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Press Enter for a design brief");
}

void loop() {
  if (Serial.available()) {
    while (Serial.available()) Serial.read();
    Serial.println("Design " + programmes[random(0, 5)] + " on " + sites[random(0, 5)] + ", " + ideas[random(0, 5)] + ".");
  }
}
