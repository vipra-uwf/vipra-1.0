#include "timestep_output_handler.hpp"

void
TimestepOutputHandler::configure(const CONFIG_MAP& configMap) {
  frequency = std::stoi(configMap.at("outputFrequency"));
}

bool
TimestepOutputHandler::isOutputCriterionMet(const Simulation&    simulation,
                                            const PedestrianSet& pedSet,
                                            const ObstacleSet&   obsSet,
                                            const Goals&         goals) {
  return (simulation.getTimestep() % frequency == 0);
}

void
TimestepOutputHandler::writeToDocument(OutputDataWriter&    outputDataWriter,
                                       const Simulation&    simulation,
                                       const PedestrianSet& pedestrianSet) {
  outputDataWriter.addFloatValue("NEW_TIMESTEP", 0);

  const auto& coords = pedestrianSet.getPedestrianCoordinates();

  for (const auto& coord : coords) {
    outputDataWriter.addFloatValue("x", coord.axis[0]);
    outputDataWriter.addFloatValue("y", coord.axis[1]);
  }
}
