cmake_minimum_required(VERSION 3.10)
project(png)

set(CMAKE_CXX_STANDARD 11)
find_package(PNG REQUIRED)
add_executable(png main.cpp pngHandle.h pngHandle.cpp)
target_link_libraries(png PUBLIC PNG::PNG)