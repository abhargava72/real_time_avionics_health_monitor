#include "Logger.hpp"

#include <filesystem>
#include <gtest/gtest.h>

TEST(LoggerTest, CreatesLogFile) {
  const std::string filename = "logs/test.log";

  Logger logger(filename);

  logger.log("Hello World");

  EXPECT_TRUE(std::filesystem::exists(filename));
}
