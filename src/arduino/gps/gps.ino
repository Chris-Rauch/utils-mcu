#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Create a software serial object for communication with GPS (using pins 4 and 3)
SoftwareSerial gpsSerial(4, 3);  // RX, TX

// Create a TinyGPS++ object to parse GPS data
TinyGPSPlus gps;

void setup() {
  // Start serial communication for output
  Serial.begin(9600);
  // Start software serial communication for GPS
  gpsSerial.begin(9600);

  Serial.println("GPS Module Example");
}

void loop() {
  // This sketch displays information every time a new sentence is correctly encoded.
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());

    // If we have a new fix (position data available)
    if (gps.location.isUpdated()) {
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6); 
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);

      Serial.print("Altitude= ");
      Serial.println(gps.altitude.meters());

      Serial.print("Speed= ");
      Serial.println(gps.speed.kmph());

      Serial.print("Course= ");
      Serial.println(gps.course.deg());

      Serial.print("Date= ");
      Serial.print(gps.date.year()); 
      Serial.print("-");
      Serial.print(gps.date.month());
      Serial.print("-");
      Serial.println(gps.date.day());

      Serial.print("Time= ");
      Serial.print(gps.time.hour());
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());
    }
  }
}

