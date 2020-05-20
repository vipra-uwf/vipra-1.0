//TODO: define the data object to hold the below information

//pedestrian locations
//layout
    //obstacles with coordinates
    //provide obstacles as geometric objects (points, lines, shapes)

#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <string>

class Data
{
    public:

       std::vector<double> getXPedestrianCoordinates();
       std::vector<double> getYPedestrianCoordinates();

       std::vector<double> getXObstacleCoordinates();
       std::vector<double> getYObstacleCoordinates(); 

       void printPedestrianCoordinates();
       void printObstacleCoordinates();

    private:
        std::vector<double> xPedestrianCoordinates;
        std::vector<double> yPedestrianCoordinates;

        std::vector<double> xObstacleCoordinates;
        std::vector<double> yObstacleCoordinates;
        
};

#endif