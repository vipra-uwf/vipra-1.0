#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel)
{
    this->pedestrianDynamicsModel = pedestrianDynamicsModel;
}

void Simulation::setData(Data* data)
 {
    this->data = data;
 }

 void Simulation::initialize()
 {
    SIM_PARAMS* simParams = data->getSimulationParams();
    this->timestep = (*simParams)["time_step"];
    this->timestep_size = (*simParams)["time_step_size"];
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
    printDataDELETETHIS();
   
    while( i < 6000)//!this->pedestrianDynamicsModel->getGoals()->isSimulationGoalMet())
    {

        if(simulationOutputHandler->isOutputCriterionMet())
        {
            simulationOutputHandler->writeToDocument();
        }
        
        
        clock.addSimulationTimeMs(this->timestep_size);
        this->pedestrianDynamicsModel->update(this->timestep_size);

        this->timestep++;
        ++i;
        this->pedestrianDynamicsModel->precompute();
    }

    // TODO this will be removed once our debugger segfault is resolved
     printDataDELETETHIS();
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

void Simulation::printDataDELETETHIS()
{
    Data* data = this->pedestrianDynamicsModel->getData();
    CalmPedestrianSet* calmPedSet = dynamic_cast<
        CalmPedestrianSet*>(data->getPedestrianSet()); 

    MovementDefinitions state;
	
    std::cout << "Pedestrians: " << std::endl; 

	for(int i = 0; i < calmPedSet->getNumPedestrians(); ++i)
	{
		std::cout << "ped [" << i << "] ("  
            << calmPedSet->getPedestrianCoordinates()
                ->at(i).coordinates[0] << ", "
		    << calmPedSet->getPedestrianCoordinates()
                ->at(i).coordinates[1] << ")"

			<< " goal (" << calmPedSet->getGoalCoordinates()
                ->at(i).coordinates[0] << ", "
			<< calmPedSet->getGoalCoordinates()
                ->at(i).coordinates[1] << ")"
		
			<< " velocity (" << calmPedSet->getVelocities()
                ->at(i).coordinates[0] << ", "
			<< calmPedSet->getVelocities()
                ->at(i).coordinates[1] << ")"

			<< " mass=" << calmPedSet->getMasses()->at(i)
			<< " desired_speed=" << calmPedSet->getDesiredSpeeds()->at(i)
			<< " reaction_time=" << calmPedSet->getReactionTimes()->at(i)
			<< " propulsion_forcex=" << calmPedSet->getPropulsionForces()
                ->at(i).coordinates[0]
            << " propulsion_forcey=" << calmPedSet->getPropulsionForces()
                ->at(i).coordinates[1]
			<< " nearest_neighbor=" 
            << calmPedSet->getNearestNeighbors()->at(i).second
            << " nearest_neighbor_originset=" 
            << calmPedSet->getNearestNeighbors()->at(i).first
			<< " speed=" << calmPedSet->getSpeeds()->at(i)
            << " priority=" 
            << calmPedSet->getPriorities()->at(i)
            << " Move_state=";

            state = calmPedSet->getMovementStates()->at(i);
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
