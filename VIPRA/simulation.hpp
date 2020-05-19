#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml.hpp"




class Simulation
{
    public:
        Simulation();
        void read_coordinates_file(std::string);

    private:
        std::vector<int> x_coordinates;
        std::vector<int> y_coordinates;

};

#endif
