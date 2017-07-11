project(people-counter)

cmake_minimum_required(VERSION 2.8.12)

find_package(OpenCV 3 REQUIRED)

include(CMakeToolsHelpers OPTIONAL)
include(${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)

include_directories(${OpenCV_INCLUDE_DIRS})

conan_basic_setup()

add_executable(people-counter src/main.cpp)

target_link_libraries(people-counter ${CONAN_LIBS})
target_link_libraries(people-counter ${OpenCV_LIBS})