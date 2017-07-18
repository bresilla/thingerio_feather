#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>

#define USERNAME "fedestanza"
#define DEVICE_ID "Potentiometer"
#define DEVICE_CREDENTIAL "Potentiometer"

#define SSID "LABFY"
#define SSID_PASSWORD "national"
int newValue = 0;

ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  pinMode(A0, INPUT);
  // LDR resource
  thing["LDR"] >> [](pson & out) {
    out = (unsigned int)newValue;
  };
}

void loop() {
  newValue = map(analogRead(A0), 0, 1000, 0, 13000);
  thing.handle();
}
