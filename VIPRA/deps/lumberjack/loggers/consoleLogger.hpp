#ifndef LUMBERJACK_CONSOLE_LOGGER_HPP
#define LUMBERJACK_CONSOLE_LOGGER_HPP
#define FMT_HEADER_ONLY

#include <iostream>

#include "../deps/fmt/core.h"
#include "../lumberjack.hpp"

namespace LumberJack {
/**
 * @brief Sends Log Messages to cout
 *
 */
struct ConsoleLogger {

  ConsoleLogger() = default;
  ConsoleLogger(ConsoleLogger&) = delete;
  ConsoleLogger(const ConsoleLogger&) = delete;
  ConsoleLogger(ConsoleLogger&&) = delete;
  ConsoleLogger& operator=(ConsoleLogger&) = delete;
  ConsoleLogger& operator=(ConsoleLogger&&) = delete;
  ~ConsoleLogger() = default;

  template <typename... Params>
  void operator()([[maybe_unused]] Level lvl, const std::string& message, Params... ps) {
    if (lvl == ERROR) {
      std::cerr << "[" << LevelStrings[lvl] << "] " << fmt::format(message, ps...) << '\n';
    } else {
      std::cout << "[" << LevelStrings[lvl] << "] " << fmt::format(message, ps...) << '\n';
    }
  }
};
}  // namespace LumberJack

#endif