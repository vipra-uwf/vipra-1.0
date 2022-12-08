#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "../../Extendable/goals/goals.hpp"
#include "../../Extendable/obstacleset/obstacle_set.hpp"
#include "../../Extendable/pedestrianset/pedestrian_set.hpp"
#include "../definitions/type_definitions.hpp"
#include "../outputdatawriter/output_data_writer.hpp"

class SimulationOutputHandler {

 public:
  virtual ~SimulationOutputHandler() = default;

  virtual void configure(const CONFIG_MAP&) = 0;
  virtual bool isOutputCriterionMet(const PedestrianSet&,
                                    const ObstacleSet&,
                                    const Goals&,
                                    size_t timestep) = 0;
  virtual void writeToDocument(OutputDataWriter&, const PedestrianSet&, size_t timestep) = 0;
};

#endif