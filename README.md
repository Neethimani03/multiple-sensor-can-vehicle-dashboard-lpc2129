# multiple-sensor-can-vehicle-dashboard-lpc2129
Embedded CAN-based vehicle dashboard using LPC2129 and multiple sensors
=======
Multiple Sensor CAN Vehicle Dashboard using LPC2129

## Overview
CAN-based vehicle dashboard using LPC2129 ARM7 microcontroller.
Multiple sensor nodes communicate via CAN to display real-time vehicle parameters.

## Sensors
- Ultrasonic Sensor (Fuel Level)
- LDR (Headlight Control)
- PWM Speed Simulation

## CAN IDs
| ID   | Parameter          |
|-----:|--------------------|
| 0x01 | Headlight Status   |
| 0x02 | Fuel Level         |
| 0x03 | Speed              |

## Features
- CAN @125 kbps
- Interrupt-driven control
- Real-time LCD dashboard
- Modular firmware design

## Tools
- Embedded C
- Keil µVision
- Flash Magic

## Author
Neethimani Ramu  
Email: neethimani03@gmail.com

