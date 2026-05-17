# Enhanced Smart Home Automation using LoRa and GSM

## Overview
This project presents an internet-independent smart home automation system using ESP32, LoRa SX1278, and GSM SIM800L modules. The system allows long-range appliance control using LoRa communication and remote SMS-based operation using GSM.

## Features
- Long-range LoRa communication
- GSM SMS control
- Internet-independent operation
- Control of 4 AC loads
- Relay-based switching
- Push-button manual control
- ESP32-based architecture

## Components Used
- ESP32
- LoRa SX1278 Module
- SIM800L GSM Module
- Relay Module
- Push Buttons
- AC Bulbs/Loads

## Technologies Used
- Embedded C
- Arduino IDE
- LoRa Communication
- GSM AT Commands

## Project Architecture
### Transmitter Unit
- ESP32
- LoRa SX1278
- SIM800L GSM
- Push buttons

### Receiver Unit
- ESP32/ESP8266
- LoRa SX1278
- Relay modules
- AC Loads

## Results
- Indoor communication: up to 500m
- Outdoor communication: up to 2km
- SMS control supported
- Average relay delay: ~120ms

## Images

### Hardware Setup
![Hardware](Images/hardware_setup.jpg)

### SIM800L Module
![SIM800L](Images/sim800l_module.jpg)

### Experimental Output
![Bulb Output](Images/bulb2_output.jpg)

## Authors
- Chaturya Vemavarapu
- Kristi Sikdar
- Sakthipooja

## Future Improvements
- EEPROM state storage
- Mobile application
- Environmental sensors
- Bi-directional LoRa acknowledgement
