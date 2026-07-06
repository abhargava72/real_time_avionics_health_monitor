#include "HealthMonitor.hpp"

SystemState HealthMonitor::evaluate(const SensorData& data) {
  bool overheat = isOverheat(data);
  bool vib = isHighVibration(data);
  bool volt = isLowVoltage(data);

  // CRITICAL: any hard safety breach
  if (overheat || (vib && volt)) {
    return SystemState::CRITICAL;
  }

  // DEGRADED: early warning signs
  if (vib || volt) {
    return SystemState::DEGRADED;
  }

  return SystemState::NORMAL;
}

bool HealthMonitor::isOverheat(const SensorData& data) {
  return data.temperature > 95.0;
}

bool HealthMonitor::isHighVibration(const SensorData& data) {
  return data.vibration > 4.0;
}

bool HealthMonitor::isLowVoltage(const SensorData& data) {
  return data.voltage < 24.0;
}
