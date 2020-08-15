#ifndef DATA_SET_FACTORY_HPP
#define DATA_SET_FACTORY_HPP

#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"

class DataSetFactory
{
	public:
		CalmPedestrianSet createCalmPedSet(std::unordered_map<
				std::string, std::vector<FLOATING_NUMBER>> inputData);

		ObstacleSet createObstacleSet(std::unordered_map<
				std::string, std::vector<FLOATING_NUMBER>> inputData);

		std::unordered_map<
			std::string, FLOATING_NUMBER> createSimulationParamsSet(
					std::unordered_map<
						std::string, std::vector<FLOATING_NUMBER>> inputData);
};

#endif
