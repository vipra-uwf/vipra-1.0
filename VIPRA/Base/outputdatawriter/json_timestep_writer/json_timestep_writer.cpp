
#include "json_timestep_writer.hpp"

JSONTimestepWriter::JSONTimestepWriter() {
  document["timesteps"] = Json::Value();
}

/**
 * @brief Returns the Json::Value that holds the timestep values
 * 
 * @return const Json::Value&
 */
const Json::Value&
JSONTimestepWriter::getDocument() const {
  return document;
}

void
JSONTimestepWriter::configure(const VIPRA::ConfigMap& configMap) {}

/**
 * @throws OutputDataWriterException
 * @brief Opens the output file, Throws {OutputDataWriterException} if unable to open file
 * @param outputFilePath - Absolute path to output file
 */
void
JSONTimestepWriter::initializeOutputFile(const std::string& outputFilePath) {
  fileStream.open(outputFilePath, std::fstream::out | std::fstream::trunc);
  if (!fileStream.is_open()) {
    OutputDataWriterException::Error("Unable To Open Output File: " + outputFilePath);
  }
}

/**
 * @brief Adds a float value to Document["timesteps"][timestep][key]
 * @note if key == "NEW_TIMESTEP" timestep is set to value
 * 
 * @param key - key to set value of
 * @param value - value to set key
 */
void
JSONTimestepWriter::addFloatValue(const std::string& key, float value) {
  if (key == "NEW_TIMESTEP") {
    timestep = value;
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

/**
 * @brief Adds a string value to Document["timesteps"][timestep][key]
 * @note if key == "NEW_TIMESTEP" timestep is set to value
 * 
 * @param key - key to set value of
 * @param value - value to set key
 */
void
JSONTimestepWriter::addStringValue(const std::string& key, const std::string& value) {
  if (key == "NEW_TIMESTEP") {
    timestep = std::stoi(value);
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

/**
 * @brief Writes the timestep values JSON to the output file, and closes the file
 * 
 */
void
JSONTimestepWriter::writeToDocument() {
  fileStream << document;
  fileStream.close();
  document.clear();
}