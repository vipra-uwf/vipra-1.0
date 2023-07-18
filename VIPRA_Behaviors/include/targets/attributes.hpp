#ifndef VIPRA_BEHAVIORS_ATTRIBUTES_HPP
#define VIPRA_BEHAVIORS_ATTRIBUTES_HPP

#include <definitions/state.hpp>
#include <definitions/type_definitions.hpp>
#include <stdexcept>
#include <variant>

#include <definitions/dimensions.hpp>
#include <definitions/dsl_types.hpp>
#include <definitions/sim_pack.hpp>
#include <events/event.hpp>
#include <targets/target.hpp>
#include "events/event_status.hpp"

namespace BHVR {
enum class Attribute {
  POSITION,
  VELOCITY,
  GOAL,
  STATE,
  LOCATION,
  STATUS,
  INVALID,
};

enum class Property {
  TYPE,
  POSITION,
  DIMENSIONS,
};

using cAttributeValue = const void*;
using AttributeValue = void*;

class AttributeHandling {
 public:
  [[nodiscard]] inline static cAttributeValue getValue(Target target, Attribute attr, Simpack pack) {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        return getPedValue(target, attr, pack);
      case TargetType::EVENT:
        return getEventValue(target, attr, pack);
      case TargetType::INVALID:
        return nullptr;
    }
  }

  inline static void setValue(Target target, Attribute attr, Simpack pack, VIPRA::State& state,
                              cAttributeValue value) {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        setPedValue(target, attr, pack, state, value);
        return;
      case TargetType::EVENT:
        setEventValue(target, attr, pack, value);
        return;
      case TargetType::INVALID:
        return;
    }
  }

  // inline static void compareValues(cAttributeValue value1, cAttributeValue value2) {}

  template <typename T>
  [[nodiscard]] inline static cAttributeValue storeValue(T&& value) {
    valueStore.push_back(new T(value));
    return valueStore.back();
  }

 private:
  // NOLINTNEXTLINE Bug in clang-tidy (https://bugs.llvm.org/show_bug.cgi?id=48040) : ignores (cppcoreguidelines-avoid-non-const-global-variables)
  static std::vector<cAttributeValue> valueStore;

  inline static cAttributeValue getPedValue(Target target, Attribute attr, Simpack pack) {
    switch (attr) {
      case Attribute::POSITION:
        return &pack.pedSet.getPedCoords(target.targetIdx);
      case Attribute::VELOCITY:
        return &pack.pedSet.getPedVelocity(target.targetIdx);
      case Attribute::GOAL:
        return &pack.goals.getEndGoal(target.targetIdx);
      case Attribute::STATE:
        return &pack.context.pedStates.at(target.targetIdx);
      default:
        throw std::runtime_error("Invalid Pedestrian Attribute");
    }
  }

  inline static cAttributeValue getEventValue(Target target, Attribute attr, Simpack pack) {
    switch (attr) {
      case Attribute::LOCATION:
        // TODO (rolland) : get this added in when locations are done
        throw std::runtime_error("Event Locations Not Implmented");
      case Attribute::STATUS:
        return &pack.context.events.at(target.targetIdx).getStatus();
      default:
        throw std::runtime_error("Invalid Event Attribute");
    }
  }

  inline static void setPedValue(Target target, Attribute attr, Simpack pack, VIPRA::State& state,
                                 cAttributeValue value) {
    switch (attr) {
      case Attribute::POSITION:
        state.coords.at(target.targetIdx) = *static_cast<const VIPRA::pcoord*>(value);
        return;
      case Attribute::VELOCITY:
        updateVelocity(target, pack, state, value);
        return;
      case Attribute::GOAL:
        // TODO (rolland) update this with goals
        throw std::runtime_error("Updating Pedestrian Goals Is Not Implemented");
        return;
      case Attribute::STATE:
        pack.context.pedStates.at(target.targetIdx) = *static_cast<const BHVR::stateUID*>(value);
        return;
      default:
        throw std::runtime_error("Invalid Pedestrian Attribute");
    }
  }

  inline static void setEventValue(Target target, Attribute attr, Simpack pack, cAttributeValue value) {
    switch (attr) {
      case Attribute::LOCATION:
        // TODO (rolland) : get this added in when locations are done
        throw std::runtime_error("Event Locations Not Implmented");
      case Attribute::STATUS:
        pack.context.events.at(target.targetIdx).setStatus(*static_cast<const BHVR::EventStatus*>(value));
        return;
      default:
        throw std::runtime_error("Invalid Event Attribute");
    }
  }

  static inline void updateVelocity(Target target, Simpack pack, VIPRA::State& state, cAttributeValue value) {
    state.velocities.at(target.targetIdx) = *static_cast<const VIPRA::veloc*>(value);
    VIPRA::f3d originalPos = pack.pedSet.getPedCoords(target.targetIdx);
    state.coords.at(target.targetIdx) = originalPos + (state.velocities.at(target.targetIdx) * pack.dT);
  }
};
}  // namespace BHVR

#endif