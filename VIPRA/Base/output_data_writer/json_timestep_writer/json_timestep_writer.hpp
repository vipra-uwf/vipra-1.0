#ifndef JSON_TIMESTEP_WRITER_HPP
#define JSON_TIMESTEP_WRITER_HPP

#include <json/json.h>
#include "../output_data_writer.hpp"


class JSONTimestepWriter : public OutputDataWriter {
  std::ofstream    fileStream;
  Json::Value      document;
  Json::ArrayIndex index = 0;
  std::string      timestep;
  int              currTimestep = 0;

 public:
  JSONTimestepWriter();

  const Json::Value& getDocument() const;

  void configure(const VIPRA::CONFIG::Map& configMap) override;
  void initializeOutputFile(const std::string& outputFilePath) override;
  void addFloatValue(const std::string& key, float value) override;
  void addStringValue(const std::string& key, const std::string& value) override;
  void writeToDocument() override;
};

#endif