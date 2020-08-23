#ifndef CALM_ENTITY_SET_FACTORY_HPP
#define CALM_ENTITY_SET_FACTORY_HPP

#include "entity_set_factory.hpp"
#include "calm_pedestrian_set.hpp"
#include "../dimensions.hpp"

class CalmEntitySetFactory : public EntitySetFactory
{
    private:
        std::vector<std::string> accumulateAttribute(
            std::string attributeName, ENTITY_SET inputData);

        std::vector<FLOATING_NUMBER> vectorStringToDouble(
            std::vector<std::string> stringVec);
	
    public:
		virtual CalmPedestrianSet* createPedestrianSet(ENTITY_SET inputData);
		virtual ObstacleSet* createObstacleSet(ENTITY_SET inputData);
		virtual SIM_PARAMS* createSimulationParams(ENTITY_SET inputData);
};

#endif
