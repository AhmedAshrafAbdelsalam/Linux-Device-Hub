add_executable(EXAMPLE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(EXAMPLE LINUX_DEVICE_HUB)
target_link_libraries(EXAMPLE ";m;bluetooth")
