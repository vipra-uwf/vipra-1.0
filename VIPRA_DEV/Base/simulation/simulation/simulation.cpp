#include "simulation.hpp"


Simulation::Simulation()
{

}

// Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel, HumanBehaviorModel *humanBehaviorModel)
// {
//     this->pedestrianDynamicsModel = pedestrianDynamicsModel;
//     this->humanBehaviorModel = humanBehaviorModel;
// }

void Simulation::configure(CONFIG_MAP* config){
    this->timestep = std::stoi(config->at("time_step"));
    this->timestep = std::stoi(config->at("time_step_size"));
}

void Simulation::setPedestrianModel(PedestrianDynamicsModel* pedestrianModel){
    this->pedestrianDynamicsModel = pedestrianModel;
}

void Simulation::setHumanBehaviorModel(HumanBehaviorModel* behaviorModel){
    this->humanBehaviorModel = behaviorModel;
}


void Simulation::setData(Data* data)
 {
    this->data = data;
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
    this->humanBehaviorModel->initialize();

    int i = 0; //delete this just for testing
    // std::cout << "Adding " << this->timestep_size << " msec to the simulation." << std::endl;

    while(!this->pedestrianDynamicsModel->getGoals()->isSimulationGoalMet())
    {

        if(simulationOutputHandler->isOutputCriterionMet())
        {
            simulationOutputHandler->writeToDocument();
        }


        clock.addSimulationTimeMs(this->timestep_size);

        this->humanBehaviorModel->update(this->timestep_size);
        this->pedestrianDynamicsModel->update(this->timestep_size);
        // this->policyModel->update(this->timestep_size); // Reserved for future use

        this->timestep++;
        ++i;
        this->pedestrianDynamicsModel->precompute();
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

PedestrianDynamicsModel* Simulation::getPedestrianDynamicsModel()
{
    return this->pedestrianDynamicsModel;
}
