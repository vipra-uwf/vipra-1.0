//
// Created by joe on 8/3/21.
//

#include "human_behavior_model.hpp"
#include "../dsl/dsl_human_behavior.hpp"

HumanBehaviorModel::HumanBehaviorModel() : seed(time(nullptr)) {}

HumanBehaviorModel::~HumanBehaviorModel() {
  for (auto hb : this->humanBehaviors) {
    delete hb;
  }
}

void
HumanBehaviorModel::timestep(const PedestrianSet&          pedSet,
                             const ObstacleSet&            obsSet,
                             const Goals&                  goals,
                             std::shared_ptr<VIPRA::State> state,
                             VIPRA::delta_t                timestep) {

  const VIPRA::size pedCnt = pedSet.getNumPedestrians();

  for (auto humanBehavior : this->humanBehaviors) {
    humanBehavior->update(pedSet, obsSet, goals, timestep);
  }

  // Iterate through the pedestrian list and apply our behavior to it.
  for (VIPRA::idx i = 0; i < pedCnt; ++i) {
    bool behaviorDecided = false;
    for (auto humanBehavior : this->humanBehaviors) {
      if (humanBehavior->select(pedSet, obsSet, goals, i)) {
        humanBehavior->act(pedSet, obsSet, goals, i, timestep);

        // Decide if this person is under the influence of the human behavior model
        if (humanBehavior->decide(pedSet, obsSet, goals, i)) {
          behaviorDecided = true;
        }
      }
    }

    if (behaviorDecided) {
      // current pedestrian is under the influence of the human behavior model
      // TODO something with that
    }
  }
}

void
HumanBehaviorModel::configure(const VIPRA::ConfigMap& configMap) {
  for (const auto& config : configMap) {
    if (config.first.find("behavior#") != std::string::npos) {
      // This is a behavior, so add it to the human behaviors. The value is the filename.
      // TODO this relative path is hardcoded, may want to change this in the future -RG
      this->humanBehaviors.push_back(new DslHumanBehavior(config.second + ".behavior", this->seed));
    }

    if (config.first == "random_seed") {
      // Override the seed value for deterministic runs.
      this->seed = static_cast<unsigned int>(atoi(config.second.c_str()));
    }
  }
}

/**
 * Initialize this model after the pedestrian set has been read in.
 */
void
HumanBehaviorModel::initialize(const ObstacleSet&   obstacleSet,
                               const PedestrianSet& pedSet,
                               const Goals&         goals) {
  for (auto humanBehavior : this->humanBehaviors) {
    humanBehavior->initialize(obstacleSet, pedSet, goals);
  }
}
