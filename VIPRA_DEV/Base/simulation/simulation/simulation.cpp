#include "simulation.hpp"

Simulation::Simulation()
{

}

// Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel, HumanBehaviorModel *humanBehaviorModel)
// {
//     this->pedestrianDynamicsModel = pedestrianDynamicsModel;
//     this->humanBehaviorModel = humanBehaviorModel;
// }

void Simulation::configure(CONFIG_MAP* configMap){
    this->timestep = std::stoi((*configMap)["time_step"]);
    this->timestep_size = std::stof((*configMap)["time_step_size"]);
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
    //this->humanBehaviorModel->initialize();

    int i = 0; //delete this just for testing
    // std::cout << "Adding " << this->timestep_size << " msec to the simulation." << std::endl;
    while(!this->pedestrianDynamicsModel->getGoals()->isSimulationGoalMet())
    {

        if(simulationOutputHandler->isOutputCriterionMet())
        {
            simulationOutputHandler->writeToDocument();
        }


        clock.addSimulationTimeMs(this->timestep_size);

        //this->humanBehaviorModel->update(this->timestep_size);
        this->pedestrianDynamicsModel->update(this->timestep_size);
        // this->policyModel->update(this->timestep_size); // Reserved for future use

        this->timestep++;
        ++i;

        if(i % 1000 == 0){
            printDataDELETETHIS();
        }

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


void Simulation::printDataDELETETHIS()
{
    Data* data = this->pedestrianDynamicsModel->getData();
    CalmPedestrianSet* calmPedSet = dynamic_cast<CalmPedestrianSet*>(data->getPedestrianSet());

    MovementDefinitions state;

    std::cout << "Pedestrians: " << std::endl;

	for(int i = 0; i < calmPedSet->getNumPedestrians(); ++i)
	{
		std::cout << "ped [" << i << "] ("
            << calmPedSet->getPedestrianCoordinates()
                ->at(i)[0] << ", "
		    << calmPedSet->getPedestrianCoordinates()
                ->at(i)[1] << ")"
			<< " goal (" << calmPedSet->getGoalCoordinates()
                .at(i)[0] << ", "
			<< calmPedSet->getGoalCoordinates()
                .at(i)[1] << ")"

			<< " velocity (" << calmPedSet->getVelocities()
                .at(i)[0] << ", "
			<< calmPedSet->getVelocities()
                .at(i)[1] << ")"

			<< " mass=" << calmPedSet->getMasses().at(i)
			<< " desired_speed=" << calmPedSet->getDesiredSpeeds().at(i)
			<< " reaction_time=" << calmPedSet->getReactionTimes().at(i)
			<< " propulsion_forcex=" << calmPedSet->getPropulsionForces()
                .at(i)[0]
            << " propulsion_forcey=" << calmPedSet->getPropulsionForces()
                .at(i)[1]
			<< " nearest_neighbor="
            << calmPedSet->getNearestNeighbors().at(i).second
            << " nearest_neighbor_originset="
            << calmPedSet->getNearestNeighbors().at(i).first
			<< " speed=" << calmPedSet->getSpeeds().at(i)
            << " priority="
            << calmPedSet->getPriorities().at(i)
            << " Move_state=";
            state = calmPedSet->getMovementStates().at(i);
            switch(state)
            {
                case MovementDefinitions::PED_DYNAM : std::cout
                    << "PED_DYNAM"; break;
                case MovementDefinitions::HUMAN : std::cout << "HUMAN"; break;
                case MovementDefinitions::POLICY : std::cout << "POLICY"; break;
                case MovementDefinitions::STOP : std::cout << "STOP"; break;
            }

			std::cout << std::endl;
	}
}
