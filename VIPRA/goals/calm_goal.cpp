#include "calm_goal.hpp"

CalmGoal::CalmGoal()
{
    std::cout << "goal created\n";
}

void CalmGoal::setExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>* hashMapData)
{
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

void CalmGoal::determinePedestrianGoals(Data* data)
{
    std::vector<Dimensions> newGoal;
    for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        int nearestExit = 0;
        if(this->exitGoal.size() > 1) 
        {
            nearestExit = nearestGoal(data, i); 
        }

        if(data->getPedestrianSet()->getPedestrianCoordinates()->at(i).coordinates[0] 
        != exitGoal.at(nearestExit).coordinates.at(0) && 
        data->getPedestrianSet()->getPedestrianCoordinates()->at(i).coordinates[1] != 0)
        {
            newGoal.push_back(
                Dimensions {
                std::vector<FLOATING_NUMBER> {
                    data->getPedestrianSet()->getPedestrianCoordinates()->at(i).coordinates[0],
                    0
                }
            }
        );
            
        }

        else if((data->getPedestrianSet()->getPedestrianCoordinates()->at(i).coordinates[0] 
        != exitGoal.at(nearestExit).coordinates.at(0)) && 
        (data->getPedestrianSet()->getPedestrianCoordinates()->at(i).coordinates[1] = 0))
        {
            newGoal.push_back(
                Dimensions {
                std::vector<FLOATING_NUMBER> {
                   exitGoal.at(nearestExit).coordinates[0],
                   0
                }
            }
        );

        }

        else
        {
            newGoal.push_back(
                Dimensions {
                std::vector<FLOATING_NUMBER> {
                   exitGoal.at(nearestExit).coordinates[0],
                   exitGoal.at(nearestExit).coordinates[1]
                }
            }
        );
        }
        

    }
}

unsigned int CalmGoal::nearestGoal(Data* data, int pedestrianIndex)
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
FLOATING_NUMBER CalmGoal::calculateDistance(Data* data, int pedestrianIndex, int exitGoalIndex)
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