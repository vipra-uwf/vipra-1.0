//TODO: define the data object to hold the below information

//pedestrian locations
//layout
    //obstacles with coordinates
    //provide obstacles as geometric objects (points, lines, shapes)

#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <string>
#include <iostream>

#include "pedestrian.hpp"

//Refactor for PedestriansSet (class of arrays) and ObstaclesSet (class of arrays) to be separate
class Data
{
    public:
        Data();

        std::vector<double> getXPedestrianCoordinates();
        std::vector<double> getYPedestrianCoordinates();
        std::vector<double> getXObstacleCoordinates();
        std::vector<double> getYObstacleCoordinates();

        void setXPedestrianCoordinates(std::vector<double>);
        void setYPedestrianCoordinates(std::vector<double>);
        void setXObstacleCoordinates(std::vector<double>);
        void setYObstacleCoordinates(std::vector<double>);

        void pushCoordinateData(double, std::string, std::string);

        void pushXPedestrianCoordinate(double);
        void pushYPedestrianCoordinate(double);
        void pushXObstacleCoordinate(double);
        void pushYObstacleCoordinate(double);

        void printPedestrianCoordinates();
        void printObstacleCoordinates();

        void createPedestrians();

    private:
        std::vector<double> xPedestrianCoordinates;
        std::vector<double> yPedestrianCoordinates;
        std::vector<Pedestrian> pedestrians;

        std::vector<double> xObstacleCoordinates;
        std::vector<double> yObstacleCoordinates;
};

#endif
