#pragma once
#ifdef BLUETOOTH
#include <Bluetooth/Bluetooth.hpp>
#include <memory>
#include <string>

class BluetoothBuilder {
 public:
  BluetoothBuilder(Bluetooth*);
  BluetoothBuilder& setReceiverAddress(const std::string&);
  BluetoothBuilder& setSocketType(const int&);
  BluetoothBuilder& setProtocol(const int&);
  BluetoothBuilder& setAddressFamily(const int&);
  BluetoothBuilder& setChannel(const int&);

 private:
  Bluetooth* senderInstance;
};
#endif