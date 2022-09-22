#ifndef TIMESTEP_OUTPUT_HANDLER_HPP
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include "../simulation_output_handler.hpp"

class TimestepOutputHandler : public SimulationOutputHandler {
 private:
  OutputDataWriter& outputDataWriter;
  PedestrianSet&    pedestrianSet;
  Simulation&       simulation;

 public:
  void configure(const CONFIG_MAP& configMap) override;
  void setOutputDataWriter(OutputDataWriter& outputDataWriter) override;
  void setPedestrianSet(const PedestrianSet& pedestrianSet) override;
  void setSimulation(const Simulation& simulation) override;
  bool isOutputCriterionMet() override;
  void writeToDocument() override;
};

#endif
