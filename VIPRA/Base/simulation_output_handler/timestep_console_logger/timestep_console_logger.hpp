#ifndef TIMESTEP_CONSOLE_LOGGER_HPP
#define TIMESTEP_CONSOLE_LOGGER_HPP

#include <spdlog/spdlog.h>
#include <simulation_output_handler/simulation_output_handler.hpp>

class TimestepConsoleLogger : public SimulationOutputHandler {
 public:
  void configure(const VIPRA::CONFIG::Map&) override;
  bool isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&, const Goals&,
                            VIPRA::t_step) override;
  void writeOutput(OutputDataWriter&, const PedestrianSet&, VIPRA::t_step) override;

 private:
  VIPRA::t_step timestep;
  VIPRA::t_step frequency;
};

#endif