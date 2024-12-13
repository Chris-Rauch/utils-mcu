# Utility Library For Various Microcontrollers

This repository contains small, reusable code snippets for microcontrollers like Arduino and Rpi. These snippets are designed for quick testing, prototyping, and learning.


## Structure

- **utils-mcu/**: Root.
  - **README.md**: Overview of the repository.
  - **.gitignore**: Ignore unnecessary files.
  - **src/**: Source code folder.
    - **arduino/**:
      - `transmit.ino`: Code for data transmission.
      - `receive.ino`: Code for data reception.
      - `README.md`: Documentation for Arduino-related code.
    - **TBD**: Placeholder.
    - **TBD**: Placeholder.
  - **docs/**: Documentation folder.
    - `setup_guide.md`: Guide to setting up the environment.
    - `dependencies.md`: Information on required dependencies.



## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/Chris-Rauch/utils-mcu.git


## Dependencies

See utils-mcu/docs/dependencies.md for more detailed information on how to use and install

This repository uses the following dependencies:

### General

- A microcontroller programming IDE/toolchain:
  - [Arduino IDE](https://www.arduino.cc/en/software) (for Arduino sketches).

### Libraries

- [RF24](https://nrf24.github.io/RF24/) (for NRF24L01 communication).
- [boost](https://www.boost.org/users/download/) (for CRC library to help with checksum)

### Tools

