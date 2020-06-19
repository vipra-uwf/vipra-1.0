#include <iostream>
#include <string>

#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"

int main()
{
    Data data;

    XMLReader xmlReader;
    xmlReader.storeData(&data);
    
    CalmPedestrianModel calmModel;
    calmModel.setData(&data);

    Simulation simulation(&calmModel);

    XMLWriter xmlWriter; 
    xmlWriter.configureXMLDocumentStructure("export_pedestrian_data.xml", "pedestrian-set", "pedestrian", "1.0", "utf-8");
    
    simulation.setOutputDataWriter(&xmlWriter);
    simulation.run();

    xmlWriter.writeDocumentContents();
    
    std::cout << "End of main(), program closing..(0)" << std::endl;
    return 0;
}
