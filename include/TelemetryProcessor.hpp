#pragma once

#include "AlertManager.hpp"
#include "HealthMonitor.hpp"
#include "Logger.hpp"
#include "SensorSimulator.hpp"

class TelemetryProcessor {
public:
  TelemetryProcessor();

  void run(int iterations);

private:
  SensorSimulator simulator_;
  HealthMonitor monitor_;
  Logger logger_;
  AlertManager alertManager_;
};
