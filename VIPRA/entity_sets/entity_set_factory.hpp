#ifndef ENTITY_SET_FACTORY_HPP
#define ENTITY_SET_FACTORY_HPP

#include <unordered_map>
#include <string>
#include <vector>

#include "pedestrian_set.hpp"
#include "obstacle_set.hpp"
#include "../type_definitions.hpp"

typedef std::vector<std::unordered_map<std::string, std::string>> ENTITY_SET;
typedef std::unordered_map<std::string, FLOATING_NUMBER> SIM_PARAMS;

class EntitySetFactory
{
    public:
        virtual ~EntitySetFactory() = default;

        virtual void configure(CONFIG_MAP* configMap) = 0;

		virtual void populatePedestrianSet(
            ENTITY_SET inputData, PedestrianSet* pedestrianSet) = 0;
		virtual void populateObstacleSet(
            ENTITY_SET inputData, ObstacleSet* obstacleSet) = 0;
		virtual void populateSimulationParams(
            ENTITY_SET inputData, SIM_PARAMS* simParams) = 0;
};

#endif