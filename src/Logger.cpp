#include "Logger.hpp"
#include <chrono>
#include <ctime>
#include <iostream>

Logger::Logger(const std::string &filename) {
  m_file.open(filename, std::ios::out | std::ios::app);

  if (!m_file.is_open()) {
    std::cerr << "Failed to open log file: " << filename << std::endl;
  }
}

Logger::~Logger() {
  if (m_file.is_open()) {
    m_file.close();
  }
}

void Logger::log(const std::string &message) {
  if (!m_file.is_open())
    return;

  // Add simple timestamp
  auto now = std::chrono::system_clock::now();
  std::time_t time = std::chrono::system_clock::to_time_t(now);

  m_file << std::ctime(&time) << " | " << message << std::endl;
}
