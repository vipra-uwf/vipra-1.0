#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class ObstacleSet
{
    private:
        int numObstacles;
        int numAisles;
        std::vector<Dimensions> obstacleCoordinates;

    public:
        ObstacleSet();
        
        void configure(CONFIG_MAP* configMap);
        int getNumObstacles();
        std::vector<Dimensions>* getObstacleCoordinates();
        
        void setNumObstacles(int numObstacles);
        void setObstacleCoordinates(std::vector<Dimensions> coordinates);
};

#endif
