#include "AlertManager.hpp"

#include <iostream>

void AlertManager::processAlert(const SensorData& data, SystemState state) {
  if (state == SystemState::NORMAL) {
    return;
  }

  std::string msg = "Temp=" + std::to_string(data.temperature) +
                    " Vib=" + std::to_string(data.vibration) +
                    " Volt=" + std::to_string(data.voltage);

  if (state == SystemState::DEGRADED) {
    sendWarning("DEGRADED CONDITION: " + msg);
  } else if (state == SystemState::CRITICAL) {
    sendCritical("CRITICAL FAILURE: " + msg);
  }
}

void AlertManager::sendWarning(const std::string& msg) {
  std::cout << "[WARNING] " << msg << std::endl;
}

void AlertManager::sendCritical(const std::string& msg) {
  std::cout << "[CRITICAL ALERT] " << msg << std::endl;
}
