#ifndef VIPRA_BEHAVIORS_ATTRIBUTES_HPP
#define VIPRA_BEHAVIORS_ATTRIBUTES_HPP

#include <stdexcept>

#include <definitions/dimensions.hpp>
#include <definitions/dsl_types.hpp>
#include <definitions/sim_pack.hpp>
#include <definitions/state.hpp>
#include <definitions/type_definitions.hpp>
#include <events/event.hpp>
#include <targets/target.hpp>
#include "behavior/exceptions.hpp"
#include "events/event_status.hpp"
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

  inline void typeCheck(Type check) const {
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

  inline void typeCheck(Type check) const {
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
  [[nodiscard]] inline static CAttributeValue getValue(Target target, Attribute attr,
                                                       Simpack pack) {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        return getPedValue(target, attr, pack);
      case TargetType::EVENT:
        return getEventValue(target, attr, pack);
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
  inline static void setValue(Target target, Attribute attr, Simpack pack,
                              VIPRA::State& state, CAttributeValue value) {
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

  /**
   * @brief Scales a targets attribute value
   * 
   * @param target : target to scale the attribute of
   * @param attr : attribute to scale
   * @param pack : simulation pack
   * @param state : timestep state
   * @param value : value to scale attribute by
   */
  inline static void scaleValue(Target target, Attribute attr, Simpack pack,
                                VIPRA::State& state, CAttributeValue value) {
    switch (target.type) {
      case TargetType::PEDESTRIAN:
        scalePedValue(target, attr, pack, state, value);
        return;
      case TargetType::EVENT:
        DSLException::error("Cannot Scale Event Value");
        return;
      case TargetType::INVALID:
        return;
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
  template <typename T>
  [[nodiscard]] inline static CAttributeValue storeValue(Type type, T&& value) {
    valueStore.emplace_back(type, new T(value));
    return valueStore.back();
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
  inline static CAttributeValue getPedValue(Target target, Attribute attr, Simpack pack) {
    switch (attr) {
      case Attribute::POSITION:
        return {Type::COORD, &pack.pedSet.getPedCoords(target.targetIdx)};
      case Attribute::VELOCITY:
        return {Type::COORD, &pack.pedSet.getPedVelocity(target.targetIdx)};
      case Attribute::GOAL:
        return {Type::COORD, &pack.goals.getEndGoal(target.targetIdx)};
      case Attribute::STATE:
        return {Type::STATE, &pack.context.pedStates.at(target.targetIdx)};
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
  inline static CAttributeValue getEventValue(Target target, Attribute attr,
                                              Simpack pack) {
    switch (attr) {
      case Attribute::LOCATION:
        // TODO (rolland) : get this added in when locations are done
        DSLException::error("Event Locations Not Implmented");
      case Attribute::STATUS:
        return {Type::STATUS, &pack.context.events.at(target.targetIdx).getStatus()};
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
  inline static void setPedValue(Target target, Attribute attr, Simpack pack,
                                 VIPRA::State& state, CAttributeValue value) {
    switch (attr) {
      case Attribute::POSITION:
        setPosition(target, state, value);
        return;
      case Attribute::VELOCITY:
        setVelocity(target, pack, state, value);
        return;
      case Attribute::GOAL:
        // TODO (rolland) update this with goals
        DSLException::error("Updating Pedestrian Goals Is Not Implemented");
        return;
      case Attribute::STATE:
        setState(target, pack, value);
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
  inline static void scalePedValue(Target target, Attribute attr, Simpack pack,
                                   VIPRA::State& state, CAttributeValue value) {
    switch (attr) {
      case Attribute::POSITION:
        DSLException::error("Cannot Scale Pedestrian Position");
        return;
      case Attribute::VELOCITY:
        scaleVelocity(target, pack, state, value);
        return;
      case Attribute::GOAL:
        // TODO (rolland) update this with goals
        DSLException::error("Updating Pedestrian Goals Is Not Implemented");
        return;
      case Attribute::STATE:
        setState(target, pack, value);
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
  inline static void setEventValue(Target target, Attribute attr, Simpack pack,
                                   CAttributeValue value) {
    switch (attr) {
      case Attribute::LOCATION:
        // TODO (rolland) : get this added in when locations are done
        DSLException::error("Event Locations Not Implmented");
      case Attribute::STATUS:
        pack.context.events.at(target.targetIdx)
            .setStatus(*static_cast<const BHVR::EventStatus*>(value.value));
        return;
      default:
        DSLException::error("Invalid Event Attribute");
    }
  }

  // ------------------------------------------- SETTERS ------------------------------------------------------------------------

  static inline void setPosition(Target target, VIPRA::State& state,
                                 CAttributeValue value) {
    value.typeCheck(Type::COORD);
    state.coords.at(target.targetIdx) = *static_cast<const VIPRA::pcoord*>(value.value);
  }

  /**
   * @brief Sets a pedestrians state attribute
   * 
   * @param target : target to set state for
   * @param pack : simulation pack
   * @param value : value to set attribute to
   */
  static inline void setState(Target target, Simpack pack, CAttributeValue value) {
    value.typeCheck(Type::STATE);
    pack.context.pedStates.at(target.targetIdx) =
        *static_cast<const BHVR::stateUID*>(value.value);
  }

  /**
   * @brief Sets a pedestrians velocity, changes next timestep state to reflect that
   * 
   * @param target : target to change velocity of
   * @param pack : simulation pack
   * @param state : next timestep state
   * @param value : value to set velocity to
   */
  static inline void setVelocity(Target target, Simpack pack, VIPRA::State& state,
                                 CAttributeValue value) {
    value.typeCheck(Type::COORD);

    state.velocities.at(target.targetIdx) =
        *static_cast<const VIPRA::veloc*>(value.value);

    VIPRA::f3d originalPos = pack.pedSet.getPedCoords(target.targetIdx);
    state.coords.at(target.targetIdx) =
        originalPos + (state.velocities.at(target.targetIdx) * pack.dT);
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
  static inline void scaleVelocity(Target target, Simpack pack, VIPRA::State& state,
                                   CAttributeValue value) {
    value.typeCheck(Type::NUMBER);

    const NumericValue& scale = *static_cast<const NumericValue*>(value.value);
    // TODO (rolland): get magnitude, scale that then apply to the unit vector
    float scaleVal = scale.value(target.targetIdx);
    auto& vel = state.velocities.at(target.targetIdx);
    vel *= scaleVal;
    state.coords.at(target.targetIdx) = pack.pedSet.getPedCoords(target.targetIdx) +
                                        (state.velocities.at(target.targetIdx) * pack.dT);
  }

  // --------------------------------------------- END SCALING ------------------------------------------------------------------------
};
}  // namespace BHVR

#endif