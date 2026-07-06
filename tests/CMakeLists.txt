add_executable(avionics_tests
    test_health_monitor.cpp
    test_sensor_simulator.cpp
    test_logger.cpp
)

target_link_libraries(avionics_tests
    PRIVATE
        avionics_core
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(avionics_tests)
