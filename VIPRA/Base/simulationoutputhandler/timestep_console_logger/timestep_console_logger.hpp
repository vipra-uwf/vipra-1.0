#ifndef TIMESTEP_CONSOLE_LOGGER_HPP
#define TIMESTEP_CONSOLE_LOGGER_HPP

#include "../simulation_output_handler.hpp"

class TimestepConsoleLogger : public SimulationOutputHandler {
 private:
  size_t timestep;
  size_t frequency;

 public:
  void configure(const CONFIG_MAP& configMap) override;
  bool isOutputCriterionMet(const Simulation&,
                            const PedestrianSet&,
                            const ObstacleSet&,
                            const Goals&) override;
  void writeToDocument(OutputDataWriter&    outputDataWriter,
                       const Simulation&    simulation,
                       const PedestrianSet& pedestrianSet) override;
};

#endif