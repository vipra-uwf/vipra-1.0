#ifndef JSON_WRITER_HPP
#define JSON_WRITER_HPP

#include "../../jsoncpp/json/json.h"
#include "../output_data_writer.hpp"

class JSONWriter : public OutputDataWriter {
 private:
  std::ofstream fileStream;
  std::string   parentElementName;
  std::string   childElementName;
  Json::Value   document;
  int           index;

  void openFile(std::string fileName);
  void setParentElementName(std::string parentElementName);
  void setChildElementName(std::string dataElementName);

 public:
  JSONWriter();
  void configure(const CONFIG_MAP& configMap) override;
  void initializeOutputFile(std::string outputFilePath) override;
  void addFloatValue(std::string key, FLOATING_NUMBER value) override;
  void addStringValue(std::string key, std::string value) override;
  void writeToDocument(const PedestrianSet& data) override;
  void writeDocumentContentsToFile() override;
};

#endif