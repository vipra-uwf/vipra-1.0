#include "calm_goals.hpp"

CalmGoals::CalmGoals()
{
}

void CalmGoals::configure(CONFIG_MAP* configMap)
{
    
}

void CalmGoals::setData(Data* data)
{
    this->data = data;
    createPedCoordPointer();

    //TODO this may not be the best place -- maybe an initGoals function-- alex
    addExitGoal(data->getSimulationParams());
    calculateNearestExit();
}

void CalmGoals::addExitGoal(std::unordered_map<std::string,
    FLOATING_NUMBER>* simulationParams)
{
    //TODO fix this method so that exits are read 
    // in a different way so that i can read in multiple exits - elisabeth
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
    std::cout << "number of exits before: " << exitGoal.size() << std::endl;
    this->exitGoal.erase(exitGoal.begin()+exitIndex);
    std::cout << "goal erased\nsize of exitGoal vector: " << 
        exitGoal.size() << std::endl;
}

void CalmGoals::clearGoals()
{
    std::cout << "number of exits before: " << exitGoal.size() << std::endl;
    this->exitGoal.clear();
    std::cout << "goals cleared\nsize of exitGoal vector: " << 
        exitGoal.size() << std::endl;
}

void CalmGoals::calculateNearestExit()
{

    if(this->exitGoal.size() > 1)
    {
        for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); 
            ++i)
        {
            this->nearestExit.push_back(nearestGoal(i));
        }
    }

    else
    {
        for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians(); 
            ++i)
        {
            this->nearestExit.push_back(0);
        }
    }
    
    // for(int i = 0; i < 5/*this->data->getPedestrianSet()->getNumPedestrians()*/
    //     ; ++i)
    // {
    //     std::cout << "nearest exit for ped " << i << " :" << nearestExit[i] 
    //         << std::endl;
    // }
    

}

void CalmGoals::determinePedestrianGoals()
{
    std::vector<Dimensions> newGoal;

    for (int i = 0; i < this->data->getPedestrianSet()->getNumPedestrians();)
    {
        if(!checkPedestianGoalsMet(i))
        {
            if(((*this->pedCoordsPtr)[i].coordinates[0]
                < this->exitGoal[nearestExit[i]].coordinates[0] - 0.011)
                && !((*this->pedCoordsPtr)[i].coordinates[1] < 0.011
                && (*this->pedCoordsPtr)[i].coordinates[1] > -0.011))
            {
                newGoal.push_back
                (
                    Dimensions 
                    {
                    std::vector<FLOATING_NUMBER> 
                        {
                            (*this->pedCoordsPtr)[i].coordinates[0], 0
                        }
                    }
                );
                ++i;
            
            }

            else if(((*this->pedCoordsPtr)[i].coordinates[0]
                < this->exitGoal[nearestExit[i]].coordinates[0] - 0.011)
                && ((*this->pedCoordsPtr)[i].coordinates[1] < 0.011
                && (*this->pedCoordsPtr)[i].coordinates[1] > -0.011))
            {
                newGoal.push_back
                (
                    Dimensions 
                    {
                    std::vector<FLOATING_NUMBER> 
                        {
                            this->exitGoal[nearestExit[i]].coordinates[0],
                            0
                        }
                     }
                );
                ++i;
            }

            else
            {
                newGoal.push_back
                (
                    Dimensions 
                    {
                    std::vector<FLOATING_NUMBER> 
                        {
                            this->exitGoal[nearestExit[i]].coordinates[0],
                            this->exitGoal[nearestExit[i]].coordinates[1]
                        }
                    }
                );
                ++i;
            }
        }
        else if (checkPedestianGoalsMet(i))
        {
            this->data->getPedestrianSet()->removePedestrian(i);
            std::cout << "check removed\nnumpeds: " << this->data->
                getPedestrianSet()->getNumPedestrians() << std::endl;
            std::cout << "check vectors size: " << this->data->
                getPedestrianSet()->getPedestrianCoordinates()->size() 
                    << std::endl;
        }

        
        
    }
    data->getPedestrianSet()->setGoalCoordinates(newGoal);
}

bool CalmGoals::checkPedestianGoalsMet(int pedIndex)
{

    bool goalMet = false;

    if(((*this->pedCoordsPtr)[pedIndex].coordinates[0]
        >= this->exitGoal[nearestExit[pedIndex]].coordinates[0] - 0.011 
        && (*this->pedCoordsPtr)[pedIndex].coordinates[0]
        <= this->exitGoal[nearestExit[pedIndex]].coordinates[0] + 0.011)
        && ((*this->pedCoordsPtr)[pedIndex].coordinates[1]
        >= this->exitGoal[nearestExit[pedIndex]].coordinates[1]))
    {
        goalMet = true;
    }

    return goalMet;
}

bool CalmGoals::isSimulationGoalMet()
{
    bool simGoalMet = false;
    if(this->data->getPedestrianSet()->getNumPedestrians() == 0)
    {
        simGoalMet = true;
    }
    return simGoalMet;
}

void CalmGoals::createPedCoordPointer()
{
    this->pedCoordsPtr = this->data->getPedestrianSet()->
        getPedestrianCoordinates();
}

unsigned int CalmGoals::nearestGoal(int pedIndex)
{
    //index of nearest starts at the first
    unsigned int nearest = 0; 
    //starts at position 1 because there should be at least 2 exit goals
    for(unsigned int i = 1; i < this->exitGoal[0].coordinates.size(); ++i)
    {
        //compares distance between exits and the pedestrian
        if(calculateDistance(pedIndex, i) < 
            calculateDistance(pedIndex, nearest))
        {
            //sets nearest to lower if a different exit is lower.
            nearest = i; 
        }
    }
    return nearest;
}

//pedestrianIndex and exitGoalIndex should probably be unsigned - V
FLOATING_NUMBER CalmGoals::calculateDistance(int pedIndex, 
    int exitGoalIndex)
{
    FLOATING_NUMBER xDistance = 
        this->exitGoal[0].coordinates[exitGoalIndex] - 
        (*this->pedCoordsPtr)[0].coordinates[pedIndex];

    xDistance = pow(xDistance, 2);


    FLOATING_NUMBER yDistance = this->exitGoal[1].coordinates[exitGoalIndex] -
        (*this->pedCoordsPtr)[1].coordinates[pedIndex];

    yDistance = pow(yDistance, 2);

    return (sqrt(xDistance + yDistance));
}

Dimensions CalmGoals::getPedExitGoal(int pedestrianIndex)
{
    return this->exitGoal[this->nearestExit[pedestrianIndex]];
}