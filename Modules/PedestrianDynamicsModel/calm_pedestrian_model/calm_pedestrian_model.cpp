#include "calm_pedestrian_model.hpp"


void CalmPedestrianModel::initialize(PedestrianSet& pedestrianSet, ObstacleSet& obstacleSet, Goals& goals) 
{
    this->pedestrianSet = static_cast<CalmPedestrianSet&>(pedestrianSet);
    this->obstacleSet = obstacleSet;
    this->goals = goals;
}