#ifndef VIPRA_BHVR_EXCEPTIONS_HPP
#define VIPRA_BHVR_EXCEPTIONS_HPP

#include <stdexcept>

class BuilderException : public std::runtime_error {
 public:
  explicit BuilderException() : std::runtime_error("") {}
  [[noreturn]] static void error() { throw BuilderException(); }
};

#endif