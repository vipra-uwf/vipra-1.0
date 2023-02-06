//
// Created by joe on 8/3/21.
//

#include "human_behavior_model.hpp"

#include <algorithm>
#include <filesystem>

void
HumanBehaviorModel::configure(const VIPRA::Config::Map& configMap) {
  seed = configMap["seed"].asUInt();
  loadBehaviors(configMap.getStringVector("behaviors"));
}

void
HumanBehaviorModel::initialize(const ObstacleSet& obsSet, const PedestrianSet& pedSet, const Goals& goals) {
  for (auto& behavior : humanBehaviors) {
    behavior.initialize(obsSet, pedSet, goals);
  }
}

void
HumanBehaviorModel::timestep(const PedestrianSet&,
                             const ObstacleSet&,
                             const Goals&,
                             std::shared_ptr<VIPRA::State>,
                             VIPRA::delta_t) {}

void
HumanBehaviorModel::loadBehaviors(std::vector<std::string> behaviors) {
  BehaviorBuilder builder;

  spdlog::info("Loading Behaviors");
  humanBehaviors.resize(behaviors.size());

  std::transform(behaviors.begin(), behaviors.end(), humanBehaviors.begin(), [&](const std::string& behaviorName) {
    const auto filePath = std::filesystem::current_path() / "../Behaviors" / (behaviorName + ".behavior");

    if (!std::filesystem::exists(filePath)) {
      spdlog::error("Behavior \"{}\" Does NOT Exist at {}", behaviorName, filePath.c_str());
      BehaviorModelException::Throw("Behavior File Doesn't Exist");
    }

    spdlog::info("Loading Behavior: {} at {}", behaviorName, std::filesystem::canonical(filePath).c_str());
    return builder.build(filePath, seed);
  });

  spdlog::info("Done Loading Behaviors");
}