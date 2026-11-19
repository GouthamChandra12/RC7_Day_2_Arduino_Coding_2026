#include <Preferences.h>

Preferences prefs;
unsigned long best;

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  prefs.begin("reaction", false);          // open a small saved area called "reaction"
  best = prefs.getULong("best", 99999);    // read the saved best time (99999 if none yet)
  delay(2000);
  Serial.println("Best time on record: " + String(best) + " ms");
}

void loop() {
  Serial.println("Get ready...");
  delay(random(2000, 5000));
  Serial.println("GO!");
  unsigned long start = millis();
  while (digitalRead(0) == HIGH) {}
  unsigned long t = millis() - start;
  Serial.println(String(t) + " ms");
  if (t < best) {
    best = t;
    prefs.putULong("best", best);          // save it. It survives a reset.
    Serial.println("NEW HIGH SCORE! Saved.");
  }
  delay(2000);
}
