#include "dsl_human_behavior.hpp"
#include "actions/alter_velocity_action.hpp"
#include "actions/stop_movement_action.hpp"
#include "conditions/and_condition.hpp"
#include "conditions/elapsed_time_condition.hpp"
#include "conditions/environment_elapsed_time_condition.hpp"
#include "conditions/environment_state_condition.hpp"
#include "conditions/state_condition.hpp"
#include "generated/BehaviorsLexer.h"
#include "generated/BehaviorsParser.h"
#include "selectors/everyone_selector.hpp"
#include "selectors/exactly_n_random_selector.hpp"
#include "selectors/id_random_selector.hpp"
#include "selectors/id_ratio_selector.hpp"
#include <antlr4-runtime/support/Any.h>

VIPRA::stateUID findState(std::vector<std::string> states, const std::string& stateName);

VIPRA::stateUID
findState(std::vector<std::string> states, const std::string& stateName) {
  VIPRA::size stateCnt = states.size();
  for (VIPRA::idx i = 0; i < stateCnt; ++i) {
    if (states.at(i) == stateName) {
      return static_cast<VIPRA::stateUID>(i);
    }
  }
  DSL_Exception::Throw("Invalid Behavior State: " + stateName);
  return 0;
}

DslHumanBehavior::DslHumanBehavior(const std::string& fileName, unsigned int seedNum)
  : HumanBehavior(), seed(seedNum) {
  std::ifstream dslFile(fileName);
  std::string   line;

  antlr4::ANTLRInputStream  input(dslFile);
  BehaviorsLexer            lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BehaviorsParser           parser(&tokens);

  BehaviorsParser::ProgramContext* tree = parser.program();

  this->visitProgram(tree);
}

DslHumanBehavior::DslHumanBehavior(const std::string& fileName) : DslHumanBehavior(fileName, time(nullptr)) {}

antlrcpp::Any
DslHumanBehavior::visitConsideration(BehaviorsParser::ConsiderationContext* ctx) {
  this->behavior = ctx->ID()->getText();
  std::cout << "Considering " << this->behavior << " type of person" << std::endl;
  return BehaviorsBaseVisitor::visitConsideration(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitIdRatioSelector(BehaviorsParser::IdRatioSelectorContext* ctx) {
  float percent = std::atof(ctx->NUMBER()->getText().c_str());
  this->addSelector(new IdRatioSelector(this->getSimulationContext(), percent / 100.0));
  std::cout << behavior << ": Added selector for " << percent << " percent of the population" << std::endl;
  return BehaviorsBaseVisitor::visitIdRatioSelector(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitExactlyNRandomSelector(BehaviorsParser::ExactlyNRandomSelectorContext* ctx) {
  VIPRA::size count = static_cast<VIPRA::size>(std::atoi(ctx->NUMBER()->getText().c_str()));
  this->addSelector(new ExactlyNRandomSelector(this->getSimulationContext(), count, seed));
  std::cout << behavior << ": Added selector for exactly " << count << " random pedestrian(s)" << std::endl;
  return BehaviorsBaseVisitor::visitExactlyNRandomSelector(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitStateDeclaration(BehaviorsParser::StateDeclarationContext* ctx) {
  std::string state = ctx->ID(1)->getText();
  this->addStateDefinition(state);

  std::cout << behavior << ": Added state definition for " << state << std::endl;
  return 0;
}

antlrcpp::Any
DslHumanBehavior::visitStateActionStopped(BehaviorsParser::StateActionStoppedContext* ctx) {
  std::string     stateName = ctx->pedestrianSelected()->ID(1)->getText();
  VIPRA::stateUID state = findState(this->getStateDefinitions(), stateName);
  this->addStateAction(state, new StopMovementAction(this->getSimulationContext()));
  std::cout << behavior << ": Added stopped action for state " << stateName << std::endl;

  return BehaviorsBaseVisitor::visitStateActionStopped(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitNoGroupRandomIdSelector(BehaviorsParser::NoGroupRandomIdSelectorContext* ctx) {
  float numerator = std::atof(ctx->randomIdRatioStatement()->NUMBER(0)->getText().c_str());
  float denominator = std::atof(ctx->randomIdRatioStatement()->NUMBER(1)->getText().c_str());
  this->addSelector(new IdRandomSelector(this->getSimulationContext(), numerator / denominator, seed));
  std::cout << behavior << ": Added selector for a random " << numerator << " out of " << denominator
            << " pedestrians with a seed of " << seed << std::endl;

  return BehaviorsBaseVisitor::visitNoGroupRandomIdSelector(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitEveryoneSelector(BehaviorsParser::EveryoneSelectorContext* ctx) {
  this->addSelector(new EveryoneSelector(this->getSimulationContext()));
  std::cout << behavior << ": Added selector for everyone. " << std::endl;

  return BehaviorsBaseVisitor::visitEveryoneSelector(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitInitialStateDeclaration(BehaviorsParser::InitialStateDeclarationContext* ctx) {
  std::string     stateName = ctx->ID(1)->getText();
  VIPRA::stateUID stateValue = findState(this->getStateDefinitions(), stateName);
  this->setInitialState(stateValue);
  std::cout << behavior << ": Set initial state to " << stateName << std::endl;
  return BehaviorsBaseVisitor::visitInitialStateDeclaration(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitEnvironmentStateDeclaration(BehaviorsParser::EnvironmentStateDeclarationContext* ctx) {
  std::string state = ctx->ID()->getText();
  this->addEnvironmentStateDefinition(state);

  std::cout << behavior << ": Added environment state definition for " << state << std::endl;

  return BehaviorsBaseVisitor::visitEnvironmentStateDeclaration(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitEnvironmentInitialStateDeclaration(
    BehaviorsParser::EnvironmentInitialStateDeclarationContext* ctx) {
  std::string     stateName = ctx->ID()->getText();
  VIPRA::stateUID stateValue = findState(this->getEnvironmentStateDefinitions(), stateName);
  this->setInitialEnvironmentState(stateValue);
  std::cout << behavior << ": Set initial environment state to " << stateName << std::endl;

  return BehaviorsBaseVisitor::visitEnvironmentInitialStateDeclaration(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitStateTransitionElapsedTime(BehaviorsParser::StateTransitionElapsedTimeContext* ctx) {
  float seconds = std::atof(ctx->conditionElapsedTime()->NUMBER()->getText().c_str());

  std::string     fromStateName = ctx->pedestrianSelected()->ID(1)->getText();
  VIPRA::stateUID fromState = findState(this->getStateDefinitions(), fromStateName);

  std::string     toStateName = ctx->ID()->getText();
  VIPRA::stateUID toState = findState(this->getStateDefinitions(), toStateName);

  SimulationContext* simContext = this->getSimulationContext();
  Condition*         fromStateCondition = new StateCondition(simContext, fromState);
  Condition*         transitionCondition = new ElapsedTimeCondition(this->getSimulationContext(), seconds);

  this->addTransition(new PedestrianTransition(
      simContext, new AndCondition(simContext, fromStateCondition, transitionCondition), toState));

  std::cout << behavior << ": Added transition from " << fromStateName << " to " << toStateName << " after "
            << seconds << "seconds." << std::endl;

  return BehaviorsBaseVisitor::visitStateTransitionElapsedTime(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitStateTransitionEnvironmentState(
    BehaviorsParser::StateTransitionEnvironmentStateContext* ctx) {
  std::string     fromStateName = ctx->pedestrianSelected()->ID(1)->getText();
  VIPRA::stateUID fromState = findState(this->getStateDefinitions(), fromStateName);

  std::string     toStateName = ctx->ID()->getText();
  VIPRA::stateUID toState = findState(this->getStateDefinitions(), toStateName);

  std::string     environmentStateName = ctx->conditionEnvironmentState()->ID()->getText();
  VIPRA::stateUID environmentStateValue =
      findState(this->getEnvironmentStateDefinitions(), environmentStateName);

  SimulationContext* simContext = this->getSimulationContext();
  Condition*         fromStateCondition = new StateCondition(simContext, fromState);
  Condition*         transitionCondition =
      new EnvironmentStateCondition(this->getSimulationContext(), environmentStateValue);

  this->addTransition(new PedestrianTransition(
      simContext, new AndCondition(simContext, fromStateCondition, transitionCondition), toState));

  std::cout << behavior << ": Added transition from " << fromStateName << " to " << toStateName
            << " when the environment state is " << environmentStateName << "." << std::endl;

  return BehaviorsBaseVisitor::visitStateTransitionEnvironmentState(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitEnvironmentTransition(BehaviorsParser::EnvironmentTransitionContext* ctx) {
  std::string     fromStateName = ctx->ID(0)->getText();
  VIPRA::stateUID fromState = findState(this->getEnvironmentStateDefinitions(), fromStateName);

  std::string     toStateName = ctx->ID(1)->getText();
  VIPRA::stateUID toState = findState(this->getEnvironmentStateDefinitions(), toStateName);

  float seconds = std::atof(ctx->conditionElapsedTime()->NUMBER()->getText().c_str());

  Condition* fromStateCondition = new EnvironmentStateCondition(this->getSimulationContext(), fromState);
  Condition* transitionCondition = new EnvironmentElapsedTimeCondition(this->getSimulationContext(), seconds);

  this->addEnvironmentTransition(new EnvironmentTransition(
      this->getSimulationContext(),
      new AndCondition(getSimulationContext(), fromStateCondition, transitionCondition),
      toState));

  std::cout << behavior << ": Added environment transition from " << fromStateName << " to " << toStateName
            << " after " << seconds << " seconds." << std::endl;

  return BehaviorsBaseVisitor::visitEnvironmentTransition(ctx);
}

antlrcpp::Any
DslHumanBehavior::visitStateActionWalkSpeed(BehaviorsParser::StateActionWalkSpeedContext* ctx) {
  std::string     stateName = ctx->pedestrianSelected()->ID(1)->getText();
  VIPRA::stateUID state = findState(this->getStateDefinitions(), stateName);
  float           factor = std::atof(ctx->walkSpeedBehavior()->NUMBER()->getText().c_str()) / 100.0F;
  std::string     fasterOrSlower = ctx->walkSpeedBehavior()->fasterOrSlower()->getText();
  ALTER_DIRECTION alterDirection;
  if (fasterOrSlower == "faster") {
    alterDirection = FASTER;
  } else if (fasterOrSlower == "slower") {
    alterDirection = SLOWER;
  } else {
    std::cerr << behavior << ": Unsupported alter direction: " << fasterOrSlower
              << " - must be faster or slower." << std::endl;
    return BehaviorsBaseVisitor::visitStateActionWalkSpeed(ctx);
  }

  this->addStateAction(state, new AlterVelocityAction(this->getSimulationContext(), alterDirection, factor));
  std::cout << behavior << ": Added alter velocity action for state " << stateName << ", " << fasterOrSlower
            << " by a factor of " << factor << std::endl;

  return BehaviorsBaseVisitor::visitStateActionWalkSpeed(ctx);
}
