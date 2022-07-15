#ifndef CALM_ENTITY_SET_FACTORY_HPP
#define CALM_ENTITY_SET_FACTORY_HPP

#include "../Base/definitions/dimensions.hpp"
#include "../Interfaces/entitysetfactory/entity_set_factory.hpp"
#include "../calm_pedestrian_set/calm_pedestrian_set.hpp"


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
};

#endif
