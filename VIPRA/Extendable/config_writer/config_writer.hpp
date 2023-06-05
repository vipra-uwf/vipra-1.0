#ifndef PEDESTRIAN_CONFIG_WRITER_HPP
#define PEDESTRIAN_CONFIG_WRITER_HPP

#include <memory>
#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {
struct PedestrianBuilderData {
  PedestrianBuilderData() = default;
  PedestrianBuilderData(const PedestrianBuilderData&) = default;
  PedestrianBuilderData(PedestrianBuilderData&&) = delete;
  PedestrianBuilderData& operator=(const PedestrianBuilderData&) = default;
  PedestrianBuilderData& operator=(PedestrianBuilderData&&) = delete;
  virtual ~PedestrianBuilderData() = default;
};
}  // namespace VIPRA

class PedestrianConfigWriterException : public std::runtime_error {
 public:
  explicit PedestrianConfigWriterException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw PedestrianConfigWriterException(message); }
};

class PedestrianConfigWriter {
 public:
  virtual void        configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void        initialize() = 0;
  virtual std::string buildPedestrians(const std::string& filePath) = 0;


  PedestrianConfigWriter(const PedestrianConfigWriter&) = default;
  PedestrianConfigWriter(PedestrianConfigWriter&&) = delete;
  PedestrianConfigWriter& operator=(const PedestrianConfigWriter&) = default;
  PedestrianConfigWriter& operator=(PedestrianConfigWriter&&) = delete;
  PedestrianConfigWriter() = default;
  virtual ~PedestrianConfigWriter() = default;
};

#endif