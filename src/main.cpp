#include <chrono>
#include <iostream>
#include <thread>

#include "HealthMonitor.hpp"
#include "Logger.hpp"
#include "SensorSimulator.hpp"

int main() {
  SensorSimulator simulator;
  HealthMonitor monitor;
  Logger logger("logs/telemetry.log");

  std::cout << "=== Avionics Health Monitor Running ===\n";

  for (int i = 0; i < 100; i++) {
    if (i == 30)
      simulator.injectTemperatureFault();

    if (i == 60)
      simulator.injectVibrationFault();

    if (i == 80)
      simulator.injectVoltageFault();

    SensorData data = simulator.generateData();
    SystemState state = monitor.evaluate(data);

    std::string logMessage = "T=" + std::to_string(data.temperature) +
                             " V=" + std::to_string(data.vibration) +
                             " Vlt=" + std::to_string(data.voltage) +
                             " STATE=" +
                             (state == SystemState::NORMAL     ? "NORMAL"
                              : state == SystemState::DEGRADED ? "DEGRADED"
                                                               : "CRITICAL");

    std::cout << logMessage << std::endl;

    logger.log(logMessage);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}