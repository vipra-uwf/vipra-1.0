#include "simulation.hpp"
#include "xml_reader.hpp"
#include "xml_writer.hpp"
#include "calm_pedestrian_model.hpp"
#include <iostream>
#include <string>

int main()
{

    Data data;

    XMLReader xmlReader;
    xmlReader.storeData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);

    
    Simulation simulation(&calmModel);


    
    std::cout << "made it here" << std::endl;
    
    XMLWriter xmlWriter; 
    //rethink this -- what if writing to multiple files in simulation at the same time?
    xmlWriter.configureXMLDocumentStructure("export_pedestrian_data.xml", "pedestrian-set", "pedestrian", "1.0", "utf-8");
    simulation.setOutputDataWriter(&xmlWriter);

    // xmlWriter.writeData(&data);

    simulation.run();

  
    return 0;
}
