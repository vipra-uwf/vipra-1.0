#ifndef VIPRA_BEHAVIORS_ID_GENERATION_HPP
#define VIPRA_BEHAVIORS_ID_GENERATION_HPP

#include <optional>
#include <string>
#include <unordered_map>

#include "definitions/dsl_types.hpp"
#include "util/caseless_str_comp.hpp"
#include "util/concepts.hpp"

namespace BHVR {

/**
 * @brief Maps std::string to uid for a given type
 * 
 * @tparam base_t 
 */
template <typename base_t>
class IdContainer {
 public:
  /**
   * @brief Empties the id map and resets current id
   * 
   */
  void clear() {
    _currId = 0;
    _ids.clear();
  }

  /**
  * @brief Adds a new object and returns its id with False, if there already exists an object with the name the original's id is returned with True
  * 
  * @param name 
  * @return std::pair<uid, bool> 
  */
  auto add(const std::string& name) -> std::pair<uid, bool> {
    auto dupe = _ids.find(name);
    if (dupe != _ids.end()) return {(*dupe).second, true};

    ++_currId;
    _ids[name] = _currId;
    return {_currId, false};
  }

  /**
   * @brief Returns the id of the object with name, std::nullopt if it doesn't exist
   * 
   * @param name 
   * @return std::optional<uid> 
   */
  auto get(const std::string& name) -> std::optional<uid> {
    auto objid = _ids.find(name);
    if (objid == _ids.end()) return std::nullopt;
    return (*objid).second;
  }

  /**
   * @brief Returns true if an object with the given name exists
   * 
   * @param name 
   * @return true 
   * @return false 
   */
  auto exists(const std::string& name) -> bool { return _ids.find(name) != _ids.end(); }

 private:
  uid                                                                                      _currId{0};
  std::unordered_map<std::string, uid, CaselessStrCompare::Hash, CaselessStrCompare::Comp> _ids;
};

/**
 * @brief Handles creating / retrieving ids for events/location/etc.
 * 
 * @tparam base_t 
 */
template <typename... types>
class IdGen {
 public:
  /**
   * @brief Resets all of the id containers
   * 
   */
  void clear() {
    forEach(_containers, [](auto& container) { container.clear(); });
  }

  /**
   * @brief Checks if an object with the given name exists
   * 
   * @tparam type 
   * @tparam std::enable_if<inTypeList<type, types...>()>::type 
   * @param name 
   * @return true 
   * @return false 
   */
  template <typename type, typename = typename std::enable_if<inTypeList<type, types...>()>::type>
  auto exists(const std::string& name) -> bool {
    return get_container<type>(name);
  }

  /**
   * @brief Adds a new object to its container, returning its id and whether it is a duplicate
   * 
   * @tparam type 
   * @tparam std::enable_if<inTypeList<type, types...>()>::type 
   * @param name 
   * @return std::pair<uid, bool> 
   */
  template <typename type, typename = typename std::enable_if<inTypeList<type, types...>()>::type>
  auto add(const std::string& name) -> std::pair<uid, bool> {
    return get_container<type>().add(name);
  }

  /**
   * @brief Returns the id of the object with name
   * 
   * @tparam type 
   * @tparam std::enable_if<inTypeList<type, types...>()>::type 
   * @param name 
   * @return std::optional<uid> 
   */
  template <typename type, typename = typename std::enable_if<inTypeList<type, types...>()>::type>
  auto get(const std::string& name) -> std::optional<uid> {
    return get_container<type>().get(name);
  }

 private:
  std::tuple<IdContainer<types>...> _containers;

  /**
   * @brief Gets the correct container
   * 
   * @tparam type 
   * @tparam std::enable_if<inTypeList<type, types...>()>::type 
   * @return IdContainer<type>& 
   */
  template <typename type, typename = typename std::enable_if<inTypeList<type, types...>()>::type>
  constexpr auto get_container() -> IdContainer<type>& {
    return std::get<IdContainer<type>>(_containers);
  }
};
}  // namespace BHVR

#endif