
#include "json_writer.hpp"

JSONWriter::JSONWriter() {
  document["values"] = Json::arrayValue;
}

void
JSONWriter::configure(const VIPRA::ConfigMap& configMap) {}

void
JSONWriter::initializeOutputFile(const std::string& outputFilePath) {
  fileStream.open(outputFilePath);
  if (!fileStream.is_open()) {
    OutputDataWriterException::Error("Unable To Open Output File: " + outputFilePath);
  }
}

void
JSONWriter::addFloatValue(const std::string& key, float value) {
  if (document[index][key].isNull()) {
    document[index][key] = value;
  } else {
    document[++index][key] = value;
  }
}

void
JSONWriter::addStringValue(const std::string& key, const std::string& value) {
  if (document[index][key].isNull()) {
    document[index][key] = value;
  } else {
    document[++index][key] = value;
  }
}

void
JSONWriter::writeToDocument() {
  fileStream << document;
  fileStream.close();
}
