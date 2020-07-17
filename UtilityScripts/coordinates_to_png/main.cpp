
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include "../../VIPRA/readers/xml_reader.hpp"
#include <iostream>

int main() {
    // g++ main.cpp ../../VIPRA/readers/xml_reader.cpp ../../VIPRA/simulation/data.cpp ../../VIPRA/entity_sets/obstacle_set.cpp -I/usr/include/python3.8 -lpython3.8

    XMLReader xmlReader;

    xmlReader.extractFileData("../../VIPRA/output_data/pedestrian_trajectory.xml", "pedestrian-set", "pedestrian");
    std::vector<FLOATING_NUMBER> trajectorySetX = xmlReader.getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> trajectorySetY = xmlReader.getFloatDataSet("y");

    xmlReader.extractFileData("../../VIPRA/input_data/a320_144_obstacles.xml", "obstacle-set", "obstacle");
    std::vector<FLOATING_NUMBER> obstacleX = xmlReader.getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> obstacleY = xmlReader.getFloatDataSet("y");

    int i = 0;
    int numPedestrians = 144;
    int numberOfSnapshots = trajectorySetX.size() / numPedestrians;

    while(i < numberOfSnapshots)
    {
        std::cout << "Displaying trajectory snapshot: " << i << std::endl;

        auto firstX = trajectorySetX.begin();
        auto firstY = trajectorySetY.begin();  

        std::vector<FLOATING_NUMBER> pedestrianX(firstX + (i * 144), firstX + ((i + 1) * 144));
        std::vector<FLOATING_NUMBER> pedestrianY(firstY + (i * 144), firstY + ((i + 1) * 144));

        std::cout << pedestrianX.size() << " " << pedestrianY.size() << std::endl;

        plt::clf();
        plt::xlim(-30, 30);
        plt::ylim(-30, 30); 
        plt::plot(pedestrianX, pedestrianY, "r.");
        plt::scatter(obstacleX, obstacleY, 1);

        plt::pause(1);
        i++;

    }

    // plt::pause(2);
    //plt::save("output.png");
    // plt::show();
}


