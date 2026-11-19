int secret;
int tries = 0;

void setup() {
  Serial.begin(115200);
  secret = random(1, 101);
  delay(2000);
  Serial.println("Guess my number, 1 to 100");
}

void loop() {
  if (Serial.available()) {
    int guess = Serial.parseInt();
    while (Serial.available()) Serial.read();
    tries++;
    if (guess < secret) Serial.println("Too low");
    else if (guess > secret) Serial.println("Too high");
    else {
      Serial.println("Got it in " + String(tries));
      secret = random(1, 101);
      tries = 0;
    }
  }
}
