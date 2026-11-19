int room = 0;   // 0 lobby, 1 atrium, 2 roof, 3 basement
String roomNames[] = {"Lobby", "Atrium", "Roof", "Basement"};

void describe() {
  Serial.println("--- " + roomNames[room] + " ---");
  if (room == 0) Serial.println("A cold lobby. Go n to the atrium, or d down to the basement.");
  if (room == 1) Serial.println("A tall atrium full of light. Go s back to the lobby, or u up to the roof.");
  if (room == 2) Serial.println("The roof. The whole city is below you. You found the best view. Go d to come down.");
  if (room == 3) Serial.println("A damp basement with one flickering lamp. Go u back up to the lobby.");
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Building tour. Type n, s, u or d and press Enter.");
  describe();
}

void loop() {
  if (Serial.available()) {
    String c = Serial.readStringUntil('\n');
    c.trim();
    int next = room;
    if (room == 0 && c == "n") next = 1;
    else if (room == 0 && c == "d") next = 3;
    else if (room == 1 && c == "s") next = 0;
    else if (room == 1 && c == "u") next = 2;
    else if (room == 2 && c == "d") next = 1;
    else if (room == 3 && c == "u") next = 0;
    if (next == room) {
      Serial.println("You cannot go that way.");
    } else {
      room = next;
      describe();
    }
  }
}
