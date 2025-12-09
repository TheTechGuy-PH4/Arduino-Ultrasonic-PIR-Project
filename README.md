# Motion & Distance Detection with Arduino Uno (Simulink Project)

This project implements a motion-activated distance detection system using an
Arduino Uno R3, an HC-SR04 Ultrasonic Sensor, a PIR motion sensor, and two LEDs
(Green and Red). The logic is built in MATLAB Simulink and deployed to the Arduino
using the Simulink Support Package for Arduino Hardware.

## Project Behavior

- If an object is **within a chosen distance threshold** (e.g., 0.3 m) **and**
  motion is detected by the PIR sensor → **GREEN LED ON**, RED OFF.
- Otherwise → **RED LED ON**, GREEN OFF.

### Hardware

- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- PIR Motion Sensor
- Green LED + 220 Ω resistor (Pin D9)
- Red LED + 220 Ω resistor (Pin D10)
- Breadboard + jumper wires
- 5V & GND rails from the Arduino

### Simulink Logic Overview

1. **Ultrasonic Sensor block** (Trigger D3, Echo D4) → distance in meters  
2. **Compare to Constant** (< 0.3 m) → `isNear`  
3. **Digital Input block** (PIR on D2) → `motionDetected`  
4. **Logical AND** (`isNear` AND `motionDetected`) → `greenCondition`  
5. **Logical NOT** (`greenCondition`) → `redCondition`  
6. **Digital Output D9** ← `greenCondition` (Green LED)  
7. **Digital Output D10** ← `redCondition` (Red LED)

## Demo Video

A short demonstration of the project running on hardware can be viewed here:

[Final Project - Testing Video](https://1drv.ms/v/c/5e03a7aeec2669cc/IQCTycJzUGHPTZsCPv1BUF2KAYXGYYR1mRFlKjWHwaAApsM?e=FVR164)

## How to Run

1. Open the Simulink model in MATLAB (e.g., `Final_Project_Simulink_Model.slx`).
2. Make sure the **Hardware board** is set to **Arduino Uno** in Model Settings.
3. Connect the Arduino via USB.
4. Run in **External mode** for live monitoring, or **Deploy to Hardware**
   to run standalone on the Arduino.
