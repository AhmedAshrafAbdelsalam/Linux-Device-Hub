add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Device)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/PowerLedController)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/JoystickController)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Observable)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Bluetooth)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/BluetoothBuilder)

add_library(LINUX_DEVICE_HUB STATIC ${LINUX_DEVICE_HUB_SOURCES})