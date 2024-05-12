#include <Observable/Observable.hpp>

void Observable::subscribe(Observer* in) {
  Observers.emplace_back(in);
}

void Observable::unsubscribe(Observer* in) {
  Observers.erase(std::remove(Observers.begin(), Observers.end(), in),
                  Observers.end());
}