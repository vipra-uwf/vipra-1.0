#ifndef DSL_HUMAN_BEHAVIOR_HPP
#define DSL_HUMAN_BEHAVIOR_HPP

#include <filesystem>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include <spdlog/spdlog.h>

#include <generated/BehaviorBaseVisitor.h>
#include <generated/BehaviorParser.h>

#include <selectors/subselector.hpp>

#include <behavior/human_behavior.hpp>
#include <builder/behavior_error_listener.hpp>

#include <events/event.hpp>
#include <locations/location.hpp>

#include <util/caseless_str_comp.hpp>

#include <attributes/attributes.hpp>
#include <time/time.hpp>
#include <values/values.hpp>
#include "definitions/dsl_types.hpp"

namespace BHVR {

using StateMap = std::unordered_map<std::string, BHVR::stateUID, CaselessStrCompare::Hash,
                                    CaselessStrCompare::Comp>;
using TypeMap = std::unordered_map<std::string, BHVR::typeUID, CaselessStrCompare::Hash,
                                   CaselessStrCompare::Comp>;
using EventMap = std::unordered_map<std::string, VIPRA::idx, CaselessStrCompare::Hash,
                                    CaselessStrCompare::Comp>;
using LocationMap = std::unordered_map<std::string, VIPRA::idx, CaselessStrCompare::Hash,
                                       CaselessStrCompare::Comp>;

using evEnd = BehaviorParser::Event_endContext*;
using evStart = BehaviorParser::Event_startContext*;
using evName = std::string;

using acStimulus = BehaviorParser::Action_stimulusContext*;
using acResponse = BehaviorParser::Action_responseContext*;
using acDuration = BehaviorParser::Action_durationContext*;
using acTarget = BehaviorParser::Action_targetContext*;

using slType = BehaviorParser::Selector_typeContext*;
using slSelector = BehaviorParser::Selector_selectorContext*;
using slGroup = BehaviorParser::Selector_fromContext*;
using slRequired = BehaviorParser::Selector_requiredContext*;

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

  [[nodiscard]] auto addEvent(BehaviorParser::Event_nameContext*) -> VIPRA::idx;

  [[nodiscard]] auto makeAttributeValue(BehaviorParser::Attr_valueContext*)
      -> BHVR::CAttributeValue;
  [[nodiscard]] static auto makeAttribute(std::string) -> BHVR::Attribute;
  [[nodiscard]] static auto makeAttributeStr(BehaviorParser::AttributeContext*)
      -> std::string;
  [[nodiscard]] static auto makeListStrs(const std::vector<antlr4::tree::TerminalNode*>&)
      -> std::vector<std::string>;

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

  // -------------------------------- FINDERS ------------------------------------------------------------------------------------------------

  template <typename T>
  [[nodiscard]] static auto findEventAttribute(BehaviorParser::EventContext* ctx)
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

  template <typename T>
  [[nodiscard]] static auto findActionAttribute(BehaviorParser::ActionContext* ctx)
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

  template <typename T>
  [[nodiscard]] static auto findSelectorAttribute(
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