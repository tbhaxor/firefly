cmake_minimum_required(VERSION 3.10)

project(firefly)
set(PROJECT_VERSION 2.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++17)

option(Firefly_ENABLE_DOUBLE_PRECISION "Whether or not to enable double precision. If this is false, float will be used." OFF)
option(Firefly_ENABLE_EXAMPLES "Whether or not to enable examples" OFF)

if (${Firefly_ENABLE_DOUBLE_PRECISION})
    add_definitions(-DDOUBLE_PRECISION=1)
endif()

include_directories(headers)

add_library(${PROJECT_NAME}_static STATIC)
add_library(${PROJECT_NAME}_shared SHARED)

set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

add_library(Firefly::Shared ALIAS ${PROJECT_NAME}_shared)
add_library(Firefly::Static ALIAS ${PROJECT_NAME}_static)

add_subdirectory(src)

if (${Firefly_ENABLE_EXAMPLES})
    message(STATUS "Enabling examples build")
    add_subdirectory(examples)
endif()

install(TARGETS ${PROJECT_NAME}_static ${PROJECT_NAME}_shared)
install(DIRECTORY headers/ DESTINATION include)
