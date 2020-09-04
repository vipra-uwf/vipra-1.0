#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

#include "readers/input_xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "writers/timestep_output_handler.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"
#include "entity_sets/calm_entity_set_factory.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "simulation/simulation.hpp"

typedef std::unordered_map<std::string, std::string> SIM_CONFIG; 

SIM_CONFIG* extractSimConfig(std::string fileName)
{
    SIM_CONFIG* simConfig = new SIM_CONFIG;

    std::string line;
    std::string delimiter = "=";
    std::ifstream inputFile(fileName); 

    while(std::getline(inputFile, line))
    {
        std::string parameter = line.substr(0, line.find(delimiter));
        std::string value = line.substr(line.find(delimiter) + 1, line.size());
        (*simConfig)[parameter] = value;
    }

    return simConfig;
}

int main()
{
    /*
    input_data_loader=xml
    output_data_writer=xml
    simulation_output_handler=timestep
    pedestrian_set=calm
    obstacle_set=calm
    entity_set_factory=calm
    goals=calm
    pedestrian_dynamics_model=calm
   */ 
    SIM_CONFIG* simConfig = extractSimConfig("sim_config.txt");

    std::cout << (*simConfig)["entity_set_factory"] << std::endl;


    delete simConfig;

    // InputXMLReader inputXMLReader;
    // XMLWriter xmlWriter;

    // CalmPedestrianSet* calmPedSet;
    // ObstacleSet* obstacleSet;
    // SIM_PARAMS* simulationParams;
	
    // CalmEntitySetFactory entitySetFactory; 
    // Data data;

    // CalmGoals goals;
	// CalmPedestrianModel calmModel;
    // TimestepOutputHandler timestepOutputHandler;
	
    // inputXMLReader.extractFileData(
    //     "./input_data/a320_144_pedestrians.xml", 
    //     "pedestrian-set");
    // ENTITY_SET pedInputFileData = inputXMLReader.getInputEntities();
	// calmPedSet = entitySetFactory.createPedestrianSet(pedInputFileData);

    // inputXMLReader.extractFileData(
    //     "./input_data/a320_144_obstacles.xml",
    //     "obstacle-set");
    // ENTITY_SET obsInputFileData = inputXMLReader.getInputEntities();
	// obstacleSet = entitySetFactory.createObstacleSet(obsInputFileData);

    // inputXMLReader.extractFileData(
    //     "./input_data/simulation_params.xml",
    //     "simulation-parameters");
    // ENTITY_SET simParamsFileData = inputXMLReader.getInputEntities();
	// simulationParams = entitySetFactory.createSimulationParams(
	// 	simParamsFileData);

    // data.setPedestrianSet(calmPedSet);
    // data.setObstacleSet(obstacleSet);
    // data.setSimulationParams(simulationParams);    

    // goals.setData(&data);

	// calmModel.setData(&data);
    // calmModel.setGoals(&goals);
    // goals.determinePedestrianGoals();
    
    // xmlWriter.configureXMLDocumentStructure(
	// 		"./output_data/pedestrian_trajectory.xml", 
	// 		"pedestrian-set", 
	// 		"pedestrian", 
	// 		"1.0", 
	// 		"utf-8");
    
    // Simulation simulation(&calmModel);
    
    // timestepOutputHandler.setPedestrianSet(calmPedSet);
    // timestepOutputHandler.setOutputDataWriter(&xmlWriter);
    // timestepOutputHandler.setTimestep(simulation.getTimestep()); 
    // timestepOutputHandler.setOutputWritingFrequency(250);
    
    // simulation.setSimulationOutputHandler(&timestepOutputHandler);
    // simulation.run();

    // xmlWriter.writeDocumentContents();

    // //deleting polymorphic class which has non-virtual destructor 
    // //might cause undefined behavior
    // //delete calmPedSet;
    // delete obstacleSet;
    // delete simulationParams;

    return 0;
}
