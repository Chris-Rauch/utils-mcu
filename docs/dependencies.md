# Dependencies

This document lists the required tools, libraries, and software for working with the code snippets in this repository.

---

## General Requirements

- **Operating System**: Compatible with Windows, macOS, and Linux.
- **Compiler/Toolchain**: A toolchain for your microcontroller (e.g., GCC for AVR, ARM GCC for STM32).
- **Microcontroller Programming Environment**: 
  - Recommended: [Arduino IDE](https://www.arduino.cc/en/software)

---

## Tools and Software

### 1. Arduino IDE
- **Description**: An integrated development environment for programming Arduino-compatible boards.
- **Version**: Recommended version 2.x or later.
- **Download**: [Arduino IDE Official Page](https://www.arduino.cc/en/software)
- **Setup Instructions**:
  1. Download and install the Arduino IDE.
  2. Install the appropriate board support packages for your microcontroller (e.g., Arduino AVR Boards or ESP32 boards).
  3. Install additional libraries as needed (see below).

---

## Libraries

### 1. RF24 Library
- **Description**: A popular library for interfacing with NRF24L01+ modules for wireless communication.
- **Version**: Latest stable release.
- **Repository**: [RF24 GitHub Repository](https://github.com/nRF24/RF24)
- **Installation Instructions**:
  1. Open the Arduino IDE.
  2. Go to **Sketch > Include Library > Manage Libraries**.
  3. Search for "RF24" in the Library Manager.
  4. Click **Install** to install the library.

- **Usage**:
  - The library provides functions for sending and receiving data using NRF24L01+ modules.
  - Example sketches are available in the `Examples` section of the Arduino IDE after installation.

### 2. Boost C++ Libraries
- **Description**: The Boost project provides free peer-reviewed portable C++ source libraries. The specific library that I am using:
  1. crc.hpp
- **Version**: 1.86.0
- **Repository**: [Official Website](https://www.boost.org/)
                  [Download Page](https://www.boost.org/users/download/)
- **Installation Instuctions**
  1. [Windows](https://www.geeksforgeeks.org/how-to-install-c-boost-libraries-on-windows/)

We emphasize libraries that work well with the C++ Standard Library. Boost
libraries are intended to be widely useful, and usable across a broad spectrum
of applications. The Boost license encourages both commercial and non-commercial use
and does not require attribution for binary use.

The project website is www.boost.org, where you can obtain more information and
[download](https://www.boost.org/users/download/) the current release.
---

## Additional Notes

- **Hardware Compatibility**:
  - Ensure that your microcontroller supports the required libraries.
  - For NRF24L01+ modules, ensure proper connections and power supply (a decoupling capacitor is often recommended).

- **Troubleshooting**:
  - If you encounter issues with the RF24 library, refer to the [RF24 Troubleshooting Guide](https://github.com/nRF24/RF24#troubleshooting).

---

Feel free to expand this file with additional tools, libraries, or setup instructions as your project grows.
