#ifndef VIPRA_BEHAVIORS_BEHAVIOR_BUILDER_HPP
#define VIPRA_BEHAVIORS_BEHAVIOR_BUILDER_HPP

#include <filesystem>
#include <stdexcept>

#include <spdlog/spdlog.h>

#include <generated/BehaviorBaseVisitor.h>
#include <generated/BehaviorParser.h>

#include <selectors/subselector.hpp>

#include <behavior/human_behavior.hpp>
#include <builder/behavior_error_listener.hpp>

#include <events/event.hpp>
#include <locations/location.hpp>

#include <attributes/attributes.hpp>
#include <conditions/condition.hpp>
#include <definitions/dsl_types.hpp>
#include <time/time.hpp>
#include <values/values.hpp>

#include <builder/builder_maps.hpp>
#include <builder/declaration_components.hpp>
#include "targets/target_modifier.hpp"
#include "values/direction.hpp"

namespace BHVR {
/**
 * @brief Parses Behavior Files and Creates the Runtime Functionality they describe
 * 
 */
class BehaviorBuilder : public BehaviorBaseVisitor {
 public:
  HumanBehavior build(std::string, const std::filesystem::path&, BHVR::seed);

 private:
  BehaviorErrorListener errorListener;

  StateMap    states;
  TypeMap     types;
  EventMap    eventsMap;
  LocationMap locations;

  Condition     startCond;
  Event         startEvent;
  HumanBehavior currentBehavior;

  BHVR::stateUID currState;
  BHVR::typeUID  currType;
  BHVR::seed     currSeed;

  void initialBehaviorSetup(const std::string&, BHVR::seed);
  void initializeTypes();
  void initializeEvents();
  void initializeStates();
  void initializeLocations();
  void endBehaviorCheck();

  // ------------------------------- UTIL -----------------------------------------------------------------------------------------

  void addAtomToAction(Action&, BehaviorParser::Action_atomContext*);
  void addTargetToAction(Action&, BehaviorParser::TargetContext*);
  void addSubCondToCondtion(Condition&, BehaviorParser::Sub_conditionContext*);

  [[nodiscard]] auto addEvent(BehaviorParser::Event_nameContext*) -> VIPRA::idx;

  [[nodiscard]] auto buildCondition(BehaviorParser::ConditionContext*) -> Condition;
  [[nodiscard]] auto buildSubSelector(slType, slSelector, std::optional<slGroup>, bool)
      -> SubSelector;

  [[nodiscard]] auto getLocation(const std::string&) const -> VIPRA::idx;
  [[nodiscard]] auto getState(const std::string&) const -> BHVR::stateUID;
  [[nodiscard]] auto getEvent(const std::string&) const -> std::optional<VIPRA::idx>;
  [[nodiscard]] auto getRange(BehaviorParser::Value_numberContext*) const
      -> VIPRA::time_range_s;
  [[nodiscard]] auto getType(const std::string&) const -> BHVR::typeUID;
  [[nodiscard]] auto getGroup(std::optional<slGroup>) const
      -> std::pair<BHVR::typeUID, std::string>;
  [[nodiscard]] auto getCompositeType(
      const std::vector<antlr4::tree::TerminalNode*>&) const -> BHVR::Ptype;
  [[nodiscard]] static auto getAttribute(std::string) -> BHVR::Attribute;

  [[nodiscard]] auto makeAttributeValue(BehaviorParser::Attr_valueContext*)
      -> BHVR::CAttributeValue;
  [[nodiscard]] static auto makeAttributeStr(BehaviorParser::AttributeContext*)
      -> std::string;
  [[nodiscard]] static auto makeListStrs(const std::vector<antlr4::tree::TerminalNode*>&)
      -> std::vector<std::string>;
  [[nodiscard]] auto makeTargetModifier(std::vector<BehaviorParser::ModifierContext*>&)
      -> std::optional<TargetModifier>;
  [[nodiscard]] static auto makeDirection(BehaviorParser::DirectionContext*) -> Direction;

  /**
   * @brief Logs an error to the console and throws an exception
   * 
   * @tparam T : 
   * @param message : message to log to console
   * @param values : values to format message with
   */
  template <typename... T>
  static void error(const std::string& message, T&&... values) {
    spdlog::error(message, std::forward<T>(values)...);
    BuilderException::error();
  }

  // ------------------------------- ANTLR FUNCTIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitEvent(BehaviorParser::EventContext*) override;
  antlrcpp::Any visitPed_Selector(BehaviorParser::Ped_SelectorContext*) override;
  antlrcpp::Any visitAction(BehaviorParser::ActionContext*) override;
  antlrcpp::Any visitDecl_Loc(BehaviorParser::Decl_LocContext*) override;
  antlrcpp::Any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext*) override;
  antlrcpp::Any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext*) override;
  antlrcpp::Any visitDecl_Ped(BehaviorParser::Decl_PedContext*) override;

  // --------------------------------- ATOMS ------------------------------------------------------------------------------------------------

  void addSetAtom(Action&, BehaviorParser::Set_atomContext*);
  void addScaleAtom(Action&, BehaviorParser::Scale_atomContext*);

  // --------------------------------- TARGET SELECTORS ------------------------------------------------------------------------------------------------

  void addNearestTypeTarget(Action&, BehaviorParser::Nearest_typeContext*,
                            std::optional<TargetModifier>);

  // --------------------------------- TARGET MODIFIERS ------------------------------------------------------------------------------------------------

  void addModifier(TargetModifier&, BehaviorParser::ModifierContext*) const;

  void addDistanceModifier(TargetModifier&, BehaviorParser::DistanceContext*) const;
  static void addDirectionModifier(TargetModifier&, BehaviorParser::DirectionContext*);

  // --------------------------------- SUBCONDITIONS ------------------------------------------------------------------------------------------------

  void addTimeElapsedSubCond(Condition&,
                             BehaviorParser::Condition_Time_Elapsed_From_EventContext*);
  void addEventOccurredSubCond(Condition&,
                               BehaviorParser::Condition_Event_OccurredContext*);
  void addEventOccurringSubCond(Condition&,
                                BehaviorParser::Condition_Event_OccurringContext*);
  void addEventStartingSubCond(Condition&,
                               BehaviorParser::Condition_Event_StartingContext*);
  void addEventEndingSubCond(Condition&, BehaviorParser::Condition_Event_EndingContext*);
  void addSpatialSubCond(Condition&, BehaviorParser::Condition_SpatialContext*);

  // --------------------------------- SUBSELECTORS ------------------------------------------------------------------------------------------------

  auto buildEveryone(slType, bool) -> SubSelector;
  auto buildExactlyN(slType, slSelector, std::optional<slGroup>, bool) -> SubSelector;
  auto buildPercent(slType, slSelector, std::optional<slGroup>, bool) -> SubSelector;

  // -------------------------------- FINDERS ------------------------------------------------------------------------------------------------

  /**
   * @brief Gets components from an event declaration context
   * 
   * @tparam T : type of component
   * @param ctx : event context
   * @return std::optional<T> 
   */
  template <typename T>
  [[nodiscard]] static auto findEventComponent(BehaviorParser::EventContext* ctx)
      -> std::optional<T> {
    for (const auto& attr : ctx->event_attribute()) {
      // Name
      if constexpr (std::is_same_v<T, std::string>)
        if (attr->event_name()) return attr->event_name()->ID()->toString();

      // Start Condition
      if constexpr (std::is_same_v<T, evStart>)
        if (attr->event_start()) return attr->event_start();

      // End Condition
      if constexpr (std::is_same_v<T, evEnd>)
        if (attr->event_end()) return attr->event_end();
    }

    return std::nullopt;
  }

  /**
   * @brief Gets components from an action declaration context
   * 
   * @tparam T : type of component
   * @param ctx : action context
   * @return std::optional<T> 
   */
  template <typename T>
  [[nodiscard]] static auto findActionComponent(BehaviorParser::ActionContext* ctx)
      -> std::optional<T> {
    for (const auto& attr : ctx->action_attribute()) {
      // Stimulus
      if constexpr (std::is_same_v<T, acStimulus>)
        if (attr->action_stimulus()) return attr->action_stimulus();

      // Response
      if constexpr (std::is_same_v<T, acResponse>)
        if (attr->action_response()) return attr->action_response();

      // Target
      if constexpr (std::is_same_v<T, acTarget>)
        if (attr->action_target()) return attr->action_target();

      // Duration
      if constexpr (std::is_same_v<T, acDuration>)
        if (attr->action_duration()) return attr->action_duration();
    }

    return std::nullopt;
  }

  /**
   * @brief Gets components from an selector declaration context
   * 
   * @tparam T : type of component
   * @param ctx : selector context
   * @return std::optional<T> 
   */
  template <typename T>
  [[nodiscard]] static auto findSelectorComponent(
      BehaviorParser::Ped_SelectorContext* ctx) -> std::optional<T> {
    for (const auto& attr : ctx->selector_attribute()) {
      // Type
      if constexpr (std::is_same_v<T, slType>)
        if (attr->selector_type()) return attr->selector_type();

      // Selector
      if constexpr (std::is_same_v<T, slSelector>)
        if (attr->selector_selector()) return attr->selector_selector();

      if constexpr (std::is_same_v<T, slGroup>)
        if (attr->selector_from()) return attr->selector_from();

      if constexpr (std::is_same_v<T, slRequired>)
        if (attr->selector_required()) return attr->selector_required();
    }

    return std::nullopt;
  }
};
}  // namespace BHVR

#endif