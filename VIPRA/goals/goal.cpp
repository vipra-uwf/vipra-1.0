#include "goal.hpp"

Goal::Goal()
{
    std::cout << "goal created\n";
}

void Goal::setExitGoal(std::vector<Dimensions> exitGoal)
{
    this->exitGoal = exitGoal;
}

void Goal::determinePedestrianGoals(Data* data)
{
    for (int i = 0; i < 2/*data->getPedestrianSet()->getNumPedestrians()*/; ++i)
    {
        int nearestExit = 0;
        if(this->exitGoal.at(0).coordinates.size() > 1) //checks for size of array in struct to get the number of exits(may move this to intializeGoals and make a vector of nearestExits) -el
        {
            nearestExit = nearestGoal(data, i); //calls nearestGoal to get nearests goal for ped
        }
        this->findPath(data, i, nearestExit);

    }
}

void Goal::findPath(Data* data, int pedestrianIndex, int nearestExit)
{
    FLOATING_NUMBER x = (exitGoal.at(nearestExit).coordinates[0] - data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0]);
    FLOATING_NUMBER y = (exitGoal.at(nearestExit).coordinates[1] - data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1]);
    bool pathFound = false;

    if(x >= 0 && y >= 0)
    {
        if(!isBlocked(data, pedestrianIndex, "POSX"))
        {
            //is path? set goal
        }
        else if(!isBlocked(data, pedestrianIndex, "POSY"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "NEGY"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "NEGX"))
        {

        }
    }
    else if(x >=0 && y < 0)
    {
        if(!isBlocked(data, pedestrianIndex, "POSX"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "NEGY"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "NEGX"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "POSY"))
        {
            
        }
    }
    else if(x < 0 && y >= 0)
    {

        if(!isBlocked(data, pedestrianIndex, "NEGX"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "POSY"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "NEGY"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "POSX"))
        {
            
        }

    }
    else if (x < 0 && y < 0)
    {
        if(!isBlocked(data, pedestrianIndex, "NEGX"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "NEGY"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "POSX"))
        {

        }
        else if(!isBlocked(data, pedestrianIndex, "POSY"))
        {
            
        }

    }
}

bool Goal::isBlocked(Data* data, int pedestrianIndex, std::string direction)
{
    bool blocked = false;
    FLOATING_NUMBER xRange = 0.7; //this value is pulled from the obstacle file. each obj is about 0.79 apart, this should check a healthy range without going over.
    FLOATING_NUMBER yRange = 0.46;
    FLOATING_NUMBER x;
    FLOATING_NUMBER y;

    if(direction == "POSX")
    {
        x = ((data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0]) + xRange);
        y = (0.5*(yRange));

        for(int i = 0; i < data->getObstacleSet()->getNumObstacles(); ++i)
        {
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= x)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] - y) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] + y))
                {
                    blocked = true;
                    break;
                }
            }
        }
    }
    else if(direction == "NEGX")
    {
        x = ((data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0]) - xRange);
        y = (0.5*(yRange));

        for(int i = 0; i < data->getObstacleSet()->getNumObstacles(); ++i)
        {
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= x)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] - y) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] + y))
                {
                    blocked = true;
                    break;
                }
            }
        }
    }
    else if(direction =="POSY")
    {
        y = ((data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1]) + yRange);
        x = (0.07);

        for(int i = 0; i < data->getObstacleSet()->getNumObstacles(); ++i)
        {
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= y)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] - x) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] + x))
                {
                    blocked = true;
                    break;
                }
            }
        }
    }
    else if(direction == "NEGY")
    {
        y = ((data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1]) - yRange);
        x = (0.07);
        for(int i = 0; i < data->getObstacleSet()->getNumObstacles(); ++i)
        {
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= y)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] - x) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] + x))
                {
                    blocked = true;
                    break;
                }
            }
        }

    }
    return blocked;

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