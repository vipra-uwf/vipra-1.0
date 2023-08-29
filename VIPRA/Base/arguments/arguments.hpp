#ifndef VIPRA_ARGUMENTS_HPP
#define VIPRA_ARGUMENTS_HPP

#include <stdexcept>
#include <string>
#include <unordered_map>

namespace VIPRA {
class Args {
 public:
  void parse(int argc, char** argv) {
    if (argc != argCnt) {
      throw std::runtime_error("Invalid Number of Arguments");
    }

    args["simulations"] = argv[1];
    args["config"] = argv[2];
    args["params"] = argv[3];
    args["pedestrians"] = argv[4];
    args["obstacles"] = argv[5];
    args["output"] = argv[6];
  }

  template <typename T>
  T get(const std::string& key);

  static constexpr size_t argCnt = 7;

 private:
  std::unordered_map<std::string, std::string> args;
};

template <>
inline std::string Args::get<std::string>(const std::string& key) {
  return args[key];
}

template <>
inline float Args::get<float>(const std::string& key) {
  return std::stof(args[key]);
}

}  // namespace VIPRA

#endif