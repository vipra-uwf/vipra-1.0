#include <string>
#include <iostream>
#include <fstream>

#include "readers/input_xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "writers/timestep_output_handler.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"
#include "entity_sets/calm_entity_set_factory.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "simulation/simulation.hpp"




int main()
{
    std::cout << "test" << std::endl;  

    std::string line;
    std::string delimiter = "=";
    std::ifstream simConfig("sim_config.txt"); 

    while(std::getline(simConfig, line))
    {
        std::string parameter = line.substr(0, line.find(delimiter));
        std::string value = line.substr(line.find(delimiter) + 1, line.size());
        std::cout << parameter << " " << value << std::endl;
    }

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
