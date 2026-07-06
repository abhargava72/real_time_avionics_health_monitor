#include <chrono>
#include <iostream>
#include <thread>

#include "SensorSimulator.hpp"

int main()
{
    SensorSimulator simulator;
    std::cout << "=== Real-Time Avionics Health Monitor ===\n\n";
    for (int i = 0; i < 100; ++i)
    {
        // Inject faults at different times
        if (i == 30)
        {
            std::cout << "\n*** Temperature Fault Injected ***\n\n";
            simulator.injectTemperatureFault();
        }

        if (i == 60)
        {
            std::cout << "\n*** Vibration Fault Injected ***\n\n";
            simulator.injectVibrationFault();
        }

        if (i == 80)
        {
            std::cout << "\n*** Voltage Fault Injected ***\n\n";
            simulator.injectVoltageFault();
        }
        SensorData data = simulator.generateData();
        std::cout << "Time: " << data.timestamp << " ms" << " | Temp: " << data.temperature << " C" << " | Vib: " << data.vibration << " g" << " | Volt: " << data.voltage << " V" << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "\nSimulation Complete.\n";
    return 0;
}