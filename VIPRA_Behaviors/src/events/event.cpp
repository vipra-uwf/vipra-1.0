

#include "events/event.hpp"

namespace BHVR {
auto Event::evaluate(VIPRA::time_s currTime, VIPRA::delta_t timestep) -> std::optional<StimulusSource> {
  evaluate_start(currTime, timestep);
  evaluate_stop(currTime, timestep);

  if (_occurring) return _stimuli;
  return std::nullopt;
}

void Event::set_start_time(const NumericValue& value) { _startTime = value; }

void Event::set_duration(const NumericValue& value) { _duration = value; }

void Event::add_stimulus(StimulusType type, uid stimId) {
  _stimuli.stimulus.type.set(static_cast<size_t>(type));
  _stimuli.stimulus.id = stimId;
}

void Event::set_location(VIPRA::f3d location, bool everywhere) {
  if (everywhere)
    _stimuli.location.set_location(std::nullopt);
  else
    _stimuli.location.set_location(location);
}

auto Event::has_occurred() const -> bool { return _occurred; }

auto Event::get_name() const -> const std::string& { return _name; }

auto in_timestep(VIPRA::time_s checkTime, VIPRA::time_s currTime, VIPRA::delta_t timeStepSize) -> bool {
  return currTime - timeStepSize < checkTime && currTime + timeStepSize > checkTime;
}

void Event::evaluate_start(VIPRA::time_s currTime, VIPRA::delta_t timestep) {
  if (!_occurred) {
    if (in_timestep(_startTime.value(0), currTime, timestep)) {
      _occurred = true;
      _occurring = true;
      if (_duration) _endTime = currTime + _duration->value(0);
    }
  }
}

void Event::evaluate_stop(VIPRA::time_s currTime, VIPRA::delta_t timestep) {
  if (_occurring && _duration) {
    if (in_timestep(_endTime, currTime, timestep)) {
      _occurring = false;
    }
  }
}

Event::Event(std::string name) : _name(std::move(name)) {}
}  // namespace BHVR
