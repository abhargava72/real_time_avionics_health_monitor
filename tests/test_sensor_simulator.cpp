#include <gtest/gtest.h>

#include "SensorSimulator.hpp"

TEST(SensorSimulatorTest, GeneratesReasonableValues) {
  SensorSimulator simulator;

  SensorData data = simulator.generateData();

  EXPECT_GT(data.temperature, 0.0);
  EXPECT_GT(data.voltage, 0.0);
  EXPECT_GT(data.vibration, 0.0);
}
