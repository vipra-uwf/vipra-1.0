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

        void pushCoordinates(std::string parseElement, double x, double y);

        void printPedestrianCoordinates();
        void printObstacleCoordinates();

        PedestrianSet* getPedestrianSet();

    private:
        PedestrianSet pedestrianSet;
        ObstacleSet obstacleSet;

};

#endif
