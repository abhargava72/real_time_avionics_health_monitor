#include "TelemetryProcessor.hpp"
#include <chrono>
#include <iostream>
#include <thread>

TelemetryProcessor::TelemetryProcessor() : logger_("logs/telemetry.log") {}

void TelemetryProcessor::run(int iterations) {
  std::cout << "=== Telemetry Processor Running ===\n";

  for (int i = 0; i < iterations; i++) {
    // Fault injection (kept inside controller now)
    if (i == 30)
      simulator_.injectTemperatureFault();

    if (i == 60)
      simulator_.injectVibrationFault();

    if (i == 80)
      simulator_.injectVoltageFault();

    // 1. Generate sensor data
    SensorData data = simulator_.generateData();

    // 2. Evaluate health
    SystemState state = monitor_.evaluate(data);

    // 3. Format message
    std::string message = "T=" + std::to_string(data.temperature) +
                          " | V=" + std::to_string(data.vibration) +
                          " | Volt=" + std::to_string(data.voltage) +
                          " | STATE=" +
                          (state == SystemState::NORMAL     ? "NORMAL"
                           : state == SystemState::DEGRADED ? "DEGRADED"
                                                            : "CRITICAL");

    // 4. Console output
    std::cout << message << std::endl;

    // 5. Log it
    logger_.log(message);

    // 6. Alerts
    alertManager_.processAlert(data, state);

    // 7. Real-time delay
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << "\n=== Simulation Complete ===\n";
}