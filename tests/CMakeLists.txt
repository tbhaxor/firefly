file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(FireflyTests ${SOURCES})
target_link_libraries(FireflyTests PRIVATE GTest::gtest_main Firefly::Shared)

gtest_discover_tests(FireflyTests)