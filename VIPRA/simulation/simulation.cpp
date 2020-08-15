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
    
    // will become while(goalIsNotMet) -- alex
    while(this->timestep < 5000)
    {
        if(simulationOutputHandler->isOutputCriterionMet())
        {
            simulationOutputHandler->writeData();
        }

        //150 is arbitrary, use whatever ms is needed
        clock.addSimulationTimeMs(150);
        this->timestep++;
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



void Simulation::printDataDELETETHIS()
{
    Data* data = this->pedestrianDynamicsModel->getData();
    CalmPedestrianSet* calmPedSet = dynamic_cast<
        CalmPedestrianSet*>(data->getPedestrianSet()); 
	
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
			<< " propulsion_force=" << calmPedSet->getPropulsionForces()->at(i)
			<< " repulsion_force=" << calmPedSet->getRepulsionForces()->at(i)
			<< " nearest_neighbor=" << calmPedSet->getNearestNeighbors()->at(i).second
            << " nearest_neighbor_originset=" << calmPedSet->getNearestNeighbors()->at(i).first
			<< " speed=" << calmPedSet->getSpeeds()->at(i)

			<< std::endl;
	}

   /* 
	for(auto x: *data->getSimulationParams())
	{
		std::cout << x.first << " " << x.second << std::endl;
	}

    std::cout <<"\n\nObstacles: " << std::endl;

    for(int i = 0; i < (data->getObstacleSet()->getNumObstacles()); i++)
    {
        std::cout << "[" << (data->getObstacleSet()->
        getObstacleCoordinates()->at(i)).coordinates[0] << ", ";
        std::cout << (data->getObstacleSet()->
        getObstacleCoordinates()->at(1)).coordinates[1] << "],  ";
    }

    */
}

void Simulation::testGoalClassDELETETHIS()
{
    Goals* goal = this->pedestrianDynamicsModel->getGoals();
    Data* data = this->pedestrianDynamicsModel->getData();

    //goal->setData(data);
    //goal->addExitGoal(data->getSimulationParams());

    //goal->calculateNearestExit();

    //goal->determinePedestrianGoals();

    for(int i = 0; i < 5/*data->getPedestrianSet()->getNumPedestrians()*/; ++i)
    {
        std::cout << "ped: " << i << " goal x:" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[0];
        std::cout << " goal y:" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[1] << std::endl;
    }

    data->getPedestrianSet()->setPedestrianCoordinates
        (*data->getPedestrianSet()->getGoalCoordinates());
    goal->determinePedestrianGoals();

    std::cout << "\n\nGoals after first goal reached: \n";

    for(int i = 0; i < 5/*data->getPedestrianSet()->getNumPedestrians()*/; ++i)
    {
        std::cout << "ped: " << i << " goal x:" <<data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[0];
        std::cout << " goal y:" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[1] << std::endl;
    }

    data->getPedestrianSet()->setPedestrianCoordinates
        (*data->getPedestrianSet()->getGoalCoordinates());
    goal->determinePedestrianGoals();

    std::cout << "\n\nGoals after second goal reached: \n";

    for(int i = 0; i < 5/*data->getPedestrianSet()->getNumPedestrians()*/; ++i)
    {
        std::cout << "ped: " << i << " goal x:" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[0];
        std::cout << " goal y:" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[1] << std::endl;
    }

    data->getPedestrianSet()->setPedestrianCoordinates
        (*data->getPedestrianSet()->getGoalCoordinates());

    std::cout << "\n\nGoals met, test removal\n";
    goal->determinePedestrianGoals();



    //goal->removeExitGoal(0); //uncomment to test
    //goal->clearGoals(); //uncomment to test

}
