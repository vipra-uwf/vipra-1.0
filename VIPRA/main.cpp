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

InputDataLoader* generateDataLoader(std::string type)
{
    if(type == "xml")
    {
        InputXMLReader* inputXMLReader = new InputXMLReader;
        return inputXMLReader;
    }
}

OutputDataWriter* generateDataWriter(std::string type)
{
    if(type == "xml")
    {
        XMLWriter* xmlWriter = new XMLWriter;
        return xmlWriter;
    }
}

SimulationOutputHandler* generateOutputHandler(std::string type)
{
    if(type == "timestep")
    {
        TimestepOutputHandler* timestepOutputHandler = new TimestepOutputHandler;
        return timestepOutputHandler;
    }
}

PedestrianSet* generatePedestrianSet(std::string type)
{
    if(type == "calm")
    {
        CalmPedestrianSet* calmPedSet = new CalmPedestrianSet;
        return calmPedSet;
    }
}

// TODO since this class now includes aisles, we should probably make this derived -- alex
ObstacleSet* generateObstacleSet(std::string type)
{
    if(type == "calm")
    {
        ObstacleSet* calmObsSet = new ObstacleSet;
        return calmObsSet;
    }
}

EntitySetFactory* generateEntitySetFactory(std::string type)
{
    if(type == "calm")
    {
        CalmEntitySetFactory* calmSetFactory = new CalmEntitySetFactory;
        return calmSetFactory;
    }
}

Goals* generateGoals(std::string type)
{
    if(type == "calm")
    {
        CalmGoals* calmGoals = new CalmGoals;
        return calmGoals;
    }
}

PedestrianDynamicsModel* generatePedDynamicsModel(std::string type)
{
    if(type == "calm")
    {
        CalmPedestrianModel* calmPedModel = new CalmPedestrianModel;
        return calmPedModel;
    }
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
    
    // InputXMLReader inputXMLReader;
    InputDataLoader* inputDataLoader = generateDataLoader((*simConfig)["input_data_loader"]); 
    // XMLWriter xmlWriter;
    OutputDataWriter* outputDataWriter = generateDataWriter((*simConfig)["output_data_writer"]);
    // CalmPedestrianSet* calmPedSet;
    PedestrianSet* pedestrianSet = generatePedestrianSet((*simConfig)["pedestrian_set"]);
    // ObstacleSet* obstacleSet;
    ObstacleSet* obstacleSet = generateObstacleSet((*simConfig)["obstacle_set"]);
    // CalmEntitySetFactory entitySetFactory; 
    EntitySetFactory* entitySetFactory = generateEntitySetFactory((*simConfig)["entity_set_factory"]); 
    // CalmGoals goals;
    Goals* goals = generateGoals((*simConfig)["goals"]);
    // CalmPedestrianModel calmModel;
    PedestrianDynamicsModel* PedestrianDynamicsModel = generatePedDynamicsModel((*simConfig)["pedestrian_dynamics_model"]);
    // TimestepOutputHandler timestepOutputHandler;
    SimulationOutputHandler* outputHandler = generateOutputHandler((*simConfig)["simulation_output_handler"]);



    // SIM_PARAMS* simulationParams;
    // Data data;


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
    
    delete simConfig;
    //DELETE ALL THE CLASSES THAT WERE MADE FROM NEW METHODS

    return 0;
}
