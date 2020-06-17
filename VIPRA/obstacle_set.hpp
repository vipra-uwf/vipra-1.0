#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "type_definitions.hpp"

class ObstacleSet
{
    private:
        int numObstacles;
        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
    public:
        ObstacleSet();
        
        int getNumObstacles();
        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();

        void setNumObstacles(int); 
        void setXCoordinates(std::vector<FLOATING_NUMBER>);
        void setYCoordinates(std::vector<FLOATING_NUMBER>);
};

#endif