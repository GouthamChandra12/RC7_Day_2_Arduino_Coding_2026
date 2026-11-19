#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("RC7-board-yourname");   // change this name
  delay(2000);
  Serial.println("Pair your Android phone with RC7-board-yourname.");
  Serial.println("Then open a Bluetooth serial terminal app and connect.");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
}
