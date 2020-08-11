#include "data_set_factory.hpp"
#include "dimensions.hpp"
		
CalmPedestrianSet DataSetFactory::createCalmPedSet(std::unordered_map<
	std::string, std::vector<FLOATING_NUMBER>> inputData)
{
	CalmPedestrianSet calmPedSet;

	std::vector<Dimensions> pedCoords;
	std::vector<Dimensions> goalCoords;
	std::vector<Dimensions> velocities;

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

		/*
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
		*/
    }

	calmPedSet.setPedestrianCoordinates(pedCoords);
	calmPedSet.setMasses(inputData["mass"]);
	calmPedSet.setReactionTimes(inputData["reaction_time"]);
	calmPedSet.setDesiredSpeeds(inputData["desired_speed"]);
	calmPedSet.setNumPedestrians(numPeds);

	/*
	calmPedSet.setPropulsionForces(inputData["propulsion_force"]);
	calmPedSet.setRepulsionForces(inputData["repulsion_force"]);

	std::vector<FLOATING_NUMBER> floatNearestNeighbors;
	std::vector<int> intNearestNeighbors(
			floatNearestNeighbors.begin(), floatNearestNeighbors.end());
	calmPedSet.setNearestNeighbors(intNearestNeighbors);

	calmPedSet.setGoalCoordinates(goalCoords);
	calmPedSet.setVelocities(velocities);

	*/

	//TODO refactor input files so this method isn't needed
	calmPedSet.initializeValues();

	return calmPedSet;	
}

