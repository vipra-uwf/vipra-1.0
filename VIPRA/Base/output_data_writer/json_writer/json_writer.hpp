#ifndef JSON_WRITER_HPP
#define JSON_WRITER_HPP

#include <json/json.h>

#include <output_data_writer/output_data_writer.hpp>

class JSONWriter : public OutputDataWriter {
 private:
  std::ofstream    fileStream;
  Json::Value      document;
  Json::ArrayIndex index = 0;

 public:
  JSONWriter();
  void configure(const VIPRA::CONFIG::Map& configMap) override;
  void initializeOutputFile(const std::string& outputFilePath) override;
  void addFloatValue(const std::string& key, float value) override;
  void addStringValue(const std::string& key, const std::string& value) override;
  void writeToDocument() override;
};

#endif