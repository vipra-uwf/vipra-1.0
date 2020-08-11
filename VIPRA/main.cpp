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
//    DataSetFactory dataSetFactory; 
    XMLReader xmlReader;
    
	xmlReader.extractFileData(
        "./input_data/a320_144_pedestrians.xml", 
        "pedestrian-set", 
        "pedestrian");

    std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> pedInputFileData = xmlReader.getInputData();
 //   calmPedSet = dataSetFactory.createCalmPedSet(pedInputFileData);

	/*
    xmlReader.extractFileData(
        "./input_data/a320_144_obstacles.xml",
        "obstacle-set", 
        "obstacle");

    std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> obsInputFileData = xmlReader.getInputData();
    obstacleSet = dataSetFactory.createObstacleSet(obsInputFileData);

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
