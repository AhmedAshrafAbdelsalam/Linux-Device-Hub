#pragma once
#ifdef JOYSTICK
#include <iostream>
#include <Device/Device.hpp>
#include <Observable/Observable.hpp>

class JoystickController : public Observable, public Device {
 public:
  /// @brief The only instance available for the controller
  static JoystickController& GetInstance();

  /// @brief Destructor
  virtual ~JoystickController();

  /// @brief Reading the input from joystick (Blocking)
  void ReadInput();

  /// @brief A getter for the last value read from event handler
  /// @return The pressed joystick button
  virtual std::any GetValue() const override;

  /// @brief Implementation of the observable notify method
  virtual void notify(const std::any&) override;

 private:
  /// @brief Constructor
  JoystickController(const std::string path, const int& o_flag);

  /// @brief Copy Constructor
  JoystickController(const JoystickController&) = delete;

  /// @brief Copy assignment operator
  JoystickController& operator=(const JoystickController&) = delete;

  /// @brief Struct to save joystick event
  JoystickEvent ev;
};
#endif