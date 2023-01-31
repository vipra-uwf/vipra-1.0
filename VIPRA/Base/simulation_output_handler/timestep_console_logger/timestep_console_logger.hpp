#ifndef TIMESTEP_CONSOLE_LOGGER_HPP
#define TIMESTEP_CONSOLE_LOGGER_HPP

#include "../simulation_output_handler.hpp"
#include <spdlog/spdlog.h>

class TimestepConsoleLogger : public SimulationOutputHandler {
 private:
  VIPRA::t_step timestep;
  VIPRA::t_step frequency;

 public:
  void configure(const VIPRA::Config::Map& configMap) override;
  bool isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&, const Goals&, VIPRA::t_step timestep) override;
  void writeOutput(OutputDataWriter& outputDataWriter, const PedestrianSet& pedestrianSet, VIPRA::t_step timestep) override;
};

#endif