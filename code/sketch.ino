// Smart Home Automation System - ESP32 (Wokwi)
// Sensors: DHT22 (temperature), LDR (light), PIR (motion)
// Outputs: Light (GPIO 26), Fan (GPIO 27)

#include <DHT.h>

#define DHTPIN     15
#define DHTTYPE    DHT22
#define LDR_PIN    34
#define PIR_PIN    13
#define LIGHT_PIN  26
#define FAN_PIN    27

const int   DARK_THRESHOLD = 2000;   // higher value = darker
const float TEMP_THRESHOLD = 30.0;   // fan ON above this (deg C)
const unsigned long LIGHT_HOLD_MS = 10000; // light stays on 10s after motion

DHT dht(DHTPIN, DHTTYPE);
unsigned long lastMotion = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  dht.begin();
  Serial.println("Smart Home Automation System started");
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  int   ldr  = analogRead(LDR_PIN);
  bool  motion = digitalRead(PIR_PIN) == HIGH;
  bool  isDark = ldr > DARK_THRESHOLD;

  if (motion) lastMotion = millis();

  bool lightOn = isDark && lastMotion != 0 && (millis() - lastMotion < LIGHT_HOLD_MS);
  digitalWrite(LIGHT_PIN, lightOn ? HIGH : LOW);

  bool fanOn = !isnan(temp) && temp > TEMP_THRESHOLD;
  digitalWrite(FAN_PIN, fanOn ? HIGH : LOW);

  Serial.printf("Temp: %.1f C | Hum: %.1f %% | LDR: %d (%s) | Motion: %s | Light: %s | Fan: %s\n",
                temp, hum, ldr, isDark ? "DARK" : "BRIGHT",
                motion ? "YES" : "NO", lightOn ? "ON" : "OFF", fanOn ? "ON" : "OFF");

  delay(1000);
}
