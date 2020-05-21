#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel)
{
    this->pedestrianDynamicsModel = pedestrianDynamicsModel;

    std::cout << "\nInitializing simulation with coordinates: " << std::endl;
    this->pedestrianDynamicsModel->printPedestrianCoordinates();
    this->pedestrianDynamicsModel->printObstacleCoordinates();
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

