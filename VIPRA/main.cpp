#include "simulation.hpp"
#include <iostream>

int main()
{
    Simulation simulation = Simulation();

    simulation.read_coordinates_file("coordinates.xml");
    simulation.print_passenger_data();
    simulation.print_obstacle_data();

    return 0;
}
