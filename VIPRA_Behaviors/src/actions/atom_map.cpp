
#include <actions/atom_map.hpp>
#include <actions/atoms/atom_change_speed.hpp>
#include <actions/atoms/atom_stop.hpp>

const std::unordered_map<std::string, std::any> AtomMap = {
    {"!stop", AtomFunc<>([]() -> std::unique_ptr<Atom> { return std::make_unique<Atom_Stop>(); })},
    {"!change_speed", AtomFunc<float, bool>([](float change, bool faster) -> std::unique_ptr<Atom> {
       return std::make_unique<Atom_Change_Speed>(change, faster);
     })}};
