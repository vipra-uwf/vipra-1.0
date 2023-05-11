#include <antlr4-runtime/support/Any.h>
#include <spdlog/spdlog.h>

#include <generated/BehaviorLexer.h>
#include <generated/BehaviorParser.h>

#include <behavior/behavior_builder.hpp>

#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>
#include <selectors/selector_percent.hpp>

#include <actions/atoms/atom_be.hpp>
#include <actions/atoms/atom_change_speed.hpp>
#include <actions/atoms/atom_stop.hpp>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>
#include <conditions/subconditions/subcondition_event.hpp>
#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include <conditions/subconditions/subcondition_event_one_time.hpp>
#include <conditions/subconditions/subcondition_start.hpp>

#include <definitions/directions.hpp>
#include <definitions/object.hpp>
#include <definitions/pedestrian_types.hpp>

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

  endBehaviorCheck();

  return std::move(currentBehavior);
}

/**
 * @brief Gets a pointer to the event with name evName from eventsMap
 * 
 * @param evName : name of event to find
 * @return Event*
 */
Event*
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

  initializeStates();
  initializeEvents();
  initializeTypes();
  currentBehavior = HumanBehavior(behaviorName);
  currentBehavior.setSeed(seedNum);
}

void
BehaviorBuilder::initializeEvents() {
  eventsMap.clear();

  startEvent = Event("!start");
  startCond.addSubCondition(SubCondition_Start{});
  startEvent.setStartCondition(std::move(startCond));

  eventsMap["!start"] = currentBehavior.addEvent(std::move(startEvent));
}

void
BehaviorBuilder::initializeStates() {
  states.clear();
  currState = 1;
}

void
BehaviorBuilder::initializeTypes() {
  types.clear();
  types["pedestrian"] = 0;
  types["pedestrians"] = 0;
  currType = 1;
}

/**
 * @brief Checks the built behavior for possible issues
 * 
 */
void
BehaviorBuilder::endBehaviorCheck() {
  if (currentBehavior.selectorCount() == 0) {
    spdlog::error("Behavior Error: No Pedestrian Selector Defined For Behavior: \"{}\"", currentBehavior.getName());
    exit(1);
  }
  if (currentBehavior.actionCount() == 0) {
    spdlog::error("Behavior Error: No Actions Defined For Behavior: \"{}\"", currentBehavior.getName());
    exit(1);
  }
}

/**
 * @brief Returns the stateUID associated with a state string, creating a new association if it doesn't exist
 * 
 * @param state : name of state
 * @return stateUID 
 */
stateUID
BehaviorBuilder::getState(const std::string& state) {
  if (states.find(state) == states.end()) {
    spdlog::error("Behavior Error: Attempt To Use Undeclared State: \"{}\"", state);
    exit(1);
  }

  return states.at(state);
}

typeUID
BehaviorBuilder::getType(const std::string& type) {
  const auto typeId = types.find(type);

  if (typeId == types.end()) {
    for (auto i : types) {
      spdlog::info("{}", i.first);
    }
    spdlog::error("Behavior Error: Attempt To Use Undeclared Pedestrian Type: \"{}\"", type);
    exit(1);
  }

  return (*typeId).second;
}

Behaviors::pType
BehaviorBuilder::getCompositeType(const std::vector<antlr4::tree::TerminalNode*>& types) {
  pType type;
  for (VIPRA::idx i = 0; i < types.size(); ++i) {
    const std::string tStr = types[i]->toString();
    auto              tid = getType(tStr);
    type += tid;
  }

  return type;
}

std::vector<std::string>
BehaviorBuilder::getTypeStrs(const std::vector<antlr4::tree::TerminalNode*>& types) {
  std::vector<std::string> strs;

  for (auto type : types) {
    strs.push_back(type->toString());
  }

  return strs;
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

  auto subcond = cond->sub_condition();
  addSubCondToCondtion(condition, subcond);

  const auto connectors = cond->connector();
  std::for_each(connectors.begin(), connectors.end(), [&](auto connector) {
    BehaviorParser::Sub_conditionContext* cond;

    if (connector->and_Connector()) {
      cond = connector->and_Connector()->sub_condition();
      condition.addAndOr(true);
    } else {
      cond = connector->or_Connector()->sub_condition();
      condition.addAndOr(false);
    }

    addSubCondToCondtion(condition, cond);
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

  if (subcond->condition_Time_Elapsed_From_Event()) {
    VIPRA::delta_t time = std::stof(subcond->condition_Time_Elapsed_From_Event()->NUMBER()->toString());
    std::string    evName = subcond->condition_Time_Elapsed_From_Event()->EVNT()->toString();
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Elapsed Time From \"{}\" Event", currentBehavior.getName(), evName);
    condition.addSubCondition(SubCondition_Elapsed_Time_From_Event{time, getEvent(evName)});
    return;
  }

  if (subcond->condition_Event_Occurred()) {
    std::string evName = subcond->condition_Event_Occurred()->EVNT()->toString();
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Event \"{}\" Occurred", currentBehavior.getName(), evName);
    condition.addSubCondition(SubCondition_Event_Occurred{getEvent(evName)});
    return;
  }

  if (subcond->condition_Event_Occurring()) {
    std::string evName = subcond->condition_Event_Occurring()->EVNT()->toString();
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Event \"{}\" Occurring", currentBehavior.getName(), evName);
    condition.addSubCondition(SubCondition_Event_Occurring{getEvent(evName)});
    return;
  }

  if (subcond->condition_Event_One_Time()) {
    std::string evName = subcond->condition_Event_One_Time()->EVNT()->toString();
    bool        onstart = (subcond->condition_Event_One_Time()->STARTS() != nullptr);
    spdlog::debug("Behavior \"{}\": Adding SubCondition: Event \"{}\" {}",
                  currentBehavior.getName(),
                  evName,
                  onstart ? "starts" : "ends");

    condition.addSubCondition(SubCondition_Event_One_Time{onstart, getEvent(evName)});
    return;
  }

  spdlog::error("Behavior Error: No Valid SubCondition For: \"{}\"", subcond->getText());
  exit(1);
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
    float change = std::stof(atom->action_atom_Percent_Walk_Speed()->FLOAT()->toString());
    action.addAtom(Atom_Change_Speed{change});
    return;
  }

  if (atom->action_Be()) {
    auto     stateStr = atom->action_Be()->STATE()->toString();
    stateUID state = getState(stateStr);
    spdlog::debug("Behavior \"{}\": Adding Action Atom: \"Be State\" state: {}", currentBehavior.getName(), stateStr);
    action.addAtom(Atom_Be{state});
    return;
  }

  // ------------ One Word Atoms -----------------
  std::string atomName = atom->getText();

  if (atom->action_Stop()) {
    spdlog::debug("Behavior \"{}\": Adding Action Atom: \"Stop\"", currentBehavior.getName());
    action.addAtom(Atom_Stop{});
    return;
  }

  spdlog::error("Behavior Error: No Atom \"{}\"", atomName);
  exit(1);
}

// ------------------------------- ANTLR VISITOR METHODS -----------------------------------------------------------------------------------------

/**
 * @brief Creates a new single fire event and adds it to the eventsMap
 * 
 * @param ctx : antlr context
 * @return antlrcpp::Any
 */
antlrcpp::Any
BehaviorBuilder::visitEvent_Single(BehaviorParser::Event_SingleContext* ctx) {

  std::string eventName = ctx->EVNT()->toString();

  if (eventsMap.find(eventName) != eventsMap.end()) {
    spdlog::error("Behavior \"{}\": Attempt To Redefine Event: \"{}\"", eventName);
    exit(1);
  }

  Event event(eventName);

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
BehaviorBuilder::visitEvent_Lasting(BehaviorParser::Event_LastingContext* ctx) {
  std::string eventName = ctx->EVNT()->toString();

  if (eventsMap.find(eventName) != eventsMap.end()) {
    spdlog::error("Behavior \"{}\": Attempt To Redefine Event: \"{}\"", eventName);
    exit(1);
  }

  Event event(eventName);

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

/**
 * @brief Gets the typeUID of the group for a selector
 * 
 * @param ctx : 
 * @return Behaviors::typeUID 
 */
Behaviors::typeUID
BehaviorBuilder::getGroup(BehaviorParser::Ped_SelectorContext* ctx) {
  if (ctx->PEDESTRIAN() || ctx->PEDESTRIANS()) {
    return 0;
  }

  return getType(ctx->ID()->toString());
}

/**
 * @brief Creates a selector from a given context
 * 
 * @param ctx : 
 * @return Selector 
 */
SubSelector
BehaviorBuilder::buildSubSelector(BehaviorParser::Ped_SelectorContext* ctx) {

  auto  types = ctx->id_list()->ID();
  pType compType = getCompositeType(types);
  auto  typeStrs = getTypeStrs(types);
  bool  required = ctx->REQUIRED() != nullptr;

  if (ctx->selector_Everyone()) {
    spdlog::debug("Behavior \"{}\": Adding Selector: \"Everyone\" Is Ped Type: {}",
                  currentBehavior.getName(),
                  fmt::join(typeStrs, ", "));
    return SubSelector{0, compType, required, selector_everyone{}};
  }

  auto        selector = ctx->selector();
  typeUID     group = getGroup(ctx);
  std::string groupStr = (group ? ctx->ID()->toString() : "Pedestrians");

  if (selector->selector_Exactly_N_Random()) {
    const VIPRA::size N = static_cast<VIPRA::size>(std::stoi(selector->selector_Exactly_N_Random()->NUMBER()->toString()));
    spdlog::debug("Behavior \"{}\": Adding Selector: \"Exactly {}\" of {} Are Ped Type: {}",
                  currentBehavior.getName(),
                  N,
                  groupStr,
                  fmt::join(typeStrs, ", "));
    return SubSelector{group, compType, required, selector_exactly_N{N}};
  }

  if (selector->selector_Percent()) {
    float percentage = std::stof(selector->selector_Percent()->NUMBER()->toString());
    spdlog::debug("Behavior \"{}\": Adding Selector: \"{} Percent\" of {} Are Ped Type: {}",
                  currentBehavior.getName(),
                  percentage,
                  groupStr,
                  fmt::join(typeStrs, ", "));
    return SubSelector{group, compType, required, selector_percent{percentage / 100.0f}};
  }

  spdlog::error("Behavior Error: Unable To Create Selector For Behavior \"{}\"", currentBehavior.getName());
  exit(1);
  return SubSelector{group, pType{0}, true, selector_everyone{}};
}

antlrcpp::Any
BehaviorBuilder::visitPed_Selector(BehaviorParser::Ped_SelectorContext* ctx) {

  currentBehavior.addSubSelector(buildSubSelector(ctx));

  return BehaviorBaseVisitor::visitPed_Selector(ctx);
}
// ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

// ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitConditional_action(BehaviorParser::Conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  const auto typeStr = ctx->ID()->toString();
  const auto type = getType(typeStr);

  spdlog::debug("Behavior \"{}\": Adding Conditional Action For {}", currentBehavior.getName(), typeStr);
  action.addCondition(buildCondition(ctx->condition()));

  std::for_each(
      atoms.begin(), atoms.end(), [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  currentBehavior.addAction(type, std::move(action));

  return BehaviorBaseVisitor::visitConditional_action(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  const auto typeStr = ctx->ID()->toString();
  const auto type = getType(typeStr);

  spdlog::debug("Behavior \"{}\": Adding Unconditional Action For {}", currentBehavior.getName(), typeStr);

  std::for_each(
      atoms.begin(), atoms.end(), [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  currentBehavior.addAction(type, std::move(action));
  return BehaviorBaseVisitor::visitUn_conditional_action(ctx);
}

// ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

// ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

antlrcpp::Any
BehaviorBuilder::visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) {
  const auto stateNames = ctx->STATE();

  for (auto state : stateNames) {
    auto name = state->toString();
    spdlog::debug("Behavior \"{}\": Adding Pedestrian State {}, id: {}", currentBehavior.getName(), name, currState);
    states[name] = currState;
    ++currState;
  }

  return BehaviorBaseVisitor::visitDecl_Ped_State(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) {
  const auto stateNames = ctx->STATE();

  for (auto state : stateNames) {
    auto name = state->toString();
    spdlog::debug("Behavior \"{}\": Adding Environment State {}, id: {}", currentBehavior.getName(), name, currState);
    states[name] = currState;
    ++currState;
  }

  return BehaviorBaseVisitor::visitDecl_Env_State(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitDecl_Ped(BehaviorParser::Decl_PedContext* ctx) {
  const auto typeNames = ctx->ID();
  pType      allTypes;

  for (auto type : typeNames) {
    auto name = type->toString();
    spdlog::debug("Behavior \"{}\": Adding Pedestrian Type {}, id: {}", currentBehavior.getName(), name, currType);
    types[name] = currType;
    allTypes += currType;
    currType = currType << 1;
  }

  spdlog::debug("Behavior \"{}\": All Types: {}", currentBehavior.getName(), allTypes.fullType);
  currentBehavior.setAllPedTypes(allTypes);
  return BehaviorBaseVisitor::visitDecl_Ped(ctx);
}

// ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
}  // namespace Behaviors