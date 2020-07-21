#include "goal.hpp"

Goal::Goal()
{
}

void Goal::initializeGoals(Data* data)
{
    int dimensions = data->getPedestrianSet()->getNumDimensions();
    this->exitGoal.resize(dimensions);
}

void Goal::setExitGoal(int dimension, FLOATING_NUMBER exitCoord)
{
    // for(int i = 0; i < this->numPedestrians; ++i)
    // {
    //     for(int j = 0; i < this->numDimensions; ++j)
    //     {
    //         this->velocities[i].coordinates.push_back(0);
    //     }
    // }

    // this->exitGoal[dimension].push_back(exitCoord);

    // TODO .. need to initialize by using data getters
}

void Goal::determinePedestrianGoals(Data* data)
{
    for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        
    }
}