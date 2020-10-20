#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

#include "type_definitions.hpp"
#include "readers/json/json.h"
#include "readers/input_xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "writers/timestep_output_handler.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/obstacle_set.hpp"
#include "entity_sets/calm_entity_set_factory.hpp"
#include "models/calm_pedestrian_model.hpp"
#include "simulation/simulation.hpp"


CONFIG_MAP* extractConfigMap(std::string objectName);

InputDataLoader* generateDataLoader(std::string type, CONFIG_MAP* configMap);
OutputDataWriter* generateDataWriter(std::string type, CONFIG_MAP* configMap);
SimulationOutputHandler* generateOutputHandler(std::string type, CONFIG_MAP* configMap);
PedestrianSet* generatePedestrianSet(std::string type, CONFIG_MAP* configMap);
ObstacleSet* generateObstacleSet(std::string type, CONFIG_MAP* configMap);
EntitySetFactory* generateEntitySetFactory(std::string type, CONFIG_MAP* configMap);
Goals* generateGoals(std::string type, CONFIG_MAP* configMap);
PedestrianDynamicsModel* generatePedDynamicsModel(std::string type, CONFIG_MAP* configMap);

void populateEntitySets(
	InputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,
	PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParams,
	std::string pedSetFile, std::string obsSetFile, std::string simParamsFile,
	CONFIG_MAP* pedConfigMap, CONFIG_MAP* obsConfigMap, CONFIG_MAP* simParamsConfigMap);

Json::Value jsonObj;

int main()
{
    // Json::Reader reader;
    // reader.parse(jsonFile, jsonObj);

    Json::CharReaderBuilder jsonReader;
    std::ifstream jsonFile("input_data/sim_config.json");
    std::string errors;

    if(Json::parseFromStream(jsonReader, jsonFile, &jsonObj, &errors))
    {
        CONFIG_MAP* inputDataLoaderConfig = extractConfigMap("input_data_loader");
        CONFIG_MAP* outputDataWriterConfig = extractConfigMap("output_data_writer"); 
        CONFIG_MAP* simulationOutputHandlerConfig = extractConfigMap("simulation_output_handler"); 
        CONFIG_MAP* pedestrianSetConfig = extractConfigMap("pedestrian_set"); 
        CONFIG_MAP* obstacleSetConfig = extractConfigMap("obstacle_set"); 
        CONFIG_MAP* simulationParametersConfig = extractConfigMap("simulation_parameters"); 
        CONFIG_MAP* entitySetFactoryConfig = extractConfigMap("entity_set_factory"); 
        CONFIG_MAP* goalsConfig = extractConfigMap("goals"); 
        CONFIG_MAP* pedestrianDynamicsModelConfig = extractConfigMap("pedestrian_dynamics_model"); 

        InputDataLoader* inputDataLoader = generateDataLoader(
            jsonObj["input_data_loader"]["type"].asString(),
            inputDataLoaderConfig);

        OutputDataWriter* outputDataWriter = generateDataWriter(
            jsonObj["output_data_writer"]["type"].asString(),
            outputDataWriterConfig);

        PedestrianSet* pedestrianSet = generatePedestrianSet(
            jsonObj["pedestrian_set"]["type"].asString(), 
            pedestrianSetConfig);

        ObstacleSet* obstacleSet = generateObstacleSet(
            jsonObj["obstacle_set"]["type"].asString(), 
            obstacleSetConfig);

        EntitySetFactory* entitySetFactory = generateEntitySetFactory(
            jsonObj["entity_set_factory"]["type"].asString(), 
            entitySetFactoryConfig); 

        Goals* goals = generateGoals(
            jsonObj["goals"]["type"].asString(), 
            goalsConfig);

        PedestrianDynamicsModel* pedestrianDynamicsModel = generatePedDynamicsModel(
            jsonObj["pedestrian_dynamics_model"]["type"].asString(), 
            pedestrianDynamicsModelConfig);

        SimulationOutputHandler* outputHandler = generateOutputHandler(
            jsonObj["simulation_output_handler"]["type"].asString(),
            simulationOutputHandlerConfig);
        
        SIM_PARAMS* simulationParams = new SIM_PARAMS;

        populateEntitySets(
            inputDataLoader, entitySetFactory, 
            pedestrianSet, obstacleSet, simulationParams, 
            jsonObj["pedestrian_set"]["inputFilePath"].asString(), 
            jsonObj["obstacle_set"]["inputFilePath"].asString(), 
            jsonObj["simulation_parameters"]["inputFilePath"].asString(),
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
        
        outputDataWriter->initializeOutputFile(
            jsonObj["output_data_writer"]["outputFilePath"].asString());
        
        outputHandler->setOutputDataWriter(outputDataWriter);
        outputHandler->setPedestrianSet(pedestrianSet);
        outputHandler->setSimulation(&simulation);

        simulation.setSimulationOutputHandler(outputHandler);
        simulation.run();

        outputDataWriter->writeDocumentContentsToFile();
        
        delete inputDataLoader;
        delete outputDataWriter;
        delete pedestrianSet;
        delete obstacleSet;
        delete simulationParams;
        delete entitySetFactory;
        delete goals;
        delete pedestrianDynamicsModel;
        delete outputHandler;

        delete inputDataLoaderConfig;
        delete outputDataWriterConfig;
        delete simulationOutputHandlerConfig;
        delete pedestrianSetConfig;
        delete obstacleSetConfig;
        delete simulationParametersConfig;
        delete entitySetFactoryConfig;
        delete goalsConfig;
        delete pedestrianDynamicsModelConfig;
    }
    else
    {
        std::cout << "Error parsing JSON: " << errors << std::endl;
    }

    return 0;
}

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
        TimestepOutputHandler* timestepOutputHandler = new TimestepOutputHandler;
        timestepOutputHandler->configure(configMap);
        return timestepOutputHandler;
    }

    return nullptr;
}

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
ObstacleSet* generateObstacleSet(std::string type, CONFIG_MAP* configMap)
{
    if(type == "calm")
    {
        ObstacleSet* calmObsSet = new ObstacleSet;
        calmObsSet->configure(configMap);
        return calmObsSet;
    }

    return nullptr;
}

EntitySetFactory* generateEntitySetFactory(std::string type, CONFIG_MAP* configMap)
{
    if(type == "calm")
    {
        CalmEntitySetFactory* calmSetFactory = new CalmEntitySetFactory;
        calmSetFactory->configure(configMap);
        return calmSetFactory;
    }

    return nullptr;
}

Goals* generateGoals(std::string type, CONFIG_MAP* configMap)
{
    if(type == "calm")
    {
        CalmGoals* calmGoals = new CalmGoals;
        calmGoals->configure(configMap);
        return calmGoals;
    }

    return nullptr;
}

PedestrianDynamicsModel* generatePedDynamicsModel(std::string type, CONFIG_MAP* configMap)
{
    if(type == "calm")
    {
        CalmPedestrianModel* calmPedModel = new CalmPedestrianModel;
        calmPedModel->configure(configMap);
        return calmPedModel;
    }

    return nullptr;
}

void populateEntitySets(
	InputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,
	PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParams,
	std::string pedSetFile, std::string obsSetFile, std::string simParamsFile,
	CONFIG_MAP* pedConfigMap, CONFIG_MAP* obsConfigMap, CONFIG_MAP* simParamsConfigMap)
{
	inputDataLoader->extractFileData(pedSetFile, pedConfigMap);
	ENTITY_SET pedInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populatePedestrianSet(pedInputFileData, pedestrianSet);

	inputDataLoader->extractFileData(obsSetFile, obsConfigMap);
	ENTITY_SET obsInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateObstacleSet(obsInputFileData, obstacleSet);

	inputDataLoader->extractFileData(simParamsFile, simParamsConfigMap);
	ENTITY_SET simParamsFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateSimulationParams(simParamsFileData, simulationParams);
}

CONFIG_MAP* extractConfigMap(std::string objectName)
{
    CONFIG_MAP* configMap = new CONFIG_MAP;

    for(unsigned int i = 0; i < jsonObj[objectName]["configuration"].size(); i++) 
    {
        std::string attribute = jsonObj[objectName]["configuration"].getMemberNames()[i];
        std::string value = jsonObj[objectName]["configuration"][attribute].asString();
        (*configMap)[attribute] = value;
    }

    return configMap;
}