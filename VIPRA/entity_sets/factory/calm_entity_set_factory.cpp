#include "calm_entity_set_factory.hpp"

void CalmEntitySetFactory::configure(CONFIG_MAP* configMap)
{

}

void CalmEntitySetFactory::populatePedestrianSet(
    ENTITY_SET inputData, PedestrianSet* calmPedestrianSet)
{

	std::vector<Dimensions> pedestrianCoordinates;
	std::vector<Dimensions> goalCoords;
	std::vector<Dimensions> velocities;

	int numPeds = inputData.size();

	for(int i = 0; i < numPeds; ++i)
    {
        pedestrianCoordinates.push_back(
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

	calmPedestrianSet->setPedestrianCoordinates(pedestrianCoordinates);
	calmPedestrianSet->setGoalCoordinates(goalCoords);
	calmPedestrianSet->setVelocities(velocities);
	dynamic_cast<CalmPedestrianSet*>(calmPedestrianSet)->setMasses(
        vectorStringToDouble(accumulateAttribute("mass", inputData)));
	dynamic_cast<CalmPedestrianSet*>(calmPedestrianSet)->setReactionTimes(
        vectorStringToDouble(accumulateAttribute("reaction_time", inputData)));
    calmPedestrianSet->setSpeeds(
        vectorStringToDouble(accumulateAttribute("speed", inputData)));
	dynamic_cast<CalmPedestrianSet*>(calmPedestrianSet)->setDesiredSpeeds(
        vectorStringToDouble(
            accumulateAttribute("desired_speed", inputData)));
	calmPedestrianSet->setNumPedestrians(numPeds);

	std::vector<FLOATING_NUMBER> floatNearestNeighbors = vectorStringToDouble(
        accumulateAttribute("nearest_neighbor", inputData));
	std::vector<int> intNearestNeighbors(
		floatNearestNeighbors.begin(), floatNearestNeighbors.end());

    std::vector<std::pair<std::string, int>> nearestNeighbors;
    std::vector<MovementDefinitions> startingMovement;
    std::vector<Dimensions> startingPropulsiveForces;
    std::vector<FLOATING_NUMBER> shoulderLengths;

    FLOATING_NUMBER startingShoulderLength = .1;

    for(long unsigned int i = 0; i < intNearestNeighbors.size(); ++i)
    {
        nearestNeighbors.push_back(std::make_pair("P", intNearestNeighbors[i]));
    }

    for(int i = 0; i < numPeds; ++i)
    {
        startingMovement.push_back(MovementDefinitions::PED_DYNAM);
    }

    for(int i = 0; i < numPeds; ++i)
    {
      shoulderLengths.push_back(startingShoulderLength);
    }

    for(int i = 0; i < numPeds; ++i)
    {
        startingPropulsiveForces.push_back(
            Dimensions
                    {
                        std::vector<FLOATING_NUMBER>
                        {
                            0,
                            0
                        }
                    }
        );
    }

    dynamic_cast<CalmPedestrianSet*>(calmPedestrianSet)->
        setNearestNeighbors(nearestNeighbors);
    dynamic_cast<CalmPedestrianSet*>(calmPedestrianSet)->
        setMovementStates(startingMovement);
    dynamic_cast<CalmPedestrianSet*>(calmPedestrianSet)->
        setShoulderLengths(shoulderLengths);
}

void CalmEntitySetFactory::populateObstacleSet(
    ENTITY_SET inputData, ObstacleSet* obstacleSet)
{
	std::vector<Dimensions> obstacleCoordinates;

	int numObstacles = inputData.size();

	for(int i = 0; i < numObstacles; ++i)
    {
        obstacleCoordinates.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(inputData[i]["x"]),
                    (FLOATING_NUMBER) std::stod(inputData[i]["y"])
                }
            }
        );
	}

	obstacleSet->setObstacleCoordinates(obstacleCoordinates);
	obstacleSet->setNumObstacles(numObstacles);
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
        else if(inputData[i].find("time_step_size") != inputData[i].end())
        {
			(*simulationParams)["time_step_size"] =
                (FLOATING_NUMBER) std::stod(inputData[i]["time_step_size"]);
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
