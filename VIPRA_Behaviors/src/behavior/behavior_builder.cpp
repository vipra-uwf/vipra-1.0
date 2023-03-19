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

namespace Behaviors {

Condition startCond;
Event     startEvent("!start");

/**
 * @brief Parses the behavior file at filepath, returns the behavior it describes
 * 
 * @param behaviorName 
 * @param filepath 
 * @param seedNum 
 * @return HumanBehavior&&
 */
HumanBehavior&&
BehaviorBuilder::build(std::string behaviorName, const std::filesystem::path& filepath, Behaviors::seed seedNum) {

  if (behaviorName[0] == '#') {
    spdlog::debug("Loading Mock Behavior: {}", behaviorName);
    return MockBehaviorBuilder::buildMockBehavior(behaviorName, seedNum);
  }

  if (!std::filesystem::exists(filepath)) {
    spdlog::error("Behavior \"{}\" Does NOT Exist at {}", behaviorName, filepath.c_str());
    exit(1);
  }

  spdlog::debug("Loading Behavior: {} at {}", behaviorName, std::filesystem::canonical(filepath).c_str());
  initialBehaviorSetup(behaviorName, seedNum);

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

/**
 * @brief Gets a pointer to the event with name evName from eventsMap
 * 
 * @param evName : name of event to find
 * @return Behaviors::Event*
 */
Behaviors::Event*
BehaviorBuilder::getEvent(const std::string& evName) {
  auto ev = eventsMap.find(evName);
  if (ev == eventsMap.end()) {
    spdlog::error("Behavior Error: Attempt To Use Event Before It Was Defined: \"{}\"", evName);
    exit(1);
  }

  return (*ev).second;
}

/**
 * @brief Cleans and sets up the builder for a new behavior
 * 
 * @param behaviorName : name of new behavior
 * @param seedNum : randomization seed for behavior
 */
void
BehaviorBuilder::initialBehaviorSetup(const std::string& behaviorName, Behaviors::seed seedNum) {
  states.clear();
  eventsMap.clear();
  startEvent = Event("!start");
  startCond.addSubCondition("start");
  startEvent.setStartCondition(std::move(startCond));
  currState = 1;
  currentBehavior = HumanBehavior(behaviorName);
  eventsMap["!start"] = currentBehavior.addEvent(std::move(startEvent));
  seed = seedNum;
}

/**
 * @brief Returns the Behaviors::stateUID associated with a state string, creating a new association if it doesn't exist
 * 
 * @param state : name of state
 * @return Behaviors::stateUID 
 */
Behaviors::stateUID
BehaviorBuilder::getState(const std::string& state) {
  if (states.find(state) == states.end()) {
    states[state] = currState++;
  }

  return states.at(state);
}

/**
 * @brief Creates a new condition adding all sub_conditions and operations
 * 
 * @param cond 
 * @return Condition
 */
Condition
BehaviorBuilder::buildCondition(BehaviorParser::ConditionContext* cond) {
  Condition condition;

  if (cond == nullptr) {
    condition.addSubCondition("start");
    return condition;
  }

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

/**
 * @brief Finds the appropriate subcondition in CondMap and adds it to the condition, along with the parameters from the behavior file
 * 
 * @param condition 
 * @param subcond 
 */
void
BehaviorBuilder::addSubCondToCondtion(Condition& condition, BehaviorParser::Sub_conditionContext* subcond) {
  if (subcond->condition_State()) {
    spdlog::debug("Behavior \"{}\": Adding SubCondition: State", currentBehavior.getName());
    auto object = (subcond->condition_State()->object()->getText() == "Pedestrian");
    auto state = getState(subcond->condition_State()->STATE()->getText());
    condition.addSubCondition("state", state, object);
    return;
  }

  if (subcond->condition_Time_Elapsed_From_Event()) {
    VIPRA::delta_t time = std::stof(subcond->condition_Time_Elapsed_From_Event()->NUMBER()->toString());
    std::string    evName = subcond->condition_Time_Elapsed_From_Event()->EVENT()->toString();
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Elapsed Time From \"{}\" Event", currentBehavior.getName(), evName);
    condition.addSubCondition("elapsed_time_from_event", time, getEvent(evName));
    return;
  }

  if (subcond->condition_Event()) {
    std::string evName = subcond->condition_Event()->EVENT()->toString();
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Event \"{}\" Occurred", currentBehavior.getName(), evName);
    condition.addSubCondition("event_occurred", getEvent(evName));
    return;
  }

  if (subcond->condition_Event_Occurring()) {
    std::string evName = subcond->condition_Event_Occurring()->EVENT()->toString();
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Event \"{}\" Occurring", currentBehavior.getName(), evName);
    condition.addSubCondition("event_occurring", getEvent(evName));
    return;
  }

  spdlog::error("Behavior Error: No Valid SubCondition For: \"{}\"", subcond->getText());
  exit(1);
}

/**
 * @brief Builds a condition from a condition context and adds it to the action
 * 
 * @param action 
 * @param cond 
 */
void
BehaviorBuilder::addConditionToAction(Action& action, BehaviorParser::ConditionContext* cond) {
  action.addCondition(buildCondition(cond));
}

/**
 * @brief Creates an action atom and adds it to the action
 * 
 * @param action 
 * @param atom 
 */
void
BehaviorBuilder::addAtomToAction(Action& action, BehaviorParser::Action_atomContext* atom) {

  if (atom->action_atom_Percent_Walk_Speed()) {
    spdlog::debug("Behavior \"{}\": Adding Action Atom: \"Change Speed\"", currentBehavior.getName());
    auto params = getChangeSpeedParams(atom);
    action.addAtom("change_speed", params.change, params.faster);
    return;
  }

  // ------------ One Word Atoms -----------------
  std::string atomName = atom->getText();

  if (atom->action_Stop()) {
    spdlog::debug("Behavior \"{}\": Adding Action Atom: \"Stop\"", currentBehavior.getName());
    action.addAtom("stop");
    return;
  }

  spdlog::error("Behavior Error: No Atom \"{}\"", atomName);
  exit(1);
}
}  // namespace Behaviors

// ------------------------------- ANTLR VISITOR METHODS -----------------------------------------------------------------------------------------

// ------------------------------- CONDITIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition(BehaviorParser::ConditionContext* ctx) {
  return BehaviorBaseVisitor::visitCondition(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitSub_condition(BehaviorParser::Sub_conditionContext* ctx) {
  return BehaviorBaseVisitor::visitSub_condition(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_Existance(BehaviorParser::Condition_ExistanceContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Existance(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_State(BehaviorParser::Condition_StateContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_State(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_Others_State(BehaviorParser::Condition_Others_StateContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Others_State(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_Met_Goal(BehaviorParser::Condition_Met_GoalContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Met_Goal(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_Time_Elapsed_From_Event(
    BehaviorParser::Condition_Time_Elapsed_From_EventContext* ctx) {

  return BehaviorBaseVisitor::visitCondition_Time_Elapsed_From_Event(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_Event(BehaviorParser::Condition_EventContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Event(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitCondition_Event_Occurring(BehaviorParser::Condition_Event_OccurringContext* ctx) {
  return BehaviorBaseVisitor::visitCondition_Event_Occurring(ctx);
}

// ------------------------------- END CONTIDTIONS -----------------------------------------------------------------------------------------

// ------------------------------- EVENTS -----------------------------------------------------------------------------------------

antlrcpp::Any
Behaviors::BehaviorBuilder::visitEvent(BehaviorParser::EventContext* ctx) {
  return BehaviorBaseVisitor::visitEvent(ctx);
}

/**
 * @brief Creates a new single fire event and adds it to the eventsMap
 * 
 * @param ctx : antlr context
 * @return antlrcpp::Any 
 */
antlrcpp::Any
Behaviors::BehaviorBuilder::visitEvent_Single(BehaviorParser::Event_SingleContext* ctx) {

  std::string eventName = ctx->EVENT()->toString();

  if (eventsMap.find(eventName) != eventsMap.end()) {
    spdlog::error("Behavior \"{}\": Attempt To Redefine Event: \"{}\"", eventName);
    exit(1);
  }

  Behaviors::Event event(eventName);

  spdlog::debug("Behavior \"{}\": Adding Single Fire Event: \"{}\"", currentBehavior.getName(), eventName);
  eventsMap[eventName] = &event;

  auto startCtx = ctx->condition();

  event.setStartCondition(buildCondition(startCtx));
  event.setEndCondition(buildCondition(nullptr));

  eventsMap[eventName] = currentBehavior.addEvent(std::move(event));

  return BehaviorBaseVisitor::visitEvent_Single(ctx);
}

/**
 * @brief Creates a lasting event and adds it to the eventsMap
 * 
 * @param ctx : antlr context
 * @return antlrcpp::Any 
 */
antlrcpp::Any
Behaviors::BehaviorBuilder::visitEvent_Lasting(BehaviorParser::Event_LastingContext* ctx) {
  std::string eventName = ctx->EVENT()->toString();

  if (eventsMap.find(eventName) != eventsMap.end()) {
    spdlog::error("Behavior \"{}\": Attempt To Redefine Event: \"{}\"", eventName);
    exit(1);
  }

  Behaviors::Event event(eventName);

  spdlog::debug("Behavior \"{}\": Adding Lasting Event: \"{}\"", currentBehavior.getName(), eventName);
  eventsMap[eventName] = &event;

  auto startCtx = ctx->condition()[0];
  auto endCtx = ctx->condition()[1];

  event.setStartCondition(buildCondition(startCtx));
  event.setEndCondition(buildCondition(endCtx));

  eventsMap[eventName] = currentBehavior.addEvent(std::move(event));

  return BehaviorBaseVisitor::visitEvent_Lasting(ctx);
}

// ------------------------------- END EVENTS -----------------------------------------------------------------------------------------

// ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

antlrcpp::Any
Behaviors::BehaviorBuilder::visitPed_Selector(BehaviorParser::Ped_SelectorContext* ctx) {
  return BehaviorBaseVisitor::visitPed_Selector(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitSelector_Percent(BehaviorParser::Selector_PercentContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Percent\"", currentBehavior.getName());
  const float percent = std::stof(ctx->NUMBER()->toString());
  currentBehavior.addSelector<Selector_Percent>(percent);

  return BehaviorBaseVisitor::visitSelector_Percent(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitSelector_Exactly_N_Random(BehaviorParser::Selector_Exactly_N_RandomContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Exactly N\"", currentBehavior.getName());
  const VIPRA::size N = static_cast<VIPRA::size>(std::stoi(ctx->NUMBER()->toString()));
  currentBehavior.addSelector<Selector_Exactly_N>(N, seed);

  return BehaviorBaseVisitor::visitSelector_Exactly_N_Random(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitSelector_Everyone(BehaviorParser::Selector_EveryoneContext* ctx) {

  spdlog::debug("Behavior \"{}\": Adding Selector: \"Everyone\"", currentBehavior.getName());
  currentBehavior.addSelector<Selector_Everyone>();

  return BehaviorBaseVisitor::visitSelector_Everyone(ctx);
}

// ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

// ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
Behaviors::BehaviorBuilder::visitConditional_action(BehaviorParser::Conditional_actionContext* ctx) {

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
Behaviors::BehaviorBuilder::visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) {

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
Behaviors::BehaviorBuilder::visitDecl_Ped(BehaviorParser::Decl_PedContext* ctx) {
  return BehaviorBaseVisitor::visitDecl_Ped(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) {
  return BehaviorBaseVisitor::visitDecl_Ped_State(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) {
  return BehaviorBaseVisitor::visitDecl_Env_State(ctx);
}

antlrcpp::Any
Behaviors::BehaviorBuilder::visitDecl_Parameters(BehaviorParser::Decl_ParametersContext* ctx) {

  const auto& params = ctx->PARAMETER();

  std::for_each(params.begin(), params.end(), [&](antlr4::tree::TerminalNode* param) {
    std::string p = param->toString();
    spdlog::debug("Behavior \"{}\": Adding Param: \"{}\"", currentBehavior.getName(), p);
    currentBehavior.addParameter(p);
  });

  return BehaviorBaseVisitor::visitDecl_Parameters(ctx);
}

// ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
