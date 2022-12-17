#ifndef PEDESTRIAN_POSITION_LOADER_HPP
#define PEDESTRIAN_POSITION_LOADER_HPP

#include <fstream>

#include "jsoncpp/json/json.h"
#include "pedestrianloader/pedestrian_loader.hpp"

struct PedestrianPositions : public PedMapType {
  PedestrianPositions() : PedMapType{"PedestrianPositions"} {}
  VIPRA::f3dVec positions;
};

class PedestrianPositionLoader : public PedestrianLoader {
 public:
  void                        configure(const VIPRA::ConfigMap& configMap) override;
  void                        initialize() override;
  std::unique_ptr<PedMapType> LoadPedestrians(const std::string& filePath) const override;
};

#endif