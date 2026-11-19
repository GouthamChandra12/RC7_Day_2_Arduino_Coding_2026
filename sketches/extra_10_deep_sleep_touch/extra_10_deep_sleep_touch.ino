RTC_DATA_ATTR int wakeCount = 0;   // this value survives deep sleep
const int threshold = 40;          // set this between your untouched and touched values

void setup() {
  Serial.begin(115200);
  delay(2000);
  wakeCount++;
  Serial.println("Wake number " + String(wakeCount));
  Serial.println("Going to sleep in 3 seconds. Touch pin 4 to wake me.");
  delay(3000);
  touchSleepWakeUpEnable(4, threshold);
  esp_deep_sleep_start();
}

void loop() {}
