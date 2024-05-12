#include <Device/Device.hpp>

std::unordered_map<DeviceType, Device*> Device::active_devices;

Device::Device(const int& fd) : fd(fd) {}

Device::Device(const std::string& path, const int& o_flag) {
  fd = open(path.c_str(), o_flag);
}

Device::~Device() {
  close(fd);
}