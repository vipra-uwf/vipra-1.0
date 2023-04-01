#ifndef VIPRA_BEHAVIORS_EXCEPTIONS_HPP
#define VIPRA_BEHAVIORS_EXCEPTIONS_HPP

#include <stdexcept>

class DSL_Exception : public std::runtime_error {
 public:
  DSL_Exception(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw DSL_Exception(message); }
};

#endif