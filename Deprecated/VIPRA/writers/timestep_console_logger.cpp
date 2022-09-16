#include "timestep_console_logger.hpp"

void TimestepConsoleLogger::configure(CONFIG_MAP *configMap)
{
    setOutputWritingFrequency(std::stoi((*configMap)["outputFrequency"]));
}

void TimestepConsoleLogger::setOutputDataWriter(
    OutputDataWriter *outputDataWriter)
{
    this->outputDataWriter = outputDataWriter;
}

void TimestepConsoleLogger::setPedestrianSet(PedestrianSet *pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

void TimestepConsoleLogger::setSimulation(Simulation *simulation)
{
    this->simulation = simulation;
    setTimestep(this->simulation->getTimestep());
}

bool TimestepConsoleLogger::isOutputCriterionMet()
{
    return *this->timestep % this->frequency == 0;
}

void TimestepConsoleLogger::writeToDocument() 
{
    printPedestrianData();
    // printAndTestGoals();
}

void TimestepConsoleLogger::setTimestep(int *timestep)
{
    this->timestep = timestep;
}

void TimestepConsoleLogger::setOutputWritingFrequency(int frequency)
{
    this->frequency = frequency;
}

void TimestepConsoleLogger::printPedestrianData()
{
    Data* data = this->simulation->getPedestrianDynamicsModel()->getData();
    CalmPedestrianSet* calmPedSet = dynamic_cast<
        CalmPedestrianSet*>(data->getPedestrianSet()); 

    MovementDefinitions state;
	
    std::cout << "\nTimestep: " << *this->timestep << std::endl; 

	for(int i = 0; i < calmPedSet->getNumPedestrians(); ++i)
	{
		std::cout
            << "pedestrian [" << i << "]"

            << " | coordinates (" << calmPedSet->getPedestrianCoordinates()
                ->at(i).coordinates[0] << ", "
		    << calmPedSet->getPedestrianCoordinates()
                ->at(i).coordinates[1] << ")"

			<< " | goal (" << calmPedSet->getGoalCoordinates()
                ->at(i).coordinates[0] << ", "
			<< calmPedSet->getGoalCoordinates()
                ->at(i).coordinates[1] << ")"
		
			<< " | velocity (" << calmPedSet->getVelocities()
                ->at(i).coordinates[0] << ", "
			<< calmPedSet->getVelocities()
                ->at(i).coordinates[1] << ")"

			 << " | mass = " << calmPedSet->getMasses()->at(i)
			 << " | desired_speed = " << calmPedSet->getDesiredSpeeds()->at(i)
			// << " | reaction_time = " << calmPedSet->getReactionTimes()->at(i)
			 << " | propulsion_force x = " << calmPedSet->getPropulsionForces()->at(i)
                .coordinates[0]
            << " | propulsion_force y = " << calmPedSet->getPropulsionForces()->at(i)
                .coordinates[1]
			// << " | repulsion_force = " << calmPedSet->getRepulsionForces()->at(i)
			 << " | nearest_neighbor = " 
             << calmPedSet->getNearestNeighbors()->at(i).second
             << " | nearest_neighbor_originset = " 
             << calmPedSet->getNearestNeighbors()->at(i).first
			 << " | speed = " << calmPedSet->getSpeeds()->at(i)
             << " | priority = " 
             << calmPedSet->getPriorities()->at(i)

            << " | move_state = ";

            state = calmPedSet->getMovementStates()->at(i);
            switch(state)
            {
                case MovementDefinitions::PED_DYNAM : std::cout << "PED_DYNAM"; break; 
                case MovementDefinitions::HUMAN : std::cout << "HUMAN"; break;
                case MovementDefinitions::POLICY : std::cout << "POLICY"; break;
                case MovementDefinitions::STOP : std::cout << "STOP"; break;
            }

			std::cout << std::endl;
	}
}

// TODO - This is broken -Liam
void TimestepConsoleLogger::printAndTestGoals()
{
    Goals* goal = this->simulation->getPedestrianDynamicsModel()->getGoals();
    Data* data = this->simulation->getPedestrianDynamicsModel()->getData();

    goal->setData(data);
    goal->addExitGoal(data->getSimulationParams());
    goal->calculateNearestExit();
    goal->determinePedestrianGoals();

    std::cout << "\nTimestep: " << *this->timestep << std::endl;

    for(int i = 0; data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        std::cout << "pedestrian [" << i << "]"
        << " | goal (" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[0]
        << ", " << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[1] 
        << ")" << std::endl;
    }

    data->getPedestrianSet()->setPedestrianCoordinates
        (*data->getPedestrianSet()->getGoalCoordinates());
    goal->determinePedestrianGoals();

    std::cout << "\n\nGoals after first goal reached: \n";

    for(int i = 0; data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        std::cout << "pedestrian [" << i << "]"
        << " | goal (" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[0]
        << ", " << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[1] 
        << ")" << std::endl;
    }

    data->getPedestrianSet()->setPedestrianCoordinates
        (*data->getPedestrianSet()->getGoalCoordinates());
    goal->determinePedestrianGoals();

    std::cout << "\n\nGoals after second goal reached: \n";

    for(int i = 0; data->getPedestrianSet()->getNumPedestrians(); ++i)
    {
        std::cout << "pedestrian [" << i << "]"
        << " | goal (" << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[0]
        << ", " << data->getPedestrianSet()->
            getGoalCoordinates()->at(i).coordinates[1] 
        << ")" << std::endl;
    }

    data->getPedestrianSet()->setPedestrianCoordinates
        (*data->getPedestrianSet()->getGoalCoordinates());

    std::cout << "\n\nGoals met, test removal\n";
    goal->determinePedestrianGoals();

    goal->removeExitGoal(0); //uncomment to test
    goal->clearGoals(); //uncomment to test
}