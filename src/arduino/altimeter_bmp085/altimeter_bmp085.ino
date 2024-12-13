#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

// Create an instance of the sensor
Adafruit_BMP085_Unified bmp;

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Initialize the sensor
  if (!bmp.begin()) {
    Serial.print("Couldn't find the sensor");
    while (1);
  }
}

void loop() {
  // Variables to hold sensor data
  sensors_event_t event;

  // Get temperature
  bmp.getEvent(&event);
  Serial.print("Temperature: ");
  Serial.print(event.temperature);
  Serial.println(" C");

  // Get pressure
  float pressure;
  bmp.getPressure(&pressure);
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  // Get altitude (using standard pressure of 1013.25 hPa)
  float altitude;
  altitude = bmp.pressureToAltitude(1013.25, pressure);
  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" meters");

  // Wait before taking another reading
  delay(2000);
}

