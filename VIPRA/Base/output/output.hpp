#ifndef VIPRA_OUTPUT_HPP
#define VIPRA_OUTPUT_HPP

#include <memory>

#include "definitions/type_definitions.hpp"
#include "sink.hpp"

namespace VIPRA {
class Output {
 public:
  /**
   * @brief Sets the output sink for output
   * 
   * @param outputSink : output sink
   */
  static inline void initialize(std::unique_ptr<VIPRA::Sink>&& outputSink) {
    sink = std::move(outputSink);
  }

  /**
   * @brief Gets configuration from module params
   * 
   * @param config : module parameters
   */
  static inline void configure(const VIPRA::Config& config) {
    outputFreq = config["outputFrequency"].get<VIPRA::cnt>();
  }

  /**
   * @brief Adds a value to the overall simulation
   * 
   * @tparam T : value type
   * @param key : json key for value
   * @param value : value
   */
  template <typename T>
  static inline void simValue(const char* key, T&& value) {
    jsonData[key] = std::forward<T>(value);
  }

  /**
   * @brief Adds a value to output for the current timestep
   * 
   * @tparam T : value type
   * @param key : json key for value
   * @param value : value
   */
  template <typename T>
  static inline void timestepValue(const char* key, T&& value) {
    if (timestep % outputFreq == 0)
      jsonData["timesteps"][timestep / outputFreq][key] = std::forward<T>(value);
  }

  /**
   * @brief Adds a value to output for a specific pedestrian
   * 
   * @tparam T : value type
   * @param pedIdx : pedestrian to add value to
   * @param key : json key for value
   * @param value : value
   */
  template <typename T>
  static inline void pedValue(VIPRA::idx pedIdx, const char* key, T&& value) {
    jsonData["pedestrians"][pedIdx][key] = std::forward<T>(value);
  }

  /**
   * @brief Adds a value to output for a specific pedestrian for the current timestep
   * 
   * @tparam T : value type
   * @param pedIdx : pedestrian to add value to
   * @param key : json key for value
   * @param value : value
   */
  template <typename T>
  static inline void pedTimestepValue(VIPRA::idx pedIdx, const char* key, T&& value) {
    if (timestep % outputFreq == 0)
      jsonData["timesteps"][timestep / outputFreq]["pedestrians"][pedIdx][key] =
          std::forward<T>(value);
  }

  static inline void simValue(const char* key, const VIPRA::f3d& value) {
    jsonData[key] = {value.x, value.y, value.z};
  }

  static inline void timestepValue(const char* key, const VIPRA::f3d& value) {
    if (timestep % outputFreq == 0) {
      jsonData["timesteps"][timestep / outputFreq][key] = {value.x, value.y, value.z};
    }
  }

  static inline void pedValue(VIPRA::idx pedIdx, const char* key,
                              const VIPRA::f3d& value) {
    jsonData["pedestrians"][pedIdx][key] = {value.x, value.y, value.z};
    ;
  }

  static inline void pedTimestepValue(VIPRA::idx pedIdx, const char* key,
                                      const VIPRA::f3d& value) {
    if (timestep % outputFreq == 0) {
      jsonData["timesteps"][timestep / outputFreq]["pedestrians"][pedIdx][key] = {
          value.x, value.y, value.z};
    }
  }

  /**
   * @brief Advances current timestep for output
   * 
   */
  static inline void nextTimestep() { ++timestep; }

  /**
   * @brief Writes json data to output sink
   * 
   */
  static inline void write() { sink->write(jsonData); }

 private:
  // NOLINTBEGIN Bug in clang-tidy (https://bugs.llvm.org/show_bug.cgi?id=48040) : ignores (cppcoreguidelines-avoid-non-const-global-variables)
  static std::unique_ptr<VIPRA::Sink> sink;
  static VIPRA::cnt                   timestep;
  static nlohmann::json               jsonData;
  static VIPRA::cnt                   outputFreq;
  // NOLINTEND
};
}  // namespace VIPRA

#endif