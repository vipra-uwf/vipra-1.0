
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <optional>
#include <stdexcept>
#include <string>

#include <spdlog/spdlog.h>
#include <support/Any.h>

#include <generated/BehaviorLexer.h>
#include <generated/BehaviorParser.h>

#include <builder/behavior_builder.hpp>

#include <definitions/type_definitions.hpp>
#include <selectors/selector_everyone.hpp>
#include <selectors/selector_exactly_N.hpp>
#include <selectors/selector_percent.hpp>

#include <actions/atoms/atom_set.hpp>

#include <conditions/subconditions/subcondition_elapsed_time.hpp>
#include <conditions/subconditions/subcondition_event.hpp>
#include <conditions/subconditions/subcondition_event_occurring.hpp>
#include <conditions/subconditions/subcondition_start.hpp>

#include <behavior/human_behavior.hpp>
#include <definitions/pedestrian_types.hpp>

#include <actions/atoms/atom_scale.hpp>
#include <attributes/attributes.hpp>
#include <behavior/exceptions.hpp>
#include <conditions/subconditions/subcondition_event_ending.hpp>
#include <conditions/subconditions/subcondition_event_starting.hpp>
#include <conditions/subconditions/subcondition_spatial.hpp>
#include <definitions/dsl_types.hpp>
#include <targets/target_selector.hpp>
#include <targets/target_selectors/target_nearest.hpp>
#include <targets/target_selectors/target_self.hpp>
#include <time/time.hpp>
#include <values/numeric_value.hpp>
#include <values/values.hpp>

namespace BHVR {

// NOLINTNEXTLINE Bug in clang-tidy (https://bugs.llvm.org/show_bug.cgi?id=48040) : ignores (cppcoreguidelines-avoid-non-const-global-variables)
std::vector<CAttributeValue> AttributeHandling::valueStore{};

/**
 * @brief Parses the behavior file at filepath, returns the behavior it describes
 * 
 * @param behaviorName : name of the behavior
 * @param filepath : path to the behavior file
 * @param seedNum : seed for randomization
 * @return HumanBehavior&&
 */
HumanBehavior BehaviorBuilder::build(std::string                  behaviorName,
                                     const std::filesystem::path& filepath,
                                     BHVR::seed                   seedNum) {
  if (!std::filesystem::exists(filepath)) {
    spdlog::error("Behavior \"{}\" Does NOT Exist at {}", behaviorName, filepath.c_str());
    BuilderException::error();
  }

  spdlog::debug("Loading Behavior: {} at {}", behaviorName,
                std::filesystem::canonical(filepath).c_str());
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
void BehaviorBuilder::initialBehaviorSetup(const std::string& behaviorName,
                                           BHVR::seed         seedNum) {
  currentBehavior = HumanBehavior(behaviorName);
  currentBehavior.setSeed(seedNum);
  currSeed = seedNum;
  initializeStates();
  initializeEvents();
  initializeTypes();
  initializeLocations();
}

/**
 * @brief cleans and sets up the events map
 * 
 */
void BehaviorBuilder::initializeEvents() {
  eventsMap.clear();

  startEvent = Event("Start");
  startCond = Condition();
  startCond.addSubCondition(SubConditionStart{});
  startEvent.setStartCondition(startCond);

  eventsMap["!Start"] = currentBehavior.addEvent(startEvent);
}

/**
 * @brief cleans and sets up the states map
 * 
 */
void BehaviorBuilder::initializeStates() {
  states.clear();
  currState = 1;
}

/**
 * @brief cleans and sets up the types map
 * 
 */
void BehaviorBuilder::initializeTypes() {
  types.clear();
  types["pedestrian"] = 0;
  types["pedestrians"] = 0;
  currType = 1;
}

/**
 * @brief cleans and sets up the locations map
 * 
 */
void BehaviorBuilder::initializeLocations() { locations.clear(); }

// ------------------------------------ END INITIALIZATION --------------------------------------------------------------------------------------

/**
 * @brief Checks the built behavior for possible issues
 * 
 */
void BehaviorBuilder::endBehaviorCheck() {
  if (currentBehavior.selectorCount() == 0) {
    spdlog::error("Behavior Error: No Pedestrian Selector Defined For Behavior: \"{}\"",
                  currentBehavior.getName());
    BuilderException::error();
  }
  if (currentBehavior.actionCount() == 0) {
    spdlog::error("Behavior Error: No Actions Defined For Behavior: \"{}\"",
                  currentBehavior.getName());
    BuilderException::error();
  }
}

/**
 * @brief Creates a new condition adding all sub_conditions and operations
 * 
 * @param cond : condition context
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
 * @brief Creates a subselector
 * 
 * @param ctx : subselector context
 * @return Selector 
 */
SubSelector BehaviorBuilder::buildSubSelector(slType type, slSelector selector,
                                              std::optional<slGroup> group,
                                              bool                   required) {
  if (selector->selector()->selector_Everyone()) {
    return buildEveryone(type, required);
  }

  if (selector->selector()->selector_Exactly_N_Random()) {
    return buildExactlyN(type, selector, group, required);
  }

  if (selector->selector()->selector_Percent()) {
    return buildPercent(type, selector, group, required);
  }

  spdlog::error("Behavior Error: Unable To Create Selector For Behavior \"{}\"",
                currentBehavior.getName());
  BuilderException::error();
}

/**
 * @brief Creates a subcondition from the context and adds it to the condition
 * 
 * @param condition : condition to add to
 * @param subcond : sub condition context
 */
void BehaviorBuilder::addSubCondToCondtion(
    Condition& condition, BehaviorParser::Sub_conditionContext* subcond) {
  if (subcond->condition_Time_Elapsed_From_Event()) {
    addTimeElapsed(condition, subcond->condition_Time_Elapsed_From_Event());
    return;
  }

  if (subcond->condition_Event_Occurred()) {
    addEventOccurred(condition, subcond->condition_Event_Occurred());
    return;
  }

  if (subcond->condition_Event_Occurring()) {
    addEventOccurring(condition, subcond->condition_Event_Occurring());
    return;
  }

  if (subcond->condition_Event_Starting()) {
    addEventStarting(condition, subcond->condition_Event_Starting());
    return;
  }

  if (subcond->condition_Event_Ending()) {
    addEventEnding(condition, subcond->condition_Event_Ending());
    return;
  }

  if (subcond->condition_Spatial()) {
    addSpatial(condition, subcond->condition_Spatial());
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
void BehaviorBuilder::addAtomToAction(Action&                             action,
                                      BehaviorParser::Action_atomContext* atom) {
  if (atom->set_atom()) {
    addSetAtom(action, atom->set_atom());
    return;
  }

  if (atom->scale_atom()) {
    addScaleAtom(action, atom->scale_atom());
    return;
  }

  spdlog::error("Behavior Error: No Atom");
  BuilderException::error();
}

/**
 * @brief Adds a target to an action
 * 
 */
void BehaviorBuilder::addTargetToAction(Action&                        action,
                                        BehaviorParser::TargetContext* ctx) {
  if (ctx->nearest_type()) {
    auto typeStr = ctx->nearest_type()->ID()->toString();
    auto type = getType(typeStr);
    spdlog::debug(R"(Behavior: "{}": Adding Target: Nearest "{}")",
                  currentBehavior.getName(), typeStr);
    action.addTarget(TargetSelector(TargetNearest{type}));
    return;
  }

  action.addTarget(TargetSelector(TargetSelf{}));
}

// --------------------------------------------------- END HELPERS ---------------------------------------------------------------------------------------------

// --------------------------------------------------- GETTERS -------------------------------------------------------------------------------------------------

/**
 * @brief Gets the id for a type from its name
 * 
 * @param type : type name
 * @return typeUID
 */
typeUID BehaviorBuilder::getType(const std::string& type) const {
  const auto typeId = types.find(type);
  if (typeId == types.end())
    error("Behavior Error: Attempt To Use Undeclared Pedestrian Type: \"{}\"", type);
  return (*typeId).second;
}

/**
 * @brief Gets the typeUID of the group for a selector
 * 
 * @param ctx : 
 * @return BHVR::typeUID 
 */
std::pair<BHVR::typeUID, std::string> BehaviorBuilder::getGroup(
    std::optional<slGroup> group) const {
  if (group) {
    auto* ctx = group.value()->group();
    if (!(ctx->PEDESTRIAN() || ctx->PEDESTRIANS())) {
      std::string name = ctx->ID()->toString();
      return {getType(name), name};
    }
  }

  return {0, "Pedestrians"};
}

/**
 * @brief Returns the stateUID associated with a state string
 * 
 * @param state : name of state
 * @return stateUID 
 */
BHVR::stateUID BehaviorBuilder::getState(const std::string& state) const {
  if (states.find(state) == states.end()) {
    spdlog::error("Behavior Error: Attempt To Use Undeclared State: \"{}\"", state);
    BuilderException::error();
  }

  return states.at(state);
}

/**
 * @brief Combines a list of types into one type
 * 
 * @param types : id_list vector
 * @return BHVR::Ptype 
 */
BHVR::Ptype BehaviorBuilder::getCompositeType(
    const std::vector<antlr4::tree::TerminalNode*>& types) const {
  Ptype compType;
  for (auto* type : types) {
    const std::string tStr = type->toString();
    auto              tid = getType(tStr);
    compType += tid;
  }

  return compType;
}

/**
 * @brief Gets a pointer to the Location with a name locName from LocationsMap
 * @exits if the location was not found
 * 
 * @param locName : Name of location to find
 * @return Location*
*/
VIPRA::idx BehaviorBuilder::getLocation(const std::string& locName) const {
  auto loc = locations.find(locName);
  if (loc == locations.end()) {
    spdlog::error("Behavior Error: Attempt To Use Location Before It Was Defined: \"{}\"",
                  locName);
    BuilderException::error();
  }

  return (*loc).second;
}

/**
 * @brief Gets a pointer to the event with name evName from eventsMap
 * @exits if the event isn't found
 * 
 * @param evName : name of event to find
 * @return Event*
 */
std::optional<VIPRA::idx> BehaviorBuilder::getEvent(const std::string& evName) const {
  auto ev = eventsMap.find(evName);
  if (ev == eventsMap.end()) return std::nullopt;
  return (*ev).second;
}

/**
 * @brief Returns the attribute type for attr
 * 
 * @param attr : attribute string
 * @return Attribute 
 */
Attribute BehaviorBuilder::getAttribute(std::string attr) {
  static std::map<std::string, Attribute> attrMap{
      {"position", Attribute::POSITION}, {"goal", Attribute::GOAL},
      {"state", Attribute::STATE},       {"velocity", Attribute::VELOCITY},
      {"location", Attribute::LOCATION}, {"status", Attribute::STATUS}};

  std::transform(attr.begin(), attr.end(), attr.begin(),
                 [](char ch) { return std::tolower(ch); });

  auto iter = attrMap.find(attr);
  if (iter == attrMap.end()) {
    return Attribute::INVALID;
  }

  return iter->second;
}

// --------------------------------------------------- END GETTERS ---------------------------------------------------------------------------------------------

// --------------------------------------------------- MAKERS --------------------------------------------------------------------------------------------------

/**
 * @brief Creates a new CAttributeValue from an attribute value context
 * 
 * @param ctx : attribute value context
 * @return BHVR::CAttributeValue 
 */
BHVR::CAttributeValue BehaviorBuilder::makeAttributeValue(
    BehaviorParser::Attr_valueContext* ctx) {
  if (ctx->value_coord()) {
    return AttributeHandling::storeValue<VIPRA::f3d>(
        Type::COORD, getCoord(ctx->value_coord(), currSeed));
  }

  if (ctx->STATE_VAL()) {
    return AttributeHandling::storeValue<BHVR::stateUID>(
        Type::STATE, getState(ctx->STATE_VAL()->toString()));
  }

  if (ctx->value_numeric()) {
    return AttributeHandling::storeValue<BHVR::NumericValue>(
        Type::NUMBER, getNumeric(ctx->value_numeric(), currSeed));
  }

  error("Unable To Create Attribute Value");
  return {Type::INVALID, nullptr};
}

/**
 * @brief Creates a vector with all of the strings for each type in a given id_list
 * 
 * @param types : id_list vector
 * @return std::vector<std::string>
 */
std::vector<std::string> BehaviorBuilder::makeListStrs(
    const std::vector<antlr4::tree::TerminalNode*>& types) {
  std::vector<std::string> strs(types.size());

  std::transform(types.begin(), types.end(), strs.begin(),
                 [](antlr4::tree::TerminalNode* type) { return type->toString(); });

  return strs;
}

/**
 * @brief Gets the string value of an attribute from a context
 * 
 */
std::string BehaviorBuilder::makeAttributeStr(BehaviorParser::AttributeContext* ctx) {
  if (ctx->POSITION()) {
    return "position";
  }
  if (ctx->VELOCITY()) {
    return "velocity";
  }
  if (ctx->GOAL()) {
    return "goal";
  }
  if (ctx->STATE()) {
    return "state";
  }
  if (ctx->LOCATION()) {
    return "location";
  }
  if (ctx->STATUS()) {
    return "status";
  }

  return "";
}

// --------------------------------------------------- END MAKERS --------------------------------------------------------------------------------------------------

/**
 * @brief Adds an event to the behavior
 * 
 * @param ctx : event context
 * @return VIPRA::idx 
 */
VIPRA::idx BehaviorBuilder::addEvent(BehaviorParser::Event_nameContext* ctx) {
  if (!ctx)
    error("Behavior Error: Event Not Given a Name: \"{}\"", currentBehavior.getName());

  auto eventName = ctx->ID()->toString();
  spdlog::debug(R"(Behavior "{}": Adding Lasting Event: "{}")", currentBehavior.getName(),
                eventName);

  VIPRA::idx eventIdx = currentBehavior.eventCount();
  eventsMap[eventName] = eventIdx;

  return eventIdx;
}

// --------------------------------------------- ANTLR VISITOR METHODS -----------------------------------------------------------------------------------------

/**
 * @brief Creates a lasting event and adds it to the eventsMap
 * 
 * @param ctx : antlr context
 * @return antlrcpp::Any 
 */
antlrcpp::Any BehaviorBuilder::visitEvent(BehaviorParser::EventContext* ctx) {
  // NOLINTBEGIN (rolland) access is checked, improper error : ignoring (bugprone-unchecked-optional-access)
  auto name = findEventComponent<evName>(ctx);
  if (!name) error(R"(Behavior "{}": Missing Event Name)", currentBehavior.getName());
  std::string eventName = "!" + name.value();

  if (getEvent(eventName))
    error(R"(Behavior "{}": Attempt To Redefine Event: "{}")", currentBehavior.getName(),
          eventName);

  auto startCond = findEventComponent<evStart>(ctx);
  if (!startCond)
    error(R"(Behavior "{}": Missing Start Condition)", currentBehavior.getName());

  auto endCond = findEventComponent<evEnd>(ctx);

  // NOTE(rolland): a bit odd but we need to ensure that the event is in the map, incase the conditions rely on it
  eventsMap[eventName] = currentBehavior.eventCount();

  Event event(eventName);

  spdlog::debug(R"(Behavior "{}": Event: "{}" Adding Start Condition)",
                currentBehavior.getName(), eventName);
  event.setStartCondition(buildCondition(startCond.value()->condition()));

  if (endCond) {
    spdlog::debug(R"(Behavior "{}": Event: "{}" Adding End Condition)",
                  currentBehavior.getName(), eventName);
    event.setEndCondition(buildCondition(endCond.value()->condition()));
  }

  eventsMap[eventName] = currentBehavior.addEvent(event);

  return BehaviorBaseVisitor::visitEvent(ctx);
  // NOLINTEND
}

antlrcpp::Any BehaviorBuilder::visitAction(BehaviorParser::ActionContext* ctx) {
  auto response = findActionComponent<acResponse>(ctx);
  if (!response)
    error(R"(Behavior "{}": Action has no Response)", currentBehavior.getName());

  auto stimulus = findActionComponent<acStimulus>(ctx);
  auto target = findActionComponent<acTarget>(ctx);
  auto duration = findActionComponent<acDuration>(ctx);

  Action action;

  const auto typeStr = ctx->ID()->toString();
  const auto type = getType(typeStr);

  spdlog::debug("Behavior \"{}\": Adding Action For {}", currentBehavior.getName(),
                typeStr);

  // NOLINTNEXTLINE (rolland) access is checked, improper error : ignoring (bugprone-unchecked-optional-access)
  auto atoms = response.value()->sub_action()->action_atom();
  std::for_each(
      atoms.begin(), atoms.end(),
      [&](BehaviorParser::Action_atomContext* atom) { addAtomToAction(action, atom); });

  if (stimulus) action.addCondition(buildCondition(stimulus.value()->condition()));
  if (target) addTargetToAction(action, target.value()->target());
  if (duration)
    action.addDuration(
        getNumeric(duration.value()->duration()->value_numeric(), currSeed));

  currentBehavior.addAction(type, action);
  return BehaviorBaseVisitor::visitAction(ctx);
}

antlrcpp::Any BehaviorBuilder::visitPed_Selector(
    BehaviorParser::Ped_SelectorContext* ctx) {
  auto type = findSelectorComponent<slType>(ctx);
  if (!type) error(R"(Behavior "{}": Selector has no Type)", currentBehavior.getName());

  auto selector = findSelectorComponent<slSelector>(ctx);
  if (!selector)
    error(R"(Behavior "{}": Selector has no Selector version)",
          currentBehavior.getName());

  auto group = findSelectorComponent<slGroup>(ctx);
  auto required = findSelectorComponent<slRequired>(ctx);

  // NOLINTBEGIN (rolland) access is checked, improper error : ignoring (bugprone-unchecked-optional-access)
  currentBehavior.addSubSelector(
      buildSubSelector(type.value(), selector.value(), group, required.has_value()));
  // NOLINTEND

  return BehaviorBaseVisitor::visitPed_Selector(ctx);
}

// ------------------------------- END ACTIONS -----------------------------------------------------------------------------------------

// ------------------------------- DECLARATIONS -----------------------------------------------------------------------------------------

antlrcpp::Any BehaviorBuilder::visitDecl_Loc(BehaviorParser::Decl_LocContext* ctx) {
  if (ctx->decl_Loc_Area_Circle()) {
    const std::string circleName = ctx->decl_Loc_Area_Circle()->ID()->toString();
    spdlog::debug("Behavior \"{}\": Adding Location {}", currentBehavior.getName(),
                  circleName);

    const float circleCenterPointX =
        getNumeric(ctx->decl_Loc_Area_Circle()->value_coord()->value_numeric().at(0),
                   currSeed)
            .value(0);
    const float circleCenterPointY =
        getNumeric(ctx->decl_Loc_Area_Circle()->value_coord()->value_numeric().at(1),
                   currSeed)
            .value(0);
    const float circleRadius =
        getNumeric(ctx->decl_Loc_Area_Circle()->value_numeric(), currSeed).value(0);

    std::shared_ptr<BHVR::Shape> circle = std::make_shared<BHVR::Circle>(
        VIPRA::f3d(circleCenterPointX, circleCenterPointY), circleRadius);

    locations[circleName] = currentBehavior.addLocation(
        BHVR::Location(circleName, BHVR::ShapeType::CIRCLE, circle));

  } else if (ctx->decl_Loc_Area_Rect()) {
    const auto rectName = ctx->decl_Loc_Area_Rect()->ID()->toString();
    spdlog::debug("Behavior \"{}\": Adding Location {}", currentBehavior.getName(),
                  rectName);

    const float rectCenterPointX =
        getNumeric(ctx->decl_Loc_Area_Rect()->value_coord()->value_numeric().at(0),
                   currSeed)
            .value(0);
    const float rectCenterPointY =
        getNumeric(ctx->decl_Loc_Area_Rect()->value_coord()->value_numeric().at(1),
                   currSeed)
            .value(0);
    const float rectLen =
        getNumeric(ctx->decl_Loc_Area_Rect()->value_numeric().at(0), currSeed).value(0);
    const float rectWidth =
        getNumeric(ctx->decl_Loc_Area_Rect()->value_numeric().at(1), currSeed).value(0);

    std::shared_ptr<BHVR::Shape> rectangle = std::make_shared<BHVR::Rectangle>(
        VIPRA::f3d(rectCenterPointX, rectCenterPointY), rectLen, rectWidth);

    locations[rectName] = currentBehavior.addLocation(
        BHVR::Location(rectName, BHVR::ShapeType::RECTANGLE, rectangle));

  } else if (ctx->decl_Loc_Point()) {
    const auto pointName = ctx->decl_Loc_Point()->ID()->toString();
    spdlog::debug("Behavior \"{}\": Adding Location {}", currentBehavior.getName(),
                  pointName);

    const float pointX =
        getNumeric(ctx->decl_Loc_Point()->value_coord()->value_numeric().at(0), currSeed)
            .value(0);
    const float pointY =
        getNumeric(ctx->decl_Loc_Point()->value_coord()->value_numeric().at(1), currSeed)
            .value(0);

    std::shared_ptr<BHVR::Shape> point =
        std::make_shared<BHVR::Point>(VIPRA::f3d(pointX, pointY));

    locations[pointName] = currentBehavior.addLocation(
        BHVR::Location(pointName, BHVR::ShapeType::POINT, point));
  }

  return BehaviorBaseVisitor::visitDecl_Loc(ctx);
}

antlrcpp::Any BehaviorBuilder::visitDecl_Ped_State(
    BehaviorParser::Decl_Ped_StateContext* ctx) {
  const auto stateNames = ctx->STATE_VAL();

  for (auto* state : stateNames) {
    auto name = state->toString();
    spdlog::debug("Behavior \"{}\": Adding Pedestrian State {}, id: {}",
                  currentBehavior.getName(), name, currState);
    states[name] = currState;
    ++currState;
  }

  return BehaviorBaseVisitor::visitDecl_Ped_State(ctx);
}

antlrcpp::Any BehaviorBuilder::visitDecl_Env_State(
    BehaviorParser::Decl_Env_StateContext* ctx) {
  const auto stateNames = ctx->STATE_VAL();

  for (auto* state : stateNames) {
    auto name = state->toString();
    spdlog::debug("Behavior \"{}\": Adding Environment State {}, id: {}",
                  currentBehavior.getName(), name, currState);
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
    spdlog::debug("Behavior \"{}\": Adding Pedestrian Type {}, id: {}",
                  currentBehavior.getName(), name, currType);
    types[name] = currType;
    allTypes += currType;
    currType = currType << 1U;
  }

  spdlog::debug("Behavior \"{}\": All Types: {}", currentBehavior.getName(),
                allTypes.fullType);
  currentBehavior.setAllPedTypes(allTypes);
  return BehaviorBaseVisitor::visitDecl_Ped(ctx);
}

// ------------------------------- END DECLARATIONS -----------------------------------------------------------------------------------------

// ------------------------------- ATOMS -----------------------------------------------------------------------------------------

/**
 * @brief Adds a set atom to the action
 * 
 * @param action : action to add atom to
 * @param ctx : set atom context
 */
void BehaviorBuilder::addSetAtom(Action& action, BehaviorParser::Set_atomContext* ctx) {
  auto attrStr = makeAttributeStr(ctx->attribute());
  auto attr = getAttribute(attrStr);
  auto attrValue = makeAttributeValue(ctx->attr_value());
  bool targetSelf = ctx->TARGET() == nullptr;
  action.addAtom(AtomSet{attr, attrValue, targetSelf});
}

/**
 * @brief Adds a scale atom to the action
 * 
 * @param action : action to add to
 * @param ctx : scale atom context
 */
void BehaviorBuilder::addScaleAtom(Action&                            action,
                                   BehaviorParser::Scale_atomContext* ctx) {
  auto attrStr = makeAttributeStr(ctx->attribute());
  auto attr = getAttribute(attrStr);
  auto attrValue = makeAttributeValue(ctx->attr_value());
  bool targetSelf = ctx->TARGET() == nullptr;
  action.addAtom(AtomScale{attr, attrValue, targetSelf});
}

// ------------------------------- END ATOMS -----------------------------------------------------------------------------------------

// ------------------------------- SUBCONDITIONS -----------------------------------------------------------------------------------------

/**
 * @brief Adds a time elapsed subcondition to a condition
 * 
 * @param condition : condition to add to
 * @param ctx : subcondition context
 */
void BehaviorBuilder::addTimeElapsed(
    Condition& condition, BehaviorParser::Condition_Time_Elapsed_From_EventContext* ctx) {
  BHVR::NumericValue dur = getNumeric(ctx->value_numeric(), currSeed);
  std::string        evName = ctx->EVNT()->toString();
  spdlog::debug(R"(Behavior "{}": Adding SubCondition: Elapsed Time From "{}" Event)",
                currentBehavior.getName(), evName);
  auto event = getEvent(evName);
  if (event)
    condition.addSubCondition(SubConditionElapsedTimeFromEvent(dur, event.value()));
  else
    error(R"(Behavior: "{}": Attempt To Use Undefined Event: "{}")",
          currentBehavior.getName(), evName);
}

/**
 * @brief Adds an event occurring subcondition to the condition
 * 
 * @param condition : condition to add to
 * @param ctx : subcondition context
 */
void BehaviorBuilder::addEventOccurred(
    Condition& condition, BehaviorParser::Condition_Event_OccurredContext* ctx) {
  std::string evName = ctx->EVNT()->toString();
  spdlog::debug(R"(Behavior "{}": Adding SubCondition: Event "{}" Occurred)",
                currentBehavior.getName(), evName);
  auto event = getEvent(evName);
  if (event)
    condition.addSubCondition(SubConditionEventOccurred(event.value()));
  else
    error(R"(Behavior: "{}": Attempt To Use Undefined Event: "{}")",
          currentBehavior.getName(), evName);
}

/**
 * @brief Adds an event occurrring subconditon to the condition
 * 
 * @param condition : condition to add to
 * @param ctx : subcondition context
 */
void BehaviorBuilder::addEventOccurring(
    Condition& condition, BehaviorParser::Condition_Event_OccurringContext* ctx) {
  std::string evName = ctx->EVNT()->toString();
  spdlog::debug(R"(Behavior "{}": Adding SubCondition: Event "{}" Occurring)",
                currentBehavior.getName(), evName);
  auto event = getEvent(evName);
  if (event)
    condition.addSubCondition(SubConditionEventOccurring(event.value()));
  else
    error(R"(Behavior: "{}": Attempt To Use Undefined Event: "{}")",
          currentBehavior.getName(), evName);
}

/**
 * @brief Adds an event starting subconditon to a condition
 * 
 * @param condition : condition to add to
 * @param ctx : subcondition context
 */
void BehaviorBuilder::addEventStarting(
    Condition& condition, BehaviorParser::Condition_Event_StartingContext* ctx) {
  std::string evName = ctx->EVNT()->toString();
  spdlog::debug(R"(Behavior "{}": Adding SubCondition: Event "{}" Occurring)",
                currentBehavior.getName(), evName);
  auto event = getEvent(evName);
  if (event)
    condition.addSubCondition(SubConditionEventStarting(event.value()));
  else
    error(R"(Behavior: "{}": Attempt To Use Undefined Event: "{}")",
          currentBehavior.getName(), evName);
}

/**
 * @brief Adds an event ending subcondition to the condition
 * 
 * @param condition : condition to add to
 * @param ctx : subcondition context
 */
void BehaviorBuilder::addEventEnding(Condition& condition,
                                     BehaviorParser::Condition_Event_EndingContext* ctx) {
  std::string evName = ctx->EVNT()->toString();
  spdlog::debug(R"(Behavior "{}": Adding SubCondition: Event "{}" Occurring)",
                currentBehavior.getName(), evName);
  auto event = getEvent(evName);
  if (event)
    condition.addSubCondition(SubConditionEventEnding(event.value()));
  else
    error(R"(Behavior: "{}": Attempt To Use Undefined Event: "{}")",
          currentBehavior.getName(), evName);
}

/**
 * @brief Adds a spatial subcondition to the condition
 * 
 * @param condition : condition to add to
 * @param ctx : spatial condition context
 */
void BehaviorBuilder::addSpatial(Condition&                                condition,
                                 BehaviorParser::Condition_SpatialContext* ctx) {
  auto distance = getNumeric(ctx->value_numeric(), currSeed);
  spdlog::debug(R"(Behavior "{}": Adding SubCondition: Spatial)",
                currentBehavior.getName());
  condition.addSubCondition(SubConditionSpatial(distance));
}

// ------------------------------- END SUBCONDITIONS -----------------------------------------------------------------------------------------

// ------------------------------- SUBSELECTORS -----------------------------------------------------------------------------------------

/**
 * @brief Creates an Eveyone selector
 * 
 * @param type : type selector selects for
 * @param required : whether the selector needs to be satisfied
 * @return SubSelector 
 */
SubSelector BehaviorBuilder::buildEveryone(slType type, bool required) {
  auto  types = type->id_list()->ID();
  Ptype comPtype = getCompositeType(types);

  auto typeStrs = makeListStrs(types);

  spdlog::debug(R"(Behavior "{}": Adding Selector: "Everyone" Is Ped Type: {})",
                currentBehavior.getName(), fmt::join(typeStrs, ", "));
  return SubSelector{0, comPtype, required, SelectorEveryone{}};
}

/**
 * @brief Creates an Exactly N selector
 * 
 * @param type : type selector selects for
 * @param selector : selector context
 * @param group : group selector pulls from
 * @param required : whether the selector needs to be satisfied
 * @return SubSelector 
 */
SubSelector BehaviorBuilder::buildExactlyN(slType type, slSelector selector,
                                           std::optional<slGroup> group, bool required) {
  auto  types = type->id_list()->ID();
  Ptype comPtype = getCompositeType(types);
  auto  typeStrs = makeListStrs(types);
  auto [groupType, groupName] = getGroup(group);

  NumericValue nPeds = getNumeric(
      selector->selector()->selector_Exactly_N_Random()->value_number(), currSeed);
  spdlog::debug(R"(Behavior "{}": Adding Selector: "Exactly {}" of {} Are Ped Type: {})",
                currentBehavior.getName(), nPeds.value(0), groupName,
                fmt::join(typeStrs, ", "));
  return SubSelector{groupType, comPtype, required, SelectorExactlyN{nPeds}};
}

/**
 * @brief Creates a percent selector
 * 
 * @param type : type selector selects for
 * @param selector : selector context
 * @param group : group selector pulls from
 * @param required : whether the selector needs to be satisfied
 * @return SubSelector 
 */
SubSelector BehaviorBuilder::buildPercent(slType type, slSelector selector,
                                          std::optional<slGroup> group, bool required) {
  auto  types = type->id_list()->ID();
  Ptype comPtype = getCompositeType(types);
  auto  typeStrs = makeListStrs(types);
  auto [groupType, groupName] = getGroup(group);

  NumericValue percentage =
      getNumeric(selector->selector()->selector_Percent()->value_number(), currSeed);
  spdlog::debug(R"(Behavior "{}": Adding Selector: "{} Percent" of {} Are Ped Type: {})",
                currentBehavior.getName(), percentage.value(0), groupName,
                fmt::join(typeStrs, ", "));
  return SubSelector{groupType, comPtype, required,
                     SelectorPercent{percentage.value(0) / 100.0F}};
}

// ------------------------------- END SUBSELECTORS -----------------------------------------------------------------------------------------

}  // namespace BHVR