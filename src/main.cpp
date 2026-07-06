#include <chrono>
#include <iostream>
#include <thread>

#include "AlertManager.hpp"
#include "HealthMonitor.hpp"
#include "Logger.hpp"
#include "SensorSimulator.hpp"

int main() {
  std::cout << "=== Real-Time Avionics Health Monitor ===\n";

  SensorSimulator simulator;
  HealthMonitor monitor;
  Logger logger("logs/telemetry.log");
  AlertManager alertManager;

  for (int i = 0; i < 100; i++) {
    // Inject faults at runtime (simulated failure progression)
    if (i == 30) {
      std::cout << "\n*** Injecting Temperature Fault ***\n";
      simulator.injectTemperatureFault();
    }

    if (i == 60) {
      std::cout << "\n*** Injecting Vibration Fault ***\n";
      simulator.injectVibrationFault();
    }

    if (i == 80) {
      std::cout << "\n*** Injecting Voltage Fault ***\n";
      simulator.injectVoltageFault();
    }

    // 1. Generate telemetry
    SensorData data = simulator.generateData();

    // 2. Evaluate system health
    SystemState state = monitor.evaluate(data);

    // 3. Format log message
    std::string message = "T=" + std::to_string(data.temperature) +
                          " | V=" + std::to_string(data.vibration) +
                          " | Volt=" + std::to_string(data.voltage) +
                          " | STATE=" +
                          (state == SystemState::NORMAL     ? "NORMAL"
                           : state == SystemState::DEGRADED ? "DEGRADED"
                                                            : "CRITICAL");

    // 4. Print to console
    std::cout << message << std::endl;

    // 5. Persist to log file
    logger.log(message);

    // 6. Trigger alerts if needed
    alertManager.processAlert(data, state);

    // 7. Simulate real-time delay (100ms control loop)
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << "\nSimulation Complete.\n";

  return 0;
}