#include <Servo.h> // Include the Servo library to generate PWM signals

// Create Servo objects for each ESC
Servo esc1, esc2, esc3, esc4;

// Define throttle range for ESCs
const int minThrottle = 1000; // Minimum PWM signal (ESC armed but motor stopped)
const int maxThrottle = 2000; // Maximum PWM signal (full throttle)

void setup() {
  // Attach ESCs to Arduino PWM pins
  esc1.attach(9);  // Connect ESC1 signal wire to pin 9
  esc2.attach(10); // Connect ESC2 signal wire to pin 10
  esc3.attach(11); // Connect ESC3 signal wire to pin 11
  esc4.attach(12); // Connect ESC4 signal wire to pin 12

  // Initialize ESCs with minimum throttle (arm sequence)
  esc1.writeMicroseconds(minThrottle);
  esc2.writeMicroseconds(minThrottle);
  esc3.writeMicroseconds(minThrottle);
  esc4.writeMicroseconds(minThrottle);

  delay(2000); // Wait for 2 seconds to ensure ESCs are armed
}

void loop() {
  // Example: Gradually increase throttle for all motors
  for (int throttle = minThrottle; throttle <= maxThrottle; throttle += 10) {
    esc1.writeMicroseconds(throttle);
    esc2.writeMicroseconds(throttle);
    esc3.writeMicroseconds(throttle);
    esc4.writeMicroseconds(throttle);

    delay(50); // Wait 50ms before increasing throttle
  }

  // Example: Gradually decrease throttle for all motors
  for (int throttle = maxThrottle; throttle >= minThrottle; throttle -= 10) {
    esc1.writeMicroseconds(throttle);
    esc2.writeMicroseconds(throttle);
    esc3.writeMicroseconds(throttle);
    esc4.writeMicroseconds(throttle);

    delay(50); // Wait 50ms before decreasing throttle
  }
}

