project(people-counter)

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV 3 REQUIRED)

include(CMakeToolsHelpers OPTIONAL)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(people-counter src/main.cpp)

target_link_libraries(people-counter ${OpenCV_LIBS})