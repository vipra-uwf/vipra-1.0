#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "../definitions/type_definitions.hpp"
#include "../outputdatawriter/output_data_writer.hpp"
#include "../simulation/simulation/simulation.hpp"

#include "../../Interfaces/pedestrianset/pedestrian_set.hpp"

class SimulationOutputHandler {
 public:
  virtual ~SimulationOutputHandler() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;
  virtual void setOutputDataWriter(OutputDataWriter& outputDataWriter) = 0;
  virtual void setPedestrianSet(const PedestrianSet& pedestrianSet) = 0;
  virtual void setSimulation(const Simulation& simulation) = 0;
  virtual bool isOutputCriterionMet() = 0;
  virtual void writeToDocument() = 0;
};

#endif