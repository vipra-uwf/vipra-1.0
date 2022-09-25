
#include "json_timestep_writer.hpp"

void
throwODWError(const std::string& message) {
  std::cerr << message;
  throw OutputDataWriterException(message);
}

JSONTimestepWriter::JSONTimestepWriter() {
  document["timesteps"] = Json::Value();
}

const Json::Value&
JSONTimestepWriter::getDocument() const {
  return document;
}

void
JSONTimestepWriter::configure(const CONFIG_MAP& configMap) {}

void
JSONTimestepWriter::initializeOutputFile(const std::string& outputFilePath) {
  fileStream.open(outputFilePath, std::fstream::out | std::fstream::trunc);
  if (!fileStream.is_open()) {
    throwODWError("Unable To Open Output File: " + outputFilePath + "\n");
  }
}

void
JSONTimestepWriter::addFloatValue(const std::string& key, FLOATING_NUMBER value) {
  if (key == "NEW_TIMESTEP") {
    ++timestep;
    return;
  }
  auto& currTS = document["timesteps"][std::to_string(timestep)];
  if (currTS.isNull()) {
    index = 0;
    currTS[index][key] = value;
  } else {
    if (currTS[index][key].isNull()) {
      currTS[index][key] = value;
    } else {
      ++index;
      currTS[index][key] = value;
    }
  }
}

void
JSONTimestepWriter::addStringValue(const std::string& key, const std::string& value) {
  if (key == "NEW_TIMESTEP") {
    ++timestep;
    return;
  }
  auto& currTS = document["timesteps"][std::to_string(timestep)];
  if (currTS.isNull()) {
    index = 0;
    currTS[index][key] = value;
  } else {
    if (currTS[key].isNull()) {
      currTS[index][key] = value;
    } else {
      ++index;
      currTS[key] = value;
    }
  }
}

void
JSONTimestepWriter::writeToDocument() {
  fileStream << document;
  fileStream.close();
  document.clear();
}