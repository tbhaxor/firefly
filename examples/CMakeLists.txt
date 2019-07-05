cmake_minimum_required(VERSION 3.9)

project(firefly_example)

set(CXX_STANDARD 17)
set(PROJECT_VERSION 2.0.0)
set(PROJECT_BINARY_DIR bin)

add_executable(${PROJECT_NAME} main.cpp)

find_library(FIREFLY firefly REQUIRED)

target_link_libraries(${PROJECT_NAME} ${FIREFLY})