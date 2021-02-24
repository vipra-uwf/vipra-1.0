#ifndef JSON_WRITER_HPP
#define JSON_WRITER_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
// #include <json/writer.h>

#include "output_data_writer.hpp"
#include "../readers/json/json.h"

class JSONWriter: public OutputDataWriter {
    private:
        Data* data;
        std::ofstream fileStream;
        int numChildElements;
        Json::Value document;
        Json::Value currentElement;

        void openFile(std::string fileName);

    public:
        JSONWriter();
        virtual void configure(CONFIG_MAP* configMap);
        virtual void initializeOutputFile(std::string outputFilePath);
        virtual void appendFloatAttributeToCurrentElement(
            std::string key, FLOATING_NUMBER value);
        virtual void appendStringAttributeToCurrentElement(
            std::string key, std::string value);
        virtual void writeToDocument(Data* data);
        virtual void writeDocumentContentsToFile();
};

#endif