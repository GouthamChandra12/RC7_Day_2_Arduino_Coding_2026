String name = "Ada";
int year = 2026;
float temp = 21.5;
bool awake = true;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Name: " + name);
  Serial.println("Year: " + String(year));
  Serial.println("Temp: " + String(temp));
  Serial.print("Awake: ");
  Serial.println(awake);
}

void loop() {}
