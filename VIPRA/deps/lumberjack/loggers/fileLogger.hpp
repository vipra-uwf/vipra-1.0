#ifndef LUMBERJACK_FILELOGGER_HPP
#define LUMBERJACK_FILELOGGER_HPP
#define FMT_HEADER_ONLY

#include <fstream>

#include "../deps/fmt/core.h"
#include "../lumberjack.hpp"

namespace LumberJack {
/**
 * @brief Sends Log messages to an output file
 *
 */
struct FileLogger {

  FileLogger() = delete;
  FileLogger(FileLogger&) = delete;
  FileLogger(const FileLogger&) = delete;
  FileLogger(FileLogger&&) = delete;
  FileLogger& operator=(FileLogger&) = delete;
  FileLogger& operator=(FileLogger&&) = delete;
  ~FileLogger() { file.close(); };

  FileLogger(const std::string& filePath)
    : filepath{filePath}, file{filePath, std::ios::out | std::ios::app} {
    if (!file.is_open()) {
      LogException::Throw("Unable To Open File: " + filePath);
    }
  }

  template <typename... Params> void operator()(Level lvl, const std::string& message, Params... ps) {
    if (!file.is_open()) {
      LogException::Throw("Unable To Open File: " + filepath);
    }
    file << "[" << LevelStrings[lvl] << "] " << fmt::format(message, ps...) << '\n';
  }

  std::string   filepath;
  std::ofstream file;
};
}  // namespace LumberJack

#endif