#ifndef VIPRA_PEDESTRIAN_LOADER_HPP
#define VIPRA_PEDESTRIAN_LOADER_HPP

#include <memory>
#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {
struct PedData {
  std::string type;
  PedData(const PedData&) = default;
  PedData(PedData&&) = delete;
  PedData& operator=(const PedData&) = default;
  PedData& operator=(PedData&&) = delete;
  explicit PedData(std::string dtype) : type(std::move(dtype)) {}
  virtual ~PedData() = default;
};
}  // namespace VIPRA

class PedestrianLoaderException : public std::runtime_error {
 public:
  explicit PedestrianLoaderException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw PedestrianLoaderException(message); }
};

class PedestrianLoader {
 public:
  virtual void                                          configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void                                          initialize() = 0;
  [[nodiscard]] virtual std::unique_ptr<VIPRA::PedData> loadPedestrians(const std::string& filePath) const = 0;


  PedestrianLoader(const PedestrianLoader&) = default;
  PedestrianLoader(PedestrianLoader&&) = delete;
  PedestrianLoader& operator=(const PedestrianLoader&) = default;
  PedestrianLoader& operator=(PedestrianLoader&&) = delete;
  PedestrianLoader() = default;
  virtual ~PedestrianLoader() = default;
};

#endif