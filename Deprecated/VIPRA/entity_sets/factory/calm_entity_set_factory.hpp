#ifndef CALM_ENTITY_SET_FACTORY_HPP
#define CALM_ENTITY_SET_FACTORY_HPP

#include "entity_set_factory.hpp"
#include "../calm_pedestrian_set.hpp"
#include "../../definitions/dimensions.hpp"

class CalmEntitySetFactory : public EntitySetFactory
{
    private:
        std::vector<std::string> accumulateAttribute(
            std::string attributeName, ENTITY_SET inputData);

        std::vector<FLOATING_NUMBER> vectorStringToDouble(
            std::vector<std::string> stringVec);
	
    public:
        virtual void configure(CONFIG_MAP* configMap);
		virtual void populatePedestrianSet(
            ENTITY_SET inputData, PedestrianSet* calmPedestrianSet);
		virtual void populateObstacleSet(
            ENTITY_SET inputData, ObstacleSet* obstacleSet);
		virtual void populateSimulationParams(
            ENTITY_SET inputData, SIM_PARAMS* simulationParams);
};

#endif
