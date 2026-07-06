#pragma once
#include "SensorData.hpp"

enum class SystemState { NORMAL, DEGRADED, CRITICAL };

class HealthMonitor {
public:
  SystemState evaluate(const SensorData &data);

private:
  bool isOverheat(const SensorData &data);
  bool isHighVibration(const SensorData &data);
  bool isLowVoltage(const SensorData &data);
};
