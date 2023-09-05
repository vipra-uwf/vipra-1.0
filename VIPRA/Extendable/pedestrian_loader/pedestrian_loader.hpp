#ifndef VIPRA_PEDESTRIAN_LOADER_HPP
#define VIPRA_PEDESTRIAN_LOADER_HPP

#include <memory>

#include "configuration/config.hpp"
#include "definitions/type_definitions.hpp"

namespace VIPRA {
/**
 * @class PedestrianLoaderException
 * @brief Custom exception class for handling errors related to PedestrianLoader.
 *
 * This class is a custom exception class derived from std::runtime_error.
 * It is used to handle errors that may occur in the PedestrianLoader class.
 */
class PedestrianLoaderException : public std::runtime_error {
 public:
  explicit PedestrianLoaderException(const std::string& message)
      : std::runtime_error(message) {}
  /**
   * @brief Static function to throw a PedestrianLoaderException with the given error message.
   *
   * @param message The error message for the exception.
   */
  static void error(const std::string& message) {
    throw PedestrianLoaderException(message);
  }
};

/**
 * @class PedestrianLoader
 * @brief Interface for loading pedestrian data from a file.
 *
 * This class is an interface for loading pedestrian data from a file.
 */
class PedestrianLoader {
 public:
  virtual void configure(const VIPRA::Config& configMap) = 0;
  virtual void initialize() = 0;

  [[nodiscard]] virtual std::vector<VIPRA::pcoord> loadPedestrians(
      const std::string& filePath) const = 0;

  PedestrianLoader(const PedestrianLoader&) = default;
  PedestrianLoader(PedestrianLoader&&) = default;
  PedestrianLoader& operator=(const PedestrianLoader&) = default;
  PedestrianLoader& operator=(PedestrianLoader&&) = default;
  PedestrianLoader() = default;
  virtual ~PedestrianLoader() = default;
};
}  // namespace VIPRA

#endif