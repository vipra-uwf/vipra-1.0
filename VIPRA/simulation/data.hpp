#ifndef DATA_HPP
#define DATA_HPP

#include "../entity_sets/pedestrian_set.hpp"
#include "../entity_sets/obstacle_set.hpp"


// TODO .. we should probably make this into a virtual class..
// the derived class would be CalmData -- Alex
class Data
{
    private:
        PedestrianSet* pedestrianSet;
        ObstacleSet obstacleSet;
    public:
        Data();
        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();
        void setPedestrianSet(PedestrianSet*);


};

#endif
