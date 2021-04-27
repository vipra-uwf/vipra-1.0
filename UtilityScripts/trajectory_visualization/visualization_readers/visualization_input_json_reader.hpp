#ifndef VISUALIZATION_INPUT_JSON_READER_HPP
#define VISUALIZATION_INPUT_JSON_READER_HPP

#include <fstream>
#include <iostream>

#include "visualization_input_data_loader.hpp"
#include "../../../VIPRA/jsoncpp/json/json.h"

class VisualizationInputJSONReader: public VisualizationInputDataLoader
{
    private:
        Json::Value jsonDocument;
        Json::CharReaderBuilder jsonReader;
        std::ifstream fileStream;
        std::string errors;

        void openFile(std::string fileName);
        void parseFile();

    public:
        virtual ENTITY_SET getInputEntities();
        virtual void configure(CONFIG_MAP* configMap);
        virtual void extractFileData(
            std::string fileName, 
            CONFIG_MAP* configMap);
};

#endif