#include <Preferences.h>

Preferences prefs;
int baseline;
unsigned long bestTime;

bool touched() {
  return touchRead(4) < baseline * 0.7;
}

bool bootPressed() {
  return digitalRead(0) == LOW;
}

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  prefs.begin("duel", false);
  bestTime = prefs.getULong("best", 99999);
  delay(2000);
  // do not touch pin 4 during this part
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Reaction duel. Player A: BOOT button. Player B: touch pin 4.");
  Serial.println("Best time on record: " + String(bestTime) + " ms");
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  if (bootPressed() || touched()) {
    Serial.println("Foul! Someone pressed too early.");
    delay(2000);
    return;
  }
  Serial.println("GO!");
  unsigned long start = millis();
  while (!bootPressed() && !touched()) {}
  unsigned long t = millis() - start;
  if (bootPressed()) {
    Serial.println("Player A wins in " + String(t) + " ms");
  } else {
    Serial.println("Player B wins in " + String(t) + " ms");
  }
  if (t < bestTime) {
    bestTime = t;
    prefs.putULong("best", bestTime);
    Serial.println("NEW RECORD! Saved.");
  }
  delay(2000);
}
