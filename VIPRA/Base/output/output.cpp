

#include "output.hpp"

// NOLINTBEGIN Bug in clang-tidy (https://bugs.llvm.org/show_bug.cgi?id=48040) : ignores (cppcoreguidelines-avoid-non-const-global-variables)
std::unique_ptr<VIPRA::Sink> VIPRA::Output::sink{};
VIPRA::cnt                   VIPRA::Output::timestep{};
nlohmann::json               VIPRA::Output::jsonData{};
VIPRA::cnt                   VIPRA::Output::outputFreq{};
// NOLINTEND