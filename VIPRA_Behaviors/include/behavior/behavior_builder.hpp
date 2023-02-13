#ifndef DSL_HUMAN_BEHAVIOR_HPP
#define DSL_HUMAN_BEHAVIOR_HPP

#include <filesystem>
#include <unordered_map>

#include <generated/BehaviorBaseVisitor.h>

#include <behavior/behavior_error_listener.hpp>
#include <behavior/human_behavior.hpp>

class DSL_Exception : public std::runtime_error {
 public:
  DSL_Exception(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw DSL_Exception(message); }
};

class BehaviorBuilder : public BehaviorBaseVisitor {
 private:
  BehaviorErrorListener                            errorListener;
  HumanBehavior                                    currentBehavior;
  std::unordered_map<std::string, VIPRA::stateUID> states;
  VIPRA::stateUID                                  currState;
  VIPRA::seed                                      seed;

 public:
  HumanBehavior&& build(std::string, const std::filesystem::path&, VIPRA::seed);

  VIPRA::stateUID getState(const std::string&);

  Condition buildCondition(BehaviorParser::ConditionContext*);

  void addSubCondToCondtion(Condition&, BehaviorParser::Sub_conditionContext*);
  void addConditionToAction(Action&, BehaviorParser::ConditionContext*);
  void addConditionToTransition(Transition&, BehaviorParser::ConditionContext*);
  void addAtomToAction(Action&, BehaviorParser::Action_atomContext*);

  // ------------------------------- TRANSITIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitTransition_Environment(BehaviorParser::Transition_EnvironmentContext* ctx) override;

  antlrcpp::Any visitTransition_Pedestrian(BehaviorParser::Transition_PedestrianContext* ctx) override;

  // ------------------------------- END TRANSITIONS -----------------------------------------------------------------------------------------

  // ------------------------------- CONDITIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitCondition(BehaviorParser::ConditionContext* ctx) override;

  antlrcpp::Any visitSub_condition(BehaviorParser::Sub_conditionContext* ctx) override;

  antlrcpp::Any visitCondition_Existance(BehaviorParser::Condition_ExistanceContext* ctx) override;

  antlrcpp::Any visitCondition_State(BehaviorParser::Condition_StateContext* ctx) override;

  antlrcpp::Any visitCondition_Others_State(BehaviorParser::Condition_Others_StateContext* ctx) override;

  antlrcpp::Any visitCondition_Time_Elapsed(BehaviorParser::Condition_Time_ElapsedContext* ctx) override;

  // ------------------------------- END CONTIDTIONS -----------------------------------------------------------------------------------------

  // ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitPed_Selector(BehaviorParser::Ped_SelectorContext* ctx) override;

  antlrcpp::Any visitSelector_Percent(BehaviorParser::Selector_PercentContext* ctx) override;

  antlrcpp::Any visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext* ctx) override;

  antlrcpp::Any visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext* ctx) override;

  // ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

  // ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitConditional_action(BehaviorParser::Conditional_actionContext* ctx) override;

  antlrcpp::Any visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) override;

  // ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

  // ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

  antlrcpp::Any visitDecl_Ped(BehaviorParser::Decl_PedContext* ctx) override;

  antlrcpp::Any visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) override;

  antlrcpp::Any visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) override;

  antlrcpp::Any visitDecl_Parameters(BehaviorParser::Decl_ParametersContext* ctx) override;

  // ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
};

#endif