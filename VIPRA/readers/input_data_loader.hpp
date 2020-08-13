#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include <unordered_map>
#include <vector>

class InputDataLoader
{
    public:
		virtual std::unordered_map<
			std::string, std::vector<FLOATING_NUMBER>> getFloatInputData() = 0;
};

#endif
