#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include "../../VIPRA/readers/input_xml_reader.hpp"
#include "../../VIPRA/readers/input_json_reader.hpp"
#include <iostream>

int main() {
    InputXMLReader inputXMLReader;
    CONFIG_MAP* pedestrianConfigMap = new CONFIG_MAP;

    pedestrianConfigMap->insert({"parentElementName", "pedestrian-set"});
    inputXMLReader.extractFileData(
        "../../VIPRA/output_data/pedestrian_trajectory.xml", 
        pedestrianConfigMap);

    ENTITY_SET pedInputFileData = inputXMLReader.getInputEntities();

    // InputJSONReader inputJSONReader;
    // CONFIG_MAP* pedestrianConfigMap = new CONFIG_MAP;

    // inputJSONReader.extractFileData(
    //     "../../VIPRA/output_data/pedestrian_trajectory.json",
    //     pedestrianConfigMap);
    // ENTITY_SET pedInputFileData = inputJSONReader.getInputEntities();

    std::vector<FLOATING_NUMBER> trajectorySetX;
    std::vector<FLOATING_NUMBER> trajectorySetY;

    for(long unsigned int i = 0; i < pedInputFileData.size(); ++i)
    {
        trajectorySetX.push_back(
            (FLOATING_NUMBER) std::stod(pedInputFileData[i]["x"]));
        trajectorySetY.push_back(
            (FLOATING_NUMBER) std::stod(pedInputFileData[i]["y"]));
    }

    CONFIG_MAP* obstacleConfigMap = new CONFIG_MAP;
    obstacleConfigMap->insert({"parentElementName", "obstacle-set"});
    
    inputXMLReader.extractFileData(
        "../../VIPRA/input_data/xml/a320_144_obstacles.xml", 
        obstacleConfigMap);

    // inputJSOReader.extractFileData(
    //     "../../VIPRA/input_data/json/a320_144_obstacles.json", 
    //     obstacleConfigMap);

    ENTITY_SET obsInputFileData = inputXMLReader.getInputEntities();

    std::vector<FLOATING_NUMBER> obstacleX;
    std::vector<FLOATING_NUMBER> obstacleY;
    
    for(long unsigned int i = 0; i < obsInputFileData.size(); ++i)
    {
        obstacleX.push_back(
            (FLOATING_NUMBER) std::stod(obsInputFileData[i]["x"]));
        obstacleY.push_back(
            (FLOATING_NUMBER) std::stod(obsInputFileData[i]["y"]));
    }

    int i = 0;
    int numPedestrians = 144;
    int numberOfSnapshots = trajectorySetX.size() / numPedestrians;

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


