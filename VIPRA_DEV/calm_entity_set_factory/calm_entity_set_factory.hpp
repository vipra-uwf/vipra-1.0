#ifndef CALM_ENTITY_SET_FACTORY_HPP
#define CALM_ENTITY_SET_FACTORY_HPP

#include "../Base/definitions/dimensions.hpp"
#include "../Interfaces/entitysetfactory/entity_set_factory.hpp"
#include "../calm_pedestrian_set/calm_pedestrian_set.hpp"


class CalmEntitySetFactory : public EntitySetFactory
{
    public:
        void            configure(CONFIG_MAP* configMap)                                                    override;
		void            populatePedestrianSet(ENTITY_SET inputData, PedestrianSet* calmPedestrianSet)       override;
		void            populateObstacleSet(ENTITY_SET inputData, ObstacleSet* obstacleSet)                 override;
};

#endif
