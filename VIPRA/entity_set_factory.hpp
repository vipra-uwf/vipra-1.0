#ifndef DATA_SET_FACTORY_HPP
#define DATA_SET_FACTORY_HPP

#include <unordered_map>
#include <string>
#include <vector>

#include <iostream>

#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"

typedef std::vector<std::unordered_map<std::string, std::string>> ENTITY_SET;

class EntitySetFactory
{
    private:
        std::vector<std::string> extractAttribute(
            std::string attributeName, ENTITY_SET inputData);

        std::vector<FLOATING_NUMBER> vectorStringToDouble(
            std::vector<std::string> stringVec);
	
    public:
		CalmPedestrianSet createCalmPedSet(ENTITY_SET inputData);

		ObstacleSet createObstacleSet(ENTITY_SET inputData);

		std::unordered_map<
			std::string, FLOATING_NUMBER> createSimulationParamsSet(
					ENTITY_SET inputData);

};

#endif
