#include <string>
#include <iostream>

#include "entity_sets/obstacle_set.hpp"
#include "simulation/simulation.hpp"
#include "readers/xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "writers/timestep_output_handler.hpp"

#include "data_set_factory.hpp"

int main()
{
    CalmPedestrianSet calmPedSet;
    ObstacleSet obstacleSet;
    Data data;
    CalmGoals goals;
	DataSetFactory dataSetFactory; 
    XMLReader xmlReader;
   
	//rapidxml forces defining of the first node .. may be a rapidxml bug -- will look at later
	xmlReader.extractFileData(
        "./input_data/a320_144_pedestrians.xml", 
        "pedestrian-set");

	//TODO make it so extractFileData doesn't require rootNodeName nor dataNodeName
    std::unordered_map<std::string, 
		std::vector<FLOATING_NUMBER>> pedInputFileData = 
			xmlReader.getInputData();
	
	calmPedSet = dataSetFactory.createCalmPedSet(pedInputFileData);


    xmlReader.extractFileData(
        "./input_data/a320_144_obstacles.xml",
        "obstacle-set");

    std::unordered_map<
		std::string, std::vector<FLOATING_NUMBER>> obsInputFileData = 
			xmlReader.getInputData();
    
	obstacleSet = dataSetFactory.createObstacleSet(obsInputFileData);

	/*
	for(int i = 0; i < obstacleSet.getNumObstacles(); ++i)
	{
		std::cout << "obs [" << i << "] "
			<< "(" << obstacleSet.getObstacleCoordinates()->at(i).coordinates[0] << ", "
	        << obstacleSet.getObstacleCoordinates()->at(i).coordinates[1] << ")"

			<< std::endl;
	}
	*/


    std::unordered_map<std::string, FLOATING_NUMBER> simulationParams;
   
    xmlReader.extractFileData(
        "./input_data/simulation_params.xml",
        "simulation-parameters");

    std::unordered_map<
		std::string, std::vector<FLOATING_NUMBER>> simParamsFileData = 
			xmlReader.getInputData();
    
	simulationParams = dataSetFactory.createSimulationParamsSet(
		simParamsFileData);


    data.setPedestrianSet(&calmPedSet);
    data.setObstacleSet(&obstacleSet);
    data.setSimulationParams(&simulationParams);    

    goals.setData(&data);

	CalmPedestrianModel calmModel;
	calmModel.setData(&data);
    calmModel.setGoals(&goals);

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
