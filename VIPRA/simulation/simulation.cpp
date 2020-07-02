#include "simulation.hpp"


Simulation::Simulation()
{
    this->timestep = 0;
}

Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel)
{
    this->pedestrianDynamicsModel = pedestrianDynamicsModel;
}

void Simulation::setOutputCriterionChecker(OutputCriterionChecker* outputCriterionChecker)
{
    this->outputCriterionChecker = outputCriterionChecker;
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


    // TODO .. this should probably be a field in the simulation -- Alex
    Clock clock;
    clock.start();
    clock.printRealStartTime();
    
    this->pedestrianDynamicsModel->precompute();

    while(this->timestep < 1000)
    {
        if(outputCriterionChecker->isOutputCriterionMet())
        {
            outputCriterionChecker->writeData();
        }

        clock.addSimulationTimeMilliseconds(150); //150 is arbitrary, use whatever ms is needed
        this->timestep++;
    }

    clock.stop();
    clock.printRealEndTime();
    clock.printRealDuration();
    clock.printSimulationDuration();
}

int* Simulation::getTimestep()
{
    return &this->timestep;
}
