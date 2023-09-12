#ifndef VIPRA_BEHAVIORS_EVENT_HPP
#define VIPRA_BEHAVIORS_EVENT_HPP

#include <definitions/type_definitions.hpp>
#include <optional>

#include "events/event_status.hpp"
#include "stimuli/events.hpp"
#include "stimuli/stimulus.hpp"
#include "values/numeric_value.hpp"

namespace BHVR {
/**
   * @brief An Event is something that occurs during a simulation
   *
   */
class Event {
 public:
  explicit Event(std::string);

  auto evaluate(VIPRA::time_s, VIPRA::delta_t) -> std::optional<StimulusSource>;

  void set_start_time(const NumericValue&);
  void set_duration(const NumericValue&);

  void add_stimulus(StimulusType, uid);

  void set_location(VIPRA::f3d, bool);

  [[nodiscard]] auto has_occurred() const -> bool;

  [[nodiscard]] auto get_name() const -> const std::string&;

 private:
  std::string _name;
  bool        _occurring = false;
  bool        _occurred = false;

  VIPRA::time_s _endTime{};

  NumericValue                _startTime;
  std::optional<NumericValue> _duration;
  StimulusSource              _stimuli;

  auto in_timestep(VIPRA::time_s, VIPRA::time_s, VIPRA::delta_t) -> bool;
  void evaluate_start(VIPRA::time_s, VIPRA::delta_t);
  void evaluate_stop(VIPRA::time_s, VIPRA::delta_t);

 public:
  ~Event() = default;
  Event(Event&&) noexcept = default;
  auto operator=(Event&&) noexcept -> Event& = default;
  Event() = default;
  Event(const Event&) = default;
  auto operator=(const Event&) -> Event& = default;
};
}  // namespace BHVR

#endif