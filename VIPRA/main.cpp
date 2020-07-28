#include <string>
#include <iostream>

#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "writers/timestep_output_handler.hpp"

int main()
{
    CalmPedestrianSet calmPedSet;
    Data data;
    CalmGoal goal;
    data.setPedestrianSet(&calmPedSet);
	
    XMLReader xmlReader;
    xmlReader.storeData(&data);

    goal.addExitGoal(data.getSimulationParams());
    goal.calculateNearestExit(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    calmModel.setGoal(&goal);

    goal.determinePedestrianGoals(&data);

    //DELETE WHEN DONE
    for(int i = 0; i < calmPedSet.getNumPedestrians(); ++i)
    {
        std::cout << "ped: " << i << "goal x:" <<calmPedSet.getGoalCoordinates()->at(i).coordinates[0];
        std::cout << "  goal y:" << calmPedSet.getGoalCoordinates()->at(i).coordinates[1] << std::endl;
    }

    XMLWriter xmlWriter; 
    xmlWriter.configureXMLDocumentStructure(
			"./output_data/pedestrian_trajectory.xml", 
			"pedestrian-set", 
			"pedestrian", 
			"1.0", 
			"utf-8");
    
    Simulation simulation(&calmModel);
    
    TimestepOutputHandler timestepOutputHandler;
    timestepOutputHandler.setPedestrianSet(&calmPedSet);
    timestepOutputHandler.setOutputDataWriter(&xmlWriter);
    timestepOutputHandler.setTimestep(simulation.getTimestep()); 
    timestepOutputHandler.setOutputWritingFrequency(250);

    simulation.setSimulationOutputHandler(&timestepOutputHandler);
    simulation.run();

    xmlWriter.writeDocumentContents();

    return 0;
}
