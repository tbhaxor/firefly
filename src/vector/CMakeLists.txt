
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

target_sources(${PROJECT_NAME}_shared PRIVATE ${SOURCES})
target_sources(${PROJECT_NAME}_static PRIVATE ${SOURCES})