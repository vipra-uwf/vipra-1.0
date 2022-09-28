#ifndef OUTPUT_DATA_WRITER_HPP
#define OUTPUT_DATA_WRITER_HPP

#include "../_pch/pch.hpp"
#include "../definitions/type_definitions.hpp"

class OutputDataWriterException : public std::exception {
 public:
  OutputDataWriterException(const std::string& message) : message(message) {}
  const std::string& what() { return message; }

  static void Error(const std::string& message) {
    std::cerr << message;
    throw OutputDataWriterException(message);
  }

 private:
  std::string message;
};

class OutputDataWriter {
 public:
  virtual ~OutputDataWriter() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;
  virtual void initializeOutputFile(const std::string& outputFilePath) = 0;
  virtual void addFloatValue(const std::string& key, FLOATING_NUMBER value) = 0;
  virtual void addStringValue(const std::string& key, const std::string& value) = 0;

  virtual void writeToDocument() = 0;
};

#endif