#ifndef JSON_TIMESTEP_WRITER_HPP
#define JSON_TIMESTEP_WRITER_HPP

#include "../../_pch/pch.hpp"

#include "../output_data_writer.hpp"
#include "../../jsoncpp/json/json.h"

class JSONTimestepWriter: public OutputDataWriter {
    private:
        Data* data;
        std::ofstream fileStream;
        Json::Value document;
        int index;
        int timestepID;
        // NOTE: these aren't used, xml specific so no need to set them -RG
        std::string parentElementName;
        std::string childElementName;

        void openFile(std::string fileName);
        void setParentElementName(std::string parentElementName);
        void setChildElementName(std::string dataElementName);

    public:
        JSONTimestepWriter();
        virtual void configure(CONFIG_MAP* configMap);
        virtual void initializeOutputFile(std::string outputFilePath);
        virtual void addFloatValue(
            std::string key, FLOATING_NUMBER value);
        virtual void addStringValue(
            std::string key, std::string value);
        virtual void writeToDocument(Data* data);
        virtual void writeDocumentContentsToFile();
};

#endif