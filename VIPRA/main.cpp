#include "simulation.hpp"
#include "xmlreader.hpp"
#include "calm_pedestrian_model.hpp"
#include <iostream>

int main()
{
    Data data;

    XMLReader xmlReader("coordinates.xml");
    xmlReader.readData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    
    Simulation simulation(&calmModel);

    return 0;
}
