add_library(${PROJECT_NAME} SHARED firefly.cpp)

install(
    TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
)