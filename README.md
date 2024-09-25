# Parking Distance Control (PDC)
## Overview
![image](https://github.com/user-attachments/assets/4f49e70f-a895-4c1d-b299-1322ea6257be)
This project is an implementation of the Park Distance Control (PDC) system based on AUTOSAR architecture (`RTE layer and Application layer`). It simulates a control mechanism that utilizes ultrasonic sensors to measure distances between a vehicle and obstacles, triggering alarms when necessary. The system communicates over CAN (Controller Area Network) and includes diagnostic features.

## Features
- **Communication (COM)**: The system uses the CAN bus to transmit sensor data and control signals between ECUs.
- **Non-volatile memory (NVM)**: NVM stores critical data like sensor calibrations and error logs to ensure system recovery after power loss.
- **Watchdog (Wdg)**: The Watchdog module monitors and ensures that critical tasks are completed within predefined time limits to avoid system failures.
- **Diagnostic**: Diagnostic trouble codes (DTCs) are used to identify and report errors in the PDC system for maintenance and troubleshooting.
- **Operation System (OS)**: The OS schedules and manages tasks, ensuring real-time operation of PDC functionalities like distance measurement and alarms.

## Software Components
![image](https://github.com/user-attachments/assets/0e4548d2-fdcf-4f8d-80f4-ade21b650b48)

The project consists of the following key software components (SWCs):
- `UltrasonicSensorSWC:` Collects distance data from ultrasonic sensors.
- `AlarmSystemSWC:` Triggers alarms when the distance to an obstacle is too short.
- `ParkDistanceControlSWC:` Processes the sensor data to compute warnings.

## ECU Allocation
![image](https://github.com/user-attachments/assets/a6523b6d-41f9-44c4-b7b2-7896a3760147)

ECUs: The system is divided into two ECUs:
- `Sensor ECU:` Manages ultrasonic sensors.
- `PDC ECU:` Manages distance calculation and alarm control.
