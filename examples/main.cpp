#include <Bluetooth/Bluetooth.hpp>
#include <BluetoothBuilder/BluetoothBuilder.hpp>
#include <JoystickController/JoystickController.hpp>
#include <PowerLedController/PowerLedController.hpp>
#include <memory>
#include <thread>

int main() {
  JoystickController* joyStick(&(JoystickController::GetInstance()));
  PowerLedController* powerLed(&(PowerLedController::GetInstance()));
  Bluetooth* bluetooth(&(Bluetooth::GetInstance()));

  BluetoothBuilder configuration(bluetooth);

  configuration.setReceiverAddress("7C:67:A2:5B:EB:B7");
  configuration.setAddressFamily(AF_BLUETOOTH);
  configuration.setChannel(1);
  configuration.setProtocol(BTPROTO_RFCOMM);
  configuration.setSocketType(SOCK_STREAM);

  bluetooth->init();

  joyStick->subscribe(powerLed);
  joyStick->subscribe(bluetooth);

  std::thread joystickListner([&joyStick]() {
    while (1) {
      joyStick->ReadInput();
    }
  });

  joystickListner.join();
}