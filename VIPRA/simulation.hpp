#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "rapidxml-1.13/rapidxml.hpp"
#include "input_data_loader.hpp"

class Simulation
{
    public:
        Simulation();
        Simulation(InputDataLoader*);
        void printPedestrianCoordinates();
        void printObstacleCoordinates();
        void run();

    private:
        std::vector<double> xPedestrianCoordinates;
        std::vector<double> yPedestrianCoordinates;

        std::vector<double> xObstacleCoordinates;
        std::vector<double> yObstacleCoordinates;

};

#endif
