#pragma once
#include <cstdint>

using std::uint64_t;

struct SensorData {
  double temperature;
  double vibration;
  double voltage;
  uint64_t timestamp;
};
