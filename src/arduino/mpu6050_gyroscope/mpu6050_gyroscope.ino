#include <Wire.h>
#include <MPU6050.h>

// Create an instance of the MPU6050 class
MPU6050 mpu;

void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Initialize the I2C communication
  Wire.begin();
  
  // Initialize the MPU6050 sensor
  mpu.initialize();
  
  // Check if the MPU6050 is connected properly
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful.");
  } else {
    Serial.println("MPU6050 connection failed.");
    while (1); // Halt the program if the sensor is not connected
  }
}

void loop() {
  // Variables to hold the sensor data
  int16_t ax, ay, az;  // Accelerometer data
  int16_t gx, gy, gz;  // Gyroscope data

  // Get the accelerometer and gyroscope data
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);
  
  // Print the accelerometer data (in raw form)
  Serial.print("Accelerometer: ");
  Serial.print("X: "); Serial.print(ax);
  Serial.print(" Y: "); Serial.print(ay);
  Serial.print(" Z: "); Serial.println(az);
  
  // Print the gyroscope data (in raw form)
  Serial.print("Gyroscope: ");
  Serial.print("X: "); Serial.print(gx);
  Serial.print(" Y: "); Serial.print(gy);
  Serial.print(" Z: "); Serial.println(gz);
  
  // Delay before the next reading
  delay(500);
}
