#pragma once

#include "HealthMonitor.hpp"
#include "SensorData.hpp"
#include <string>

class AlertManager {
public:
  void processAlert(const SensorData &data, SystemState state);

private:
  void sendWarning(const std::string &msg);
  void sendCritical(const std::string &msg);
};