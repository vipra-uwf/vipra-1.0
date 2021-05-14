#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
#include "./visualization_readers/visualization_input_json_reader.hpp"
#include "../../VIPRA/readers/input_json_reader.hpp"
#include <iostream>

int main()
{
    VisualizationInputJSONReader visualizationInputJSONReader;
    InputJSONReader inputJSONReader;
    CONFIG_MAP *pedestrianConfigMap = new CONFIG_MAP;
    std::vector<ENTITY_SET> pedestrianInputFileData;
    CONFIG_MAP *obstacleConfigMap = new CONFIG_MAP;
    ENTITY_SET obstacleInputFileData;
    std::vector<std::vector<FLOATING_NUMBER>> pedestrianLocationsX;
    std::vector<std::vector<FLOATING_NUMBER>> pedestrianLocationsY;
    std::vector<FLOATING_NUMBER> currentTimestepSetX;
    std::vector<FLOATING_NUMBER> currentTimestepSetY;
    std::vector<FLOATING_NUMBER> obstacleLocationsX;
    std::vector<FLOATING_NUMBER> obstacleLocationsY;
    int numberOfSnapshots;

    pedestrianConfigMap->insert({"parentElementName", "pedestrian-set"});
    visualizationInputJSONReader.extractFileData(
        "../../VIPRA/output_data/pedestrian_trajectory.json",
        pedestrianConfigMap);
    pedestrianInputFileData = visualizationInputJSONReader.getInputEntities();

    for (long unsigned int i = 0; i < pedestrianInputFileData.size(); ++i)
    {
        for (long unsigned int j = 0; j < (pedestrianInputFileData[i].size() / 2); ++j)
        {
            currentTimestepSetX.push_back(
                (FLOATING_NUMBER)std::stod(pedestrianInputFileData[i][j]["x"]));
            currentTimestepSetY.push_back(
                (FLOATING_NUMBER)std::stod(pedestrianInputFileData[i][j]["y"]));
        }
        pedestrianLocationsX.push_back(currentTimestepSetX);
        pedestrianLocationsY.push_back(currentTimestepSetY);

        currentTimestepSetX.clear();
        currentTimestepSetY.clear();
    }

    obstacleConfigMap->insert({"parentElementName", "obstacle-set"});
    inputJSONReader.extractFileData(
        "../../VIPRA/input_data/json/a320_144_obstacles.json",
        obstacleConfigMap);
    obstacleInputFileData = inputJSONReader.getInputEntities();

    for(long unsigned int i = 0; i < obstacleInputFileData.size(); ++i)
    {
        obstacleLocationsX.push_back(
            (FLOATING_NUMBER) std::stod(obstacleInputFileData[i]["x"]));
        obstacleLocationsY.push_back(
            (FLOATING_NUMBER) std::stod(obstacleInputFileData[i]["y"]));
    }

    numberOfSnapshots = pedestrianLocationsX.size();

    plt::clf();
    plt::xlim(-5, 30);
    plt::ylim(-5, 20);
    plt::scatter(obstacleLocationsX, obstacleLocationsY, 1);
    plt::pause(2);

    for (int i = 0; i < numberOfSnapshots; i++)
    {        
        std::cout << "Displaying trajectory snapshot: " << i << std::endl;

        plt::clf();
        plt::xlim(-5, 30);
        plt::ylim(-5, 20);
        plt::plot(pedestrianLocationsX[i], pedestrianLocationsY[i], "r.");
        plt::scatter(obstacleLocationsX, obstacleLocationsY, 1);

        plt::pause(.15);
    }

    plt::pause(2);
    plt::save("output.png");
    plt::show();
}