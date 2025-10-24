#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Distance.hh"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Distance distance;
uint32_t walkIns = 0;

void setup() {
    Serial.begin(9600); 

    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.cp437(true);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("Walk-Ins:"));

  double dist = distance.measure();
  if(dist > 50 && dist < 100) {
    walkIns++;
  }

  display.setCursor(0, 20);
  display.println(walkIns);
  display.display();
  
  delay(20);
}

