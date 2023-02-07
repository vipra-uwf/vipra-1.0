#include <antlr4-runtime/support/Any.h>
#include <spdlog/spdlog.h>

#include <generated/BehaviorLexer.h>
#include <generated/BehaviorParser.h>

#include <behavior/behavior_builder.hpp>

#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>
#include <selectors/selector_percent.hpp>

HumanBehavior&&
BehaviorBuilder::build(std::string behaviorName, const std::filesystem::path& fileName, VIPRA::seed seedNum) {
  currentBehavior = HumanBehavior(behaviorName);
  seed = seedNum;
  std::ifstream dslFile(fileName);

  antlr4::ANTLRInputStream  input(dslFile);
  BehaviorLexer             lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BehaviorParser            parser(&tokens);

  BehaviorParser::ProgramContext* tree = parser.program();

  visitProgram(tree);
  return std::move(currentBehavior);
}

void
BehaviorBuilder::addAtomToAction(Action& action, BehaviorParser::Action_atomContext* atom) {

  std::string atomName = atom->getText();
  spdlog::debug("Behavior {}: Unconditional Action Adding Atom: {}", currentBehavior.getName(), atomName);

  if (atomName == "!change_speed") {
    action.addAtom(atomName, 0.1f, true);
  } else {
    action.addAtom(atomName);
  }
}

// ------------------------------- TRANSITIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitTransition_Environment(BehaviorParser::Transition_EnvironmentContext* ctx) {
  return BehaviorBaseVisitor::visitTransition_Environment(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitTransition_Pedestrian(BehaviorParser::Transition_PedestrianContext* ctx) {
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

  spdlog::debug("Adding Selector: Percent to {}", currentBehavior.getName());
  const float percent = std::stof(ctx->NUMBER()->toString());
  currentBehavior.addSelector<Selector_Percent>(percent);

  return BehaviorBaseVisitor::visitSelector_Percent(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Exactly N\"");
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

  return BehaviorBaseVisitor::visitConditional_action(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  spdlog::debug("Behavior {}: Adding Unconditional Action", currentBehavior.getName());

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
