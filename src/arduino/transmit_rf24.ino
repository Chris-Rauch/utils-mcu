/*
 * Author: Chris Rauch
 *
 * Description: This source code configures an Arduino Nano microcontroller to
 *   send data using an nRF24L01 transceiver module. It demonstrates setting up 
 *   the transceiver, transmitting payload data, and verifying successful 
 *   transmission. The program increments and sends a floating-point value 
 *   (`payload`) at regular intervals.
 *
 * Pinout:
 *   nRF24L01 | Arduino Nano
 *   -----------------------
 *   VCC      |     3.3V (or alternative power source)
 *   GND      |     GND
 *   CE       |     D9
 *   CSN      |     D10
 *   SCK      |     D13
 *   MOSI     |     D11
 *   MISO     |     D12
 *   *Note - Power is buggy. If connected to Arduino board (vice alternative
 *   power source) the transmitter needs AT LEAST 10uF capacitor
 *
 * Features:
 *   - Configurable SPI speed for communication with the nRF24L01 module.
 *   - Use of a 5-byte pipe address to uniquely identify the communication 
 *     channel.
 *   - Customizable RF settings such as power level, data rate, and
 *     communication channel.
 *   - Transmits payload data (a float) over the air with acknowledgment of
 *     success or failure.
 *   - Serial monitoring for debugging and feedback on payload transmission.
 *
 * Notes:
 *   - Ensure the nRF24L01 module is powered by a stable 3.3V supply to avoid communication issues.
 *   - The SPI communication speed is set to 2 MHz for reliable operation with the Arduino Nano.
 *   - The RF channel is set to 69 to minimize interference with other devices.
 
 * Dependencies:
 *   Software:
 *     - Arduino IDE (i used version 2.3.3)
 *     - Libraries:
 *       - RF24 (https://github.com/nRF24/RF24)
 *       - printf (optional for debugging with `printDetails` and `printPrettyDetails`)
 *     - Serial Monitor for debugging and monitoring data (built into Arduino IDE or external tools like PuTTY)
 *   Hardware:
 *     - Arduino microcontroller (i used a Nano board)
 *     - nRF24L01+ transceiver module (Amazon link: https://www.amazon.com/dp/B00WG9HO6Q?ref=ppx_yo2ov_dt_b_fed_asin_title)
 *     - 3.3V regulator or 10uF capacitor (if not already provided in your setup)
 *     - External power supply for nRF24L01 module (optional but recommended for stable operation)
 *     - Jumper wires and breadboard (or PCB for permanent setups) (optional)
 */
#include <SPI.h>
#include "printf.h"
#include "RF24.h"

#define CE_PIN 9
#define CSN_PIN 10

// constants
const uint8_t pipe[6] = "1Node";    // pipe indentifier
const uint32_t spi_speed = 2000000; // SPI speed in Hz

// payload info
float payload = 0.0;
const uint8_t payload_size = sizeof(payload);

// configure the transeiver
RF24 radio(CE_PIN, CSN_PIN, spi_speed);

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
  }

  // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}
  }

  // configure radio
  radio.setPALevel(RF24_PA_MIN);      // signal strength
  radio.setDataRate(RF24_250KBPS);    // lower data rate to improve reliability
  radio.setPayloadSize(payload_size); // size of payload
  radio.openWritingPipe(pipe);        // pipe 0
  radio.stopListening();              // put radio in TX mode
  radio.setChannel(69);               // unique channel to decrease traffic
  //radio.setAutoAck(true);

  // For debugging info
   printf_begin();             // needed only once for printing details
   radio.printDetails();       // (smaller) function that prints raw register values
   radio.printPrettyDetails(); // (larger) function that prints human readable data

}  // setup

void loop() {
  bool report = radio.write(&payload, payload_size);  // transmit & save the report
  if (report) {
    Serial.println(payload);  // print payload sent
    payload += 1.00;          // increment float payload
  } else {
    Serial.println(F("Transmission failed or timed out"));  // payload was not delivered
  }

  // to make this example readable
  delay(300); 
}  // loop
