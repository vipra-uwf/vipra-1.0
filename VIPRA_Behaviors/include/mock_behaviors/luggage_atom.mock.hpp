#ifndef VIPRA_LUGGAGE_MOCK_BEHAVIOR_HPP
#define VIPRA_LUGGAGE_MOCK_BEHAVIOR_HPP

#include <actions/action_atom.hpp>
#include <behavior/human_behavior.hpp>

namespace Behaviors {
class Atom_Luggage_Mock : public Atom {
 public:
  Atom_Luggage_Mock() = delete;
  explicit Atom_Luggage_Mock(float);

  void performAction(const PedestrianSet&,
                     const ObstacleSet&,
                     const Goals&,
                     const BehaviorContext&,
                     VIPRA::idx,
                     VIPRA::delta_t,
                     std::shared_ptr<VIPRA::State>) override;

 private:
  void construct(const PedestrianSet&);

  float                   luggageTime;
  bool                    constructed;
  std::vector<VIPRA::idx> selectedPeds;
  std::vector<bool>       gottenLuggage;
};
}  // namespace Behaviors

#endif