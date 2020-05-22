#include "simulation.hpp"
#include "xmlreader.hpp"
#include "calm_pedestrian_model.hpp"
#include <iostream>
#include <string>

//coordinates.xml no longer being used
//obstacleCoordinates.xml and pedestrianCoordinates are being used instead

int main()
{

    Data data;
    XMLReader xmlReader;
    //xmlReader.setData(&data);

    xmlReader.extractFileData("pedestrian_coordinates.xml", "pedestrian-set", "pedestrian");
    xmlReader.storeData(&data);

    xmlReader.extractFileData("obstacle_coordinates.xml", "obstacle-set", "obstacle");
    xmlReader.storeData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    
    Simulation simulation(&calmModel);

    return 0;
}
