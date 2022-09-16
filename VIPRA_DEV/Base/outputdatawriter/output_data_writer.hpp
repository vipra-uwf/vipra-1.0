#ifndef OUTPUT_DATA_WRITER_HPP
#define OUTPUT_DATA_WRITER_HPP

#include "../_pch/pch.hpp"
#include "../definitions/type_definitions.hpp"

#include "../../Extendable/pedestrianset/pedestrian_set.hpp"

class OutputDataWriter {
 public:
  virtual ~OutputDataWriter() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;
  virtual void initializeOutputFile(std::string outputFilePath) = 0;
  virtual void addFloatValue(std::string key, FLOATING_NUMBER value) = 0;
  virtual void addStringValue(std::string key, std::string value) = 0;
  virtual void writeToDocument(const PedestrianSet& data) = 0;
  virtual void writeDocumentContentsToFile() = 0;
};

#endif