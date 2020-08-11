#include <string>
#include <iostream>

#include "entity_sets/obstacle_set.hpp"
#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "writers/timestep_output_handler.hpp"

int main()
{
    CalmPedestrianSet calmPedSet;
    ObstacleSet obstacleSet;
    Data data;
	//TODO will need to call setNumPedestrians and setNumObstacles inside factory
//    DataSetFactory dataSetFactory; 
    XMLReader xmlReader;
   
	//rapidxml forces defining of this node .. may be a rapidxml bug -- will look at later
	xmlReader.extractFileData(
        "./input_data/a320_144_pedestrians.xml", 
        "pedestrian-set");

	//TODO make it so extractFileData doesn't require rootNodeName nor dataNodeName
    std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> pedInputFileData = xmlReader.getInputData();

	


	std::unordered_map<std::string, std::vector<FLOATING_NUMBER>>::iterator it = pedInputFileData.begin();
    while (it != pedInputFileData.end())
    {
        std::cout << "\n" << it->first << std::endl;
		
		for(long unsigned int i = 0; i < it->second.size(); ++i)
		{
			std::cout << it->second.at(i) << " ";
		}

		it++;
    }

	


	//   calmPedSet = dataSetFactory.createCalmPedSet(pedInputFileData);

	/*
   xmlReader.extractFileData(
        "./input_data/a320_144_obstacles.xml",
        "obstacle-set", 
        "obstacle");

    std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> obsInputFileData = xmlReader.getInputData();
    obstacleSet = dataSetFactory.createObstacleSet(obsInputFileData);


	//TODO USE EXTRACTFILEDATA HERE INSTEAD OF OPEN change simulation params file so attributes arent datanodename
    xmlReader.openFile("./input_data/simulation_params.xml");
    std::unordered_map<std::string, FLOATING_NUMBER> simulationParams = xmlReader.getSimulationParams("parameters");
    
    data.setPedestrianSet(&calmPedSet);
    data.setObstacleSet(&obstacleSet);
    data.setSimulationParams(&simulationParams);    
    
    CalmPedestrianModel calmModel;
    calmModel.setData(&data);

    Simulation simulation(&calmModel);

    ...etc
	 */


	/*
    CalmPedestrianSet calmPedSet;
	ObstacleSet obstacleSet; 
	Data data;
    CalmGoals goal;
    data.setPedestrianSet(&calmPedSet);
	
    XMLReader xmlReader;
    xmlReader.storeData(&data);

    CalmPedestrianModel calmModel;
    calmModel.setData(&data);
    calmModel.setGoals(&goal);

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

    simulation.testGoalClassDELETETHIS();
    simulation.run();

    xmlWriter.writeDocumentContents();
	*/


    return 0;
}
