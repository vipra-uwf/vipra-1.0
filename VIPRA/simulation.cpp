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


    // this->pedestrianDynamicsModel->precompute();


    // int i = 0; 

    // while(i < 10)
    // {
    //     this->outputDataWriter->writeFloatData("x", i);
    //     this->outputDataWriter->writeFloatData("y", -i);
    //     i++;
    // }


    //TODO this will be removed once our debugger segfault is resolved
    // printDataDELETETHIS();

    this->outputDataWriter->writeData(this->pedestrianDynamicsModel->getData());
}


void Simulation::printDataDELETETHIS()
{
    Data* data = this->pedestrianDynamicsModel->getData();

    std::cout << "Pedestrians: " << std::endl; 

    for(long long unsigned int i = 0; i < (data->getPedestrianSet()->getXCoordinates()->size()); i++)
    {
        std::cout << "[" << (*data->getPedestrianSet()->getXCoordinates())[i] << ", ";
        std::cout << (*data->getPedestrianSet()->getYCoordinates())[i] << "] ";
        std::cout << (*data->getPedestrianSet()->getTypes())[i] << std::endl;
    }

    std::cout <<"\nObstacles: " << std::endl;
   
    for(long long unsigned int i = 0; i < (data->getObstacleSet()->getXCoordinates()->size()); i++)
    {
        std::cout << "[" << (*data->getObstacleSet()->getXCoordinates())[i] << ", ";
        std::cout << (*data->getObstacleSet()->getYCoordinates())[i] << "] " << std::endl;
    }
}
