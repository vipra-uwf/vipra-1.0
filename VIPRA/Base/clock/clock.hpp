#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"
#include <spdlog/spdlog.h>

class Clock {
 private:
  std::chrono::time_point<std::chrono::system_clock> realStartTime;
  std::chrono::time_point<std::chrono::system_clock> realEndTime;
  std::chrono::time_point<std::chrono::system_clock> simulationEndTime;
  std::chrono::duration<double>                      realElapsedSeconds;
  void                                               calculateRealElapsedSeconds();
  unsigned long                                      simulationElapsedMs;

 public:
  Clock();
  void start();
  void stop();
  void printRealStartTime();
  void printRealDuration();
  void printRealEndTime();
  void addSimulationTimeMs(VIPRA::delta_t seconds);
  void printSimulationDuration();

  void configure(const VIPRA::Config::Map& config);
};

#endif