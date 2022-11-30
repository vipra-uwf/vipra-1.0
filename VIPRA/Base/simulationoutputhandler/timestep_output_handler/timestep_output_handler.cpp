#include "timestep_output_handler.hpp"

void
TimestepOutputHandler::configure(const CONFIG_MAP& configMap) {
  frequency = std::stoi(configMap.at("outputFrequency"));
}

bool
TimestepOutputHandler::isOutputCriterionMet(const PedestrianSet& pedSet,
                                            const ObstacleSet&   obsSet,
                                            const Goals&         goals,
                                            size_t               timestep) {
  return (timestep % frequency == 0);
}

void
TimestepOutputHandler::writeToDocument(OutputDataWriter&    outputDataWriter,
                                       const PedestrianSet& pedestrianSet,
                                       size_t               timestep) {
  outputDataWriter.addFloatValue("NEW_TIMESTEP", timestep);

  const auto& coords = pedestrianSet.getPedestrianCoordinates();

  for (const auto& coord : coords) {
    outputDataWriter.addFloatValue("x", coord.axis[0]);
    outputDataWriter.addFloatValue("y", coord.axis[1]);
  }
}
