#include <antlr4-runtime/support/Any.h>
#include <spdlog/spdlog.h>

#include <generated/BehaviorLexer.h>
#include <generated/BehaviorParser.h>

#include <behavior/behavior_builder.hpp>

#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>
#include <selectors/selector_percent.hpp>

HumanBehavior&&
BehaviorBuilder::build(const std::filesystem::path& fileName, VIPRA::seed seedNum) {
  currentBehavior = HumanBehavior();
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
  spdlog::debug("Adding Selector: Percent");
  const float percent = std::stof(ctx->NUMBER()->toString());
  currentBehavior.addSelector<Selector_Percent>(percent);

  return BehaviorBaseVisitor::visitSelector_Percent(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext* ctx) {
  spdlog::debug("Adding Selector: Exactly N");
  const VIPRA::size N = static_cast<VIPRA::size>(std::stoi(ctx->NUMBER()->toString()));
  currentBehavior.addSelector<Selector_Exactly_N>(N, seed);

  return BehaviorBaseVisitor::visitSelector_Exactly_N_Random(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext* ctx) {
  spdlog::debug("Adding Selector: Everyone");
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
BehaviorBuilder::visitNon_conditional_action(BehaviorParser::Non_conditional_actionContext* ctx) {
  return BehaviorBaseVisitor::visitNon_conditional_action(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitSub_action(BehaviorParser::Sub_actionContext* ctx) {
  return BehaviorBaseVisitor::visitSub_action(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitAction_atom(BehaviorParser::Action_atomContext* ctx) {
  return BehaviorBaseVisitor::visitAction_atom(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitAction_Stop(BehaviorParser::Action_StopContext* ctx) {
  return BehaviorBaseVisitor::visitAction_Stop(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitAction_atom_Percent_Walk_Speed(BehaviorParser::Action_atom_Percent_Walk_SpeedContext* ctx) {
  return BehaviorBaseVisitor::visitAction_atom_Percent_Walk_Speed(ctx);
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
  return BehaviorBaseVisitor::visitDecl_Parameters(ctx);
}

// ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
