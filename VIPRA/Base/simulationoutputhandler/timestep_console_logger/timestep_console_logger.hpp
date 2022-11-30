#ifndef TIMESTEP_CONSOLE_LOGGER_HPP
#define TIMESTEP_CONSOLE_LOGGER_HPP

#include "../simulation_output_handler.hpp"

class TimestepConsoleLogger : public SimulationOutputHandler {
 private:
  size_t timestep;
  size_t frequency;

 public:
  void configure(const CONFIG_MAP& configMap) override;
  bool isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&, const Goals&, size_t timestep) override;
  void writeToDocument(OutputDataWriter&    outputDataWriter,
                       const PedestrianSet& pedestrianSet,
                       size_t               timestep) override;
};

#endif