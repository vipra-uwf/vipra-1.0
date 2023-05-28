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
  VIPRA::time_ms                                     elapsedTime;

  void calculateRealElapsedSeconds();

 public:
  Clock();
  void start();
  void stop();
  void printRealStartTime();
  void printRealDuration();
  void printRealEndTime();
  void addSimulationTimeMs(VIPRA::time_ms);
  void printSimulationDuration() const;

  void configure(const VIPRA::CONFIG::Map&);
};

#endif