#ifndef VIPRA_BEHAVIORS_HUMAN_BEHAVIOR_HPP
#define VIPRA_BEHAVIORS_HUMAN_BEHAVIOR_HPP

#include <party_llama/event_system_immediate.hpp>

#include "events/event.hpp"

#include "stimuli/events.hpp"
#include "stimuli/stimulus.hpp"

namespace BHVR {
class HumanBehavior {
 public:
  explicit HumanBehavior(const std::string&);

  [[nodiscard]] auto get_seed() const -> BHVR::seed;

 private:
  std::string _name{};
  BHVR::seed  _seed{};

  pllama::EventSystem_Immediate<AuditoryEvent, VisualEvent> _stimuliSystem;

 public:
  template <typename stim_t, typename handle_t>
  void add_stimuli_response(handle_t&& handler) {
    _stimuliSystem.on<stim_t>(std::forward<handle_t>(handler));
  }

  HumanBehavior() = default;
  ~HumanBehavior() = default;
  HumanBehavior(const HumanBehavior&) = default;
  HumanBehavior(HumanBehavior&&) noexcept = default;
  auto operator=(const HumanBehavior&) -> HumanBehavior& = default;
  auto operator=(HumanBehavior&&) noexcept -> HumanBehavior& = default;
};
}  // namespace BHVR

#endif