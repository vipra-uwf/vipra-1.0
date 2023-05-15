#ifndef VIPRA_BHVR_EXCEPTIONS_HPP
#define VIPRA_BHVR_EXCEPTIONS_HPP

#include <stdexcept>

class DSLException : public std::runtime_error {
 public:
  explicit DSLException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw DSLException(message); }
};

#endif