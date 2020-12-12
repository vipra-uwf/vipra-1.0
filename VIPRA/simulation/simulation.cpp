#include "simulation.hpp"


Simulation::Simulation()
{
    this->timestep = 0;
}

Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel)
{
    this->timestep = 0;
    this->pedestrianDynamicsModel = pedestrianDynamicsModel;
}

void Simulation::setSimulationOutputHandler(
    SimulationOutputHandler* simulationOutputHandler)
{
    this->simulationOutputHandler = simulationOutputHandler;
}

/*
- pedestrian dynamics model
    - input to model - pedestrians, layout, goal for each pedestrian
        - goals will likely need to be defined as 
        a template class or function pointer
            - two goals - one for simulation, one for each pedestrian
    - how each pedestrian will move
    - output - positions of the pedestrians, velocity, 
    - additional movement characteristics
        - define an output format similar to our input format
- human behavior model
- policy
- ODE solver - look into boost ode solvers
*/
void Simulation::run()
{
    //until goal is met
        //on pedestrian dynamics model, do precompute
        //on pedestrian dynamics model, do update
    
    clock.start();
    clock.printRealStartTime();
    
    this->pedestrianDynamicsModel->precompute();

    int i = 0; //delete this just for testing
    
    while(i < 5000/*!this->pedestrianDynamicsModel->getGoals()->isSimulationGoalMet()*/)
    {

        if(simulationOutputHandler->isOutputCriterionMet())
        {
            simulationOutputHandler->writeToDocument();
        }
        
        //.01 is arbitrary, use whatever ms is needed
        clock.addSimulationTimeMs(.01);
        // this->pedestrianDynamicsModel->update(.01);

        this->timestep++;
        ++i;
        // this->pedestrianDynamicsModel->precompute();
    }

    // TODO this will be removed once our debugger segfault is resolved
    // printDataDELETETHIS();
    //testGoalClassDELETETHIS();

    clock.stop();
    clock.printRealEndTime();
    clock.printRealDuration();
    clock.printSimulationDuration();
}

int* Simulation::getTimestep()
{
    return &this->timestep;
}

PedestrianDynamicsModel* Simulation::getPedestrianDynamicsModel()
{
    return this->pedestrianDynamicsModel;
}


