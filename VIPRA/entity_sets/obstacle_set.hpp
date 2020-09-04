#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "../type_definitions.hpp"
#include "../dimensions.hpp"

//TODO this class should probably be derived - alex
class ObstacleSet
{
    private:
        int numObstacles;
        int numAisles;
		//what if the user doesn't want to use single point coordinates?
        std::vector<Dimensions> obstacleCoordinates;

    public:
        ObstacleSet();
        
        int getNumObstacles();
        std::vector<Dimensions>* getObstacleCoordinates();
        
        void setNumObstacles(int numObstacles);
        void setObstacleCoordinates(std::vector<Dimensions> coordinates);
};

#endif
