#ifndef VIPRA_BEHAVIORS_BEHAVIOR_BUILDER_HPP
#define VIPRA_BEHAVIORS_BEHAVIOR_BUILDER_HPP

#include <filesystem>
#include <stdexcept>

#include <spdlog/spdlog.h>

#include "generated/BehaviorBaseVisitor.h"

#include "behaviors/human_behavior.hpp"

#include "builder/builder_exception.hpp"
#include "builder/declaration_components.hpp"
#include "builder/id_generation.hpp"

#include "events/event.hpp"
#include "generated/BehaviorParser.h"

namespace BHVR {
/**
 * @brief Parses Behavior Files and Creates the Runtime Functionality they describe
 * 
 */
class BehaviorBuilder : public BehaviorBaseVisitor {
 public:
  auto build(std::string, const std::filesystem::path&, BHVR::seed) -> HumanBehavior;

 private:
  IdGen<Event> _ids{};

  HumanBehavior _behavior;

  void initialize_behavior(const std::string&);

  // ------------------------------- ANTLR FUNCTIONS -----------------------------------------------------------------------------------------

  auto visitEvent(BehaviorParser::EventContext* /*ctx*/) -> antlrcpp::Any override;
  auto visitPed_Selector(BehaviorParser::Ped_SelectorContext* /*ctx*/) -> antlrcpp::Any override;
  auto visitAction(BehaviorParser::ActionContext* /*ctx*/) -> antlrcpp::Any override;
  auto visitDecl_Ped_State(BehaviorParser::Decl_Ped_StateContext* /*ctx*/) -> antlrcpp::Any override;
  auto visitDecl_Env_State(BehaviorParser::Decl_Env_StateContext* /*ctx*/) -> antlrcpp::Any override;
  auto visitDecl_Ped(BehaviorParser::Decl_PedContext* /*ctx*/) -> antlrcpp::Any override;
  auto visitLocation(BehaviorParser::LocationContext* /*ctx*/) -> antlrcpp::Any override;

  // --------------------------------- EVENTS ------------------------------------------------------------------------------------------------

  template <typename... comp_ts>
  void validate_required_components(const std::string& name, std::optional<comp_ts>&... comps) {
    (
        [&]() {
          if (!comps) error("Missing Required Component in: " + name);
        },
        ...);
  }

  void set_event_where(Event&, BehaviorParser::Event_whereContext*);
  void set_event_start(Event&, BehaviorParser::Event_startContext*);
  void set_event_duration(Event&, BehaviorParser::Event_durationContext*);

  // --------------------------------- STIMULI ------------------------------------------------------------------------------------------------

  /**
   * @brief Adds stimulus production to an object
   * 
   * @tparam obj_t 
   * @tparam ctx_t 
   * @param obj 
   * @param ctx 
   */
  template <typename obj_t, typename ctx_t>
  void add_stimuli(obj_t& obj, ctx_t* ctx) {
    auto stimNames = ctx->produces()->ID();
    auto stimTypes = ctx->produces()->stimulus_type();
    auto [stimId, duplicate] = _ids.add<Stimulus>(obj.getName());

    for (size_t i = 0; i < stimNames.size(); ++i) {
      auto stimName = stimNames[i]->toString();
      auto stimID = _ids.get<Stimulus>(stimName);

      if (!stimID) stimID = _ids.add<Stimulus>(stimName).first;
      auto stimType = getStimType(stimTypes[i]->toString());

      obj.addStimulus(stimType, stimID.value());
    }
  }

  // -------------------------------- FINDERS ------------------------------------------------------------------------------------------------

  /**
   * @brief Logs an error to the console and throws an exception
   * 
   * @tparam T : 
   * @param message : message to log to console
   * @param values : values to format message with
   */
  template <typename... args_t>
  static void error(const std::string& message, args_t&&... values) {
    spdlog::error(message, std::forward<args_t>(values)...);
    BuilderException::error();
  }

  // -------------------------------- FINDERS ------------------------------------------------------------------------------------------------

  /**
   * @brief Gets components from an event declaration context
   * 
   * @tparam T : type of component
   * @param ctx : event context
   * @return std::optional<T> 
   */
  template <typename comp_t>
  [[nodiscard]] static auto find_event_component(BehaviorParser::EventContext* ctx) -> std::optional<comp_t> {
    for (const auto& attr : ctx->event_attribute()) {
      // Name
      if constexpr (std::is_same_v<comp_t, std::string>)
        if (attr->event_name()) return attr->event_name()->ID()->toString();

      // Start Condition
      if constexpr (std::is_same_v<comp_t, evStart>)
        if (attr->event_start()) return attr->event_start();

      // End Condition
      if constexpr (std::is_same_v<comp_t, evDuration>)
        if (attr->event_duration()) return attr->event_duration();

      // Stimulus
      if constexpr (std::is_same_v<comp_t, evProduce>)
        if (attr->event_produce()) return attr->event_produce();
    }

    return std::nullopt;
  }

  /**
   * @brief Gets components from an action declaration context
   * 
   * @tparam T : type of component
   * @param ctx : action context
   * @return std::optional<T> 
   */
  template <typename comp_t>
  [[nodiscard]] static auto find_action_component(BehaviorParser::ActionContext* ctx)
      -> std::optional<comp_t> {
    for (const auto& attr : ctx->action_attribute()) {
      // Stimulus
      if constexpr (std::is_same_v<comp_t, acStimulus>)
        if (attr->action_stimulus()) return attr->action_stimulus();

      // Response
      if constexpr (std::is_same_v<comp_t, acResponse>)
        if (attr->action_response()) return attr->action_response();

      // Target
      if constexpr (std::is_same_v<comp_t, acTarget>)
        if (attr->action_target()) return attr->action_target();

      // Duration
      if constexpr (std::is_same_v<comp_t, acDuration>)
        if (attr->action_duration()) return attr->action_duration();

      // Produce
      if constexpr (std::is_same_v<comp_t, acProduce>)
        if (attr->action_produce()) return attr->action_produce();
    }

    return std::nullopt;
  }

  /**
   * @brief Gets components from an selector declaration context
   * 
   * @tparam T : type of component
   * @param ctx : selector context
   * @return std::optional<T> 
   */
  template <typename comp_t>
  [[nodiscard]] static auto find_selector_component(BehaviorParser::Ped_SelectorContext* ctx)
      -> std::optional<comp_t> {
    for (const auto& attr : ctx->selector_attribute()) {
      // Type
      if constexpr (std::is_same_v<comp_t, slType>)
        if (attr->selector_type()) return attr->selector_type();

      // Selector
      if constexpr (std::is_same_v<comp_t, slSelector>)
        if (attr->selector_selector()) return attr->selector_selector();

      if constexpr (std::is_same_v<comp_t, slGroup>)
        if (attr->selector_from()) return attr->selector_from();

      if constexpr (std::is_same_v<comp_t, slRequired>)
        if (attr->selector_required()) return attr->selector_required();
    }

    return std::nullopt;
  }

  /**
   * @brief Gets components from an selector declaration context
   * 
   * @tparam T : type of component
   * @param ctx : selector context
   * @return std::optional<T> 
   */
  template <typename comp_t>
  [[nodiscard]] static auto find_location_component(BehaviorParser::LocationContext* ctx)
      -> std::optional<comp_t> {
    for (const auto& attr : ctx->location_attribute()) {
      // Type
      if constexpr (std::is_same_v<comp_t, lcName>)
        if (attr->loc_name()) return attr->loc_name();

      // Selector
      if constexpr (std::is_same_v<comp_t, lcShape>)
        if (attr->loc_shape()) return attr->loc_shape();

      if constexpr (std::is_same_v<comp_t, lcDimensions>)
        if (attr->loc_dimensions()) return attr->loc_dimensions();
    }

    return std::nullopt;
  }
};
}  // namespace BHVR

#endif