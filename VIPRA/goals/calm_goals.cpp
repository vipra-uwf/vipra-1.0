#include "calm_goals.hpp"

CalmGoals::CalmGoals()
{
}

void CalmGoals::addExitGoal(std::unordered_map<std::string,
    FLOATING_NUMBER>* simulationParams)
{
    //TODO fix this method so that exits are read in a different way so that i can read in multiple exits
    FLOATING_NUMBER x;
    FLOATING_NUMBER y;

    x = (*simulationParams)["exit_door_x"];
    y = (*simulationParams)["exit_door_y"];

    std::vector<Dimensions> exit;

    exit.push_back(
        Dimensions {
        std::vector<FLOATING_NUMBER> {x,y}
        }
    );

    this->exitGoal = exit;
}

void CalmGoals::removeExitGoal(int exitIndex)
{
    this->exitGoal.erase(exitGoal.begin()+exitIndex);
}

void CalmGoals::clearGoals()
{
    this->exitGoal.clear();
}

void CalmGoals::calculateNearestExit(Data* data)
{

    if(this->exitGoal.size() > 1) 
    {
        for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
        {
            this->nearestExit.push_back(nearestGoal(data, i));
        }
    }

    else
    {
        for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
        {
            this->nearestExit.push_back(0);
        }
    }

}

void CalmGoals::determinePedestrianGoals(Data* data)
{
    std::vector<Dimensions> newGoal;
    for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        if(!checkPedestianGoalsMet(data, i))
        {
            if((*data->getPedestrianSet()->getPedestrianCoordinates())[i]
                .coordinates[0] != this->exitGoal[nearestExit[i]].coordinates[0]
                && ((*data->getPedestrianSet()->getPedestrianCoordinates())[i]
                .coordinates[1] != 0))
            {
                newGoal.push_back
                (
                    Dimensions 
                    {
                    std::vector<FLOATING_NUMBER> 
                        {
                        (*data->getPedestrianSet()->getPedestrianCoordinates())[i]
                        .coordinates[0], 0}
                    }
                );
            
            }

            else if((*data->getPedestrianSet()->getPedestrianCoordinates())[i]
                .coordinates[0]!= this->exitGoal[nearestExit[i]].
                coordinates[0] && ((*data->getPedestrianSet()->
                getPedestrianCoordinates())[i].coordinates[1] = 0))
            {
                newGoal.push_back
                (
                    Dimensions 
                    {
                    std::vector<FLOATING_NUMBER> 
                        {
                        exitGoal[nearestExit[i]].coordinates[0],
                        0
                        }
                     }
                );
            }

            else
            {
                newGoal.push_back
                (
                    Dimensions 
                    {
                    std::vector<FLOATING_NUMBER> 
                        {
                        exitGoal[nearestExit[i]].coordinates[0],
                        exitGoal[nearestExit[i]].coordinates[1]
                        }
                    }
                );
            }
        }
        else
        {
            data->getPedestrianSet()->removePedestrian(i);
        }
        
    }
}

bool CalmGoals::checkPedestianGoalsMet(Data* data, int pedestrianIndex)
{

    bool goalMet = false;

    if((*data->getPedestrianSet()->getPedestrianCoordinates())[pedestrianIndex]
        .coordinates[0] == this->exitGoal[nearestExit[pedestrianIndex]]
        .coordinates[0] && (*data->getPedestrianSet()->
        getPedestrianCoordinates())[pedestrianIndex]
        .coordinates[1] == this->exitGoal[nearestExit[pedestrianIndex]]
        .coordinates[1])
    {
        goalMet = true;
    }

    return goalMet;
}

bool CalmGoals::isSimulationGoalMet(Data* data)
{
    bool simGoalMet = false;
    if(data->getPedestrianSet()->getNumPedestrians() == 0)
    {
        simGoalMet = true;
    }
    return simGoalMet;
}

unsigned int CalmGoals::nearestGoal(Data* data, int pedestrianIndex)
{
    //index of nearest starts at the first
    unsigned int nearest = 0; 
    //starts at position 1 because there should be at least 2 exit goals
    for(unsigned int i = 1; i < this->exitGoal[0].coordinates.size(); ++i)
    {
        //compares distance between exits and the pedestrian
        if(calculateDistance(data, pedestrianIndex, i) < 
            calculateDistance(data, pedestrianIndex, nearest))
        {
            //sets nearest to lower if a different exit is lower.
            nearest = i; 
        }
    }
    return nearest;
}

//pedestrianIndex and exitGoalIndex should probably be unsigned - V
FLOATING_NUMBER CalmGoals::calculateDistance(Data* data, 
    int pedestrianIndex, int exitGoalIndex)
{
    FLOATING_NUMBER xDistance = 
        this->exitGoal[0].coordinates[exitGoalIndex] - 
        (*data->getPedestrianSet()->getPedestrianCoordinates())[0]
        .coordinates[pedestrianIndex];

    xDistance = pow(xDistance, 2);


    FLOATING_NUMBER yDistance = this->exitGoal[1].coordinates[exitGoalIndex] -
        (*data->getPedestrianSet()->getPedestrianCoordinates())[1]
        .coordinates[pedestrianIndex];

    yDistance = pow(yDistance, 2);

    return (sqrt(xDistance + yDistance));
}