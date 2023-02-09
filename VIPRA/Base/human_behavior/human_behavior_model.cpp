//
// Created by joe on 8/3/21.
//

#include "human_behavior_model.hpp"

#include <algorithm>
#include <filesystem>

#include <mock_behaviors/mock_behaviors_builder.hpp>

void
HumanBehaviorModel::configure(const VIPRA::Config::Map& configMap) {
  seed = configMap["seed"].asUInt();
  loadBehaviors(configMap.getStringVector("behaviors"));
}

void
HumanBehaviorModel::initialize(const PedestrianSet& pedSet, const ObstacleSet& obsSet, const Goals& goals) {
  for (auto& behavior : humanBehaviors) {
    behavior.initialize(pedSet, obsSet, goals);
  }
}

void
HumanBehaviorModel::timestep(const PedestrianSet&          pedSet,
                             const ObstacleSet&            obsSet,
                             const Goals&                  goals,
                             std::shared_ptr<VIPRA::State> state,
                             VIPRA::delta_t                dT) {
  std::for_each(humanBehaviors.begin(), humanBehaviors.end(), [&](HumanBehavior& behavior) {
    behavior.timestep(pedSet, obsSet, goals, state, dT);
  });
}

void
HumanBehaviorModel::loadBehaviors(std::vector<std::string> behaviors) {

#ifdef MOCK_BEHAVIORS
  loadMockBehaviors(behaviors);
#else

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
    return builder.build(behaviorName, filePath, seed);
  });
#endif

  spdlog::info("Done Loading Behaviors");
}

void
HumanBehaviorModel::loadMockBehaviors(const std::vector<std::string>& behaviors) {

  MockBehaviorBuilder builder;
  spdlog::info("Loading Mock Behaviors");
  humanBehaviors.resize(behaviors.size());
  std::transform(behaviors.begin(), behaviors.end(), humanBehaviors.begin(), [&](const std::string& behaviorName) {
    spdlog::info("Loading Mock Behavior: {}", behaviorName);
    return builder.buildMockBehavior(behaviorName);
  });

  spdlog::info("Done Loading Mock Behaviors");
}
