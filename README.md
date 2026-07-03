# Environmental-Monitoring-Projects-using-Arduino-UNO
# 🌦️ Environmental Monitoring Projects using Arduino UNO

A collection of four Arduino-based environmental monitoring projects developed using the **DHT11 Temperature & Humidity Sensor**, **BMP280 Pressure & Altitude Sensor**, and **SSD1306 OLED Display**. These projects demonstrate sensor interfacing, environmental data visualization, weather estimation, and OLED-based user interfaces.

---

# 📌 Projects Included

- 🌡️ Project 1 – Room Comfort Meter
- ⛰️ Project 2 – Pressure & Altitude Display
- 🌦️ Project 3 – Mini Weather Station
- ☀️ Project 4 – Smart Weather Forecast Indicator

---

# 🎯 Objective

The objective of this project collection is to learn how to interface multiple environmental sensors with the Arduino UNO and display real-time environmental data on an OLED display. These projects cover temperature, humidity, atmospheric pressure, altitude estimation, and simple weather prediction techniques.

---

# 🛠️ Components Used

- Arduino UNO
- DHT11 Temperature & Humidity Sensor
- BMP280 Pressure & Altitude Sensor
- SSD1306 OLED Display (128×64)
- Breadboard
- Jumper Wires
- USB Cable

---

# 🔌 Circuit Connections

| Component | Arduino UNO |
|-----------|-------------|
| DHT11 Data | D7 |
| BMP280 SDA | A4 |
| BMP280 SCL | A5 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| VCC | 5V |
| GND | GND |

---

# 📂 Project Overview

---

## 🌡️ Project 1 – Room Comfort Meter

### Description

This project monitors the room's temperature and humidity using the DHT11 sensor. The OLED continuously displays live readings and classifies the room environment based on the measured values.

### Features

- Live Temperature Monitoring
- Live Humidity Monitoring
- OLED Display
- Room Condition Classification
  - 😊 Comfortable
  - 🥵 Hot
  - 💧 Humid
- Automatic Refresh Every 2 Seconds
- Thermometer Progress Bar (Bonus)

---

## ⛰️ Project 2 – Pressure & Altitude Display

### Description

This project uses the BMP280 sensor to measure atmospheric pressure and estimate altitude. The sensor readings are displayed on the OLED and simultaneously printed to the Serial Monitor.

### Features

- Atmospheric Pressure Measurement
- Altitude Estimation
- OLED Display
- Serial Monitor Output
- Updates Every Second
- Vertical Altitude Indicator (Bonus)

---

## 🌦️ Project 3 – Mini Weather Station

### Description

This project combines both the DHT11 and BMP280 sensors into a single OLED dashboard, providing a compact weather monitoring system.

### Features

- Temperature Display
- Humidity Display
- Pressure Display
- Altitude Display
- Single Dashboard Layout
- Continuous Live Updates
- Startup Splash Screen (Bonus)

---

## ☀️ Project 4 – Smart Weather Forecast Indicator

### Description

A simple weather prediction system that estimates weather conditions using atmospheric pressure values measured by the BMP280 sensor.

### Weather Conditions

- ☀ Sunny
- ⛅ Normal
- 🌧 Possible Rain

> **Note:** This project provides only a basic educational approximation and is not intended for accurate weather forecasting.

### Features

- Pressure Monitoring
- Weather Prediction
- OLED Status Display
- Continuous Sensor Updates
- Weather Icons (Bonus)

---

# 💻 Code Highlights

Across these four projects, the following concepts are implemented:

- Reading temperature and humidity using the DHT11 sensor
- Reading atmospheric pressure and altitude using the BMP280 sensor
- Displaying live environmental data on an OLED display
- Updating sensor readings in real time
- Classifying environmental conditions
- Estimating weather using atmospheric pressure
- Displaying sensor information through clean OLED interfaces

---

# 📚 Libraries Used

- Adafruit GFX
- Adafruit SSD1306
- Adafruit BMP280
- DHT Sensor Library
- Wire Library

---

# 📷 Circuit Diagram

> Add your circuit diagram here.

Example:

```
images/Circuit_Diagram.png
```

---

# 📸 Output Images

Add your project screenshots here.

```
images/Room_Comfort_Meter.jpg

images/Pressure_Altitude.jpg

images/Mini_Weather_Station.jpg

images/Weather_Forecast.jpg
```

---

# 📖 Project Structure

Environmental-Monitoring-Projects/
│
├── Room_Comfort_Meter:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/484cfb9b-eb25-433c-aea5-c032ef1496de" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/d004aeb7-9a2f-4deb-a89c-198ea45ad830" />

├── Pressure_Altitude_Display:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/c5e291e7-70f5-4354-a797-752e2ea7df36" />

├── Mini_Weather_Station:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/b6449a26-738e-4303-bd7e-65bc594bfdaf" />
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/a89e9fcc-1c48-42ef-b4d1-d2ff7aa4e6f8" />

├── Smart_Weather_Forecast:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/4fbf23f5-2c0d-47bb-afb8-500b9da79fde" />

# 🎯 Learning Outcomes

By completing these projects, the following skills were developed:

- Arduino UNO Programming
- DHT11 Sensor Interfacing
- BMP280 Sensor Interfacing
- One-Wire Communication
- I2C Communication
- OLED Display Programming
- Environmental Monitoring
- Atmospheric Pressure Measurement
- Altitude Estimation
- Basic Weather Prediction
- Real-Time Embedded Systems
- Sensor Data Visualization

---

# 🚀 Future Improvements

- Add Wi-Fi Connectivity (ESP8266/ESP32)
- Cloud-Based Weather Logging
- Mobile App Monitoring
- SD Card Data Logging
- Real-Time Clock (RTC) Integration
- Weather Trend Analysis
- Air Quality Monitoring
- Interactive OLED Menu System

---

# 👨‍💻 Author

**Akshaya**

Arduino Environmental Monitoring Projects
