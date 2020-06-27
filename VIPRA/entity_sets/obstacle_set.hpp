#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "../type_definitions.hpp"

class ObstacleSet
{
    private:
        int numObstacles;
        int numDimensions;
        std::vector<std::vector<FLOATING_NUMBER>> obstacleCoordinates;

    public:
        ObstacleSet();
        
        int getNumObstacles();
        int getNumDimensions();
        void initializeObstacles();
        std::vector<std::vector<FLOATING_NUMBER>>* getObstacleCoordinates();

        void setNumObstacles(int); 
        void setObstacleCoordinates(std::vector<FLOATING_NUMBER>);
};

#endif