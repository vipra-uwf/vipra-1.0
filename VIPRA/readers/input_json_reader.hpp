#ifndef INPUT_JSON_READER_HPP
#define INPUT_JSON_READER_HPP

#include "input_data_loader.hpp"

class InputJSONReader: public InputDataLoader
{
    private:

    public:
        virtual ENTITY_SET getInputEntities();
        virtual void configure(CONFIG_MAP* configMap);
        virtual void extractFileData(
            std::string fileName, 
            CONFIG_MAP* configMap);
};

#endif