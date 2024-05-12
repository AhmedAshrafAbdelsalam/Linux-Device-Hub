#pragma once
#ifdef POWERLED
#include <iostream>
#include <Device/Device.hpp>
#include <Observer/Observer.hpp>

#define LED_ON "255"
#define LED_OFF "0"

class PowerLedController : public Observer, public Device {
 public:
  /// @brief Move constructor
  PowerLedController(PowerLedController&&) noexcept;

  /// @brief Move assignment operator
  PowerLedController& operator=(PowerLedController&&);

  /// @brief The only instance available for the controller
  static PowerLedController& GetInstance();

  /// @brief Destructor
  virtual ~PowerLedController();

  /// @brief Change the state of led when an event occurs
  void WriteOutput(const char*);

  /// @brief Observer method
  virtual void act(const std::any&) override;

 private:
  /// @brief Constructor
  explicit PowerLedController(const std::string&, const int&);

  /// @brief Copy constructor
  PowerLedController(const PowerLedController&) = delete;

  /// @brief Copy assignment operator
  PowerLedController& operator=(const PowerLedController&) = delete;

  /// @brief Implementation of event getter
  virtual std::any GetValue() const override;

  /// @brief Buffer to hold the data
  const char* data;
};
#endif