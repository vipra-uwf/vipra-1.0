#ifndef JSON_WRITER_HPP
#define JSON_WRITER_HPP

#include "../../../deps/jsoncpp/json/json.h"
#include "../output_data_writer.hpp"

class JSONWriter : public OutputDataWriter {
 private:
  std::ofstream fileStream;
  Json::Value   document;
  int           index = 0;

 public:
  JSONWriter();
  void configure(const CONFIG_MAP& configMap) override;
  void initializeOutputFile(const std::string& outputFilePath) override;
  void addFloatValue(const std::string& key, FLOATING_NUMBER value) override;
  void addStringValue(const std::string& key, const std::string& value) override;
  void writeToDocument() override;
};

#endif