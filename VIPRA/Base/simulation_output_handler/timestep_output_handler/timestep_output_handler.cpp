#include "timestep_output_handler.hpp"

void
TimestepOutputHandler::configure(const VIPRA::ConfigMap& configMap) {
  frequency = std::stoul(configMap.at("outputFrequency"));
}

bool
TimestepOutputHandler::isOutputCriterionMet([[maybe_unused]] const PedestrianSet& pedSet,
                                            [[maybe_unused]] const ObstacleSet&   obsSet,
                                            [[maybe_unused]] const Goals&         goals,
                                            VIPRA::t_step                         timestep) {
  return (timestep % frequency == 0);
}

void
TimestepOutputHandler::writeOutput(OutputDataWriter&    outputDataWriter,
                                   const PedestrianSet& pedestrianSet,
                                   VIPRA::t_step        timestep) {
  outputDataWriter.addFloatValue("NEW_TIMESTEP", timestep);

  const auto& coords = pedestrianSet.getPedestrianCoordinates();

  for (const auto& coord : coords) {
    outputDataWriter.addFloatValue("x", coord.x);
    outputDataWriter.addFloatValue("y", coord.y);
  }
}
