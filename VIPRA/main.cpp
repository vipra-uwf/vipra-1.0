#include <iostream>
#include <string>

#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "writers/output_timestep_checker.hpp"
#include "goals/calm_goal.hpp"

int main()
{
    CalmPedestrianSet calmPedSet;
    Data data;
    CalmGoal goal;
    data.setPedestrianSet(&calmPedSet);
	
    XMLReader xmlReader;
    xmlReader.storeData(&data);

    goal.addExitGoal(data.getHashMapData());

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    calmModel.setGoal(&goal);

    goal.determinePedestrianGoals(&data);

    XMLWriter xmlWriter; 
    xmlWriter.configureXMLDocumentStructure(
			"./output_data/pedestrian_trajectory.xml", 
			"pedestrian-set", 
			"pedestrian", 
			"1.0", 
			"utf-8");
    
    Simulation simulation(&calmModel);
    
    OutputTimestepChecker outputTimestepChecker;
    outputTimestepChecker.setPedestrianSet(&calmPedSet);
    outputTimestepChecker.setOutputDataWriter(&xmlWriter);
    outputTimestepChecker.setTimestep(simulation.getTimestep()); 
    outputTimestepChecker.setOutputWritingFrequency(250);

    simulation.setOutputCriterionChecker(&outputTimestepChecker);
    simulation.run();

    xmlWriter.writeDocumentContents();

    return 0;
}
