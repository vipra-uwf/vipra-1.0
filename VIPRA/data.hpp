#ifndef DATA_HPP
#define DATA_HPP

#include "pedestrian_set.hpp"
#include "obstacle_set.hpp"

class Data
{
    public:
        Data();
        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();

    private:
        PedestrianSet pedestrianSet;
        ObstacleSet obstacleSet;
};

#endif
