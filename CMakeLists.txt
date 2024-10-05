cmake_minimum_required(VERSION 3.10)

project(firefly)

set(PROJECT_VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0135 NEW)
cmake_policy(SET CMP0076 NEW)

option(Firefly_ENABLE_EXAMPLES "Whether or not to enable examples" OFF)
option(Firefly_ENABLE_TESTS "Whether or not to enable tests" OFF)

include_directories(headers)

add_library(${PROJECT_NAME} INTERFACE)

if (${Firefly_ENABLE_EXAMPLES})
    message(STATUS "Enabling examples build")
    add_subdirectory(examples)
endif()

if (${Firefly_ENABLE_TESTS})
    message(STATUS "Enabling tests")
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(googletest)
    FetchContent_GetProperties(googletest)

    include(GoogleTest)
    include_directories("${googletest_SOURCE_DIR}/googlemock/include")
    enable_testing()
    add_subdirectory(tests)
endif()

install(DIRECTORY headers/ DESTINATION include)
