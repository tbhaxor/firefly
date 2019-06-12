
project(test)

add_executable(test test.cpp)

target_link_libraries(
    ${PROJECT_NAME} firefly
)