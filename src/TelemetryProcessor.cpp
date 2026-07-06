#include "TelemetryProcessor.hpp"
#include <chrono>
#include <iostream>
#include <thread>

TelemetryProcessor::TelemetryProcessor() : m_logger("logs/telemetry.log") {}

void TelemetryProcessor::run(int iterations) {
  std::cout << "=== Telemetry Processor Running ===\n";

  for (int i = 0; i < iterations; i++) {
    // Fault injection (kept inside controller now)
    if (i == 30)
      m_simulator.injectTemperatureFault();

    if (i == 60)
      m_simulator.injectVibrationFault();

    if (i == 80)
      m_simulator.injectVoltageFault();

    // 1. Generate sensor data
    SensorData data = m_simulator.generateData();

    // 2. Evaluate health
    SystemState state = m_monitor.evaluate(data);

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
    m_logger.log(message);

    // 6. Alerts
    m_alertManager.processAlert(data, state);

    // 7. Real-time delay
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << "\n=== Simulation Complete ===\n";
}