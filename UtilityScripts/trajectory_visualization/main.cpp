#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
#include "../../VIPRA/readers/input_json_reader.hpp"
#include <iostream>

int main() {
    InputJSONReader inputJSONReader;
    CONFIG_MAP* pedestrianConfigMap = new CONFIG_MAP;
    ENTITY_SET pedInputFileData;
    CONFIG_MAP* obstacleConfigMap = new CONFIG_MAP;
    ENTITY_SET obsInputFileData;
    std::vector<FLOATING_NUMBER> trajectorySetX;
    std::vector<FLOATING_NUMBER> trajectorySetY;
    std::vector<FLOATING_NUMBER> obstacleX;
    std::vector<FLOATING_NUMBER> obstacleY;
    int i;
    int numPedestrians;
    int numberOfSnapshots;

    pedestrianConfigMap->insert({"parentElementName", "pedestrian-set"});
    inputJSONReader.extractFileData(
        "../../VIPRA/output_data/pedestrian_trajectory.json",
        pedestrianConfigMap);
    pedInputFileData = inputJSONReader.getInputEntities();

    for(long unsigned int i = 0; i < pedInputFileData.size(); ++i)
    {
        trajectorySetX.push_back(
            (FLOATING_NUMBER) std::stod(pedInputFileData[i]["x"]));
        trajectorySetY.push_back(
            (FLOATING_NUMBER) std::stod(pedInputFileData[i]["y"]));
    }

    obstacleConfigMap->insert({"parentElementName", "obstacle-set"});
    inputJSONReader.extractFileData(
        "../../VIPRA/input_data/json/a320_144_obstacles.json", 
        obstacleConfigMap);
    obsInputFileData = inputJSONReader.getInputEntities();
    
    for(long unsigned int i = 0; i < obsInputFileData.size(); ++i)
    {
        obstacleX.push_back(
            (FLOATING_NUMBER) std::stod(obsInputFileData[i]["x"]));
        obstacleY.push_back(
            (FLOATING_NUMBER) std::stod(obsInputFileData[i]["y"]));
    }

    i = 0;
    numPedestrians = 144;
    numberOfSnapshots = trajectorySetX.size() / numPedestrians;

    plt::clf();
    plt::xlim(-5, 30);
    plt::ylim(-5, 20); 
    plt::scatter(obstacleX, obstacleY, 1);
    plt::pause(2);

    while(i < numberOfSnapshots)
    {
        std::cout << "Displaying trajectory snapshot: " << i << std::endl;

        auto firstX = trajectorySetX.begin();
        auto firstY = trajectorySetY.begin();  

        std::vector<FLOATING_NUMBER> pedestrianX(
            firstX + (i * 144), firstX + ((i + 1) * 144));
        std::vector<FLOATING_NUMBER> pedestrianY(
            firstY + (i * 144), firstY + ((i + 1) * 144));

        plt::clf();
        plt::xlim(-5, 30);
        plt::ylim(-5, 20); 
        plt::plot(pedestrianX, pedestrianY, "r.");
        plt::scatter(obstacleX, obstacleY, 1);

        plt::pause(.15);
        i++;
    }

    plt::pause(2);
    plt::save("output.png");
    plt::show();
}