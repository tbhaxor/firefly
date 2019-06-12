
project(_test)

add_executable(${PROJECT_NAME} test.cpp)

target_link_libraries(
    ${PROJECT_NAME} firefly
)