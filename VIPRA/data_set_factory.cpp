#include "data_set_factory.hpp"
#include "dimensions.hpp"
#include "entity_sets/obstacle_set.hpp"
		
CalmPedestrianSet DataSetFactory::createCalmPedSet(std::unordered_map<
	std::string, std::vector<FLOATING_NUMBER>> inputData)
{
	CalmPedestrianSet calmPedSet;

	std::vector<Dimensions> pedCoords;
	std::vector<Dimensions> goalCoords;
	std::vector<Dimensions> velocities;
	std::vector<std::pair<std::string, int>> nearestNeighbors;

	int numPeds = inputData["x"].size();

	for(int i = 0; i < numPeds; ++i)
    {
        pedCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    inputData["x"][i], 
                    inputData["y"][i]
                }
            }
        );
		
		goalCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    inputData["goal_x"][i], 
                    inputData["goal_y"][i]
                }
            }
        );

		velocities.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    inputData["velocity_x"][i], 
                    inputData["velocity_y"][i]
                }
            }

        );

		nearestNeighbors.push_back(
			std::make_pair("P", inputData["nearest_neighbor"][i])
		);
    }

	calmPedSet.setPedestrianCoordinates(pedCoords);
	calmPedSet.setGoalCoordinates(goalCoords);
	calmPedSet.setVelocities(velocities);
	calmPedSet.setMasses(inputData["mass"]);
	calmPedSet.setReactionTimes(inputData["reaction_time"]);
    calmPedSet.setSpeeds(inputData["speed"]);
	calmPedSet.setDesiredSpeeds(inputData["desired_speed"]);
	calmPedSet.setPropulsionForces(inputData["propulsion_force"]);
	calmPedSet.setRepulsionForces(inputData["repulsion_force"]);
	calmPedSet.setNumPedestrians(numPeds);
	calmPedSet.setNearestNeighbors(nearestNeighbors);

	return calmPedSet;	
}

ObstacleSet DataSetFactory::createObstacleSet(
		std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> inputData)
{
	ObstacleSet obstacleSet;

	std::vector<Dimensions> obsCoords;
	
	int numObs = inputData["x"].size();

	for(int i = 0; i < numObs; ++i)
    {
        obsCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    inputData["x"][i], 
                    inputData["y"][i]
                }
            }
        );
	}

	obstacleSet.setObstacleCoordinates(obsCoords);
	obstacleSet.setNumObstacles(numObs);

	return obstacleSet;
}

std::unordered_map<
	std::string, FLOATING_NUMBER> DataSetFactory::createSimulationParamsSet(
			std::unordered_map<
				std::string, std::vector<FLOATING_NUMBER>> inputData)
{
	std::unordered_map<std::string, FLOATING_NUMBER> simulationParams;

	simulationParams["luggage"] = inputData["luggage"].at(0);
	simulationParams["exit_door_x"] = inputData["exit_door_x"].at(0);
	simulationParams["exit_door_y"] = inputData["exit_door_y"].at(0);
	simulationParams["time_step"] = inputData["time_step"].at(0);
	
	simulationParams["aligning_stop_threshold"] = 
		inputData["aligning_stop_threshold"].at(0);

	simulationParams["toward_aisle_stop_threshold"] = 
		inputData["toward_aisle_stop_threshold"].at(0);

	simulationParams["in_aisle_stop_threshold"] = 
		inputData["in_aisle_stop_threshold"].at(0);

	return simulationParams;
}

