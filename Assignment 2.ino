#define LED_PIN    13
#define SENSOR_PIN A0

#define BRIGHTNESS_THRESHOLD 900

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  int state = (sensorValue <= BRIGHTNESS_THRESHOLD) ? HIGH : LOW;
  digitalWrite(LED_PIN, state);
}