#include "simulation.hpp"
#include "xmlreader.hpp"
#include <iostream>

int main()
{
    Simulation simulation = Simulation();

    simulation.readCoordinatesFile("coordinates.xml");

    XMLReader xmlReader("coordinates.xml");
    xmlReader.readData();

    Simulation simulation2(&xmlReader);


    simulation.printPassengerData();
    simulation.printObstacleData();


    return 0;
}
