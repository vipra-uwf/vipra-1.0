#include <iostream>
#include <string>

#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
// #include "xmlconverter.hpp"

int main()
{
    CalmPedestrianSet calmPedSet;
    Data data;
    data.setPedestrianSet(&calmPedSet);

    XMLReader xmlReader;
    xmlReader.storeData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);

    Simulation simulation(&calmModel);

    XMLWriter xmlWriter; 
    xmlWriter.configureXMLDocumentStructure("./output_data/pedestrian_trajectory.xml", "pedestrian-set", "pedestrian", "1.0", "utf-8");

    simulation.setOutputDataWriter(&xmlWriter);
    simulation.run();

    xmlWriter.writeDocumentContents();
    
    return 0;
}
