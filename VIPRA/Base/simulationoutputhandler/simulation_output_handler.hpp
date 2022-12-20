#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "outputdatawriter/output_data_writer.hpp"
#include "pedestrianset/pedestrian_set.hpp"

class SimulationOutputHandler {

 public:
  virtual ~SimulationOutputHandler() = default;

  virtual void configure(const VIPRA::ConfigMap&) = 0;
  virtual bool isOutputCriterionMet(const PedestrianSet&,
                                    const ObstacleSet&,
                                    const Goals&,
                                    VIPRA::t_step timestep) = 0;
  virtual void writeToDocument(OutputDataWriter&, const PedestrianSet&, VIPRA::t_step timestep) = 0;
};

#endif