#ifndef OUTPUT_DATA_WRITER_HPP
#define OUTPUT_DATA_WRITER_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "definitions/config_map.hpp"
#include "definitions/type_definitions.hpp"

class OutputDataWriterException : public std::runtime_error {
 public:
  explicit OutputDataWriterException(const std::string& message) : std::runtime_error(message) {}
  static void error(const std::string& message) { throw OutputDataWriterException(message); }
};

class OutputDataWriter {
 public:
  virtual ~OutputDataWriter() = default;

  virtual void configure(const VIPRA::CONFIG::Map& configMap) = 0;
  virtual void initializeOutputFile(const std::string& outputFilePath) = 0;
  virtual void addFloatValue(const std::string& key, float value) = 0;
  virtual void addStringValue(const std::string& key, const std::string& value) = 0;

  virtual void writeToDocument() = 0;
};

#endif