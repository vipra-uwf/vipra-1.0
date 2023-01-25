#ifndef TIMESTEP_OUTPUT_HANDLER_HPP
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include "../simulation_output_handler.hpp"

class TimestepOutputHandler : public SimulationOutputHandler {
 private:
  VIPRA::t_step frequency;

 public:
  void configure(const VIPRA::ConfigMap& configMap) override;
  bool isOutputCriterionMet(const PedestrianSet& pedSet,
                            const ObstacleSet&   obsSet,
                            const Goals&         goals,
                            VIPRA::t_step        timestep) override;
  void writeOutput(OutputDataWriter& outputDataWriter, const PedestrianSet& pedestrianSet, VIPRA::t_step timestep) override;
};

#endif
