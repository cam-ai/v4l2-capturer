cmake_minimum_required(VERSION 3.10.0)
INCLUDE_DIRECTORIES(capture/inc)

project(camera_capture)

enable_testing()

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -o0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -o3 -Wall")

add_subdirectory(./capture)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/bin)

add_executable(camera_capture camera_capture.cpp)
target_link_libraries(camera_capture capture)

add_subdirectory(./test)

