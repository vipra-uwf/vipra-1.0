#ifndef DSL_HUMAN_BEHAVIOR_HPP
#define DSL_HUMAN_BEHAVIOR_HPP

#include <filesystem>
#include <stdexcept>
#include <unordered_map>

#include <generated/BehaviorBaseVisitor.h>
#include <generated/BehaviorParser.h>

#include <selectors/subselector.hpp>

#include <behavior/behavior_error_listener.hpp>
#include <behavior/human_behavior.hpp>

#include <events/event.hpp>
#include <locations/location.hpp>
#include <shapes/shape_class_definitions.hpp>

#include <util/caseless_str_comp.hpp>

#include <time/time.hpp>
#include <values/values.hpp>


namespace BHVR {

using StateMap = std::unordered_map<std::string, BHVR::stateUID, CaselessStrCompare::Hash,
                                    CaselessStrCompare::Comp>;
using TypeMap = std::unordered_map<std::string, BHVR::typeUID, CaselessStrCompare::Hash,
                                   CaselessStrCompare::Comp>;
using EventMap = std::unordered_map<std::string, VIPRA::idx, CaselessStrCompare::Hash,
                                    CaselessStrCompare::Comp>;
using LocationMap = std::unordered_map<std::string, VIPRA::idx, CaselessStrCompare::Hash,
                                       CaselessStrCompare::Comp>;

class BuilderException : public std::runtime_error {
 public:
  explicit BuilderException() : std::runtime_error("") {}
  static void error() { throw BuilderException(); }
};

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

  BHVR::seed currSeed;

  void initialBehaviorSetup(const std::string&, BHVR::seed);
  void initializeTypes();
  void initializeEvents();
  void initializeStates();
  void initializeLocations();
  void endBehaviorCheck();

  void addAtomToAction(Action&, BehaviorParser::Action_atomContext*);

  [[nodiscard]] Condition   buildCondition(BehaviorParser::ConditionContext*);
  [[nodiscard]] SubSelector buildSubSelector(BehaviorParser::Ped_SelectorContext*);
  void addSubCondToCondtion(Condition&, BehaviorParser::Sub_conditionContext*);

  [[nodiscard]] BHVR::stateUID      getState(const std::string&);
  [[nodiscard]] VIPRA::idx          getEvent(const std::string&);
  [[nodiscard]] VIPRA::time_range_s getRange(BehaviorParser::Value_numberContext*);

  [[nodiscard]] BHVR::typeUID getType(const std::string&) const;
  [[nodiscard]] BHVR::typeUID getGroup(BehaviorParser::Ped_SelectorContext*) const;
  [[nodiscard]] BHVR::Ptype   getCompositeType(
        const std::vector<antlr4::tree::TerminalNode*>&) const;
  static std::vector<std::string> getListStrs(
      const std::vector<antlr4::tree::TerminalNode*>&);
  VIPRA::idx getLocation(const std::string&);

  // ------------------------------- EVENTS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitEvent_Single(BehaviorParser::Event_SingleContext*) override;

  antlrcpp::Any visitEvent_Lasting(BehaviorParser::Event_LastingContext*) override;

  // ------------------------------- END EVENTS -----------------------------------------------------------------------------------------

  // ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitPed_Selector(BehaviorParser::Ped_SelectorContext*) override;

  // ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

  // ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitConditional_action(
      BehaviorParser::Conditional_actionContext*) override;

  antlrcpp::Any visitUn_conditional_action(
      BehaviorParser::Un_conditional_actionContext*) override;

  // ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

  // ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitDecl_Loc(BehaviorParser::Decl_LocContext*) override;

  antlrcpp::Any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext*) override;

  antlrcpp::Any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext*) override;

  antlrcpp::Any visitDecl_Ped(BehaviorParser::Decl_PedContext*) override;

  // ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
};
}  // namespace BHVR

#endif