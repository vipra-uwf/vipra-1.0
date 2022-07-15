#include "calm_entity_set_factory.hpp"

void CalmEntitySetFactory::configure(CONFIG_MAP* configMap)
{

}

void CalmEntitySetFactory::populatePedestrianSet(
    ENTITY_SET inputData, PedestrianSet* calmPedestrianSet)
{

    const size_t pedCount = inputData.size();
    calmPedestrianSet->initialize(pedCount);

    std::vector<Dimensions> pedestrianCoords;
    for(const auto& pedCoord : inputData){
        pedestrianCoords.push_back(
            Dimensions{
                {
                    std::stof(pedCoord.at("x")),
                    std::stof(pedCoord.at("y"))
                }
            }
        );
    }

    calmPedestrianSet->setPedestrianCoordinates(pedestrianCoords);
}

void CalmEntitySetFactory::populateObstacleSet(
    ENTITY_SET inputData, ObstacleSet* obstacleSet)
{
     // TODO NEXT Seg fault here -RG
    std::vector<Dimensions> exitsCoords;
    CONFIG_MAP params = inputData[0];
    for(int i = 0; i < params.size(); ++i){
        exitsCoords.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(params["x"]),
                    (FLOATING_NUMBER) std::stod(params["y"])
                }
            }
        );
    }

	std::vector<Dimensions> obstacleCoordinates;
    CONFIG_MAP obstacles = inputData[1];
	int numObstacles = obstacles.size();
	for(int i = 0; i < numObstacles; ++i)
    {
        obstacleCoordinates.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    (FLOATING_NUMBER) std::stod(obstacles["x"]),
                    (FLOATING_NUMBER) std::stod(obstacles["y"])
                }
            }
        );
	}

    obstacleSet->setExits(exitsCoords);
	obstacleSet->setObstacleCoordinates(obstacleCoordinates);
	obstacleSet->setNumObstacles(numObstacles);
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
