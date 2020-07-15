#include "goal.hpp"

Goal::Goal()
{
    std::cout << "goal created\n";
}

void Goal::setExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>* hashMapData)
{
    //add an additional goal to the vector of exit goals
    FLOATING_NUMBER x;
    FLOATING_NUMBER y;

    x = (*hashMapData)["exit_door_x"];
    y = (*hashMapData)["exit_door_y"];

    std::vector<Dimensions> exit;

    exit.push_back(
    Dimensions {
                std::vector<FLOATING_NUMBER> {
                    x,
                    y
                }
            }
    );

    std::cout << "exit has beed set\n";

    this->exitGoal = exit;
}

void Goal::determinePedestrianGoals(Data* data)
{
    std::cout << "check1\n";
    for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        int nearestExit = 0;
        //checks for size of array in struct to get the number of exits
        //(may move this to intializeGoals and make a vector of nearestExits) - E
        if(this->exitGoal.size() > 1) 
        {
            //calls nearestGoal to get nearests goal for ped - E
            nearestExit = nearestGoal(data, i); 
        }
        this->findPath(data, i, nearestExit);

    }
}

void Goal::findPath(Data* data, int pedestrianIndex, int nearestExit)
{
    FLOATING_NUMBER x = (
        exitGoal.at(nearestExit).coordinates[0] - 
        data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0]
        );
    FLOATING_NUMBER y = (
        exitGoal.at(nearestExit).coordinates[1] - 
        data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1]
        );

    if(x >= 0 && y >= 0)
    {
        if(!isBlocked(data, pedestrianIndex, "POSX"))
        {
            std::cout << "posx wins\n";
            std::cout << "x:" << data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
                      << " y:" << data->getPedestrianSet()->getPedestrianCoordinates()
                      ->at(pedestrianIndex).coordinates[1] << std::endl;
        }
        else if(!isBlocked(data, pedestrianIndex, "POSY"))
        {
            std::cout << "posy wins\n";
            std::cout << "x:" << data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
                      << " y:" << data->getPedestrianSet()->getPedestrianCoordinates()
                      ->at(pedestrianIndex).coordinates[1] << std::endl;
        }
        else if(!isBlocked(data, pedestrianIndex, "NEGY"))
        {
            std::cout << "negy wins\n";
            std::cout << "x:" << data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
                      << " y:" << data->getPedestrianSet()->getPedestrianCoordinates()
                      ->at(pedestrianIndex).coordinates[1] << std::endl;
        }
        else if(!isBlocked(data, pedestrianIndex, "NEGX"))
        {
            std::cout << "negx wins\n";
            std::cout << "x:" << data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
                      << " y:" << data->getPedestrianSet()->getPedestrianCoordinates()
                      ->at(pedestrianIndex).coordinates[1] << std::endl;
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
    //this value is pulled from the obstacle file. each obj is about 0.79 apart
    //... this should check a healthy range without going over. - E
    //maybe pull from new obstacle file, it shouldn't be hardcoded here? - V
    FLOATING_NUMBER xRange = 1.2; 
    FLOATING_NUMBER yRange = 0.46;
    FLOATING_NUMBER x;
    FLOATING_NUMBER y;

    if(direction == "POSX")
    {
        x = ((data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0]) + xRange);
        y = (0.5*(yRange));

        for(int i = 0; i < data->getObstacleSet()->getNumObstacles(); ++i)
        {
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= 
            data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= x)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] - y) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] + y))
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
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= 
            data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= x)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] - y) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] + y))
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
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= 
            data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= y)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] - x) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] + x))
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
            if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] <= 
            data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[1] 
            && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[1] >= y)
            {
                if(data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] >= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] - x) 
                && data->getObstacleSet()->getObstacleCoordinates()->at(i).coordinates[0] <= 
                (data->getPedestrianSet()->getPedestrianCoordinates()->at(pedestrianIndex).coordinates[0] + x))
                {
                    blocked = true;
                    break;
                }
            }
        }

    }
    return blocked;

}


//if you intend to return a -1 flag for any reason in the future this will
//have to be changed back to int, and then i can be cast to int in the inner-most
//part of the loop, or in the loop's conditionional statement - V
unsigned int Goal::nearestGoal(Data* data, int pedestrianIndex)
{
    //index of nearest starts at the first
    unsigned int nearest = 0; 
    //starts at position 1 because there should be at least 2 exit goals
    for(unsigned int i = 1; i < exitGoal.at(0).coordinates.size(); ++i) 
    {
        //compares distance between exits and the pedestrian
        if(calculateDistance(data, pedestrianIndex, i) < calculateDistance(data, pedestrianIndex, nearest)) 
        {
            //sets nearest to lower if a different exit is lower.
            nearest = i; 
        }
    }
    return nearest;
}

//pedestrianIndex and exitGoalIndex should probably be unsigned - V
FLOATING_NUMBER Goal::calculateDistance(Data* data, int pedestrianIndex, int exitGoalIndex)
{
    FLOATING_NUMBER xDistance = 
        exitGoal[0].coordinates[exitGoalIndex] - 
        data->getPedestrianSet()->getPedestrianCoordinates()->at(0).coordinates[pedestrianIndex]
    ;
    xDistance = pow(xDistance, 2);


    FLOATING_NUMBER yDistance = exitGoal[1].coordinates[exitGoalIndex] - 
        data->getPedestrianSet()->getPedestrianCoordinates()->at(1).coordinates[pedestrianIndex]
    ;
    yDistance = pow(yDistance, 2);

    return (sqrt(xDistance + yDistance));
}