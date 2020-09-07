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
		
        virtual ENTITY_SET getInputEntities() = 0;
};

#endif
