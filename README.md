# Self-Balancing-Bi-Copter-Control
# Self-Balancing Bicopter Control System

This repository contains the code and instructions for a self-balancing bicopter control system. The project uses an MPU6050 sensor and PID control to maintain balance by adjusting the speed of two motors.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The self-balancing bicopter project aims to stabilize a two-motor setup using a PID control system. The MPU6050 sensor provides accelerometer and gyroscope data, which is processed to maintain balance by adjusting the speed of the motors via Electronic Speed Controllers (ESCs).

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- MPU6050 sensor
- Two Electronic Speed Controllers (ESCs)
- Two motors
- Jumper wires
- Breadboard (optional)

## Software Requirements

- Arduino IDE
- MPU6050 library
- Servo library
- I2Cdev library

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/abdullahfaroq/Self-Balancing-Bi-Copter-Control.git
   cd Self-Balancing-Bi-Copter-Control
