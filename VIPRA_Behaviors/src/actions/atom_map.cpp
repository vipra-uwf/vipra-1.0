
#include <actions/atom_map.hpp>
#include <actions/atoms/atom_change_speed.hpp>
#include <actions/atoms/atom_stop.hpp>
#include <actions/atoms/atom_be.hpp>

#include <definitions/dsl_types.hpp>

#include <mock_behaviors/disembark_atom.mock.hpp>
#include <mock_behaviors/luggage_atom.mock.hpp>

namespace Behaviors { 

/**
* @brief Map that holds the constructor functions for atoms
*/
const std::unordered_map<std::string, std::any> AtomMap = {
    {"stop", AtomFunc<>([]() -> std::unique_ptr<Atom> { return std::make_unique<Atom_Stop>(); })},
    {"change_speed", AtomFunc<float>([](float change) -> std::unique_ptr<Atom> { return std::make_unique<Atom_Change_Speed>(change); })},
    {"be", AtomFunc<stateUID>([](stateUID state) -> std::unique_ptr<Atom> { return std::make_unique<Atom_Be>(state); })},
    {"mock_luggage", AtomFunc<float>([](float time) -> std::unique_ptr<Atom> { return std::make_unique<Atom_Luggage_Mock>(time); })},
    {"mock_disembark", AtomFunc<>([]() -> std::unique_ptr<Atom> { return std::make_unique<Atom_Disembark_Mock>(); })}
};
}