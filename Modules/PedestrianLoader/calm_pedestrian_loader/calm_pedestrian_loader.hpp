#ifndef PEDESTRIAN_POSITION_LOADER_HPP
#define PEDESTRIAN_POSITION_LOADER_HPP

#include <fstream>
#include <vector>

#include <json/json.h>
#include <spdlog/spdlog.h>

#include <pedestrian_loader/pedestrian_loader.hpp>

#include <definitions/dimensions.hpp>

struct CalmPedData : public VIPRA::PedData {
  CalmPedData() : VIPRA::PedData{"CalmPedData"} {}
  VIPRA::f3dVec positions;
  std::vector<float> masses;
  std::vector<float> shoulderLengths;
  std::vector<float> desiredSpeeds;
  std::vector<float> reactionTimes;
};

class CalmPedestrianLoader : public PedestrianLoader {
 public:
  void configure(const VIPRA::CONFIG::Map& configMap) override;
  void initialize() override;
  [[nodiscard]] std::unique_ptr<VIPRA::PedData> loadPedestrians(
      const std::string& filePath) const override;

  CalmPedestrianLoader() = default;
};

#endif