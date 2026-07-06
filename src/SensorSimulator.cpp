#include "SensorSimulator.hpp"

SensorSimulator::SensorSimulator()
    : m_temperature(70.0), m_vibration(1.0), m_voltage(28.0), m_temperatureFault(false),
      m_vibrationFault(false), m_voltageFault(false), m_temperatureNoise(0.0, 0.5),
      m_vibrationNoise(0.0, 0.1), m_voltageNoise(0.0, 0.2), m_timestamp(0) {}

SensorData SensorSimulator::generateData() {
  // Advance simulated time
  m_timestamp += 100;

  // Simulate fault behavior
  if (m_temperatureFault) {
    m_temperature += 0.4;
  }

  if (m_vibrationFault) {
    m_vibration += 0.08;
  }

  if (m_voltageFault) {
    m_voltage -= 0.05;
  }

  SensorData data;

  data.temperature = m_temperature + m_temperatureNoise(generator_);
  data.vibration = m_vibration + m_vibrationNoise(generator_);
  data.voltage = m_voltage + m_voltageNoise(generator_);
  data.timestamp = m_timestamp;

  return data;
}

void SensorSimulator::injectTemperatureFault() {
  m_temperatureFault = true;
}

void SensorSimulator::injectVoltageFault() {
  m_voltageFault = true;
}

void SensorSimulator::injectVibrationFault() {
  m_vibrationFault = true;
}

void SensorSimulator::reset() {
  m_temperature = 70.0;
  m_vibration = 1.0;
  m_voltage = 28.0;

  m_temperatureFault = false;
  m_vibrationFault = false;
  m_voltageFault = false;

  m_timestamp = 0;
}
