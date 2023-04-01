#ifndef DSL_HUMAN_BEHAVIOR_HPP
#define DSL_HUMAN_BEHAVIOR_HPP

#include <filesystem>
#include <unordered_map>

#include <generated/BehaviorBaseVisitor.h>

#include <behavior/behavior_error_listener.hpp>
#include <behavior/human_behavior.hpp>
#include <events/event.hpp>

namespace Behaviors {
class BehaviorBuilder : public BehaviorBaseVisitor {
 private:
  BehaviorErrorListener errorListener;
  HumanBehavior         currentBehavior;

  std::unordered_map<std::string, Behaviors::stateUID> states;
  std::unordered_map<std::string, Behaviors::Event*>   eventsMap;

  Behaviors::stateUID currState;
  Behaviors::seed     seed;

  void initialBehaviorSetup(const std::string&, Behaviors::seed);

  Event* getEvent(const std::string&);
  void   addSubCondToCondtion(Condition&, BehaviorParser::Sub_conditionContext*);
  void   addAtomToAction(Action&, BehaviorParser::Action_atomContext*);

 public:
  HumanBehavior&& build(std::string, const std::filesystem::path&, Behaviors::seed);

  Behaviors::stateUID getState(const std::string&);

  Condition buildCondition(BehaviorParser::ConditionContext*);

  // ------------------------------- EVENTS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitEvent_Single(BehaviorParser::Event_SingleContext* ctx) override;

  antlrcpp::Any visitEvent_Lasting(BehaviorParser::Event_LastingContext* ctx) override;

  // ------------------------------- END EVENTS -----------------------------------------------------------------------------------------

  // ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitSelector_Percent(BehaviorParser::Selector_PercentContext* ctx) override;

  antlrcpp::Any visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext* ctx) override;

  antlrcpp::Any visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext* ctx) override;

  // ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

  // ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitConditional_action(BehaviorParser::Conditional_actionContext* ctx) override;

  antlrcpp::Any visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) override;

  // ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

  // ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) override;

  antlrcpp::Any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) override;

  // ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
};
}  // namespace Behaviors

#endif