file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(FireflyTests ${SOURCES})
target_link_libraries(FireflyTests PRIVATE GTest::gtest_main firefly)
target_compile_definitions(FireflyTests PRIVATE -DFirefly_TEST_EPSILON=1e-3)

gtest_discover_tests(FireflyTests)