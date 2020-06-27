#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel)
{
    this->pedestrianDynamicsModel = pedestrianDynamicsModel;
}

void Simulation::setOutputDataWriter(OutputDataWriter* outputDataWriter)
{
    this->outputDataWriter = outputDataWriter;
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
    Clock clock;
    clock.start();
    clock.printRealStartTime();
    
    this->pedestrianDynamicsModel->precompute();

    int i = 0; 

    Data* data = this->pedestrianDynamicsModel->getData();

    // indicates what writing will be like for a single time step - Alex
    while(i < data->getPedestrianSet()->getNumPedestrians())
    {
        this->outputDataWriter->writeFloatData("x", i);
        this->outputDataWriter->writeFloatData("y", -i);
        i++;
        clock.addSimulationTimeMilliseconds(150);//150 is arbitrary, use whatever ms is needed
    }
    

    // TODO this will be removed once our debugger segfault is resolved
    printDataDELETETHIS();

    // this->outputDataWriter->writeData(this->pedestrianDynamicsModel->getData());
    clock.stop();
    clock.printRealEndTime();
    clock.printRealDuration();
    clock.printSimulationDuration();
}


void Simulation::printDataDELETETHIS()
{
    Data* data = this->pedestrianDynamicsModel->getData();

    std::cout << "Pedestrians: " << std::endl; 

    for(int i = 0; i < (data->getPedestrianSet()->getNumPedestrians()); i++)
    {
        std::cout
        << i 
        << " | coordinates = (" << (data->getPedestrianSet()->getPedestrianCoordinates()->at(0))[i] << ", " 
        << (data->getPedestrianSet()->getPedestrianCoordinates()->at(1))[i] << ")"
        << " | speed = " << (*data->getPedestrianSet()->getSpeeds())[i] 
        << " | mass = " << (*data->getPedestrianSet()->getMasses())[i] 
        << " | reaction_time = " << (*data->getPedestrianSet()->getReactionTimes())[i] 
        << " | desired_speed = " << (*data->getPedestrianSet()->getDesiredSpeeds())[i] 
        << " | propulsion_force = " << (*data->getPedestrianSet()->getPropulsionForces())[i] 
        << " | repulsion_force = " << (*data->getPedestrianSet()->getRepulsionForces())[i] 
        << " | nearest_neighbor = " << (*data->getPedestrianSet()->getNearestNeighbor())[i] 
        << std::endl;
    }

    std::cout <<"\n\nObstacles: " << std::endl;
   
    for(int i = 0; i < (data->getObstacleSet()->getNumObstacles()); i++)
    {
        std::cout << "[" << (data->getObstacleSet()->getObstacleCoordinates()->at(0))[i] << ", ";
        std::cout << (data->getObstacleSet()->getObstacleCoordinates()->at(1))[i] << "],  ";
    }
}
