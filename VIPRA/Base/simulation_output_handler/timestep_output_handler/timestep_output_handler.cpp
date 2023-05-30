#include "timestep_output_handler.hpp"

void TimestepOutputHandler::configure(const VIPRA::CONFIG::Map& configMap) {
  frequency = configMap["outputFrequency"].asUInt64();
}

bool TimestepOutputHandler::isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                                 VIPRA::t_step timestep) {
  return (timestep % frequency == 0);
}

void TimestepOutputHandler::writeOutput(OutputDataWriter& outputDataWriter, const PedestrianSet& pedestrianSet,
                                        VIPRA::t_step timestep) {
  outputDataWriter.addFloatValue("NEW_TIMESTEP", static_cast<float>(timestep));

  const auto& coords = pedestrianSet.getPedestrianCoordinates();

  for (const auto& coord : coords) {
    outputDataWriter.addFloatValue("x", coord.x);
    outputDataWriter.addFloatValue("y", coord.y);
  }
}
