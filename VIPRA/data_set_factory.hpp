#ifndef DATA_SET_FACTORY_HPP
#define DATA_SET_FACTORY_HPP

#include <unordered_map>
#include <string>
#include <vector>

#include "entity_sets/calm_pedestrian_set.hpp"

class DataSetFactory
{
	public:
		CalmPedestrianSet createCalmPedSet(std::unordered_map<
				std::string, std::vector<FLOATING_NUMBER>> inputData);
};

#endif
