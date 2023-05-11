#ifndef VISUALIZATION_INPUT_DATALOADER_HPP
#define VISUALIZATION_INPUT_DATALOADER_HPP

#include "../../../VIPRA/simulation/data.hpp"
#include "../../../VIPRA/definitions/type_definitions.hpp"
#include <unordered_map>
#include <vector>

class VisualizationInputDataLoader
{
    public:
        virtual ~VisualizationInputDataLoader() = default;

        virtual void extractFileData(
            std::string fileName, 
            CONFIG_MAP* configMap) = 0;
        virtual void configure(CONFIG_MAP* configMap) = 0; 
        
        virtual std::vector<ENTITY_SET> getInputEntities() = 0; 
};

#endif
