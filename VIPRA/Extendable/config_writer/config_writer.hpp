#ifndef PEDESTRIAN_CONFIG_WRITER_HPP
#define PEDESTRIAN_CONFIG_WRITER_HPP

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"
#include <memory>

namespace VIPRA {
struct PedestrianBuilderData {
  PedestrianBuilderData() {}
  virtual ~PedestrianBuilderData() = default;
};
}  // namespace VIPRA

class PedestrianConfigWriterException : public std::runtime_error {
 public:
  PedestrianConfigWriterException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw PedestrianConfigWriterException(message); }
};

class PedestrianConfigWriter {
 public:
  virtual ~PedestrianConfigWriter() = default;

  virtual void        configure(const VIPRA::Config::Map& configMap) = 0;
  virtual void        initialize() = 0;
  virtual std::string buildPedestrians(const std::string& filePath) = 0;
};

#endif