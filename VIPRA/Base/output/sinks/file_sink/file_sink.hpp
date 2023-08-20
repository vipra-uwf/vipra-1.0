#ifndef VIPRA_FILE_SINK_HPP
#define VIPRA_FILE_SINK_HPP

#include <string>

#include "configuration/config.hpp"
#include "output/sink.hpp"

namespace VIPRA {
class FileSink : public Sink {
 public:
  void configure(const VIPRA::Config &) override;
  void write(const nlohmann::json &) override;

 private:
  std::string filename;

 public:
  FileSink() = default;
};
}  // namespace VIPRA

#endif