#pragma once
#include "SensorData.hpp"

#include <random>

class SensorSimulator {
public:
  SensorSimulator();

  // Generate one snapshot of telemetry
  SensorData generateData();

  // Inject faults
  void injectTemperatureFault();
  void injectVoltageFault();
  void injectVibrationFault();

  // Reset simulator back to normal operation
  void reset();

private:
  // Nominal sensor values
  double m_temperature;
  double m_vibration;
  double m_voltage;

  // Fault flags
  bool m_temperatureFault;
  bool m_vibrationFault;
  bool m_voltageFault;

  // Random number generation
  std::default_random_engine generator_;
  std::normal_distribution<double> m_temperatureNoise;
  std::normal_distribution<double> m_vibrationNoise;
  std::normal_distribution<double> m_voltageNoise;

  // Internal timestamp (milliseconds)
  uint64_t m_timestamp;
};
