#include "simulation.hpp"


Simulation::Simulation(Goals& goals,
                        PedestrianSet& pedestrianSet,
                        ObstacleSet& obstacleSet,
                        PedestrianDynamicsModel& pedestrianDynamicsModel,
                        HumanBehaviorModel& humanBehaviorModel,
                        SimulationOutputHandler& simulationOutputHandler)
{
    this->goals = goals;
    this->pedestrianSet = pedestrianSet;
    this->obstacleSet = obstacleSet;
    this->pedestrianDynamicsModel = pedestrianDynamicsModel;
    this->humanBehaviorModel = humanBehaviorModel;
    this->simulationOutputHandler = simulationOutputHandler;
}

void Simulation::configure(const CONFIG_MAP &config) {
    this->timestep = 0;
    this->timestep_size = std::stof(config.at("time_step_size"));
}

int Simulation::getTimestep() const {
    return this->timestep;
}

void Simulation::run() {

    while(this->goals.isSimulationGoalMet()) {
        //create ProposedState
        //Create ProposedStateDerivative (Naming can be changed)

        //Call PolicyModel
        //TODO: humanBehaviorModel should take in type State
        this->humanBehaviorModel.update(this->timestep);
        //Set flags to indicate if human behavior has effected state of pedestrian
        //Update both States

        //TODO: pedestrianDynamicsModel should return type State
        this->pedestrianDynamicsModel.update(this->timestep);

        //TODO: call pedestrianSet::updateState

        if(this->simulationOutputHandler.isOutputCriterionMet()) {
            this->simulationOutputHandler.writeToDocument();
        }

        //Call update goals on goals to update current goals on pedestrians
    }
    
}