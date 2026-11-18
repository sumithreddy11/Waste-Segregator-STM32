# Waste Segregator STM32
Designed and implemented a smart waste segregation system using STM32 ARM Cortex-M4 ( STM32F446RE MCU BOARD), integrating a capacitive moisture sensor and servo motor for automated wet/dry waste classification with real-time embedded control.

# Overview

Waste segregation is an essential step toward efficient recycling and sustainable waste management. This project presents a low-cost embedded system that automatically classifies waste into Wet and Dry categories based on moisture content.

A Capacitive Soil Moisture Sensor measures the moisture level of the waste. The **STM32 ARM Cortex-M4** processes the sensor data and controls a servo motor, which mechanically diverts the waste into the appropriate bin.

The system is designed to be simple, reliable, and suitable for educational prototypes and small-scale waste management applications.


# Features

Automatic Wet/Dry waste classification
ARM Cortex-M4 (STM32) based implementation
Capacitive Soil Moisture Sensor
Servo motor based sorting mechanism
Real-time analog sensor processing
Low-cost and compact hardware design
Easily extendable for IoT applications


# Hardware Components

<img width="837" height="415" alt="image" src="https://github.com/user-attachments/assets/12659eff-f322-46ae-a615-45ba71b2ccce" />



# Software Used

STM32 Arduino Core
Arduino IDE 
Embedded C++
Servo Library

# System Architecture

<img width="1024" height="572" alt="image" src="https://github.com/user-attachments/assets/dd756645-f331-4ce8-8cab-7587173ee480" />

## Quick start

| Signal | STM32 pin |
| --- | --- |
| Capacitive moisture sensor analog output | PA0 |
| Servo control | PA8 |

1. Install the STM32 Arduino Core in Arduino IDE and select your STM32F446RE board.
2. Connect the sensor and servo using the pin table and component specifications. Connect their signal grounds to the controller ground.
3. Open and upload `SmartWasteSegregator.ino`. Open Serial Monitor at 9600 baud.
4. Test known wet and dry samples. Adjust `moistureThreshold` for your sensor and materials.

## Demo and expected behavior

The serial monitor prints the raw reading and classification. A value above 500 is wet and moves the servo to 120°. A value of 500 or below is dry and moves it to 60°. The servo returns to 90° after one second. The sketch then waits 1.5 seconds before taking the next sample.
