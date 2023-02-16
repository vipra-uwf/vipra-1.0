
#include <actions/atom_map.hpp>
#include <actions/atoms/atom_change_speed.hpp>
#include <actions/atoms/atom_stop.hpp>

#include <mock_behaviors/disembark_atom.mock.hpp>
#include <mock_behaviors/luggage_atom.mock.hpp>

namespace Behaviors { 
const std::unordered_map<std::string, std::any> AtomMap = {
    {"stop", AtomFunc<>([]() -> std::unique_ptr<Atom> { return std::make_unique<Atom_Stop>(); })},
    {"change_speed", AtomFunc<float, bool>([](float change, bool faster) -> std::unique_ptr<Atom> { return std::make_unique<Atom_Change_Speed>(change, faster); })},
    {"mock_luggage", AtomFunc<float>([](float time) -> std::unique_ptr<Atom> { return std::make_unique<Atom_Luggage_Mock>(time); })},
    {"mock_disembark", AtomFunc<>([]() -> std::unique_ptr<Atom> { return std::make_unique<Atom_Disembark_Mock>(); })}
};
}