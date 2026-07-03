#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 8;
const int buzzerPin = 9;

const float TEMP_LIMIT = 30.0;     // Temperature Threshold
const float HUM_LIMIT = 70.0;      // Humidity Threshold

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  dht.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10,20);
  display.println("ENV");
  display.setCursor(5,42);
  display.println("MONITOR");
  display.display();

  delay(2000);
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    return;
  }

  display.clearDisplay();
  display.setTextSize(1);

  if (temp > TEMP_LIMIT) {

    digitalWrite(ledPin, HIGH);

    // Fast buzzer pattern
    tone(buzzerPin, 2000);
    delay(200);
    noTone(buzzerPin);
    delay(100);

    display.setCursor(0,10);
    display.println("HIGH TEMPERATURE");
    display.setCursor(25,25);
    display.println("ALERT!");
    display.setCursor(0,48);
    display.print("Temp: ");
    display.print(temp);
    display.print((char)247);
    display.print("C");
  }

  else if (hum > HUM_LIMIT) {

    digitalWrite(ledPin, LOW);

    // Slow buzzer pattern
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
    delay(300);

    display.setCursor(5,15);
    display.println("HIGH");
    display.setCursor(5,28);
    display.println("HUMIDITY!");
    display.setCursor(0,48);
    display.print("Humidity: ");
    display.print(hum);
    display.print("%");
  }

  else {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    display.setCursor(0,0);
    display.println("Environment OK");

    display.setCursor(0,20);
    display.print("Temp: ");
    display.print(temp);
    display.print((char)247);
    display.println("C");

    display.setCursor(0,38);
    display.print("Humidity: ");
    display.print(hum);
    display.println("%");
  }

  display.display();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C   ");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  delay(1000);
}