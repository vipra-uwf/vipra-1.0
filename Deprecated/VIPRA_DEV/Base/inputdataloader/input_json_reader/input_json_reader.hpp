#ifndef INPUT_JSON_READER_HPP
#define INPUT_JSON_READER_HPP

#include "../input_data_loader.hpp"
#include "../../jsoncpp/json/json.h"

class InputJSONReader: public InputDataLoader
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