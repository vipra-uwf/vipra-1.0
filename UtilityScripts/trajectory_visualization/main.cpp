#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
#include "./visualization_readers/visualization_input_json_reader.hpp"
#include <iostream>

int main()
{
    //REFACTOR VARIABLE NAMES
    VisualizationInputJSONReader visualizationInputJSONReader;
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
    int numberOfPedestrians;
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

    // obstacleConfigMap->insert({"parentElementName", "obstacle-set"});
    // visualizationInputJSONReader.extractFileData(
    //     "../../VIPRA/input_data/json/a320_144_obstacles.json",
    //     obstacleConfigMap);
    // obstacleInputFileData = visualizationInputJSONReader.getInputEntities();

    // for(long unsigned int i = 0; i < obstacleInputFileData.size(); ++i)
    // {
    //     obstacleLocationsX.push_back(
    //         (FLOATING_NUMBER) std::stod(obstacleInputFileData[i]["x"]));
    //     obstacleLocationsY.push_back(
    //         (FLOATING_NUMBER) std::stod(obstacleInputFileData[i]["y"]));
    // }

    // i = 0;
    // numberOfPedestrians = 144;
    // numberOfSnapshots = pedestrianLocationsX.size() / numberOfPedestrians;

    // plt::clf();
    // plt::xlim(-5, 30);
    // plt::ylim(-5, 20);
    // plt::scatter(obstacleLocationsX, obstacleLocationsY, 1);
    // plt::pause(2);

    // while(i < numberOfSnapshots)
    // {
    //     std::cout << "Displaying trajectory snapshot: " << i << std::endl;

    //     auto firstX = pedestrianLocationsX.begin();
    //     auto firstY = pedestrianLocationsY.begin();

    //     std::vector<FLOATING_NUMBER> pedestrianX(
    //         firstX + (i * 144), firstX + ((i + 1) * 144));
    //     std::vector<FLOATING_NUMBER> pedestrianY(
    //         firstY + (i * 144), firstY + ((i + 1) * 144));

    //     plt::clf();
    //     plt::xlim(-5, 30);
    //     plt::ylim(-5, 20);
    //     plt::plot(pedestrianX, pedestrianY, "r.");
    //     plt::scatter(obstacleLocationsX, obstacleLocationsY, 1);

    //     plt::pause(.15);
    //     i++;
    // }

    // plt::pause(2);
    // plt::save("output.png");
    // plt::show();
}