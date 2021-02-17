#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TM1637.h>

#define CLK 4
#define DIO 3
#define oneWireBus 2

TM1637 display(CLK, DIO);
OneWire oneWire(oneWireBus);
DallasTemperature tempSens(&oneWire);

int speeker A0;
float temperature;

void setup() {
  Serial.begin(9600);
  tempSens.begin();
  display.begin();
  display.setBrightness(4);
  pinMode(speeker, OUTPUT);
  tone(speeker, 500);
  delay(500);
  tone(speeker, 0);
}

void loop() {
  temperature = tempSens.getTempCByIndex(0);
  tempSens.requestTemperatures();
  display.display(temperature);
  delay(1000);
}