#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280 bmp;

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BUTTON 2
#define LED 8
#define BUZZER 9

int page = 1;

unsigned long previousMillis = 0;
const unsigned long interval = 5000;

bool lastButtonState = HIGH;

void setup() {

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    while (1);

  if (!bmp.begin(0x76))
    while (1);

  display.clearDisplay();
}

void loop() {

  bool buttonState = digitalRead(BUTTON);

  if (lastButtonState == HIGH && buttonState == LOW) {

    page++;

    if (page > 3)
      page = 1;

    previousMillis = millis();

    delay(200);
  }

  lastButtonState = buttonState;

  if (millis() - previousMillis >= interval) {

    previousMillis = millis();

    page++;

    if (page > 3)
      page = 1;
  }

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  float pressure = bmp.readPressure() / 100.0;
  float altitude = bmp.readAltitude(1013.25);

  // Alerts
  if (temperature > 35 || humidity > 80) {

    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);

  } else {

    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Page ");
  display.print(page);
  display.print("/3");

  switch(page)
  {

    case 1:

      display.setCursor(0,15);
      display.println("Temperature");

      display.setTextSize(2);
      display.setCursor(0,28);
      display.print(temperature,1);
      display.print("C");

      display.setTextSize(1);
      display.setCursor(0,55);
      display.print("Humidity:");
      display.print(humidity,1);
      display.print("%");

      break;

    case 2:

      display.setTextSize(1);

      display.setCursor(0,15);
      display.println("Pressure");

      display.setTextSize(2);
      display.setCursor(0,28);
      display.print(pressure,0);
      display.print("hPa");

      display.setTextSize(1);
      display.setCursor(0,55);
      display.print("Alt:");
      display.print(altitude,1);
      display.print("m");

      break;

    case 3:

      display.setTextSize(1);

      display.setCursor(0,12);
      display.println("Weather Dashboard");

      display.setCursor(0,26);
      display.print("Temp:");
      display.print(temperature,1);
      display.print("C");

      display.setCursor(0,38);
      display.print("Hum :");
      display.print(humidity,1);
      display.print("%");

      display.setCursor(0,50);
      display.print("Pres:");
      display.print(pressure,0);

      display.setCursor(75,50);
      display.print("Alt:");
      display.print(altitude,0);

      break;
  }

  display.display();

  delay(500);
}