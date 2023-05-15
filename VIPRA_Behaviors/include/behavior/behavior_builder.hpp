#ifndef DSL_HUMAN_BEHAVIOR_HPP
#define DSL_HUMAN_BEHAVIOR_HPP

#include <filesystem>
#include <unordered_map>

#include <generated/BehaviorBaseVisitor.h>

#include <selectors/subselector.hpp>

#include <behavior/behavior_error_listener.hpp>
#include <behavior/human_behavior.hpp>
#include <events/event.hpp>

#include <util/caseless_str_comp.hpp>

namespace BHVR {

using StateMap = std::unordered_map<std::string, BHVR::stateUID, CaselessStrCompare::Hash, CaselessStrCompare::Comp>;
using TypeMap = std::unordered_map<std::string, BHVR::typeUID, CaselessStrCompare::Hash, CaselessStrCompare::Comp>;
using EventMap = std::unordered_map<std::string, BHVR::Event*, CaselessStrCompare::Hash, CaselessStrCompare::Comp>;

class BehaviorBuilder : public BehaviorBaseVisitor {
 public:
  HumanBehavior build(std::string, const std::filesystem::path&, BHVR::seed);

 private:
  BehaviorErrorListener errorListener;

  StateMap states;
  TypeMap  types;
  EventMap eventsMap;

  BHVR::stateUID currState;
  BHVR::typeUID  currType;

  BHVR::seed currSeed;

  void initialBehaviorSetup(const std::string&, BHVR::seed);
  void initializeTypes();
  void initializeEvents();
  void initializeStates();
  void endBehaviorCheck();

  void addAtomToAction(Action&, BehaviorParser::Action_atomContext*);

  Condition buildCondition(BehaviorParser::ConditionContext*);
  void      addSubCondToCondtion(Condition&, BehaviorParser::Sub_conditionContext*);

  SubSelector buildSubSelector(BehaviorParser::Ped_SelectorContext*);

  BHVR::stateUID getState(const std::string&);
  Event*         getEvent(const std::string&);

  BHVR::typeUID                   getType(const std::string&) const;
  BHVR::typeUID                   getGroup(BehaviorParser::Ped_SelectorContext*) const;
  BHVR::Ptype                     getCompositeType(const std::vector<antlr4::tree::TerminalNode*>&) const;
  static std::vector<std::string> getListStrs(const std::vector<antlr4::tree::TerminalNode*>&);
  float                           getValue(BehaviorParser::Value_numberContext*) const;

  float makeRandomValue(float, float) const;

  // ------------------------------- EVENTS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitEvent_Single(BehaviorParser::Event_SingleContext*) override;

  antlrcpp::Any visitEvent_Lasting(BehaviorParser::Event_LastingContext*) override;

  // ------------------------------- END EVENTS -----------------------------------------------------------------------------------------

  // ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitPed_Selector(BehaviorParser::Ped_SelectorContext*) override;

  // ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

  // ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitConditional_action(BehaviorParser::Conditional_actionContext*) override;

  antlrcpp::Any visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext*) override;

  // ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

  // ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext*) override;

  antlrcpp::Any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext*) override;

  antlrcpp::Any visitDecl_Ped(BehaviorParser::Decl_PedContext*) override;

  // ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
};
}  // namespace BHVR

#endif