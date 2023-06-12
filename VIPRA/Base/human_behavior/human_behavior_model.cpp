
#include "human_behavior_model.hpp"

#include <algorithm>
#include <filesystem>

void HumanBehaviorModel::configure(const VIPRA::CONFIG::Map& configMap) {
  seed = configMap["seed"].asUInt();
  loadBehavior(configMap.getStringVector("behaviors"));
}

void HumanBehaviorModel::initialize(const PedestrianSet& pedSet,
                                    const ObstacleSet& obsSet, const Goals& goals) {
  for (auto& behavior : humanBehaviors) {
    behavior.initialize(pedSet, obsSet, goals);
  }
}

void HumanBehaviorModel::timestep(PedestrianSet& pedSet, ObstacleSet& obsSet,
                                  Goals& goals, VIPRA::State& state, VIPRA::delta_t dT) {
  for (auto& behavior : humanBehaviors) {
    behavior.timestep(pedSet, obsSet, goals, state, dT);
  }
}

void HumanBehaviorModel::loadBehavior(const std::vector<std::string>& behaviors) {
  BHVR::BehaviorBuilder builder;
  spdlog::info("Loading {} Behaviors", behaviors.size());
  humanBehaviors.resize(behaviors.size());
  std::transform(behaviors.begin(), behaviors.end(), humanBehaviors.begin(),
                 [&](const std::string& behaviorName) {
                   const auto filePath = std::filesystem::current_path() /
                                         "../Behaviors" / (behaviorName + ".behavior");
                   return builder.build(behaviorName, filePath, seed);
                 });

  spdlog::info("Done Loading Behavior");
}