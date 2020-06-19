#ifndef DATA_HPP
#define DATA_HPP

#include "../entity_sets/pedestrian_set.hpp"
#include "../entity_sets/obstacle_set.hpp"

class Data
{
    private:
        PedestrianSet pedestrianSet;
        ObstacleSet obstacleSet;
    public:
        Data();
        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();
};

#endif
