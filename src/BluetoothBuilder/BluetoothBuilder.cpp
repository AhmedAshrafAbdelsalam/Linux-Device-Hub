#ifdef BLUETOOTH
#include <BluetoothBuilder/BluetoothBuilder.hpp>

BluetoothBuilder::BluetoothBuilder(Bluetooth* instance) {
  this->senderInstance = instance;
}

BluetoothBuilder& BluetoothBuilder::setReceiverAddress(
    const std::string& addr) {
  this->senderInstance->setReceiverAddress(addr);
  return *this;
}

BluetoothBuilder& BluetoothBuilder::setSocketType(const int& socType) {
  this->senderInstance->setSocketType(socType);
  return *this;
}

BluetoothBuilder& BluetoothBuilder::setProtocol(const int& protocol) {
  this->senderInstance->setProtocol(protocol);
  return *this;
}

BluetoothBuilder& BluetoothBuilder::setAddressFamily(const int& addrFamily) {
  this->senderInstance->setAddressFamily(addrFamily);
  return *this;
}

BluetoothBuilder& BluetoothBuilder::setChannel(const int& channel) {
  this->senderInstance->setChannel(channel);
  return *this;
}
#endif