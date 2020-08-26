#ifndef ENTITY_SET_FACTORY_HPP
#define ENTITY_SET_FACTORY_HPP

#include <unordered_map>
#include <string>
#include <vector>

#include "../pedestrian_set.hpp"
#include "../obstacle_set.hpp"

typedef std::vector<std::unordered_map<std::string, std::string>> ENTITY_SET;
typedef std::unordered_map<std::string, FLOATING_NUMBER> SIM_PARAMS;

class EntitySetFactory
{
    public:
		virtual PedestrianSet* createPedestrianSet(ENTITY_SET inputData) = 0;
		virtual ObstacleSet* createObstacleSet(ENTITY_SET inputData) = 0;
		virtual SIM_PARAMS* createSimulationParams(ENTITY_SET inputData) = 0;
};

#endif