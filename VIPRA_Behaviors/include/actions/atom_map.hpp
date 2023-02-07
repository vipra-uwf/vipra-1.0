#ifndef VIPRA_ATOM_MAP_HPP
#define VIPRA_ATOM_MAP_HPP

#include <actions/action_atom.hpp>
#include <any>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

template <typename... Params> using AtomFunc = std::function<std::unique_ptr<Atom>(Params...)>;

extern const std::unordered_map<std::string, std::any> AtomMap;

#endif