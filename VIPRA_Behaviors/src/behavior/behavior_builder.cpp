
#include <algorithm>
#include <cmath>

#include <spdlog/spdlog.h>
#include <support/Any.h>

#include <generated/BehaviorLexer.h>
#include <generated/BehaviorParser.h>

#include <behavior/behavior_builder.hpp>

#include <definitions/type_definitions.hpp>
#include <optional>
#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>
#include <selectors/selector_percent.hpp>

#include <actions/atoms/atom_be.hpp>
#include <actions/atoms/atom_change_speed.hpp>
#include <actions/atoms/atom_stop.hpp>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>
#include <conditions/subconditions/subcondition_event.hpp>
#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include <conditions/subconditions/subcondition_start.hpp>

#include <definitions/directions.hpp>
#include <definitions/object.hpp>
#include <definitions/pedestrian_types.hpp>
#include "behavior/human_behavior.hpp"

namespace BHVR {

/**
 * @brief Parses the behavior file at filepath, returns the behavior it describes
 * 
 * @param behaviorName 
 * @param filepath 
 * @param seedNum 
 * @return HumanBehavior&&
 */
HumanBehavior BehaviorBuilder::build(std::string behaviorName, const std::filesystem::path& filepath, BHVR::seed seedNum) {

  if (!std::filesystem::exists(filepath)) {
    spdlog::error("Behavior \"{}\" Does NOT Exist at {}", behaviorName, filepath.c_str());
    BuilderException::error();
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

  return currentBehavior;
}

// ---------------------------------------- INITIALIZATION -----------------------------------------------------------------------------------

/**
 * @brief Cleans and sets up the builder for a new behavior
 * 
 * @param behaviorName : name of new behavior
 * @param seedNum : randomization seed for behavior
 */
void BehaviorBuilder::initialBehaviorSetup(const std::string& behaviorName, BHVR::seed seedNum) {
  currentBehavior = HumanBehavior(behaviorName);
  currentBehavior.setSeed(seedNum);
  currSeed = seedNum;
  initializeStates();
  initializeEvents();
  initializeTypes();
  initializeLocations();
}

void BehaviorBuilder::initializeEvents() {
  eventsMap.clear();

  startEvent = Event("!start");
  startCond = Condition();
  startCond.addSubCondition(SubConditionStart{});
  startEvent.setStartCondition(startCond);

  eventsMap["!start"] = currentBehavior.addEvent(startEvent);
}

void BehaviorBuilder::initializeStates() {
  states.clear();
  currState = 1;
}

void BehaviorBuilder::initializeTypes() {
  types.clear();
  types["pedestrian"] = 0;
  types["pedestrians"] = 0;
  currType = 1;
}

void BehaviorBuilder::initializeLocations() {
  locations.clear();


}


// ------------------------------------ END INITIALIZATION --------------------------------------------------------------------------------------

/**
 * @brief Creates a new condition adding all sub_conditions and operations
 * 
 * @param cond 
 * @return Condition
 */
Condition BehaviorBuilder::buildCondition(BehaviorParser::ConditionContext* cond) {
  Condition condition;

  auto* subcond = cond->sub_condition();
  addSubCondToCondtion(condition, subcond);

  const auto connectors = cond->connector();
  std::for_each(connectors.begin(), connectors.end(), [&](auto connector) {
    BehaviorParser::Sub_conditionContext* cond = nullptr;

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
void BehaviorBuilder::addSubCondToCondtion(Condition& condition, BehaviorParser::Sub_conditionContext* subcond) {

  if (subcond->condition_Time_Elapsed_From_Event()) {
    VIPRA::delta_t time = getValue(subcond->condition_Time_Elapsed_From_Event()->duration()->value_number());
    std::string    evName = subcond->condition_Time_Elapsed_From_Event()->EVNT()->toString();
    spdlog::debug(R"(Behavior "{}": Adding SubCondition: Elapsed Time {} Seconds From "{}" Event)",
                  currentBehavior.getName(),
                  std::to_string(time),
                  evName);
    condition.addSubCondition(SubConditionElapsedTimeFromEvent(time, getEvent(evName)));
    return;
  }

  if (subcond->condition_Event_Occurred()) {
    std::string evName = subcond->condition_Event_Occurred()->EVNT()->toString();
    spdlog::debug(R"(Behavior "{}": Adding SubCondition: Event "{}" Occurred)", currentBehavior.getName(), evName);
    condition.addSubCondition(SubConditionEventOccurred(getEvent(evName)));
    return;
  }

  if (subcond->condition_Event_Occurring()) {
    std::string evName = subcond->condition_Event_Occurring()->EVNT()->toString();
    spdlog::debug(R"(Behavior "{}": Adding SubCondition: Event "{}" Occurring)", currentBehavior.getName(), evName);
    condition.addSubCondition(SubConditionEventOccurring(getEvent(evName)));
    return;
  }

  spdlog::error("Behavior Error: No Valid SubCondition For: \"{}\"", subcond->getText());
  BuilderException::error();
}

/**
 * @brief Creates an action atom and adds it to the action
 * 
 * @param action : action to add the atom to
 * @param atom : atom context
 */
void BehaviorBuilder::addAtomToAction(Action& action, BehaviorParser::Action_atomContext* atom) {

  if (atom->action_atom_Percent_Walk_Speed()) {
    spdlog::debug(R"(Behavior "{}": Adding Action Atom: "Change Speed")", currentBehavior.getName());
    float change = getValue(atom->action_atom_Percent_Walk_Speed()->value_number());
    action.addAtom(AtomChangeSpeed{change});
    return;
  }

  if (atom->action_Be()) {
    auto     stateStr = atom->action_Be()->STATE()->toString();
    stateUID state = getState(stateStr);
    spdlog::debug(R"(Behavior "{}": Adding Action Atom: "Be State" state: {})", currentBehavior.getName(), stateStr);
    action.addAtom(AtomBe{state});
    return;
  }

  // ------------ One Word Atoms -----------------
  std::string atomName = atom->getText();

  if (atom->action_Stop()) {
    spdlog::debug(R"(Behavior "{}": Adding Action Atom: "Stop")", currentBehavior.getName());
    action.addAtom(AtomStop{});
    return;
  }

  spdlog::error("Behavior Error: No Atom \"{}\"", atomName);
  BuilderException::error();
}

// ------------------------- UTIL Methods -----------------------------------------------------------------------------------------------------

/**
 * @brief Gets a pointer to the event with name evName from eventsMap
 * @exits if the event isn't found
 * 
 * @param evName : name of event to find
 * @return Event*
 */
VIPRA::idx BehaviorBuilder::getEvent(const std::string& evName) {
  auto ev = eventsMap.find(evName);
  if (ev == eventsMap.end()) {
    spdlog::error("Behavior Error: Attempt To Use Event Before It Was Defined: \"{}\"", evName);
    BuilderException::error();
  }

  return (*ev).second;
}


/**
 * @brief Gets a pointer to the Location with a name locName from LocationsMap
 * @exits if the location was not found
 * 
 * @param locName : Name of location to find
 * @return Location*
*/
VIPRA::idx BehaviorBuilder::getLocation(const std::string& locName) {
  auto loc = locations.find(locName);
  if(loc == locations.end()) {
    spdlog::error("Behavior Error: Attempt To Use Location Before It Was Defined: \"{}\"", locName);
    exit(1);
  }

  return (*loc).second;
}

/**
 * @brief Returns the stateUID associated with a state string
 * @exits if the state isn't found
 * 
 * @param state : name of state
 * @return stateUID 
 */
stateUID BehaviorBuilder::getState(const std::string& state) {
  if (states.find(state) == states.end()) {
    spdlog::error("Behavior Error: Attempt To Use Undeclared State: \"{}\"", state);
    BuilderException::error();
  }

  return states.at(state);
}

/**
 * @brief Gets the id for a type from its name
 * @exits if the type isn't found
 * 
 * @param type : type name
 * @return typeUID
 */
typeUID BehaviorBuilder::getType(const std::string& type) const {
  const auto typeId = types.find(type);

  if (typeId == types.end()) {
    spdlog::error("Behavior Error: Attempt To Use Undeclared Pedestrian Type: \"{}\"", type);
    BuilderException::error();
  }

  return (*typeId).second;
}

/**
 * @brief Combines a list of types into one type
 * 
 * @param types : id_list vector
 * @return BHVR::Ptype 
 */
BHVR::Ptype BehaviorBuilder::getCompositeType(const std::vector<antlr4::tree::TerminalNode*>& types) const {
  Ptype compType;
  for (auto* type : types) {
    const std::string tStr = type->toString();
    auto              tid = getType(tStr);
    compType += tid;
  }

  return compType;
}

/**
 * @brief Gets a numerical value from a value context
 * 
 * @param value : value context
 * @return float 
 */
float BehaviorBuilder::getValue(BehaviorParser::Value_numberContext* value) const {
  if (value->FLOAT()) {
    return std::stof(value->FLOAT()->toString());
  }

  if (value->NUMBER()) {
    return std::stof(value->NUMBER()->toString());
  }

  if (value->number_random()) {
    auto* ctx = value->number_random();

    float ret = 0;
    if (ctx->random_float()) {
      auto numbers = ctx->random_float()->FLOAT();
      ret = makeRandomValue(std::stof(numbers[0]->toString()), std::stof(numbers[1]->toString()));
    } else {
      auto numbers = ctx->random_number()->NUMBER();
      ret = std::round(makeRandomValue(std::stof(numbers[0]->toString()), std::stof(numbers[1]->toString())));
    }

    return ret;
  }

  spdlog::error("Behavior Error: Unable To Get Value For Behavior: \"{}\"", currentBehavior.getName());
  BuilderException::error();
  return 0;
}

VIPRA::time_range_s BehaviorBuilder::getRange(BehaviorParser::Value_numberContext* value) {

  VIPRA::time_range_s ret;

  if (value->number_random()) {
    auto* ctx = value->number_random();

    if (ctx->random_float()) {
      auto numbers = ctx->random_float()->FLOAT();
      ret.first = std::stof(numbers[0]->toString());
      ret.second = std::stof(numbers[1]->toString());
    } else {
      auto numbers = ctx->random_number()->NUMBER();
      ret.first = std::round(std::stof(numbers[0]->toString()));
      ret.second = std::round(std::stof(numbers[1]->toString()));
    }

    return ret;
  }

  if (value->FLOAT()) {
    float val = std::stof(value->FLOAT()->toString());
    ret = {val, val};
    return ret;
  }

  if (value->NUMBER()) {
    float val = std::stof(value->NUMBER()->toString());
    ret = {val, val};
    return ret;
  }

  spdlog::error("Behavior Error: Unable To Get Value For Behavior: \"{}\"", currentBehavior.getName());
  BuilderException::error();
  return {0, 0};
}

/**
 * @brief Makes a random float between min and max (inclusive)
 * 
 * @param min : minimum value
 * @param max : maximum value
 * @return float 
 */
float BehaviorBuilder::makeRandomValue(float min, float max) const {
  srand(currSeed);

  // TODO(rolland): replace rand
  float val = min + (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min)));

  return val;
}

/**
 * @brief Creates a vector with all of the strings for each type in a given id_list
 * 
 * @param types : id_list vector
 * @return std::vector<std::string>
 */
std::vector<std::string> BehaviorBuilder::getListStrs(const std::vector<antlr4::tree::TerminalNode*>& types) {
  std::vector<std::string> strs(types.size());

  std::transform(
      types.begin(), types.end(), strs.begin(), [](antlr4::tree::TerminalNode* type) { return type->toString(); });

  return strs;
}

/**
 * @brief Checks the built behavior for possible issues
 * 
 */
void BehaviorBuilder::endBehaviorCheck() {
  if (currentBehavior.selectorCount() == 0) {
    spdlog::error("Behavior Error: No Pedestrian Selector Defined For Behavior: \"{}\"", currentBehavior.getName());
    BuilderException::error();
  }
  if (currentBehavior.actionCount() == 0) {
    spdlog::error("Behavior Error: No Actions Defined For Behavior: \"{}\"", currentBehavior.getName());
    BuilderException::error();
  }
}

// --------------------------------------------- ANTLR VISITOR METHODS -----------------------------------------------------------------------------------------

/**
 * @brief Creates a new single fire event and adds it to the eventsMap
 * 
 * @param ctx : antlr context
 * @return antlrcpp::Any
 */
antlrcpp::Any BehaviorBuilder::visitEvent_Single(BehaviorParser::Event_SingleContext* ctx) {

  std::string eventName = ctx->EVNT()->toString();

  if (eventsMap.find(eventName) != eventsMap.end()) {
    spdlog::error(R"(Behavior "{}": Attempt To Redefine Event: "{}")", eventName);
    BuilderException::error();
  }

  Event event(eventName);

  spdlog::debug(R"(Behavior "{}": Adding Single Fire Event: "{}")", currentBehavior.getName(), eventName);
  eventsMap[eventName] = currentBehavior.eventCount();

  auto* startCtx = ctx->condition();

  event.setStartCondition(buildCondition(startCtx));
  event.setEndCondition(buildCondition(nullptr));

  eventsMap[eventName] = currentBehavior.addEvent(event);

  return BehaviorBaseVisitor::visitEvent_Single(ctx);
}

/**
 * @brief Creates a lasting event and adds it to the eventsMap
 * 
 * @param ctx : antlr context
 * @return antlrcpp::Any 
 */
antlrcpp::Any BehaviorBuilder::visitEvent_Lasting(BehaviorParser::Event_LastingContext* ctx) {
  std::string eventName = ctx->EVNT()->toString();

  if (eventsMap.find(eventName) != eventsMap.end()) {
    spdlog::error(R"(Behavior "{}": Attempt To Redefine Event: "{}")", eventName);
    BuilderException::error();
  }

  Event event(eventName);

  spdlog::debug(R"(Behavior "{}": Adding Lasting Event: "{}")", currentBehavior.getName(), eventName);
  eventsMap[eventName] = currentBehavior.eventCount();

  auto* startCtx = ctx->condition()[0];
  auto* endCtx = ctx->condition()[1];

  spdlog::debug(R"(Behavior "{}": Event: "{}" Adding Start Condition)", currentBehavior.getName(), eventName);
  event.setStartCondition(buildCondition(startCtx));
  spdlog::debug(R"(Behavior "{}": Event: "{}" Adding End Condition)", currentBehavior.getName(), eventName);
  event.setEndCondition(buildCondition(endCtx));

  eventsMap[eventName] = currentBehavior.addEvent(event);

  return BehaviorBaseVisitor::visitEvent_Lasting(ctx);
}

// ------------------------------- END EVENTS -----------------------------------------------------------------------------------------

// ------------------------------- SELECTORS -----------------------------------------------------------------------------------------

/**
 * @brief Gets the typeUID of the group for a selector
 * 
 * @param ctx : 
 * @return BHVR::typeUID 
 */
BHVR::typeUID BehaviorBuilder::getGroup(BehaviorParser::Ped_SelectorContext* ctx) const {
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
SubSelector BehaviorBuilder::buildSubSelector(BehaviorParser::Ped_SelectorContext* ctx) {

  auto  types = ctx->id_list()->ID();
  Ptype comPtype = getCompositeType(types);
  auto  typeStrs = getListStrs(types);
  bool  required = ctx->REQUIRED() != nullptr;

  if (ctx->selector_Everyone()) {
    spdlog::debug(R"(Behavior "{}": Adding Selector: "Everyone" Is Ped Type: {})",
                  currentBehavior.getName(),
                  fmt::join(typeStrs, ", "));
    return SubSelector{0, comPtype, required, SelectorEveryone{}};
  }

  auto*       selector = ctx->selector();
  typeUID     group = getGroup(ctx);
  std::string groupStr = (group != 0U ? ctx->ID()->toString() : "Pedestrians");

  if (selector->selector_Exactly_N_Random()) {
    const auto nPeds = static_cast<VIPRA::size>(getValue(selector->selector_Exactly_N_Random()->value_number()));
    spdlog::debug(R"(Behavior "{}": Adding Selector: "Exactly {}" of {} Are Ped Type: {})",
                  currentBehavior.getName(),
                  nPeds,
                  groupStr,
                  fmt::join(typeStrs, ", "));
    return SubSelector{group, comPtype, required, SelectorExactlyN{nPeds}};
  }

  if (selector->selector_Percent()) {
    float percentage = getValue(selector->selector_Percent()->value_number());
    spdlog::debug(R"(Behavior "{}": Adding Selector: "{} Percent" of {} Are Ped Type: {})",
                  currentBehavior.getName(),
                  percentage,
                  groupStr,
                  fmt::join(typeStrs, ", "));
    return SubSelector{group, comPtype, required, SelectorPercent{percentage / 100.0F}};
  }

  spdlog::error("Behavior Error: Unable To Create Selector For Behavior \"{}\"", currentBehavior.getName());
  BuilderException::error();
  return SubSelector{group, Ptype{0}, true, SelectorEveryone{}};
}

antlrcpp::Any BehaviorBuilder::visitPed_Selector(BehaviorParser::Ped_SelectorContext* ctx) {

  currentBehavior.addSubSelector(buildSubSelector(ctx));

  return BehaviorBaseVisitor::visitPed_Selector(ctx);
}
// ------------------------------- END SELECTORS -----------------------------------------------------------------------------------------

// ------------------------------- ACTIONS -----------------------------------------------------------------------------------------

antlrcpp::Any BehaviorBuilder::visitConditional_action(BehaviorParser::Conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  const auto typeStr = ctx->ID()->toString();
  const auto type = getType(typeStr);

  if (ctx->duration()) {
    const auto timeRange = getRange(ctx->duration()->value_number());
    spdlog::debug("Behavior \"{}\": Adding Time Range To Action For {}, Range: {}-{}",
                  currentBehavior.getName(),
                  typeStr,
                  timeRange.first,
                  timeRange.second);
    action.addDuration(timeRange, currSeed);
  }

  spdlog::debug("Behavior \"{}\": Adding Conditional Action For {}", currentBehavior.getName(), typeStr);
  action.addCondition(buildCondition(ctx->condition()));

  std::for_each(
      atoms.begin(), atoms.end(), [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  currentBehavior.addAction(type, action);

  return BehaviorBaseVisitor::visitConditional_action(ctx);
}

antlrcpp::Any BehaviorBuilder::visitUn_conditional_action(BehaviorParser::Un_conditional_actionContext* ctx) {

  const auto& atoms = ctx->sub_action()->action_atom();
  Action      action;

  const auto typeStr = ctx->ID()->toString();
  const auto type = getType(typeStr);

  spdlog::debug("Behavior \"{}\": Adding Unconditional Action For {}", currentBehavior.getName(), typeStr);

  std::for_each(
      atoms.begin(), atoms.end(), [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  currentBehavior.addAction(type, action);
  return BehaviorBaseVisitor::visitUn_conditional_action(ctx);
}

// ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

// ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

antlrcpp::Any 
BehaviorBuilder::visitDecl_Loc(BehaviorParser::Decl_LocContext* ctx) {

  if (ctx->decl_Loc_Area_Circle()) {

    const std::string circleName = ctx->decl_Loc_Area_Circle()->ID()->toString();
    spdlog::debug("Behavior \"{}\": Adding Location {}", currentBehavior.getName(), circleName);

    float circleCenterPointX = getValue(ctx->decl_Loc_Area_Circle()->point()->value_number().at(0));
    float circleCenterPointY = getValue(ctx->decl_Loc_Area_Circle()->point()->value_number().at(1));
    float circleRadius = getValue(ctx->decl_Loc_Area_Circle()->value_number());

    std::shared_ptr<BHVR::Shape> circle = std::make_shared<BHVR::Circle>(VIPRA::f3d(circleCenterPointX, circleCenterPointY), circleRadius);

    locations[circleName] = currentBehavior.addLocation(BHVR::Location(circleName, BHVR::ShapeType::CIRCLE, circle));

  } else if (ctx->decl_Loc_Area_Rect()) {
    
    const auto rectName = ctx->decl_Loc_Area_Rect()->ID()->toString();
    spdlog::debug("Behavior \"{}\": Adding Location {}", currentBehavior.getName(), rectName);

    const auto rectCenterPointX = getValue(ctx->decl_Loc_Area_Rect()->point()->value_number().at(0));
    const auto rectCenterPointY = getValue(ctx->decl_Loc_Area_Rect()->point()->value_number().at(1));
    const auto rectLen = getValue(ctx->decl_Loc_Area_Rect()->value_number().at(0));
    const auto rectWidth = getValue(ctx->decl_Loc_Area_Rect()->value_number().at(1));

    std::shared_ptr<BHVR::Shape> rectangle = std::make_shared<BHVR::Rectangle>(VIPRA::f3d(rectCenterPointX, rectCenterPointY), rectLen, rectWidth);
    
    locations[rectName] = currentBehavior.addLocation(BHVR::Location(rectName, BHVR::ShapeType::RECTANGLE, rectangle)); 

  } else if(ctx->decl_Loc_Point()) {

    const auto pointName = ctx->decl_Loc_Point()->ID()->toString();
    spdlog::debug("Behavior \"{}\": Adding Location {}", currentBehavior.getName(), pointName);

    const auto pointX = getValue(ctx->decl_Loc_Point()->point()->value_number().at(0));
    const auto pointY = getValue(ctx->decl_Loc_Point()->point()->value_number().at(1));

    std::shared_ptr<BHVR::Shape> point = std::make_shared<BHVR::Point>(VIPRA::f3d(pointX, pointY));

    locations[pointName] = currentBehavior.addLocation(BHVR::Location(pointName, BHVR::ShapeType::POINT, point)); 
    
  }

  return BehaviorBaseVisitor::visitDecl_Loc(ctx);
}

antlrcpp::Any
BehaviorBuilder::visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) {
  const auto stateNames = ctx->STATE();

  for (auto* state : stateNames) {
    auto name = state->toString();
    spdlog::debug("Behavior \"{}\": Adding Pedestrian State {}, id: {}", currentBehavior.getName(), name, currState);
    states[name] = currState;
    ++currState;
  }

  return BehaviorBaseVisitor::visitDecl_Ped_State(ctx);
}

antlrcpp::Any BehaviorBuilder::visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) {
  const auto stateNames = ctx->STATE();

  for (auto* state : stateNames) {
    auto name = state->toString();
    spdlog::debug("Behavior \"{}\": Adding Environment State {}, id: {}", currentBehavior.getName(), name, currState);
    states[name] = currState;
    ++currState;
  }

  return BehaviorBaseVisitor::visitDecl_Env_State(ctx);
}

antlrcpp::Any BehaviorBuilder::visitDecl_Ped(BehaviorParser::Decl_PedContext* ctx) {
  const auto typeNames = ctx->ID();
  Ptype      allTypes;

  for (auto* type : typeNames) {
    auto name = type->toString();
    spdlog::debug("Behavior \"{}\": Adding Pedestrian Type {}, id: {}", currentBehavior.getName(), name, currType);
    types[name] = currType;
    allTypes += currType;
    currType = currType << 1U;
  }

  spdlog::debug("Behavior \"{}\": All Types: {}", currentBehavior.getName(), allTypes.fullType);
  currentBehavior.setAllPedTypes(allTypes);
  return BehaviorBaseVisitor::visitDecl_Ped(ctx);
}

// ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------
}  // namespace BHVR