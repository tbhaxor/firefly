cmake_minimum_required(VERSION 3.10)

project(firefly LANGUAGES CXX VERSION 2.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++17)

cmake_policy(SET CMP0135 NEW)

option(Firefly_ENABLE_DOUBLE_PRECISION "Whether or not to enable double precision. If this is false, float will be used." OFF)
option(Firefly_ENABLE_EXAMPLES "Whether or not to enable examples" OFF)
option(Firefly_ENABLE_TESTS "Whether or not to enable tests" OFF)

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

if (${Firefly_ENABLE_TESTS})
    enable_testing()

    include(FetchContent)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    message(STATUS "Enabling tests build")
    FetchContent_MakeAvailable(googletest)
    add_subdirectory(tests)
endif()

install(TARGETS ${PROJECT_NAME}_static ${PROJECT_NAME}_shared)
install(DIRECTORY headers/ DESTINATION include)
