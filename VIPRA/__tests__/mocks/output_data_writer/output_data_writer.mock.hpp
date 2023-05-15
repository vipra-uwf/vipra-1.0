#ifndef VIPRA_OUTPUT_DATA_WRITER_MOCK_HPP
#define VIPRA_OUTPUT_DATA_WRITER_MOCK_HPP

#include <gmock/gmock.h>

#include "output_data_writer/output_data_writer.hpp"

class OutputDataWriterMock : public OutputDataWriter {
 public:
  MOCK_METHOD(void, configure, (const VIPRA::CONFIG::Map& configMap), (override));
  MOCK_METHOD(void, initializeOutputFile, (const std::string& outputFilePath), (override));
  MOCK_METHOD(void, addFloatValue, (const std::string& key, float value), (override));
  MOCK_METHOD(void, addStringValue, (const std::string& key, const std::string& value), (override));
  MOCK_METHOD(void, writeToDocument, (), (override));
};

#endif