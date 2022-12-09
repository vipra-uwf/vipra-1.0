#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "definitions/type_definitions.hpp"
#include "goals/goals.hpp"
#include "obstacleset/obstacle_set.hpp"
#include "outputdatawriter/output_data_writer.hpp"
#include "pedestrianset/pedestrian_set.hpp"


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