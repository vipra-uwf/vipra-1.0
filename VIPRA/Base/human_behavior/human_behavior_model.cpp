
#include "human_behavior_model.hpp"

#include <algorithm>
#include <cstdint>
#include <filesystem>

#include "definitions/type_definitions.hpp"
#include "spdlog/spdlog.h"

namespace VIPRA {
/**
 * @brief Gets module values from module params
 * 
 * @param configMap : 
 */
void HumanBehaviorModel::configure(const VIPRA::Config& configMap) {
  seed = BHVR::seed{configMap["seed"].get<VIPRA::size>()};
  loadBehaviors(configMap["behaviors"]);
}

/**
 * @brief Initializes each behavior
 * 
 * @param pedSet : 
 * @param obsSet : 
 * @param goals : 
 */
void HumanBehaviorModel::initialize(const VIPRA::PedestrianSet& pedSet,
                                    const VIPRA::ObstacleSet&   obsSet,
                                    VIPRA::Goals&               goals) {
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
void HumanBehaviorModel::timestep(VIPRA::PedestrianSet& pedSet,
                                  VIPRA::ObstacleSet& obsSet, VIPRA::Goals& goals,
                                  VIPRA::State& state, VIPRA::delta_t dT) {
  for (auto& behavior : humanBehaviors) {
    behavior.timestep(pedSet, obsSet, goals, state, dT);
  }
}

/**
 * @brief Builds each behavior from the vector of file paths
 * 
 * @param behaviors : 
 */
void HumanBehaviorModel::loadBehaviors(const VIPRA::Config& behaviors) {
  BHVR::BehaviorBuilder builder;
  spdlog::info("Loading {} Behaviors", behaviors.size());

  if (!behaviors.is_array())
    BehaviorModelException::error("Configuration File Behaviors not in proper format");

  for (const auto& value : behaviors.items()) {
    const auto filePath = std::filesystem::current_path() / "../Behaviors" /
                          (value.value().get<std::string>() + ".bhvr");
    humanBehaviors.push_back(builder.build(value.value(), filePath, seed));
  }

  spdlog::info("Done Loading Behaviors");
}
}  // namespace VIPRA