#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(InputDataLoader* loader) 
{
    this->xPedestrianCoordinates = loader->getXPedestrianCoordinates();
    this->yPedestrianCoordinates = loader->getYPedestrianCoordinates();

    this->xObstacleCoordinates = loader->getXObstacleCoordinates();
    this->yObstacleCoordinates = loader->getYObstacleCoordinates();
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

void Simulation::printPedestrianCoordinates()
{
    for(int i = 0; i < this->xPedestrianCoordinates.size(); ++i)
    {
        std::cout << "Pedestrian " << i + 1 << " [" << this->xPedestrianCoordinates[i]<< ", " 
        << this->yPedestrianCoordinates[i] << "]" << std::endl;
    }
}

void Simulation::printObstacleCoordinates()
{
    for(int i = 0; i < this->xObstacleCoordinates.size(); ++i)
    {
        std::cout << "Obstacle " << i + 1 << " [" << this->xObstacleCoordinates[i] << ", "
        << this->yObstacleCoordinates[i] << "]" << std::endl;
    }
}
