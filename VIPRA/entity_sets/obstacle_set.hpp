#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class ObstacleSet
{
    public:
        virtual ~ObstacleSet() = default;
        
        virtual void configure(CONFIG_MAP* configMap) = 0;
        virtual int getNumObstacles() = 0;
        virtual std::vector<Dimensions>* getObstacleCoordinates() = 0;
        virtual void setNumObstacles(int numObstacles) = 0;
        virtual void setObstacleCoordinates(
            std::vector<Dimensions> coordinates) = 0;
};

#endif
