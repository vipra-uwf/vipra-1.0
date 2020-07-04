#include "goal.hpp"

Goal::Goal()
{
}

void Goal::setExitGoal(std::vector<Dimensions> exitGoal)
{
    this->exitGoal = exitGoal;
}

void Goal::determinePedestrianGoals(Data* data)
{
    for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        int nearestExit = 0;
        if(this->exitGoal.at(0).coordinates.size() > 1) //checks for size of array in struct to get the number of exits(may move this to intializeGoals and make a vector of nearestExits) -el
        {
            nearestExit = nearestGoal(data, i); //calls nearestGoal to get nearests goal for ped
        }




    }
}

void Goal::findPath(Data* data, int pedestrianIndex, int nearestExit)
{
    FLOATING_NUMBER x = (data->getPedestrianSet()->getPedestrianCoordinates()->at(0).coordinates[pedestrianIndex]) -(exitGoal.at(0).coordinates[nearestExit]);
    FLOATING_NUMBER y = (data->getPedestrianSet()->getPedestrianCoordinates()->at(1).coordinates[pedestrianIndex]) -(exitGoal.at(1).coordinates[nearestExit]);
    
}

bool Goal::isBlocked(Data* data, int pedestrianIndex)
{
    bool blocked = false;
}



int Goal::nearestGoal(Data* data, int pedestrianIndex)
{
    int nearest = 0; //index of nearest starts at the first
    for(int i = 1; i < exitGoal.at(0).coordinates.size(); ++i) //starts at position 1 because there should be at least 2 exit goals
    {
        if(calculateDistance(data, pedestrianIndex, i) < calculateDistance(data, pedestrianIndex, nearest)) //compares distance between exits and the pedestrian
        {
            nearest = i; //sets nearest to lower if a different exit is lower.
        }
    }
    return nearest;
}

FLOATING_NUMBER Goal::calculateDistance(Data* data, int pedestrianIndex, int exitGoalIndex)
{
    FLOATING_NUMBER xDistance = pow(exitGoal[0].coordinates[exitGoalIndex] - data->getPedestrianSet()->getPedestrianCoordinates()->at(0).coordinates[pedestrianIndex], 2);
    FLOATING_NUMBER yDistance = pow(exitGoal[1].coordinates[exitGoalIndex] - data->getPedestrianSet()->getPedestrianCoordinates()->at(1).coordinates[pedestrianIndex], 2);
    return (sqrt(xDistance + yDistance));
}