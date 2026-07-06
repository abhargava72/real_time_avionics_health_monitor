#pragma once
#include "SensorData.hpp"
#include <random>

class SensorSimulator
{
public:
    SensorSimulator();

    // Generate one snapshot of telemetry
    SensorData generateData();

    // Inject faults
    void injectTemperatureFault();
    void injectVoltageFault();
    void injectVibrationFault();

    // Reset simulator back to normal operation
    void reset();

private:
    // Nominal sensor values
    double temperature_;
    double vibration_;
    double voltage_;

    // Fault flags
    bool temperatureFault_;
    bool vibrationFault_;
    bool voltageFault_;

    // Random number generation
    std::default_random_engine generator_;
    std::normal_distribution<double> temperatureNoise_;
    std::normal_distribution<double> vibrationNoise_;
    std::normal_distribution<double> voltageNoise_;

    // Internal timestamp (milliseconds)
    uint64_t timestamp_;
};
