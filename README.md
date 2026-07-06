
# 🚀 Real-Time Avionics Health Monitoring System (C++)

A lightweight, real-time simulation of an avionics health monitoring system built in C++.
This project models how embedded aerospace systems continuously process sensor data, detect faults, and evaluate system health using deterministic logic.

---

## 🧠 Overview

Modern avionics systems require continuous monitoring of critical sensor data such as temperature, vibration, and voltage. These systems must operate under strict real-time constraints and immediately detect abnormal behavior to ensure safety.

This project simulates that environment by:

- Generating real-time sensor telemetry
- Processing data in a fixed-time control loop
- Detecting anomalies and threshold violations
- Classifying system health states
- Logging alerts and system status updates

---

## 🏗️ System Architecture

The system is divided into modular components:

### 1. Sensor Simulator

- Generates synthetic avionics sensor data
- Introduces realistic noise and fault conditions
- Simulates:
  - Engine temperature drift
  - Vibration spikes
  - Voltage fluctuations

### 2. Real-Time Control Loop

- Executes every 100ms
- Mimics embedded avionics scheduling
- Processes latest sensor snapshot each cycle

### 3. Health Monitoring Engine

Evaluates system state using deterministic rules:

- 🟢 NORMAL → Safe operating conditions
- 🟡 DEGRADED → Early warning signs detected
- 🔴 CRITICAL → Immediate failure risk

### 4. Alert & Logging System

- Outputs structured telemetry logs
- Flags abnormal system behavior in real time

---

## ⚙️ Tech Stack

- C++17
- STL (Standard Library)
- CMake (build system)
- Multithreading (std::this_thread)
- Chrono utilities for timing simulation

---

## 📊 System Behavior

Each sensor cycle produces readings like:
