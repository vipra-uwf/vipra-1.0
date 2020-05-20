#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(InputDataLoader* reader)
{
    this->passengerCoordinates = reader->getPassengerCoordinates();
    this->obstacleCoordinates = reader->getObstacleCoordinates();
}


//pedestrian dynamics model
    //input to model - pedestrians, layout, goal for each pedestrian
    //how each pedestrian will move
    //output - positions of the pedestrians, velocity, additional movement characteristics
//human behavior model
//policy
//ODE solver
void Simulation::run()
{
    //until goal is met
        //on pedestrian dynamics model, do precompute
        //on pedestrian dynamics model, do update
}

void Simulation::printPassengerData()
{
    for(int i = 0; i < this->passengerCoordinates.size(); ++i)
    {
        std::cout << "Passenger " << i + 1 << " [" << this->passengerCoordinates[i].first << ", " 
        << this->passengerCoordinates[i].second << "]" << std::endl;
    }
}

void Simulation::printObstacleData()
{
    for(int i = 0; i < this->obstacleCoordinates.size(); ++i)
    {
        std::cout << "Obstacle " << i + 1 << " [" << this->obstacleCoordinates[i].first << ", "
        << this->obstacleCoordinates[i].second << "]" << std::endl;
    }
}
