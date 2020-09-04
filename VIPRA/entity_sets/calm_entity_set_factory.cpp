#include "calm_entity_set_factory.hpp"
		
void CalmEntitySetFactory::populatePedestrianSet(
    ENTITY_SET inputData, PedestrianSet* calmPedSet)
{

	std::vector<Dimensions> pedCoords;
	std::vector<Dimensions> goalCoords;
	std::vector<Dimensions> velocities;

	int numPeds = inputData.size();

	for(int i = 0; i < numPeds; ++i)
    {
        pedCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(inputData[i]["x"]), 
                    (FLOATING_NUMBER) std::stod(inputData[i]["y"])
                }
            }
        );
		
		goalCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(inputData[i]["goal_x"]), 
                    (FLOATING_NUMBER) std::stod(inputData[i]["goal_y"])
                }
            }
        );

		velocities.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(inputData[i]["velocity_x"]), 
                    (FLOATING_NUMBER) std::stod(inputData[i]["velocity_y"])
                }
            }
        );
    }

	calmPedSet->setPedestrianCoordinates(pedCoords);
	calmPedSet->setGoalCoordinates(goalCoords);
	calmPedSet->setVelocities(velocities);
	dynamic_cast<CalmPedestrianSet*>(calmPedSet)->setMasses(
        vectorStringToDouble(accumulateAttribute("mass", inputData)));
	dynamic_cast<CalmPedestrianSet*>(calmPedSet)->setReactionTimes(
        vectorStringToDouble(accumulateAttribute("reaction_time", inputData)));
    calmPedSet->setSpeeds(
        vectorStringToDouble(accumulateAttribute("speed", inputData)));
	dynamic_cast<CalmPedestrianSet*>(calmPedSet)->setDesiredSpeeds(
        vectorStringToDouble(accumulateAttribute("desired_speed", inputData)));
	dynamic_cast<CalmPedestrianSet*>(calmPedSet)->setPropulsionForces(
        vectorStringToDouble(accumulateAttribute("propulsion_force", inputData)));
	dynamic_cast<CalmPedestrianSet*>(calmPedSet)->setRepulsionForces(
        vectorStringToDouble(accumulateAttribute("repulsion_force", inputData)));
	calmPedSet->setNumPedestrians(numPeds);

	std::vector<FLOATING_NUMBER> floatNearestNeighbors = vectorStringToDouble(
        accumulateAttribute("nearest_neighbor", inputData));
	std::vector<int> intNearestNeighbors(
		floatNearestNeighbors.begin(), floatNearestNeighbors.end());
    std::vector<std::pair<std::string, int>> nearestNeighbors;
    
    for(long unsigned int i = 0; i < intNearestNeighbors.size(); ++i)
    {
        nearestNeighbors.push_back(std::make_pair("P", intNearestNeighbors[i]));
    }
	
	dynamic_cast<CalmPedestrianSet*>(calmPedSet)->setNearestNeighbors(nearestNeighbors);
}

void CalmEntitySetFactory::populateObstacleSet(ENTITY_SET inputData, ObstacleSet* obstacleSet)
{
	std::vector<Dimensions> obsCoords;
	
	int numObs = inputData.size();

	for(int i = 0; i < numObs; ++i)
    {
        obsCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(inputData[i]["x"]), 
                    (FLOATING_NUMBER) std::stod(inputData[i]["y"])
                }
            }
        );
	}

	obstacleSet->setObstacleCoordinates(obsCoords);
	obstacleSet->setNumObstacles(numObs);
}

void CalmEntitySetFactory::populateSimulationParams(
    ENTITY_SET inputData, SIM_PARAMS* simulationParams)
{

    for(long unsigned int i = 0; i < inputData.size(); ++i)
    {
        if(inputData[i].find("luggage") != inputData[i].end())
        {
	        (*simulationParams)["luggage"] = 
                (FLOATING_NUMBER) std::stod(inputData[i]["luggage"]);
        }
        else if(inputData[i].find("exit_door_x") != inputData[i].end())
        {
            (*simulationParams)["exit_door_x"] = 
                (FLOATING_NUMBER) std::stod(inputData[i]["exit_door_x"]);
        }
        else if(inputData[i].find("exit_door_y") != inputData[i].end())
        {
            (*simulationParams)["exit_door_y"] =
                (FLOATING_NUMBER) std::stod(inputData[i]["exit_door_y"]);
        }
        else if(inputData[i].find("time_step") != inputData[i].end())
        {
			(*simulationParams)["time_step"] = 
                (FLOATING_NUMBER) std::stod(inputData[i]["time_step"]);
        }
        else if(inputData[i].find("aligning_stop_threshold") 
                != inputData[i].end())
        {
	        (*simulationParams)["aligning_stop_threshold"] = 
		        (FLOATING_NUMBER) std::stod(
                    inputData[i]["aligning_stop_threshold"]);
        }
        else if(inputData[i].find("toward_aisle_stop_threshold") 
                != inputData[i].end())
        {
	        (*simulationParams)["toward_aisle_stop_threshold"] = 
		        (FLOATING_NUMBER) std::stod(
                    inputData[i]["toward_aisle_stop_threshold"]);
        }
        else if(inputData[i].find("in_aisle_stop_threshold") 
                != inputData[i].end())
        {
            (*simulationParams)["in_aisle_stop_threshold"] = 
		        (FLOATING_NUMBER) std::stod(
                    inputData[i]["in_aisle_stop_threshold"]);
        }
    }
}

std::vector<std::string> CalmEntitySetFactory::accumulateAttribute(
    std::string attributeName, ENTITY_SET inputData)
{
    std::vector<std::string> attributes;

    for(long unsigned int i = 0; i < inputData.size(); ++i)
    {
        attributes.push_back(inputData[i][attributeName]);
    }

    return attributes;
}

std::vector<FLOATING_NUMBER> CalmEntitySetFactory::vectorStringToDouble(
    std::vector<std::string> stringVec)
{
    std::vector<FLOATING_NUMBER> floatVec;

    for(long unsigned int i = 0; i < stringVec.size(); ++i)
    {
        floatVec.push_back(std::stod(stringVec[i]));
    }

    return floatVec;
}

