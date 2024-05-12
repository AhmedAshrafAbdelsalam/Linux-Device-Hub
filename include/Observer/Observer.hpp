#pragma once

#include <any>

class Observer {
 public:
  /// @brief Action to be done by observers when event occurs
  virtual void act(const std::any&) = 0;
};