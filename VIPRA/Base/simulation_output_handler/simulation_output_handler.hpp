#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacle_set/obstacle_set.hpp"
#include "output_data_writer/output_data_writer.hpp"
#include "pedestrian_set/pedestrian_set.hpp"

/**
 * @brief Coordinates output writers
 * 
 */
class SimulationOutputHandler {
 public:
  virtual void configure(const VIPRA::CONFIG::Map&) = 0;
  virtual bool isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&,
                                    const Goals&, VIPRA::t_step timestep) = 0;
  virtual void writeOutput(OutputDataWriter&, const PedestrianSet&,
                           VIPRA::t_step timestep) = 0;

  SimulationOutputHandler(const SimulationOutputHandler&) = default;
  SimulationOutputHandler(SimulationOutputHandler&&) = delete;
  SimulationOutputHandler& operator=(const SimulationOutputHandler&) = default;
  SimulationOutputHandler& operator=(SimulationOutputHandler&&) = delete;
  SimulationOutputHandler() = default;
  virtual ~SimulationOutputHandler() = default;
};

#endif