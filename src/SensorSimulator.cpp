#include "SensorSimulator.hpp"

SensorSimulator::SensorSimulator()
    : temperature_(70.0), vibration_(1.0), voltage_(28.0),
      temperatureFault_(false), vibrationFault_(false), voltageFault_(false),
      temperatureNoise_(0.0, 0.5), vibrationNoise_(0.0, 0.1),
      voltageNoise_(0.0, 0.2), timestamp_(0) {}

SensorData SensorSimulator::generateData() {
  // Advance simulated time
  timestamp_ += 100;

  // Simulate fault behavior
  if (temperatureFault_) {
    temperature_ += 0.4;
  }

  if (vibrationFault_) {
    vibration_ += 0.08;
  }

  if (voltageFault_) {
    voltage_ -= 0.05;
  }

  SensorData data;

  data.temperature = temperature_ + temperatureNoise_(generator_);
  data.vibration = vibration_ + vibrationNoise_(generator_);
  data.voltage = voltage_ + voltageNoise_(generator_);
  data.timestamp = timestamp_;

  return data;
}

void SensorSimulator::injectTemperatureFault() { temperatureFault_ = true; }

void SensorSimulator::injectVoltageFault() { voltageFault_ = true; }

void SensorSimulator::injectVibrationFault() { vibrationFault_ = true; }

void SensorSimulator::reset() {
  temperature_ = 70.0;
  vibration_ = 1.0;
  voltage_ = 28.0;

  temperatureFault_ = false;
  vibrationFault_ = false;
  voltageFault_ = false;

  timestamp_ = 0;
}
