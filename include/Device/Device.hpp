#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <Types/Types.hpp>
#include <any>
#include <exception>
#include <unordered_map>
#include <iostream>

/// @brief Exception if the file decsriptor returned -1 (error opening file)
class FileCreationError : std::exception {};

class Device {
 public:
  /* Deleted */
  /// @brief Copy constructor
  Device(const Device&) = delete;

  /// @brief Move constructor
  Device(Device&&) = delete;

  /// @brief Copy assignment operator
  Device& operator=(const Device&) = delete;

  /// @brief Move assignment operator
  Device& operator=(Device&&) = delete;

  /// @brief Destructor
  virtual ~Device();

  /// @brief Getter for last value read/written for device
  virtual std::any GetValue() const = 0;

  /// @brief List of all active devices
  static std::unordered_map<DeviceType, Device*> active_devices;

 protected:
  /// @brief Default Constructor
  explicit Device(const int& fd);

  /// @brief Constructor
  explicit Device(const std::string& path, const int& o_flag);

  int fd = -1;
};