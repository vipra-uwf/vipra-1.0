#ifndef VIPRA_BHVR_CASELESS_STR_COMP_HPP
#define VIPRA_BHVR_CASELESS_STR_COMP_HPP

#include <cstring>
#include <string>

/**
 * @brief Struct for caseless look up in a std::map
 * 
 */
struct CaselessStrCompare {
  struct Comp {
    bool operator()(const std::string& str1, const std::string& str2) const {
      const size_t cnt = str1.size();
      if (cnt != str2.size()) {
        return false;
      }

      for (size_t i = 0; i < cnt; ++i) {
        if (str1[i] == str2[i]) {
          continue;
        }

        if (str1[i] > str2[i]) {
          if (str1[i] - spaceAscii != str2[i]) {
            return false;
          }
        } else {
          if (str2[i] - spaceAscii != str1[i]) {
            return false;
          }
        }
      }
      return true;
    }
  };
  struct Hash {
    size_t operator()(const std::string& str) const {
      std::string temp{str};
      for (char& ch : temp) {
        ch = static_cast<char>(std::tolower(ch));
      }
      return std::hash<std::string>{}(temp);
    }
  };

 private:
  static constexpr char spaceAscii = 32;
};

#endif