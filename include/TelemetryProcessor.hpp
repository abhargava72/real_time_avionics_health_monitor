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
  SensorSimulator m_simulator;
  HealthMonitor m_monitor;
  Logger m_logger;
  AlertManager m_alertManager;
};
