#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include <unordered_map>
#include <vector>

class InputDataLoader
{
    public:
        virtual ~InputDataLoader() = default;

        // TODO extractFileData should take params, just re call configure and pass a new map to it

        virtual void extractFileData(
            std::string fileName, 
            CONFIG_MAP* configMap) = 0;
        virtual void configure(CONFIG_MAP* configMap) = 0; 
        
        virtual ENTITY_SET getInputEntities() = 0;
};

#endif
