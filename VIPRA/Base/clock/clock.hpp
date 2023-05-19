#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

#include <spdlog/spdlog.h>
#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"


class Clock {
 private:
  std::chrono::time_point<std::chrono::system_clock> realStartTime;
  std::chrono::time_point<std::chrono::system_clock> realEndTime;
  std::chrono::time_point<std::chrono::system_clock> simulationEndTime;
  std::chrono::duration<double>                      realElapsedSeconds;
  void                                               calculateRealElapsedSeconds();
  uint64_t                                           simulationElapsedMs;

 public:
  Clock();
  void start();
  void stop();
  void printRealStartTime();
  void printRealDuration();
  void printRealEndTime();
  void addSimulationTimeMs(VIPRA::delta_t seconds);
  void printSimulationDuration() const;

  void configure(const VIPRA::CONFIG::Map& config);
};

#endif