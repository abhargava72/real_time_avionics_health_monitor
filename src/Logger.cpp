#include "Logger.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

Logger::Logger(const std::string &filename) {
  file_.open(filename, std::ios::out | std::ios::app);

  if (!file_.is_open()) {
    std::cerr << "Failed to open log file: " << filename << std::endl;
  }
}

Logger::~Logger() {
  if (file_.is_open()) {
    file_.close();
  }
}

void Logger::log(const std::string &message) {
  if (!file_.is_open())
    return;

  // Add simple timestamp
  auto now = std::chrono::system_clock::now();
  std::time_t time = std::chrono::system_clock::to_time_t(now);

  file_ << std::ctime(&time) << " | " << message << std::endl;
}
