/*

  https://github.com/RTGoodenough/LumberJack

  MIT License

  Copyright (c) 2022 RTGoodenough

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/

#ifndef LUMBERJACK_LOGGING_HPP
#define LUMBERJACK_LOGGING_HPP
#define FMT_HEADER_ONLY

#include <array>
#include <stdexcept>
#include <string>

namespace LumberJack {

const std::array<std::string, 4> LevelStrings{"DEBUG", "INFO", "WARN", "ERROR"};

/**
 * @brief Enum for Log message levels
 *
 */
enum Level {
  DEBUG,
  INFO,
  WARN,
  ERROR,
};

/**
 * @brief Exception Class For Loggers
 *
 */
class LogException : public std::runtime_error {
 public:
  LogException(const std::string& message) : std::runtime_error(message) {}
  static void Throw(const std::string& message) { throw LogException(message); }

  LogException() = delete;
  LogException(LogException&) = delete;
  LogException(LogException&&) = delete;
  LogException& operator=(const LogException&) = delete;
  LogException& operator=(LogException&&) = delete;
  ~LogException() = default;
};

/**
 * @brief Logger Interaction Class
 */
template <typename L> class Logger {
 public:
  Logger(Logger&) = delete;
  Logger(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger& operator=(Logger&&) = delete;

  template <typename... Params> Logger(Params... ps) : level(ERROR), log_impl(ps...) {}

  template <typename... Params> Logger(Level lvl, Params... ps) : level(lvl), log_impl(ps...) {}

  template <typename... Params> void Log(Level lvl, const std::string& message, Params... ps) {
    if (level <= lvl) {
      log_impl(lvl, message, ps...);
    }
  }

  void setLevel(Level lvl) { level = lvl; }

 private:
  Level level;
  L     log_impl;
};

/**
 * @brief Calls the provided Logger with Level ERROR
 *
 * @tparam L - Logger Implementation
 * @tparam params - Variadic Parameters
 * @param logger - Reference to Logger Impl
 * @param message - Message to pass to logger
 * @param ps - Any additional parameters for the logger
 */
template <typename L, typename... params> inline static void
Error(Logger<L>& logger, const std::string& message, params... ps) {
  logger.Log(ERROR, message, ps...);
}

template <typename L, typename... params> inline static void
Error(Logger<L>&& logger, const std::string& message, params... ps) {
  logger.Log(ERROR, message, ps...);
}

/**
 * @brief Calls the provided Logger with Level WARN
 *
 * @tparam L - Logger Implementation
 * @tparam params - Variadic Parameters
 * @param logger - Reference to Logger Impl
 * @param message - Message to pass to logger
 * @param ps - Any additional parameters for the logger
 */
template <typename L, typename... params> inline static void
Warn(Logger<L>& logger, const std::string& message, params... ps) {
  logger.Log(WARN, message, ps...);
}
template <typename L, typename... params> inline static void
Warn(Logger<L>&& logger, const std::string& message, params... ps) {
  logger.Log(WARN, message, ps...);
}

/**
 * @brief Calls the provided Logger with Level INFO
 *
 * @tparam L - Logger Implementation
 * @tparam params - Variadic Parameters
 * @param logger - Reference to Logger Impl
 * @param message - Message to pass to logger
 * @param ps - Any additional parameters for the logger
 */
template <typename L, typename... params> inline static void
Info(Logger<L>& logger, const std::string& message, params... ps) {
  logger.Log(INFO, message, ps...);
}
template <typename L, typename... params> inline static void
Info(Logger<L>&& logger, const std::string& message, params... ps) {
  logger.Log(INFO, message, ps...);
}

/**
 * @brief Calls the provided Logger with Level DEBUG
 *
 * @tparam L - Logger Implementation
 * @tparam params - Variadic Parameters
 * @param logger - Reference to Logger Impl
 * @param message - Message to pass to logger
 * @param ps - Any additional parameters for the logger
 */
template <typename L, typename... params> inline static void
Debug(Logger<L>& logger, const std::string& message, params... ps) {
  logger.Log(DEBUG, message, ps...);
}
template <typename L, typename... params> inline static void
Debug(Logger<L>&& logger, const std::string& message, params... ps) {
  logger.Log(DEBUG, message, ps...);
}

}  // namespace LumberJack

namespace LJ = LumberJack;

#endif