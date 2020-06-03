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
    this->pedestrianDynamicsModel->precompute();

}

//pedestrian dynamics model
    //input to model - pedestrians, layout, goal for each pedestrian
        //goals will likely need to be defined as a template class or function pointer 
            //two goals - one for simulation, one for each pedestrian
    //how each pedestrian will move
    //output - positions of the pedestrians, velocity, additional movement characteristics
        //define an output format similar to our input format
//human behavior model
//policy
//ODE solver
//ODE solver - look into boost ode solvers
void Simulation::run()
{
    //until goal is met
        //on pedestrian dynamics model, do precompute
        //on pedestrian dynamics model, do update
}

