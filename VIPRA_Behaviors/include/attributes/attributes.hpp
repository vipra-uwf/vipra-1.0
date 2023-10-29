#ifndef VIPRA_BEHAVIORS_ATTRIBUTES_HPP
#define VIPRA_BEHAVIORS_ATTRIBUTES_HPP

#include <stdexcept>

#include "behavior/exceptions.hpp"
#include "definitions/dimensions.hpp"
#include "definitions/dsl_types.hpp"
#include "definitions/sim_pack.hpp"
#include "definitions/state.hpp"
#include "definitions/type_definitions.hpp"
#include "events/event.hpp"
#include "events/event_status.hpp"
#include "targets/target.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
/**
  * @brief Attribute Type
  * 
  */
enum class Attribute {
  INVALID = 0,
  POSITION,
  VELOCITY,
  GOAL,
  STATE,
  LOCATION,
  STATUS,
};

/**
 * @brief Property Type
 * 
 */
enum class Property {
  TYPE,
  POSITION,
  DIMENSIONS,
};

/**
 * @brief Attribute Value Type Information
 * 
 */
enum class Type {
  INVALID = 0,
  NUMBER,
  COORD,
  STATE,
  STATUS,
};

/**
 * @brief Holds an immutable attribute value and its type
 * 
 */
struct CAttributeValue {
  Type        type;
  const void* value;

  CAttributeValue(Type aType, const void* aVal) : type(aType), value(aVal) {}

  inline void type_check(Type check) const {
    if (type != check) DSLException::error("Invalid Type");
  }
};

/**
 * @brief Holds a mutable attribute value and its type
 * 
 */
struct AttributeValue {
  Type  type;
  void* value;

  /**
   * @brief Checks that the value is a given type, throws exception if not correct type
   * 
   * @param check : type value should be
   */
  inline void type_check(Type check) const {
    if (type != check) DSLException::error("Invalid Type");
  }
};

/**
 * @brief Handles all getting/setting of attributes in Behaviors
 * 
 */
class AttributeHandling {
 public:
  /**
   * @brief Returns the specified attribute value of the target
   * 
   * @param target : target to get attribute from
   * @param attr : attribute type to get
   * @param pack : simulation pack
   * @return CAttributeValue 
   */
  [[nodiscard]] inline static auto get_value(Target target, Attribute attr, Simpack pack) -> CAttributeValue {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        return get_ped_value(target, attr, pack);
      case TargetType::EVENT:
        return get_event_value(target, attr, pack);
      case TargetType::INVALID:
        return {Type::INVALID, nullptr};
    }
  }

  /**
   * @brief Sets a targets attribute value
   * 
   * @param target : target to set the attribute of
   * @param attr : attribute to set
   * @param pack : simulation pack
   * @param state : timestep state
   * @param value : value to set attribute to
   */
  inline static void set_value(Target target, Attribute attr, Simpack pack, VIPRA::State& state,
                               CAttributeValue value) {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        set_ped_value(target, attr, pack, state, value);
        return;
      case TargetType::EVENT:
        set_event_value(target, attr, pack, value);
        return;
      case TargetType::INVALID:
        return;
    }
  }

  /**
   * @brief Scales a targets attribute value
   * 
   * @param target : target to scale the attribute of
   * @param attr : attribute to scale
   * @param pack : simulation pack
   * @param state : timestep state
   * @param value : value to scale attribute by
   */
  inline static void scale_value(Target target, Attribute attr, Simpack pack, VIPRA::State& state,
                                 CAttributeValue value) {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        scale_ped_value(target, attr, pack, state, value);
        return;
      case TargetType::EVENT:
        DSLException::error("Cannot Scale Event Value");
        return;
      case TargetType::INVALID:
        return;
    }
  }

  /**
   * @brief Checks if two AttributeValues are equal
   * 
   * @param value1 : first value
   * @param value2 : second value
   * @return true : if equal
   * @return false : if not equal or not same type
   */
  [[nodiscard]] inline static auto equal(CAttributeValue value1, CAttributeValue value2) -> bool {
    if (value1.type != value2.type) return false;

    switch (value1.type) {
      case Type::INVALID:
        return false;
      case Type::NUMBER:
        return *static_cast<const float*>(value1.value) == *static_cast<const float*>(value2.value);
      case Type::COORD:
        return *static_cast<const VIPRA::f3d*>(value1.value) == *static_cast<const VIPRA::f3d*>(value2.value);
      case Type::STATE:
        return *static_cast<const BHVR::stateUID*>(value1.value) ==
               *static_cast<const BHVR::stateUID*>(value2.value);
      case Type::STATUS:
        return *static_cast<const BHVR::EventStatus*>(value1.value) ==
               *static_cast<const BHVR::EventStatus*>(value2.value);
    }
  }

  /**
   * @brief Adds an attribute value to the value store, for later use in atoms
   * 
   * @tparam T : value type
   * @param type : attribute type
   * @param value : attribute value
   * @return CAttributeValue
   */
  template <typename value_t>
  [[nodiscard]] inline static auto store_value(Type type, value_t&& value) -> CAttributeValue {
    valueStore.emplace_back(type, new value_t(value));
    return valueStore.back();
  }

  inline static void cleanup() {
    // NOLINTBEGIN
    for (auto data : valueStore) {
      switch (data.type) {
        case Type::INVALID:
          break;
        case Type::NUMBER:
          delete static_cast<const float*>(data.value);
          break;
        case Type::COORD:
          delete static_cast<const VIPRA::f3d*>(data.value);
          break;
        case Type::STATE:
          delete static_cast<const BHVR::stateUID*>(data.value);
          break;
        case Type::STATUS:
          delete static_cast<const BHVR::EventStatus*>(data.value);
          break;
      }
    }
    // NOLINTEND
  }

 private:
  // NOLINTNEXTLINE Bug in clang-tidy (https://bugs.llvm.org/show_bug.cgi?id=48040) : ignores (cppcoreguidelines-avoid-non-const-global-variables)
  static std::vector<CAttributeValue> valueStore;

  /**
   * @brief Gets a pedestrians attribute value
   * 
   * @param target : pedestrian to get the attribute from
   * @param attr : attribute type
   * @param pack : simulation pack
   * @return CAttributeValue 
   */
  inline static auto get_ped_value(Target target, Attribute attr, Simpack pack) -> CAttributeValue {
    switch (attr) {
      case Attribute::POSITION:
        return {Type::COORD, &pack.get_pedset().getPedCoords(target.targetIdx)};
      case Attribute::VELOCITY:
        return {Type::COORD, &pack.get_pedset().getPedVelocity(target.targetIdx)};
      case Attribute::GOAL:
        return {Type::COORD, &pack.get_goals().getEndGoal(target.targetIdx)};
      case Attribute::STATE:
        return {Type::STATE, &pack.get_context().pedStates[target.targetIdx]};
      default:
        DSLException::error("Invalid Pedestrian Attribute");
    }
  }

  /**
   * @brief Gets an events attribute value
   * 
   * @param target : event to get attribute of
   * @param attr : attribute type
   * @param pack : simulation pack
   * @return CAttributeValue 
   */
  inline static auto get_event_value(Target target, Attribute attr, Simpack pack) -> CAttributeValue {
    switch (attr) {
      case Attribute::LOCATION:
        // TODO (rolland) : get this added in when locations are done
        DSLException::error("Event Locations Not Implmented");
      case Attribute::STATUS:
        return {Type::STATUS, &pack.get_context().events[target.targetIdx].get_status()};
      default:
        DSLException::error("Invalid Event Attribute");
    }
  }

  /**
   * @brief Sets a pedestrians attribute
   * 
   * @param target : pedestrian to set the attribute of
   * @param attr : attribute type
   * @param pack : simulation pack
   * @param state : next timestep state
   * @param value : value to set attribute to
   */
  inline static void set_ped_value(Target target, Attribute attr, Simpack pack, VIPRA::State& state,
                                   CAttributeValue value) {
    switch (attr) {
      case Attribute::POSITION:
        set_position(target, state, value);
        return;
      case Attribute::VELOCITY:
        set_velocity(target, pack, state, value);
        return;
      case Attribute::GOAL:
        set_goal(target, pack, value);
        return;
      case Attribute::STATE:
        set_state(target, pack, value);
        return;
      default:
        DSLException::error("Invalid Pedestrian Attribute");
    }
  }

  /**
   * @brief Scales a pedestrians attribute by a given value
   * 
   * @param target : pedestrian to scale the attribute of
   * @param attr : attribute type
   * @param pack : simulation pack
   * @param state : next timestep state
   * @param value : value to set attribute to
   */
  inline static void scale_ped_value(Target target, Attribute attr, Simpack pack, VIPRA::State& state,
                                     CAttributeValue value) {
    switch (attr) {
      case Attribute::POSITION:
        DSLException::error("Cannot Scale Pedestrian Position");
        return;
      case Attribute::VELOCITY:
        scale_velocity(target, pack, state, value);
        return;
      case Attribute::GOAL:
        // TODO (rolland) update this with goals
        DSLException::error("Updating Pedestrian Goals Is Not Implemented");
        return;
      case Attribute::STATE:
        set_state(target, pack, value);
        return;
      default:
        DSLException::error("Invalid Pedestrian Attribute");
    }
  }

  /**
   * @brief Sets an events attribute
   * 
   * @param target : event to set the attribute of
   * @param attr : attribute type
   * @param pack : simulation pack
   * @param value : value to set attribute to
   */
  inline static void set_event_value(Target target, Attribute attr, Simpack pack, CAttributeValue value) {
    switch (attr) {
      case Attribute::LOCATION:
        // TODO (rolland) : get this added in when locations are done
        DSLException::error("Event Locations Not Implmented");
      case Attribute::STATUS:
        pack.get_context().events[target.targetIdx].set_status(
            *static_cast<const BHVR::EventStatus*>(value.value));
        return;
      default:
        DSLException::error("Invalid Event Attribute");
    }
  }

  // ------------------------------------------- SETTERS ------------------------------------------------------------------------

  /**
   * @brief Sets a pedesetrians position
   * 
   * @param target : pedestrian to set the position of
   * @param state : next time step state
   * @param value : value to set position to
   */
  static inline void set_position(Target target, VIPRA::State& state, CAttributeValue value) {
    value.type_check(Type::COORD);
    state.coords[target.targetIdx] = *static_cast<const VIPRA::pcoord*>(value.value);
  }

  /**
   * @brief Sets a pedestrians state attribute
   * 
   * @param target : target to set state for
   * @param pack : simulation pack
   * @param value : value to set attribute to
   */
  static inline void set_state(Target target, Simpack pack, CAttributeValue value) {
    value.type_check(Type::STATE);
    pack.get_context().pedStates[target.targetIdx] = *static_cast<const BHVR::stateUID*>(value.value);
  }

  /**
   * @brief Sets a pedestrians goal, calling the Goals module to recalculate pathing
   * 
   * @param target : target to change velocity of
   * @param pack : simulation pack
   * @param value : value to set velocity to
   */
  static inline void set_goal(Target target, Simpack pack, CAttributeValue value) {
    value.type_check(Type::COORD);
    pack.get_goals().changeEndGoal(target.targetIdx, pack.get_pedset().getPedCoords(target.targetIdx),
                                   *static_cast<const VIPRA::f3d*>(value.value));
  }

  /**
   * @brief Sets a pedestrians velocity, changes next timestep state to reflect that
   * 
   * @param target : target to change velocity of
   * @param pack : simulation pack
   * @param state : next timestep state
   * @param value : value to set velocity to
   */
  static inline void set_velocity(Target target, Simpack pack, VIPRA::State& state, CAttributeValue value) {
    value.type_check(Type::COORD);

    state.velocities[target.targetIdx] = *static_cast<const VIPRA::veloc*>(value.value);

    VIPRA::f3d originalPos = pack.get_pedset().getPedCoords(target.targetIdx);
    state.coords[target.targetIdx] = originalPos + (state.velocities[target.targetIdx] * pack.dT);
  }

  // ------------------------------------------- END SETTERS ------------------------------------------------------------------------

  // --------------------------------------------- SCALING ------------------------------------------------------------------------

  /**
   * @brief Scales a pedestrians velocity, changes next timestep state to reflect that
   * 
   * @param target : target to change velocity of
   * @param pack : simulation pack
   * @param state : next timestep state
   * @param value : value to set velocity to
   */
  static inline void scale_velocity(Target target, Simpack pack, VIPRA::State& state, CAttributeValue value) {
    value.type_check(Type::NUMBER);

    const NumericValue& scale = *static_cast<const NumericValue*>(value.value);
    // TODO (rolland): get magnitude, scale that then apply to the unit vector
    float scaleVal = scale.value(target.targetIdx);
    auto  tempvel = state.velocities[target.targetIdx];
    tempvel *= scaleVal;
    state.coords[target.targetIdx] = pack.get_pedset().getPedCoords(target.targetIdx) + (tempvel * pack.dT);
  }

  // --------------------------------------------- END SCALING ------------------------------------------------------------------------
};
}  // namespace BHVR

#endif