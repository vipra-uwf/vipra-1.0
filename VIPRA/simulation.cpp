#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(ReaderInterface* reader)
{
    this->passengerTypes = reader->getPassengerTypes();
    this->passengerCoordinates = reader->getPassengerCoordinates();
    this->obstacleCoordinates = reader->getObstacleCoordinates();
}

void Simulation::printPassengerData()
{
    for(int i = 0; i < this->passengerCoordinates.size(); ++i)
    {
        std::cout << "Passenger " << i + 1 << " (" << this->passengerTypes[i] << ") ["
        << this->passengerCoordinates[i].first << ", " << this->passengerCoordinates[i].second << "]" << std::endl;
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
