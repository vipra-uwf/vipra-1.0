
#include "human_behavior_model.hpp"

#include <algorithm>
#include <filesystem>

/**
 * @brief Gets module values from module params
 * 
 * @param configMap : 
 */
void HumanBehaviorModel::configure(const VIPRA::CONFIG::Map& configMap) {
  seed = configMap["seed"].asUInt();
  loadBehavior(configMap.getStringVector("behaviors"));
}

/**
 * @brief Initializes each behavior
 * 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 */
void HumanBehaviorModel::initialize(const PedestrianSet& pedSet,
                                    const ObstacleSet& obsSet, const Goals& goals) {
  for (auto& behavior : humanBehaviors) {
    behavior.initialize(pedSet, obsSet, goals);
  }
}

/**
 * @brief Calls each behavior's timestep method
 * 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 * @param state : 
 * @param dT : 
 */
void HumanBehaviorModel::timestep(PedestrianSet& pedSet, ObstacleSet& obsSet,
                                  Goals& goals, VIPRA::State& state, VIPRA::delta_t dT) {
  for (auto& behavior : humanBehaviors) {
    behavior.timestep(pedSet, obsSet, goals, state, dT);
  }
}

/**
 * @brief Builds each behavior from the vector of file paths
 * 
 * @param behaviors : 
 */
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