#ifndef VIPRA_CONFIGURATION_HPP
#define VIPRA_CONFIGURATION_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "jsoncpp/json/json.h"

#include "definitions/type_definitions.hpp"

namespace VIPRA {
namespace Config {

class ConfigurationException : public std::runtime_error {
 public:
  ConfigurationException(const std::string& message) : std::runtime_error{message} {}
  static void Throw(const std::string& message) { throw ConfigurationException(message); }
};

class Map {
 public:
  ~Map() = default;
  Map() : document(Json::Value()) {}
  Map(const Map& other) : document(other.document) {}
  Map(Map&& other) noexcept : document(std::move(other.document)) {}
  Map(Json::Value doc) : document(std::move(doc)) {}
  Map& operator=(const Map& other) noexcept {
    document = other.document;
    return *this;
  }
  Map& operator=(Map&& other) noexcept {
    document = other.document;
    return *this;
  }

  const Json::Value& operator[](const std::string& key) const { return document[key]; }
  Json::Value&       operator[](const std::string& key) { return document[key]; }

  std::vector<std::string> getStringVector(const std::string& key) const {
    const VIPRA::size        valCnt = document[key].size();
    std::vector<std::string> ret(valCnt);

    for (VIPRA::idx i = 0; i < valCnt; ++i) {
      if (document[key][static_cast<Json::ArrayIndex>(i)].type() != Json::ValueType::stringValue) {
        ConfigurationException::Throw("Attempt To Get String Vector From Config Value That Doesn't Match That Type, Key: " +
                                      key);
      }
      ret[i] = document[key][static_cast<Json::ArrayIndex>(i)].asString();
    }

    return ret;
  }

 private:
  Json::Value document;
};

}  // namespace Config
}  // namespace VIPRA

#endif