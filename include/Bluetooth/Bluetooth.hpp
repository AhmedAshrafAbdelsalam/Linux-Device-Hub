#pragma once
#ifdef BLUETOOTH
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <fcntl.h>
#include <unistd.h>
#include <Device/Device.hpp>
#include <Observer/Observer.hpp>
#include <string>

#define FAILED 1
#define SUCCEDED 0

class BluetoothBuilder;

class Bluetooth : public Observer, public Device {
 public:
  friend BluetoothBuilder;

  Bluetooth(const Bluetooth&) = delete;
  Bluetooth& operator=(const Bluetooth&) = delete;
  ~Bluetooth();

  static Bluetooth& GetInstance();

  int init();
  int sendData(const std::string&);
  std::any GetValue() const override;
  virtual void act(const std::any&) override;

 private:
  Bluetooth(const int&);

  void setReceiverAddress(const std::string&);
  void setSocketType(const int&);
  void setProtocol(const int&);
  void setAddressFamily(const int&);
  void setChannel(const int&);

  struct bluetoothConfig {
    struct sockaddr_rc bluetoothSocket = {0};
    int protocol;
    int socketType;
  };

  bluetoothConfig config;
  std::string data;
};
#endif