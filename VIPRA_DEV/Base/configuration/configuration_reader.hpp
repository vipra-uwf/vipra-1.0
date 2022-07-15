#ifndef CONFIGURATION_READER_HPP
#define CONFIGURATION_READER_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "../definitions/type_definitions.hpp"
#include "../jsoncpp/json/json.h"

class ConfigurationReader
{
    private:
        Json::Value jsonDocument;
        Json::CharReaderBuilder jsonReader;
        std::ifstream fileStream;
        std::string errors;

        void openFile(std::string fileName);
        void parseFile();
    
    public:
        void readJsonConfiguration(std::string fileName);
        Json::Value getJsonObject();

        void configure(CONFIG_MAP* config);
};

#endif