
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include "xml_reader.hpp"
#include <vector>

int main() {

    XMLReader xmlReader;
    xmlReader.extractFileData("a320_144_pedestrians.xml", "pedestrian-set", "pedestrian");
    std::vector<FLOATING_NUMBER> pedestrianX = xmlReader.getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> pedestrianY = xmlReader.getFloatDataSet("y");

    xmlReader.extractFileData("a320_144_obstacles.xml", "obstacle-set", "obstacle");
    std::vector<FLOATING_NUMBER> obstacleX = xmlReader.getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> obstacleY = xmlReader.getFloatDataSet("y");

    int i = 0;

    while(i < pedestrianX.size())
    {
        pedestrianX.at(i) = pedestrianX.at(i) * 1.1;
        pedestrianY.at(i) = pedestrianY.at(i) * 1.1;

        plt::clf();

        plt::xlim(-30, 30);
        plt::ylim(-30, 30); 
        plt::plot(pedestrianX, pedestrianY, "r.");
        plt::scatter(obstacleX, obstacleY, 1);

        plt::pause(0.01);
        i++;
    }

    // plt::xlim(-30, 30);
    // plt::ylim(-30, 30); 
    // plt::plot(pedestrianX, pedestrianY, "r.");
    // plt::scatter(obstacleX, obstacleY, 1);
    // plt::save("obstacles.png");
    // plt::show();
}

// g++ main.cpp xml_reader.cpp -I/usr/include/python3.8 -lpython3.8