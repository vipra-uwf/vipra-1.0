#include "simulation.hpp"
#include "xmlreader.hpp"
#include <iostream>

int main()
{
    XMLReader xmlReader("coordinates.xml");
    xmlReader.readData();

    //TODO: Remove xmlReader from simulation, send data instead
    Simulation simulation(&xmlReader);

    simulation.printPedestrianCoordinates();
    simulation.printObstacleCoordinates();

    return 0;
}
