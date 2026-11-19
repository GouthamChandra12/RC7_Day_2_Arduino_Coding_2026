int baseline;
unsigned long taps[3];
int count = 0;
bool wasTouched = false;

// The secret: 500 ms between tap 1 and 2, 1500 ms between tap 2 and 3
const int gap1 = 500;
const int gap2 = 1500;
const int slack = 300;   // how far off you are allowed to be

bool touched() {
  return touchRead(4) < baseline * 0.7;
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += touchRead(4);
    delay(20);
  }
  baseline = sum / 20;
  Serial.println("Knock the secret on pin 4");
}

void loop() {
  bool now = touched();
  if (now && !wasTouched) {
    taps[count] = millis();
    count++;
    if (count == 3) {
      long a = taps[1] - taps[0];
      long b = taps[2] - taps[1];
      if (abs(a - gap1) < slack && abs(b - gap2) < slack) {
        Serial.println("ACCESS GRANTED");
      } else {
        Serial.println("Wrong knock: " + String(a) + " ms, " + String(b) + " ms");
      }
      count = 0;
    }
  }
  if (count > 0 && millis() - taps[count - 1] > 3000) {
    Serial.println("Too slow. Start again.");
    count = 0;
  }
  wasTouched = now;
  delay(30);
}
