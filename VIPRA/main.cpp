#include "simulation.hpp"
#include <iostream>

int main()
{
    Simulation simulation = Simulation();

    simulation.read_coordinates_file("coordinates.xml");

    return 0;
}
