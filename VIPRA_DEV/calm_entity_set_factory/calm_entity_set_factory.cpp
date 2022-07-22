#include "calm_entity_set_factory.hpp"

#include <iostream>

void CalmEntitySetFactory::configure(CONFIG_MAP* configMap)
{

}

void CalmEntitySetFactory::populatePedestrianSet(ENTITY_SET inputData, PedestrianSet* calmPedestrianSet)
{
    const size_t pedCount = inputData["pedestrians"].size();
    calmPedestrianSet->initialize(pedCount);
    calmPedestrianSet->setPedestrianCoordinates(inputData["pedestrians"]);
}

void CalmEntitySetFactory::populateObstacleSet(ENTITY_SET inputData, ObstacleSet* obstacleSet)
{
    for(const auto& [type, locations] : inputData){
        obstacleSet->addObjects(type, locations);
    }
}