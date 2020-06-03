#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <string>
#include <iostream>

#include "pedestrian_set.hpp"
#include "obstacle_set.hpp"

class Data
{
    public:
        Data();

        void pushCoordinates(std::string parseElement, FLOATING_NUMBER x, FLOATING_NUMBER y);

        void printPedestrianCoordinates();
        void printObstacleCoordinates();

        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();

    private:
        PedestrianSet pedestrianSet;
        ObstacleSet obstacleSet;

};

#endif
