#include "HealthMonitor.hpp"
#include "SensorData.hpp"

#include <gtest/gtest.h>

TEST(HealthMonitorTest, NormalState) {
  HealthMonitor monitor;

  SensorData data{
      72.0, // temperature
      1.0,  // vibration
      28.0, // voltage
      42    // timestamp
  };

  EXPECT_EQ(monitor.evaluate(data), SystemState::NORMAL);
}

TEST(HealthMonitorTest, OverheatCritical) {
  HealthMonitor monitor;

  SensorData data{100.0, 1.0, 28.0, 42};

  EXPECT_EQ(monitor.evaluate(data), SystemState::CRITICAL);
}

TEST(HealthMonitorTest, LowVoltageDegraded) {
  HealthMonitor monitor;

  SensorData data{70.0, 1.0, 23.0, 42};

  EXPECT_EQ(monitor.evaluate(data), SystemState::DEGRADED);
}