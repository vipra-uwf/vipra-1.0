#include <iostream>
#include <string>

#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "xmlconverter.hpp"

int main()
{
    Data data;

    // this code is quick and dirty.. will make it better if this type of converter is something we want to keep for the long term -- Alex
    // XMLConverter xmlConverter;
    // xmlConverter.convertToXML("coord_A320_144.d_coordinates.txt", 13);
    // xmlConverter.convertToXML("coord_A320_144.d_coordinates.txt", 16);

    XMLReader xmlReader;
    xmlReader.storeData(&data);
    
    CalmPedestrianModel calmModel;
    calmModel.setData(&data);

    Simulation simulation(&calmModel);

    XMLWriter xmlWriter; 
    xmlWriter.configureXMLDocumentStructure("pedestrian_trajectory.xml", "pedestrian-set", "pedestrian", "1.0", "utf-8");
    
    simulation.setOutputDataWriter(&xmlWriter);
    simulation.run();

    xmlWriter.writeDocumentContents();
    
    // std::cout << "End of main(), program closing..(0)" << std::endl;
    return 0;
}
