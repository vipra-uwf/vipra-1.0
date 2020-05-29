#include "simulation.hpp"
#include "xml_reader.hpp"
#include "calm_pedestrian_model.hpp"
#include <iostream>
#include <string>


//coordinates.xml was split into obstacleCoordinates.xml and pedestrianCoordinates

int main()
{

    Data data;
    XMLReader xmlReader;

    xmlReader.extractFileData("pedestrian_coordinates.xml", "pedestrian-set", "pedestrian");
    xmlReader.storeData(&data);

    xmlReader.extractFileData("obstacle_coordinates.xml", "obstacle-set", "obstacle");
    xmlReader.storeData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    
    Simulation simulation(&calmModel);

    return 0;
}
