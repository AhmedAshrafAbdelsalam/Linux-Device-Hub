#pragma once

#include <algorithm>
#include <any>
#include <vector>
#include <Observer/Observer.hpp>

class Observable {
 public:
  /// @brief Notification for all observers when event occurs
  /// @param notifier Which event notifying the observers, it's left for the
  /// user to define it's type
  virtual void notify(const std::any&) = 0;

  /// @brief Adding a new observer
  /// @param in The observer to be added
  void subscribe(Observer*);

  /// @brief Removing a new observer
  /// @param in The observer to be removed
  void unsubscribe(Observer*);

 protected:
  /// @brief List of all observers subscribing to the observable
  std::vector<Observer*> Observers;
};