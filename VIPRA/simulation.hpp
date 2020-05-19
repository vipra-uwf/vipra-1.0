#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "rapidxml-1.13/rapidxml.hpp"

class Simulation
{
    public:
        Simulation();
        void read_coordinates_file(std::string);
        void print_passenger_data();
        void print_obstacle_data();

    private:
        std::vector<std::string> passenger_types;
        std::vector<std::pair<double, double>> passenger_coordinates;
        std::vector<std::pair<double, double>> obstacle_coordinates;
};

#endif
