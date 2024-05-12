cmake_minimum_required(VERSION 3.8)
project(LinuxDeviceHub)

set(CMAKE_CXX_STANDARD 17)

set(AVAILABLE_DEVICES "devices" CACHE STRING "List_of_active_devices")

include(linux-cmake-build-config.cmake)

add_definitions(${AVAILABLE_DEVICES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
