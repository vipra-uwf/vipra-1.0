
#include "timestep_console_logger.hpp"

void TimestepConsoleLogger::configure(const VIPRA::CONFIG::Map& configMap) {
  frequency = configMap["outputFrequency"].asUInt64();
}

bool TimestepConsoleLogger::isOutputCriterionMet(const PedestrianSet&, const ObstacleSet&, const Goals&,
                                                 VIPRA::t_step currTimestep) {
  return (currTimestep % frequency == 0);
}

void TimestepConsoleLogger::writeOutput(OutputDataWriter&, const PedestrianSet& pedestrianSet, VIPRA::t_step currTimestep) {
  spdlog::debug("TIMESTEP: {}", currTimestep);

  const auto&       coords = pedestrianSet.getPedestrianCoordinates();
  const VIPRA::size coordCnt = coords.size();

  for (VIPRA::idx i = 0; i < coordCnt; ++i) {
    spdlog::debug("Pedestrian {}: x:{}, y:{}, z:{}", std::to_string(i), coords.at(i).x, coords.at(i).y, coords.at(i).z);
  }
}