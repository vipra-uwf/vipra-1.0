#include "data_set_factory.hpp"
		
CalmPedestrianSet DataSetFactory::createCalmPedSet(std::unordered_map<
	std::string, std::vector<FLOATING_NUMBER>> inputData)
{
	CalmPedestrianSet calmPedSet;

	std::vector<Dimensions> pedCoords;
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
    }

	calmPedSet.setPedestrianCoordinates(pedCoords);
	calmPedSet.setMasses(inputData["mass"]);
	calmPedSet.setReactionTimes(inputData["reaction_time"]);
	calmPedSet.setDesiredSpeeds(inputData["desired_speed"]);
	calmPedSet.setNumPedestrians(numPeds);
	
	//TODO refactor input files so this method isn't needed
	calmPedSet.initializeValues();

	return calmPedSet;	
}

