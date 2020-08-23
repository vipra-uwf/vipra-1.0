#ifndef CALM_ENTITY_SET_FACTORY_HPP
#define CALM_ENTITY_SET_FACTORY_HPP

#include "entity_set_factory.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"
#include "dimensions.hpp"

class CalmEntitySetFactory : public EntitySetFactory
{
    private:
        std::vector<std::string> extractAttribute(
            std::string attributeName, ENTITY_SET inputData);

        std::vector<FLOATING_NUMBER> vectorStringToDouble(
            std::vector<std::string> stringVec);
	
    public:
		virtual PedestrianSet createPedestrianSet(ENTITY_SET inputData);
		virtual ObstacleSet createObstacleSet(ENTITY_SET inputData);
		virtual SIM_PARAMS createSimulationParamsSet(ENTITY_SET inputData);
};

#endif
