#include <antlr4-runtime/support/Any.h>
#include <spdlog/spdlog.h>

#include <generated/BehaviorLexer.h>
#include <generated/BehaviorParser.h>

#include <behavior/behavior_builder.hpp>
#include <mock_behaviors/mock_behaviors_builder.hpp>

#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>
#include <selectors/selector_percent.hpp>

#include <actions/atoms/atom_change_speed.hpp>
#include <actions/atoms/atom_stop.hpp>

HumanBehavior&&
BehaviorBuilder::build(std::string behaviorName, const std::filesystem::path& filepath, VIPRA::seed seedNum) {

  if (behaviorName[0] == '#') {
    spdlog::info("Loading Mock Behavior: {}", behaviorName);
    return MockBehaviorBuilder::buildMockBehavior(behaviorName, seedNum);
  }

  if (!std::filesystem::exists(filepath)) {
    spdlog::error("Behavior \"{}\" Does NOT Exist at {}", behaviorName, filepath.c_str());
    exit(1);
  }

  spdlog::info("Loading Behavior: {} at {}", behaviorName, std::filesystem::canonical(filepath).c_str());
  states.clear();
  currState = 1;
  currentBehavior = HumanBehavior(behaviorName);
  seed = seedNum;
  std::ifstream dslFile(filepath);

  antlr4::ANTLRInputStream  input(dslFile);
  BehaviorLexer             lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BehaviorParser            parser(&tokens);

  parser.removeErrorListeners();
  parser.addErrorListener(&errorListener);

  BehaviorParser::ProgramContext* tree = parser.program();

  visitProgram(tree);

  return std::move(currentBehavior);
}

VIPRA::stateUID
BehaviorBuilder::getState(const std::string& state) {
  if (states.find(state) == states.end()) {
    states[state] = currState++;
  }

  return states.at(state);
}

Condition
BehaviorBuilder::buildCondition(BehaviorParser::ConditionContext* cond) {
  Condition condition;

  const auto subConds = cond->sub_condition();
  std::for_each(subConds.begin(), subConds.end(), [&](BehaviorParser::Sub_conditionContext* subcond) {
    addSubCondToCondtion(condition, subcond);
  });

  const auto andor = cond->ANDOR();
  std::for_each(andor.begin(), andor.end(), [&](antlr4::tree::TerminalNode* andor) {
    condition.addAndOr(andor->getText() == "and" || andor->getText() == "And" || andor->getText() == "AND");
  });
  return condition;
}

void
BehaviorBuilder::addSubCondToCondtion(Condition& condition, BehaviorParser::Sub_conditionContext* subcond) {
  if (subcond->condition_State()) {
    spdlog::debug("Behavior \"{}\": Adding SubCondition: State", currentBehavior.getName());
    auto object = (subcond->condition_State()->object()->getText() == "Pedestrian");
    auto state = getState(subcond->condition_State()->STATE()->getText());
    condition.addSubCondition("state", state, object);
    return;
  }

  if (subcond->condition_Time_Elapsed()) {
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Elapsed Time", currentBehavior.getName());
    VIPRA::delta_t time = std::stof(subcond->condition_Time_Elapsed()->NUMBER()->toString()) * 1000;
    condition.addSubCondition("elapsed_time", time);
    return;
  }

  spdlog::error("Behavior Error: No Valid SubCondition For: \"{}\"", subcond->getText());
  exit(1);
}

void
BehaviorBuilder::addConditionToAction(Action& action, BehaviorParser::ConditionContext* cond) {
  action.addCondition(buildCondition(cond));
}

void
BehaviorBuilder::addConditionToTransition(Transition& transition, BehaviorParser::ConditionContext* cond) {
  transition.addCondition(buildCondition(cond));
}

void
BehaviorBuilder::addAtomToAction(Action& action, BehaviorParser::Action_atomContext* atom) {

  if (atom->action_atom_Percent_Walk_Speed()) {
    spdlog::debug("Behavior \"{}\": Action Adding Atom: \"Change Speed\"", currentBehavior.getName());
    auto params = getChangeSpeedParams(atom);
    action.addAtom("change_speed", params.change, params.faster);
    return;
  }

  // ------------ One Word Atoms -----------------
  std::string atomName = atom->getText();

  if (atomName == "!stop") {
    spdlog::debug("Behavior \"{}\": Action Adding Atom: \"Stop\"", currentBehavior.getName());
    action.addAtom("stop");
    return;
  }

  spdlog::error("Behavior Error: No Atom \"{}\"", atomName);
  exit(1);
}

// ------------------------------- TRANSITIONS -----------------------------------------------------------------------------------------

// 'The Environment will' state_Set condition '.';
antlrcpp::Any
BehaviorBuilder::visitTransition_Environment(BehaviorParser::Transition_EnvironmentContext* ctx) {
  const std::string     stateStr = ctx->state_Set()->STATE()->toString();
  const VIPRA::stateUID newState = getState(stateStr);

  Transition transition(newState);
  spdlog::debug("Behavior \"{}\": Adding Environment Transition To State:\"{}\"", currentBehavior.getName(), stateStr);
  addConditionToTransition(transition, ctx->condition());

  currentBehavior.addEnvTransition(std::move(transition));
  return BehaviorBaseVisitor::visitTransition_Environment(ctx);
}

//AN ID 'will' state_Set condition '.';
antlrcpp::Any
BehaviorBuilder::visitTransition_Pedestrian(BehaviorParser::Transition_PedestrianContext* ctx) {
  const std::string     stateStr = ctx->state_Set()->STATE()->toString();
  const VIPRA::stateUID newState = getState(ctx->state_Set()->STATE()->toString());

  Transition transition(newState);
  spdlog::debug("Behavior \"{}\": Adding Pedestrian Transition To State: \"{}\"", currentBehavior.getName(), stateStr);
  addConditionToTransition(transition, ctx->condition());

  currentBehavior.addPedTransition(std::move(transition));
  return BehaviorBaseVisitor::visitTransition_Pedestrian(ctx);
}

// ------------------------------- END TRANSITIONS -----------------------------------------------------------------------------------------

// ------------------------------- CONDITIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitCondition(BehaviorParser::ConditionContext* ctx) {
  return BehaviorBaseVisitor::visitCondition(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSub_condition(BehaviorParser::Sub_conditionContext* ctx) {
  return BehaviorBaseVisitor::visitSub_condition(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitCondition_Existance(BehaviorParser::Condition_ExistanceContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Existance(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitCondition_State(BehaviorParser::Condition_StateContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_State(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitCondition_Others_State(BehaviorParser::Condition_Others_StateContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Others_State(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitCondition_Time_Elapsed(BehaviorParser::Condition_Time_ElapsedContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Time_Elapsed(ctx);
}

// ------------------------------- END CONTIDTIONS -----------------------------------------------------------------------------------------

// ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitPed_Selector(BehaviorParser::Ped_SelectorContext* ctx) {
  return BehaviorBaseVisitor::visitPed_Selector(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSelector_Percent(BehaviorParser::Selector_PercentContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Percent\"", currentBehavior.getName());
  const float percent = std::stof(ctx->NUMBER()->toString());
  currentBehavior.addSelector<Selector_Percent>(percent);

  return BehaviorBaseVisitor::visitSelector_Percent(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Exactly N\"", currentBehavior.getName());
  const VIPRA::size N = static_cast<VIPRA::size>(std::stoi(ctx->NUMBER()->toString()));
  currentBehavior.addSelector<Selector_Exactly_N>(N, seed);

  return BehaviorBaseVisitor::visitSelector_Exactly_N_Random(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Everyone\"");
  currentBehavior.addSelector<Selector_Everyone>();

  return BehaviorBaseVisitor::visitSelector_Everyone(ctx);
}

// ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

// ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitConditional_action(BehaviorParser::Conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  spdlog::debug("Behavior \"{}\": Adding Conditional Action", currentBehavior.getName());
  addConditionToAction(action, ctx->condition());

  std::for_each(
      atoms.begin(), atoms.end(), [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  currentBehavior.addAction(std::move(action));

  return BehaviorBaseVisitor::visitConditional_action(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  spdlog::debug("Behavior \"{}\": Adding Unconditional Action", currentBehavior.getName());

  std::for_each(
      atoms.begin(), atoms.end(), [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  currentBehavior.addAction(std::move(action));
  return BehaviorBaseVisitor::visitUn_conditional_action(ctx);
}

// ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

// ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitDecl_Ped(BehaviorParser::Decl_PedContext* ctx) {
  return BehaviorBaseVisitor::visitDecl_Ped(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) {
  return BehaviorBaseVisitor::visitDecl_Ped_State(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) {
  return BehaviorBaseVisitor::visitDecl_Env_State(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitDecl_Parameters(BehaviorParser::Decl_ParametersContext* ctx) {

  const auto& params = ctx->PARAMETER();

  std::for_each(params.begin(), params.end(), [&](antlr4::tree::TerminalNode* param) {
    std::string p = param->toString();
    spdlog::debug("Behavior \"{}\": Adding Param: \"{}\"", currentBehavior.getName(), p);
    currentBehavior.addParameter(p);
  });

  return BehaviorBaseVisitor::visitDecl_Parameters(ctx);
}

// ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
