#ifdef JOYSTICK
#include <JoystickController/JoystickController.hpp>

JoystickController::JoystickController(const std::string path,
                                       const int& o_flag)
    : Device(path, o_flag) {
  try {
    if (fd == -1)
      throw FileCreationError();
  } catch (const FileCreationError& ex) {
    std::cerr << "Error while opening file";
    this->~JoystickController();
  }
}

JoystickController& JoystickController::GetInstance() {
  static JoystickController instance{"/dev/input/js0", O_RDONLY};

  static bool first_time = true;

  if (first_time == true) {
    Device::active_devices.insert({DeviceType::Joystick, &instance});
    first_time = false;
  }

  return instance;
}

std::any JoystickController::GetValue() const {
  return std::any(ev);
}

void JoystickController::ReadInput() {
  read(fd, &ev, sizeof(ev));
  notify(DeviceType::Joystick);
}

void JoystickController::notify(const std::any& current_device) {
  for (auto& itr : Observers)
    itr->act(current_device);
}

JoystickController::~JoystickController() {}
#endif
