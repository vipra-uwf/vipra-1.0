#include "builder/behavior_builder.hpp"
#include "builder/declaration_components.hpp"
#include "events/event.hpp"
#include "stimuli/events.hpp"
#include "values/values.hpp"

namespace BHVR {

void BehaviorBuilder::initialize_behavior(const std::string& name) {
  _behavior = HumanBehavior(name);
  _ids.clear();
}

// ------------------------------- ANTLR FUNCTIONS -----------------------------------------------------------------------------------------

auto BehaviorBuilder::visitEvent(BehaviorParser::EventContext* ctx) -> antlrcpp::Any {
  auto name = find_event_component<evName>(ctx);
  auto produces = find_event_component<evProduce>(ctx);
  auto startTime = find_event_component<evStart>(ctx);
  auto duration = find_event_component<evDuration>(ctx);
  auto where = find_event_component<evWhere>(ctx);

  validate_required_components<evName, evProduce, evStart, evWhere>("Event", name, produces, startTime,
                                                                    where);

  // NOLINTBEGIN(bugprone-unchecked-optional-access) (rolland) all accesses were checked above
  Event event(name.value());
  _ids.add<Event>(name.value());
  add_stimuli(event, produces.value());
  set_event_start(event, startTime.value());
  set_event_where(event, where.value());
  // NOLINTEND(bugprone-unchecked-optional-access)

  if (duration) set_event_duration(event, duration.value());

  return BehaviorBaseVisitor::visitEvent(ctx);
}

auto BehaviorBuilder::visitPed_Selector(BehaviorParser::Ped_SelectorContext* ctx) -> antlrcpp::Any {
  return BehaviorBaseVisitor::visitPed_Selector(ctx);
}

auto BehaviorBuilder::visitAction(BehaviorParser::ActionContext* ctx) -> antlrcpp::Any {
  return BehaviorBaseVisitor::visitAction(ctx);
}

auto BehaviorBuilder::visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* ctx) -> antlrcpp::Any {
  return BehaviorBaseVisitor::visitDecl_Ped_State(ctx);
}

auto BehaviorBuilder::visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* ctx) -> antlrcpp::Any {
  return BehaviorBaseVisitor::visitDecl_Env_State(ctx);
}

auto BehaviorBuilder::visitDecl_Ped(BehaviorParser::Decl_PedContext* ctx) -> antlrcpp::Any {
  return BehaviorBaseVisitor::visitDecl_Ped(ctx);
}

auto BehaviorBuilder::visitLocation(BehaviorParser::LocationContext* ctx) -> antlrcpp::Any {
  return BehaviorBaseVisitor::visitLocation(ctx);
}

// ------------------------------- END ANTLR FUNCTIONS -----------------------------------------------------------------------------------------

// ------------------------------- EVENTS -----------------------------------------------------------------------------------------

void BehaviorBuilder::set_event_where(Event& event, BehaviorParser::Event_whereContext* ctx) {
  if (ctx->EVERYWHERE())
    event.set_location(VIPRA::f3d{}, true);
  else
    event.set_location(get_coord(ctx->value_coord(), _behavior.get_seed()), false);
}

void BehaviorBuilder::set_event_start(Event& event, BehaviorParser::Event_startContext* ctx) {
  event.set_start_time(get_numeric(ctx->value_numeric(), _behavior.get_seed()));
}

void BehaviorBuilder::set_event_duration(Event& event, BehaviorParser::Event_durationContext* ctx) {
  event.set_duration(get_numeric(ctx->value_numeric(), _behavior.get_seed()));
}

// ------------------------------- END EVENTS -----------------------------------------------------------------------------------------

}  // namespace BHVR