#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "../definitions/type_definitions.hpp"
#include "../outputdatawriter/output_data_writer.hpp"
#include "../simulation/simulation/simulation.hpp"

#include "../../Extendable/pedestrianset/pedestrian_set.hpp"

class SimulationOutputHandler {

 public:
  virtual ~SimulationOutputHandler() = default;

  virtual void configure(const CONFIG_MAP&) = 0;
  virtual bool isOutputCriterionMet(const Simulation&,
                                    const PedestrianSet&,
                                    const ObstacleSet&,
                                    const Goals&) = 0;
  virtual void writeToDocument(OutputDataWriter&,
                               const Simulation&,
                               const PedestrianSet&) = 0;
};

#endif