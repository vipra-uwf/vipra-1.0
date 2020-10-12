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

InputDataLoader* generateDataLoader(std::string type)
{
    if(type == "xml")
    {
        InputXMLReader* inputXMLReader = new InputXMLReader;
        return inputXMLReader;
    }

    return nullptr;
}

OutputDataWriter* generateDataWriter(std::string type)
{
    if(type == "xml")
    {
        XMLWriter* xmlWriter = new XMLWriter;
        return xmlWriter;
    }

    return nullptr;
}

SimulationOutputHandler* generateOutputHandler(std::string type)
{
    if(type == "timestep")
    {
        TimestepOutputHandler* timestepOutputHandler = 
            new TimestepOutputHandler;
        return timestepOutputHandler;
    }

    return nullptr;
}

PedestrianSet* generatePedestrianSet(std::string type)
{
    if(type == "calm")
    {
        CalmPedestrianSet* calmPedSet = new CalmPedestrianSet;
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
	std::string pedFileRootKey, std::string obsFileRootKey, std::string simParamsFileRootKey)
{
	inputDataLoader->extractFileData(pedSetFile, pedFileRootKey);
	ENTITY_SET pedInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populatePedestrianSet(pedInputFileData, pedestrianSet);

	inputDataLoader->extractFileData(obsSetFile, obsFileRootKey);
	ENTITY_SET obsInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateObstacleSet(obsInputFileData, obstacleSet);

	inputDataLoader->extractFileData(simParamsFile, simParamsFileRootKey);
	ENTITY_SET simParamsFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateSimulationParams(simParamsFileData, simulationParams);
}

void configureOutputDataWriter(
    OutputDataWriter* outputDataWriter, std::string type)
{
    if(type == "xml")
    {
        dynamic_cast<XMLWriter*>(outputDataWriter)->
            configureXMLDocumentStructure(
                "./output_data/pedestrian_trajectory.xml", 
                "pedestrian-set", 
                "pedestrian", 
                "1.0", 
                "utf-8");
    }
}

void configureOutputHandler(SimulationOutputHandler* outputHandler, 
    PedestrianSet* pedestrianSet, OutputDataWriter* outputDataWriter, 
    Simulation* simulation, std::string type)
{
    if(type == "timestep")
    {
        outputHandler->setPedestrianSet(pedestrianSet);
        outputHandler->setOutputDataWriter(outputDataWriter);
        dynamic_cast<TimestepOutputHandler*>(outputHandler)->setTimestep(
            simulation->getTimestep());
        dynamic_cast<TimestepOutputHandler*>(outputHandler)->
            setOutputWritingFrequency(250);
    }
}

void writeTrajectoryToFile(OutputDataWriter* outputDataWriter, std::string type)
{
    if(type == "xml")
    {
        dynamic_cast<XMLWriter*>(outputDataWriter)->writeDocumentContents();
    }
}




int main()
{
    Json::Reader reader;
    std::ifstream jsonFile("input_data/sim_config.json");
    Json::Value jsonObj;
    reader.parse(jsonFile, jsonObj);
    
    InputDataLoader* inputDataLoader = generateDataLoader(
        jsonObj["input_data_loader"].asString()); 
    OutputDataWriter* outputDataWriter = generateDataWriter(
        jsonObj["output_data_writer"].asString());
    PedestrianSet* pedestrianSet = generatePedestrianSet(
        jsonObj["pedestrian_set"]["type"].asString());
    ObstacleSet* obstacleSet = generateObstacleSet(
        jsonObj["obstacle_set"]["type"].asString());
    EntitySetFactory* entitySetFactory = generateEntitySetFactory(
        jsonObj["entity_set_factory"].asString()); 
    Goals* goals = generateGoals(
        jsonObj["goals"].asString());
    PedestrianDynamicsModel* pedestrianDynamicsModel = generatePedDynamicsModel(
        jsonObj["pedestrian_dynamics_model"].asString());
    SimulationOutputHandler* outputHandler = generateOutputHandler(
        jsonObj["simulation_output_handler"].asString());
    
    SIM_PARAMS* simulationParams = new SIM_PARAMS;

    populateEntitySets(
        pedestrianSet, obstacleSet, simulationParams, 
        inputDataLoader, entitySetFactory, 
        jsonObj["pedestrian_set"]["inputFile"].asString(), jsonObj["obstacle_set"]["inputFile"].asString(), jsonObj["sim_params"]["inputFile"].asString(),
        jsonObj["pedestrian_set"]["fileRootKey"].asString(), jsonObj["obstacle_set"]["fileRootKey"].asString(), jsonObj["sim_params"]["fileRootKey"].asString());

    Data data;
    data.setPedestrianSet(pedestrianSet);
    data.setObstacleSet(obstacleSet);
    data.setSimulationParams(simulationParams);    

    goals->setData(&data);
	pedestrianDynamicsModel->setData(&data);
    pedestrianDynamicsModel->setGoals(goals);
    goals->determinePedestrianGoals();
    
    Simulation simulation(pedestrianDynamicsModel);

    configureOutputDataWriter(
        outputDataWriter, jsonObj["output_data_writer"].asString());
    configureOutputHandler(
        outputHandler, pedestrianSet, outputDataWriter, 
        &simulation, jsonObj["simulation_output_handler"].asString());

    simulation.setSimulationOutputHandler(outputHandler);
    simulation.run();

    writeTrajectoryToFile(outputDataWriter, jsonObj["output_data_writer"].asString());
    
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