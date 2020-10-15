#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include <unordered_map>
#include <vector>

typedef std::vector<std::unordered_map<std::string, std::string>> ENTITY_SET;

class InputDataLoader
{
    public:
        virtual ~InputDataLoader() = default;

        // TODO create hashmap setter methods just outputDataWriter
        // TODO fileName shouldnt be optional is json but rootElementName should be
        // TODO therefore it should go into the configuartion section
        virtual void extractFileData(
            std::string fileName, 
            std::string rootElementName) = 0;
        virtual void configure(CONFIG_MAP* configMap) = 0; 
        virtual ENTITY_SET getInputEntities() = 0;
};

#endif
