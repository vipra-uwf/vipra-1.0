#ifndef ENTITY_SET_FACTORY_HPP
#define ENTITY_SET_FACTORY_HPP

#include <unordered_map>
#include <string>
#include <vector>

#include "../../Base/definitions/type_definitions.hpp"

#include "../pedestrianset/pedestrian_set.hpp"
#include "../obstacleset/obstacle_set.hpp"

class EntitySetFactory
{
      public:
            virtual           ~EntitySetFactory() = default;

            virtual void      configure(CONFIG_MAP* configMap)                                             = 0;

            virtual void      populatePedestrianSet(ENTITY_SET inputData, PedestrianSet* pedestrianSet)    = 0;
            virtual void      populateObstacleSet(ENTITY_SET inputData, ObstacleSet* obstacleSet)          = 0;
};

#endif