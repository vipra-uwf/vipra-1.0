#ifndef VIPRA_BEHAVIORS_CASELESS_STR_COMP_HPP
#define VIPRA_BEHAVIORS_CASELESS_STR_COMP_HPP

#include <string.h>
#include <string>

struct caseless_str_compare {
  struct comp {
    bool operator()(const std::string& str1, const std::string& str2) const {
      const size_t cnt = str1.size();
      if (cnt != str2.size())
        return false;

      for (size_t i = 0; i < cnt; ++i) {
        if (str1[i] == str2[i])
          continue;

        if (str1[i] > str2[i]) {
          if (str1[i] - 32 != str2[i]) {
            return false;
          }
        } else {
          if (str2[i] - 32 != str1[i]) {
            return false;
          }
        }
      }
      return true;
    }
  };
  struct hash {
    size_t operator()(const std::string& str) const {
      std::string temp{str};
      for (char& c : temp) {
        c = std::tolower(c);
      }
      return std::hash<std::string>{}(temp);
    }
  };
};

#endif