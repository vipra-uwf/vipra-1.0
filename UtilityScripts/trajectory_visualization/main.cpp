
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include "../../VIPRA/readers/input_xml_reader.hpp"
#include <iostream>

int main() {
    // g++ main.cpp ../../VIPRA/readers/input_xml_reader.cpp ../../VIPRA/simulation/data.cpp ../../VIPRA/entity_sets/obstacle_set.cpp -I/usr/include/python3.8 -lpython3.8

    InputXMLReader inputXMLReader;

    // inputXMLReader.extractFileData("../../VIPRA/output_data/pedestrian_trajectory.xml", "pedestrian-set", "pedestrian");
    inputXMLReader.extractFileData(
        "../../VIPRA/output_data/pedestrian_animfile.xml", 
        "pedestrian-set");

    std::unordered_map<
        std::string, std::vector<FLOATING_NUMBER>> pedInputFileData = 
			inputXMLReader.getInputEntities();

    std::vector<FLOATING_NUMBER> trajectorySetX = pedInputFileData["x"];
    std::vector<FLOATING_NUMBER> trajectorySetY = pedInputFileData["y"];

    inputXMLReader.extractFileData(
        "../../VIPRA/input_data/a320_144_obstacles.xml", 
        "obstacle-set");

    std::unordered_map<
		std::string, std::vector<FLOATING_NUMBER>> obsInputFileData = 
			inputXMLReader.getInputEntities();

    std::vector<FLOATING_NUMBER> obstacleX = obsInputFileData["x"];
    std::vector<FLOATING_NUMBER> obstacleY = obsInputFileData["y"];

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

        std::vector<FLOATING_NUMBER> pedestrianX(firstX + (i * 144), firstX + ((i + 1) * 144));
        std::vector<FLOATING_NUMBER> pedestrianY(firstY + (i * 144), firstY + ((i + 1) * 144));

        plt::clf();
        plt::xlim(-5, 30);
        plt::ylim(-5, 20); 
        plt::plot(pedestrianX, pedestrianY, "r.");
        plt::scatter(obstacleX, obstacleY, 1);

        plt::pause(.15);
        i++;
    }

    plt::pause(2);
    //plt::save("output.png");
    plt::show();
}


