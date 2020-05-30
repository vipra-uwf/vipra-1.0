#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <string>
#include <iostream>

#include "pedestrian_set.hpp"
#include "obstacle_set.hpp"

//Refactor for PedestriansSet (class of arrays) and ObstaclesSet (class of arrays) to be separate
class Data
{
    public:
        Data();

        void pushCoordinates(std::string parseElement, FLOATING_NUMBER x, FLOATING_NUMBER y);

        void printPedestrianCoordinates();
        void printObstacleCoordinates();

        PedestrianSet* getPedestrianSet();

    private:
        PedestrianSet pedestrianSet;
        ObstacleSet obstacleSet;

};

#endif
