
#include "timestep_console_logger.hpp"

void
TimestepConsoleLogger::configure(const VIPRA::ConfigMap& configMap) {
  frequency = std::stoul(configMap.at("outputFrequency"));
}

bool
TimestepConsoleLogger::isOutputCriterionMet([[maybe_unused]] const PedestrianSet& pedSet,
                                            [[maybe_unused]] const ObstacleSet&   obsSet,
                                            [[maybe_unused]] const Goals&         goals,
                                            VIPRA::t_step                         currTimestep) {
  return (currTimestep % frequency == 0);
}

void
TimestepConsoleLogger::writeOutput([[maybe_unused]] OutputDataWriter& outputDataWriter,
                                   const PedestrianSet&               pedestrianSet,
                                   VIPRA::t_step                      currTimestep) {
  LJ::Debug(simLogger, "TIMESTEP: {}", currTimestep);

  const auto&       coords = pedestrianSet.getPedestrianCoordinates();
  const VIPRA::size coordCnt = coords.size();

  for (VIPRA::idx i = 0; i < coordCnt; ++i) {
    LJ::Debug(simLogger, "Pedestrian {}: x:{}, y:{}, z:{}", i, coords.at(i).x, coords.at(i).y);
  }
}
