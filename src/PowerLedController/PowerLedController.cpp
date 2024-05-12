#ifdef POWERLED
#include <PowerLedController/PowerLedController.hpp>

PowerLedController::PowerLedController(const std::string& path,
                                       const int& o_flag)
    : Device(path, o_flag) {
  try {
    if (fd == -1)
      throw FileCreationError();
  } catch (const FileCreationError& ex) {
    std::cerr << "Error while opening file";
    this->~PowerLedController();
  }
}

PowerLedController::PowerLedController(PowerLedController&& in) noexcept
    : Device(in.fd) {
  this->data = std::move(in.data);
  this->data = nullptr;
}

PowerLedController& PowerLedController::operator=(PowerLedController&& in) {
  this->data = std::move(in.data);
  this->data = nullptr;
  return *this;
}

PowerLedController& PowerLedController::GetInstance() {
  static PowerLedController instance{"/sys/class/leds/PWR/brightness",
                                     O_WRONLY};

  static bool first_time = true;

  if (first_time == true) {
    Device::active_devices.insert({DeviceType::PowerLed, &instance});
    first_time = false;
  }

  return instance;
}

std::any PowerLedController::GetValue() const {
  return std::any(data);
}

void PowerLedController::WriteOutput(const char* in) {
  data = in;
  write(fd, data, std::strlen(data));
}

void PowerLedController::act(const std::any& current_device) {
  if (std::any_cast<DeviceType>(current_device) ==
      DeviceType::Joystick) {
    if (std::any_cast<JoystickEvent>(
            active_devices[DeviceType::Joystick]->GetValue())
            .type == 1)
      WriteOutput(PWR_LED_ON);
    else if (std::any_cast<JoystickEvent>(
                 active_devices[DeviceType::Joystick]->GetValue())
                 .type == 2)
      WriteOutput(PWR_LED_OFF);
  }
}

PowerLedController::~PowerLedController() {}
#endif
