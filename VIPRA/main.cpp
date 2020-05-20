#include "simulation.hpp"
#include "xmlreader.hpp"
#include <iostream>

int main()
{
    XMLReader xmlReader("coordinates.xml");
    xmlReader.readData();

    Simulation simulation(&xmlReader);

    simulation.printPassengerData();
    simulation.printObstacleData();

    return 0;
}
