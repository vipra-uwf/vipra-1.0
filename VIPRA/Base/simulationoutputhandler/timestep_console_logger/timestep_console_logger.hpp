#ifndef TIMESTEP_CONSOLE_LOGGER_HPP
#define TIMESTEP_CONSOLE_LOGGER_HPP

#include "../simulation_output_handler.hpp"
#include "logging/logging.hpp"

class TimestepConsoleLogger : public SimulationOutputHandler {
 private:
  VIPRA::t_step timestep;
  VIPRA::t_step frequency;

 public:
  void configure(const VIPRA::ConfigMap& configMap) override;
  bool isOutputCriterionMet(const PedestrianSet&,
                            const ObstacleSet&,
                            const Goals&,
                            VIPRA::t_step timestep) override;
  void writeToDocument(OutputDataWriter&    outputDataWriter,
                       const PedestrianSet& pedestrianSet,
                       VIPRA::t_step        timestep) override;
};

#endif