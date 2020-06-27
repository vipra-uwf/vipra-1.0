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
    this->exitGoal.at(dimension).push_back(exitCoord);
}

void Goal::determinePedestrianGoals(Data* data)
{
    for (int i = 0; i < data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        
    }
}