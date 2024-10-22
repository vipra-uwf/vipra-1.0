#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../_pch/pch.hpp"

#include "../simulation/data/data.hpp"
#include "../definitions/type_definitions.hpp"

class InputDataLoader
{
    public:
        virtual ~InputDataLoader() = default;

        // TODO extractFileData should('nt?) take params, just re call configure and pass a new map to it

        virtual void extractFileData(
            std::string fileName, 
            CONFIG_MAP* configMap) = 0;
        virtual void configure(CONFIG_MAP* configMap) = 0; 
        
        virtual ENTITY_SET getInputEntities() = 0;

        // TODO make a type definiton for reading in sim_config.json and sim_options.json
        // TODO virtual NEW_CONFIG/OPTIONS_TYPE getConfigEntities()  
};

#endif
