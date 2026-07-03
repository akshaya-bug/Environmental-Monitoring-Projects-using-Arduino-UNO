#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280 bmp;

void drawSun() {
  display.fillCircle(110, 12, 6, SSD1306_WHITE);
}

void drawCloud() {
  display.fillCircle(105, 12, 4, SSD1306_WHITE);
  display.fillCircle(112, 10, 5, SSD1306_WHITE);
  display.fillCircle(119, 12, 4, SSD1306_WHITE);
  display.fillRect(105, 12, 18, 6, SSD1306_WHITE);
}

void drawRain() {
  drawCloud();
  display.drawLine(108, 20, 106, 24, SSD1306_WHITE);
  display.drawLine(114, 20, 112, 24, SSD1306_WHITE);
  display.drawLine(120, 20, 118, 24, SSD1306_WHITE);
}

void setup() {

  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  if (!bmp.begin(0x76)) {
    if (!bmp.begin(0x77)) {
      display.setCursor(0,0);
      display.println("BMP280 Error");
      display.display();
      while(1);
    }
  }

  display.setTextSize(2);
  display.setCursor(10,20);
  display.println("WEATHER");
  display.display();

  delay(2000);
}

void loop() {

  float pressure = bmp.readPressure()/100.0;
  float altitude = bmp.readAltitude(1013.25);

  String weather;

  if(pressure > 1015)
    weather = "Sunny";

  else if(pressure >=1000)
    weather = "Normal";

  else
    weather = "Rain";

  // Serial Monitor
  Serial.print("Pressure : ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Altitude : ");
  Serial.print(altitude);
  Serial.println(" m");

  Serial.print("Weather : ");
  Serial.println(weather);

  Serial.println("---------------------");

  // OLED
  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.println("Weather Monitor");

  display.setCursor(0,15);
  display.print("Pressure:");
  display.print(pressure,1);
  display.println(" hPa");

  display.setCursor(0,30);
  display.print("Altitude:");
  display.print(altitude,1);
  display.println(" m");

  display.setCursor(0,48);
  display.print("Weather:");

  if(weather=="Sunny"){
    display.print(" Sunny");
    drawSun();
  }

  else if(weather=="Normal"){
    display.print(" Normal");
    drawCloud();
  }

  else{
    display.print(" Rain");
    drawRain();
  }

  display.display();

  delay(1000);
}