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

   /* xmlReader.openFile("pedestrianCoordinates.xml");
    xmlReader.setRootNodeName("pedestrian-set");
    xmlReader.setParseNodeName("pedestrian");
    xmlReader.writeData(&data);*/

    //only one or the other works right now

    xmlReader.openFile("obstacleCoordinates.xml");
    xmlReader.setRootNodeName("obstacle-set");
    xmlReader.setParseNodeName("obstacle");
    xmlReader.writeData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    
    Simulation simulation(&calmModel);

    return 0;
}
