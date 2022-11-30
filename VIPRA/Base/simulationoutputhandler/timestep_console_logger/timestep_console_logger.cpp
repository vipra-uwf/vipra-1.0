
#include "timestep_console_logger.hpp"

void
TimestepConsoleLogger::configure(const CONFIG_MAP& configMap) {
  frequency = std::stoi(configMap.at("outputFrequency"));
}

bool
TimestepConsoleLogger::isOutputCriterionMet(const PedestrianSet& pedSet,
                                            const ObstacleSet&   obsSet,
                                            const Goals&         goals,
                                            size_t               timestep) {
  return (timestep % frequency == 0);
}

void
TimestepConsoleLogger::writeToDocument(OutputDataWriter&    outputDataWriter,
                                       const PedestrianSet& pedestrianSet,
                                       size_t               timestep) {
  std::printf("TIMESTEP: %i", timestep);
  const auto& coords = pedestrianSet.getPedestrianCoordinates();
  for (int i = 0; i < coords.size(); ++i) {
    std::printf("Pedestrian: %i : X: %f, Y: %f\n", i, coords.at(i).axis[0], coords.at(i).axis[1]);
  }
}
