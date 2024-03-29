cmake_minimum_required(VERSION 3.10)

project(firefly)
set(PROJECT_VERSION 2.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0135 NEW)

option(Firefly_ENABLE_DOUBLE_PRECISION "Whether or not to enable double precision. If this is false, float will be used." ON)
option(Firefly_ENABLE_EXAMPLES "Whether or not to enable examples" OFF)
option(Firefly_ENABLE_TESTS "Whether or not to enable tests" OFF)

if (${Firefly_ENABLE_DOUBLE_PRECISION})
    add_definitions(-DDOUBLE_PRECISION=1)
endif()

include_directories(headers)


add_library(${PROJECT_NAME} SHARED)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
endif()

add_subdirectory(src)

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

install(TARGETS ${PROJECT_NAME})
install(DIRECTORY headers/ DESTINATION include)
