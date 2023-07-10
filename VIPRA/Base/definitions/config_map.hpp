#ifndef VIPRA_CONFIGURATION_HPP
#define VIPRA_CONFIGURATION_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include <json/json.h>

#include <definitions/type_definitions.hpp>

namespace VIPRA::CONFIG {

class ConfigurationException : public std::runtime_error {
 public:
  explicit ConfigurationException(const std::string& message)
      : std::runtime_error{message} {}
  static void error(const std::string& message) { throw ConfigurationException(message); }
};

class Map {
 public:
  ~Map() = default;
  Map() = default;
  Map(const Map& other) = default;
  Map(Map&& other) noexcept = default;
  Map& operator=(const Map& other) = default;
  Map& operator=(Map&& other) noexcept = default;

  explicit Map(Json::Value doc) : document(std::move(doc)) {}

  const Json::Value& operator[](const std::string& key) const { return document[key]; }
  Json::Value&       operator[](const std::string& key) { return document[key]; }

  [[nodiscard]] std::vector<std::string> getStringVector(const std::string& key) const {
    const VIPRA::size        valCnt = document[key].size();
    std::vector<std::string> ret(valCnt);

    for (VIPRA::idx i = 0; i < valCnt; ++i) {
      if (document[key][static_cast<Json::ArrayIndex>(i)].type() !=
          Json::ValueType::stringValue) {
        ConfigurationException::error(
            "Attempt To Get String Vector From Config Value That Doesn't Match That "
            "Type, Key: " +
            key);
      }
      ret[i] = document[key][static_cast<Json::ArrayIndex>(i)].asString();
    }

    return ret;
  }

 private:
  Json::Value document;
};

}  // namespace VIPRA::CONFIG

#endif