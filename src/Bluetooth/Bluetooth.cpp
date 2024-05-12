#ifdef BLUETOOTH
#include <Bluetooth/Bluetooth.hpp>

Bluetooth::Bluetooth(const int& in) : Device(in) {}

Bluetooth::~Bluetooth() {
  close(fd);
}

void Bluetooth::setReceiverAddress(const std::string& addr) {
  str2ba(addr.c_str(), &(config.bluetoothSocket.rc_bdaddr));
}
void Bluetooth::setSocketType(const int& socType) {
  config.socketType = socType;
}
void Bluetooth::setProtocol(const int& protocol) {
  config.protocol = protocol;
}
void Bluetooth::setAddressFamily(const int& addrFamily) {
  config.bluetoothSocket.rc_family = addrFamily;
}
void Bluetooth::setChannel(const int& channel) {
  config.bluetoothSocket.rc_channel = channel;
}

int Bluetooth::init() {
  fd = socket(config.bluetoothSocket.rc_family,
                                config.socketType, config.protocol);

  if (connect(fd, (struct sockaddr*)&config.bluetoothSocket,
              sizeof(config.bluetoothSocket)) < 0)
    return FAILED;
  else
    return SUCCEDED;
}

int Bluetooth::sendData(const std::string& data) {
  if (write(fd, data.c_str(), data.length()) < 0)
    return FAILED;
  else
    return SUCCEDED;
}

std::any Bluetooth::GetValue() const {
  return std::any(data);
}

void Bluetooth::act(const std::any& current_device) {
  if (std::any_cast<DeviceType>(current_device) ==
      DeviceType::Joystick) {
    data = std::to_string(std::any_cast<JoystickEvent>(
                              active_devices[DeviceType::Joystick]->GetValue())
                              .type) +
           "\n";
    data = data +
           std::to_string(std::any_cast<JoystickEvent>(
                              active_devices[DeviceType::Joystick]->GetValue())
                              .number) +
           "\n";
    data = data +
           std::to_string(std::any_cast<JoystickEvent>(
                              active_devices[DeviceType::Joystick]->GetValue())
                              .value) +
           "\n";
    data = data +
           std::to_string(std::any_cast<JoystickEvent>(
                              active_devices[DeviceType::Joystick]->GetValue())
                              .time) +
           "\n";
  }

  sendData(data);
}

Bluetooth& Bluetooth::GetInstance() {
  static Bluetooth instance{-1};

  static bool first_time = true;

  if (first_time == true) {
    Device::active_devices.insert({DeviceType::Bluetooth, &instance});
    first_time = false;
  }

  return instance;
}
#endif
