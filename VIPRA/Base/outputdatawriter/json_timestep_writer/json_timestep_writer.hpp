#ifndef JSON_TIMESTEP_WRITER_HPP
#define JSON_TIMESTEP_WRITER_HPP

#include "../../../deps/jsoncpp/json/json.h"
#include "../output_data_writer.hpp"
class JSONTimestepWriter : public OutputDataWriter {
  std::ofstream fileStream;
  Json::Value   document;
  int           index = 0;
  int           timestep = 0;

 public:
  JSONTimestepWriter();

  const Json::Value& getDocument() const;

  void configure(const CONFIG_MAP& configMap) override;
  void initializeOutputFile(const std::string& outputFilePath) override;
  void addFloatValue(const std::string& key, FLOATING_NUMBER value) override;
  void addStringValue(const std::string& key, const std::string& value) override;
  void writeToDocument() override;
};

#endif