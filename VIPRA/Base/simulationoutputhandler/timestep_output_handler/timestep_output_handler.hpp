#ifndef TIMESTEP_OUTPUT_HANDLER_HPP
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include "../simulation_output_handler.hpp"

class TimestepOutputHandler : public SimulationOutputHandler {
 private:
  size_t frequency;

 public:
  void configure(const CONFIG_MAP& configMap) override;
  bool isOutputCriterionMet(const PedestrianSet& pedSet,
                            const ObstacleSet&   obsSet,
                            const Goals&         goals,
                            size_t               timestep) override;
  void writeToDocument(OutputDataWriter&    outputDataWriter,
                       const PedestrianSet& pedestrianSet,
                       size_t               timestep) override;
};

#endif
