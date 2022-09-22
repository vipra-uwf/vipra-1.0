#ifndef JSON_TIMESTEP_WRITER_HPP
#define JSON_TIMESTEP_WRITER_HPP

#include "../../jsoncpp/json/json.h"
#include "../output_data_writer.hpp"

class JSONTimestepWriter : public OutputDataWriter {
  std::ofstream fileStream;
  Json::Value   document;
  int           index;
  int           timestepID;

  void openFile(std::string fileName);
  void setParentElementName(std::string parentElementName);
  void setChildElementName(std::string dataElementName);

 public:
  JSONTimestepWriter();
  void configure(const CONFIG_MAP& configMap) override;
  void initializeOutputFile(std::string outputFilePath) override;
  void addFloatValue(std::string key, FLOATING_NUMBER value) override;
  void addStringValue(std::string key, std::string value) override;
  void writeToDocument(const PedestrianSet&) override;
  void writeDocumentContentsToFile() override;
};

#endif