#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

#include "readers/json/json.h"
#include "readers/input_xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "writers/timestep_output_handler.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"
#include "entity_sets/calm_entity_set_factory.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "simulation/simulation.hpp"

InputDataLoader* generateDataLoader(std::string type, CONFIG_MAP* configMap)
{
    if(type == "xml")
    {
        InputXMLReader* inputXMLReader = new InputXMLReader;
        inputXMLReader->configure(configMap);
        return inputXMLReader;
    }

    return nullptr;
}

OutputDataWriter* generateDataWriter(std::string type, CONFIG_MAP* configMap)
{
    if(type == "xml")
    {
        XMLWriter* xmlWriter = new XMLWriter;
        xmlWriter->configure(configMap);
        return xmlWriter;
    }

    return nullptr;
}

SimulationOutputHandler* generateOutputHandler(std::string type, CONFIG_MAP* configMap)
{
    if(type == "timestep")
    {
        TimestepOutputHandler* timestepOutputHandler = 
            new TimestepOutputHandler;
        timestepOutputHandler->configure(configMap);
        return timestepOutputHandler;
    }

    return nullptr;
}

// TODO add CONFIG_MAP* parameter to the remaining generator methods
PedestrianSet* generatePedestrianSet(std::string type, CONFIG_MAP* configMap)
{
    if(type == "calm")
    {
        CalmPedestrianSet* calmPedSet = new CalmPedestrianSet;
        calmPedSet->configure(configMap);
        return calmPedSet;
    }

    return nullptr;
}

// TODO since this class now includes aisles, 
// we should probably make this derived -- alex
ObstacleSet* generateObstacleSet(std::string type)
{
    if(type == "calm")
    {
        ObstacleSet* calmObsSet = new ObstacleSet;
        return calmObsSet;
    }

    return nullptr;
}

EntitySetFactory* generateEntitySetFactory(std::string type)
{
    if(type == "calm")
    {
        CalmEntitySetFactory* calmSetFactory = new CalmEntitySetFactory;
        return calmSetFactory;
    }

    return nullptr;
}

Goals* generateGoals(std::string type)
{
    if(type == "calm")
    {
        CalmGoals* calmGoals = new CalmGoals;
        return calmGoals;
    }

    return nullptr;
}

PedestrianDynamicsModel* generatePedDynamicsModel(std::string type)
{
    if(type == "calm")
    {
        CalmPedestrianModel* calmPedModel = new CalmPedestrianModel;
        return calmPedModel;
    }

    return nullptr;
}

void populateEntitySets(
	PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParams,
	InputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,
	std::string pedSetFile, std::string obsSetFile, std::string simParamsFile,
	CONFIG_MAP* pedConfigMap, CONFIG_MAP* obsConfigMap, CONFIG_MAP* simParamsConfigMap)
{
	inputDataLoader->extractFileData(pedSetFile, pedConfigMap);
	ENTITY_SET pedInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populatePedestrianSet(pedInputFileData, pedestrianSet);
    std::cout << "populated ped set" << std::endl;


	inputDataLoader->extractFileData(obsSetFile, obsConfigMap);
	ENTITY_SET obsInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateObstacleSet(obsInputFileData, obstacleSet);
    std::cout << "populated obs set" << std::endl;

	inputDataLoader->extractFileData(simParamsFile, simParamsConfigMap);
	ENTITY_SET simParamsFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateSimulationParams(simParamsFileData, simulationParams);
}

void configureOutputHandler(
    SimulationOutputHandler* outputHandler, PedestrianSet* pedestrianSet, 
    OutputDataWriter* outputDataWriter, Simulation* simulation)
{
    outputHandler->setOutputDataWriter(outputDataWriter);
    outputHandler->setPedestrianSet(pedestrianSet);
    outputHandler->setSimulation(simulation);
}

void writeTrajectoryToFile(OutputDataWriter* outputDataWriter, std::string type)
{
    if(type == "xml")
    {
        // TODO make writeDocumentContents into virtual method
        dynamic_cast<XMLWriter*>(outputDataWriter)->writeDocumentContents();
    }
}


Json::Value jsonObj;
typedef std::unordered_map<std::string, std::string> CONFIG_MAP; 

CONFIG_MAP* extractConfigMap(std::string objectName)
{
    CONFIG_MAP* configMap = new CONFIG_MAP;

    for(int i = 0; i < jsonObj[objectName]["configuration"].size(); i++) 
    {
        std::string attribute = jsonObj[objectName]["configuration"].getMemberNames()[i];
        std::string value = jsonObj[objectName]["configuration"][attribute].asString();
        (*configMap)[attribute] = value;
    }

    return configMap;
}


int main()
{
    // TODO dont make jsonObj a global variable
    // TODO deallocate all the CONFIG_MAPs
    // TODO should probably put sim_params.xml in sim_config.json

    Json::Reader reader;
    std::ifstream jsonFile("input_data/sim_config.json");
    reader.parse(jsonFile, jsonObj);

    CONFIG_MAP* inputDataLoaderConfig = extractConfigMap("input_data_loader");
    CONFIG_MAP* outputDataWriterConfig = extractConfigMap("output_data_writer"); 
    CONFIG_MAP* simulationOutputHandlerConfig = extractConfigMap("simulation_output_handler"); 
    CONFIG_MAP* pedestrianSetConfig = extractConfigMap("pedestrian_set"); 
    CONFIG_MAP* obstacleSetConfig = extractConfigMap("obstacle_set"); 
    CONFIG_MAP* simulationParametersConfig = extractConfigMap("sim_params"); 
    CONFIG_MAP* entitySetFactoryConfig = extractConfigMap("entity_set_factory"); 
    CONFIG_MAP* goalsConfig = extractConfigMap("goals"); 
    CONFIG_MAP* pedestrianDynamicsModelConfig = extractConfigMap("pedestrian_dynamics_model"); 

    InputDataLoader* inputDataLoader = generateDataLoader(
        jsonObj["input_data_loader"]["type"].asString(),
        inputDataLoaderConfig
    );

    OutputDataWriter* outputDataWriter = generateDataWriter(
        jsonObj["output_data_writer"]["type"].asString(),
        outputDataWriterConfig
    );

    PedestrianSet* pedestrianSet = generatePedestrianSet(
        jsonObj["pedestrian_set"]["type"].asString(), pedestrianSetConfig);
    ObstacleSet* obstacleSet = generateObstacleSet(
        jsonObj["obstacle_set"]["type"].asString());
    EntitySetFactory* entitySetFactory = generateEntitySetFactory(
        jsonObj["entity_set_factory"]["type"].asString()); 
    Goals* goals = generateGoals(
        jsonObj["goals"]["type"].asString());
    PedestrianDynamicsModel* pedestrianDynamicsModel = generatePedDynamicsModel(
        jsonObj["pedestrian_dynamics_model"]["type"].asString());

    SimulationOutputHandler* outputHandler = generateOutputHandler(
        jsonObj["simulation_output_handler"]["type"].asString(),
        simulationOutputHandlerConfig
    );
    
    SIM_PARAMS* simulationParams = new SIM_PARAMS;

    populateEntitySets(
        pedestrianSet, obstacleSet, simulationParams, 
        inputDataLoader, entitySetFactory, 
        jsonObj["pedestrian_set"]["inputFilePath"].asString(), 
        jsonObj["obstacle_set"]["inputFilePath"].asString(), 
        jsonObj["sim_params"]["inputFilePath"].asString(),
        pedestrianSetConfig, obstacleSetConfig, simulationParametersConfig);

    Data data;
    data.setPedestrianSet(pedestrianSet);
    data.setObstacleSet(obstacleSet);
    data.setSimulationParams(simulationParams);    

    goals->setData(&data);
	pedestrianDynamicsModel->setData(&data);
    pedestrianDynamicsModel->setGoals(goals);
    goals->determinePedestrianGoals();
    
    Simulation simulation(pedestrianDynamicsModel);

    configureOutputHandler(
        outputHandler, pedestrianSet, 
        outputDataWriter, &simulation);

    simulation.setSimulationOutputHandler(outputHandler);
    simulation.run();

    writeTrajectoryToFile(outputDataWriter, jsonObj["output_data_writer"]["type"].asString());
    
    delete inputDataLoader;
    delete outputDataWriter;
    delete pedestrianSet;
    delete obstacleSet;
    delete simulationParams;
    delete entitySetFactory;
    delete goals;
    delete pedestrianDynamicsModel;
    delete outputHandler;

    return 0;
}