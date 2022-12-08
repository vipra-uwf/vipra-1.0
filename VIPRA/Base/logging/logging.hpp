#ifndef VIPRA_LOGGING_HPP
#define VIPRA_LOGGING_HPP

#include <iostream>

template <typename... P> static void
Error(const std::string& message, P... params) {
  std::cerr << message << '\n';
}

template <typename... P> static void
Warn(const std::string& message, P... params) {
  std::cout << message << '\n';
}

template <typename... P> static void
Info(const std::string& message, P... params) {
  std::cout << message << '\n';
}

template <typename... P> static void
Debug(const std::string& message, P... params) {
  std::cout << message << '\n';
}
#endif