#include "calm_entity_set_factory.hpp"
		
PedestrianSet CalmEntitySetFactory::createPedestrianSet(
    ENTITY_SET inputData)
{
	CalmPedestrianSet calmPedSet;

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

	calmPedSet.setPedestrianCoordinates(pedCoords);
	calmPedSet.setGoalCoordinates(goalCoords);
	calmPedSet.setVelocities(velocities);
	calmPedSet.setMasses(
        vectorStringToDouble(extractAttribute("mass", inputData)));
	calmPedSet.setReactionTimes(
        vectorStringToDouble(extractAttribute("reaction_time", inputData)));
    calmPedSet.setSpeeds(
        vectorStringToDouble(extractAttribute("speed", inputData)));
	calmPedSet.setDesiredSpeeds(
        vectorStringToDouble(extractAttribute("desired_speed", inputData)));
	calmPedSet.setPropulsionForces(
        vectorStringToDouble(extractAttribute("propulsion_force", inputData)));
	calmPedSet.setRepulsionForces(
        vectorStringToDouble(extractAttribute("repulsion_force", inputData)));
	calmPedSet.setNumPedestrians(numPeds);

	std::vector<FLOATING_NUMBER> floatNearestNeighbors = 
        vectorStringToDouble(extractAttribute("nearest_neighbor", inputData));
	
	std::vector<int> intNearestNeighbors(
		floatNearestNeighbors.begin(), floatNearestNeighbors.end());
	
	calmPedSet.setNearestNeighbors(intNearestNeighbors);

	return calmPedSet;	
}

ObstacleSet CalmEntitySetFactory::createObstacleSet(ENTITY_SET inputData)
{
	ObstacleSet obstacleSet;

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

	obstacleSet.setObstacleCoordinates(obsCoords);
	obstacleSet.setNumObstacles(numObs);

	return obstacleSet;
}

std::unordered_map<
	std::string, FLOATING_NUMBER> 
        CalmEntitySetFactory::createSimulationParamsSet(ENTITY_SET inputData)
{
	std::unordered_map<std::string, FLOATING_NUMBER> simulationParams;

    for(long unsigned int i = 0; i < inputData.size(); ++i)
    {
        if(inputData[i].find("luggage") != inputData[i].end())
        {
	        simulationParams["luggage"] = 
                (FLOATING_NUMBER) std::stod(inputData[i]["luggage"]);
        }
        else if(inputData[i].find("exit_door_x") != inputData[i].end())
        {
            simulationParams["exit_door_x"] = 
                (FLOATING_NUMBER) std::stod(inputData[i]["exit_door_x"]);
        }
        else if(inputData[i].find("exit_door_y") != inputData[i].end())
        {
            simulationParams["exit_door_y"] =
                (FLOATING_NUMBER) std::stod(inputData[i]["exit_door_y"]);
        }
        else if(inputData[i].find("time_step") != inputData[i].end())
        {
			simulationParams["time_step"] = 
                (FLOATING_NUMBER) std::stod(inputData[i]["time_step"]);
        }
        else if(inputData[i].find("aligning_stop_threshold") 
                != inputData[i].end())
        {
	        simulationParams["aligning_stop_threshold"] = 
		        (FLOATING_NUMBER) std::stod(
                    inputData[i]["aligning_stop_threshold"]);
        }
        else if(inputData[i].find("toward_aisle_stop_threshold") 
                != inputData[i].end())
        {
	        simulationParams["toward_aisle_stop_threshold"] = 
		        (FLOATING_NUMBER) std::stod(
                    inputData[i]["toward_aisle_stop_threshold"]);
        }
        else if(inputData[i].find("in_aisle_stop_threshold") 
                != inputData[i].end())
        {
            simulationParams["in_aisle_stop_threshold"] = 
		        (FLOATING_NUMBER) std::stod(
                    inputData[i]["in_aisle_stop_threshold"]);
        }
    }
	
    return simulationParams;
}


std::vector<std::string> CalmEntitySetFactory::extractAttribute(
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

