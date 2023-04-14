

#include <selectors/selector.hpp>

namespace Behaviors {

void
Selector::initialize(const std::string&   behaviorName,
                     Behaviors::seed      seed,
                     const PedestrianSet& pedSet,
                     const ObstacleSet&   obsSet,
                     const Goals&         goals) {
  selectedPeds = selector(seed, pedSet, obsSet, goals);
  for (auto pedIdx : selectedPeds) {
    spdlog::debug("Selected Pedestrian ID: {} For Behavior: {} Type ID: {}", pedIdx, behaviorName, type.fullType);
  }
}

void
Selector::timestep(PedestrianSet&                pedSet,
                   ObstacleSet&                  obsSet,
                   Goals&                        goals,
                   BehaviorContext&              context,
                   VIPRA::delta_t                dT,
                   std::shared_ptr<VIPRA::State> state) {

  std::for_each(selectedPeds.begin(), selectedPeds.end(), [&](VIPRA::idx pedIdx) {
    std::for_each(actions.begin(), actions.end(), [&](Action& action) {
      action.performAction(pedSet, obsSet, goals, context, pedIdx, dT, state);
    });
  });
}

void
Selector::addAction(Action&& action) {
  actions.emplace_back(std::move(action));
}

typeUID
Selector::Group() const {
  return group;
}

pType
Selector::Type() const {
  return type;
}

size_t
Selector::actionCount() const {
  return actions.size();
}

// --------------- CONSTRUCTORS ---------------------------------------------------------------

Selector::Selector(typeUID groupType, pType pedType, SelectorFunc&& func)
  : group(groupType), type(pedType), selector(std::move(func)), actions(), selectedPeds() {}

Selector::Selector(Selector&& other) noexcept
  : type(std::move(other.type)), selector(std::move(other.selector)), actions(std::move(other.actions)),
    selectedPeds(std::move(other.selectedPeds)) {}

Selector&
Selector::operator=(Selector&& other) noexcept {
  type = other.type;
  selector = std::move(other.selector);
  actions = std::move(other.actions);
  selectedPeds = std::move(other.selectedPeds);
  return *this;
}

// --------------- END CONSTRUCTORS ---------------------------------------------------------------
}  // namespace Behaviors
