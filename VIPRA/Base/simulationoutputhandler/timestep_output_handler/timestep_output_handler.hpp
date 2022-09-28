#ifndef TIMESTEP_OUTPUT_HANDLER_HPP
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include "../simulation_output_handler.hpp"

class TimestepOutputHandler : public SimulationOutputHandler {
 private:
  size_t frequency;

 public:
  void configure(const CONFIG_MAP& configMap) override;
  bool isOutputCriterionMet(const Simulation&    simulation,
                            const PedestrianSet& pedSet,
                            const ObstacleSet&   obsSet,
                            const Goals&         goals) override;
  void writeToDocument(OutputDataWriter&    outputDataWriter,
                       const Simulation&    simulation,
                       const PedestrianSet& pedestrianSet) override;
};

#endif
