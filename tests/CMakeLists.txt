add_executable(FireflyTests)

add_subdirectory(vector)
add_subdirectory(utilities)

target_link_libraries(FireflyTests PRIVATE GTest::gtest_main firefly)

gtest_discover_tests(FireflyTests)