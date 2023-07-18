#ifndef TIMESTEP_OUTPUT_HANDLER_HPP
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include <simulation_output_handler/simulation_output_handler.hpp>

/**
 * @brief Outputs timesteps, x,y,z positions of each pedestrian
 * 
 */
class TimestepOutputHandler : public SimulationOutputHandler {
 private:
  VIPRA::t_step frequency;

 public:
  void configure(const VIPRA::CONFIG::Map&) override;
  bool isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&, const Goals&,
                            VIPRA::t_step) override;
  void writeOutput(OutputDataWriter&, const PedestrianSet&, VIPRA::t_step) override;
};

#endif
