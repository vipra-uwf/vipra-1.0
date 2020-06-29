#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class ObstacleSet
{
    private:
        int numObstacles;
        int numDimensions = 2;
        std::vector<Dimensions> obstacleCoordinates;

    public:
        ObstacleSet();
        
        int getNumObstacles();
        int getNumDimensions();
        std::vector<Dimensions>* getObstacleCoordinates();

        void setNumObstacles(int); 
        void setNumDimensions(int);
        void setObstacleCoordinates(std::vector<Dimensions>);
};

#endif