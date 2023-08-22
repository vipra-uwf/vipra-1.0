

#include "file_sink.hpp"

#include <spdlog/spdlog.h>
#include <fstream>
#include <stdexcept>

namespace VIPRA {

void FileSink::configure(const VIPRA::Config& config) { filename = config["filepath"]; }

void FileSink::write(const nlohmann::json& json) {
  std::fstream output;
  output.open(filename, std::fstream::out | std::fstream::trunc);
  if (!output.is_open()) {
    throw std::runtime_error("Unable To Open Output File: " + filename);
  }
  output << json;
  output.close();
}
}  // namespace VIPRA