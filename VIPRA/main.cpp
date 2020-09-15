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

void populateEntitySets(PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, 
    SIM_PARAMS* simulationParams, InputDataLoader* inputDataLoader, 
    EntitySetFactory* entitySetFactory, std::string type)
{
    if(type == "calm")
    {
        dynamic_cast<InputXMLReader*>(inputDataLoader)->extractFileData(
            "./input_data/a320_144_pedestrians.xml", 
            "pedestrian-set");
        ENTITY_SET pedInputFileData = inputDataLoader->getInputEntities();
        entitySetFactory->populatePedestrianSet(
            pedInputFileData, pedestrianSet);

        dynamic_cast<InputXMLReader*>(inputDataLoader)->extractFileData(
            "./input_data/a320_144_obstacles.xml",
            "obstacle-set");
        ENTITY_SET obsInputFileData = inputDataLoader->getInputEntities();
        entitySetFactory->populateObstacleSet(obsInputFileData, obstacleSet);

        dynamic_cast<InputXMLReader*>(inputDataLoader)->extractFileData(
            "./input_data/simulation_params.xml",
            "simulation-parameters");
        ENTITY_SET simParamsFileData = inputDataLoader->getInputEntities();
        entitySetFactory->populateSimulationParams(
            simParamsFileData, simulationParams);
    }
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

    SIM_CONFIG* simConfig = extractSimConfig("sim_config.txt");
    
    InputDataLoader* inputDataLoader = generateDataLoader(
        (*simConfig)["input_data_loader"]); 
    OutputDataWriter* outputDataWriter = generateDataWriter(
        (*simConfig)["output_data_writer"]);
    PedestrianSet* pedestrianSet = generatePedestrianSet(
        (*simConfig)["pedestrian_set"]);
    ObstacleSet* obstacleSet = generateObstacleSet(
        (*simConfig)["obstacle_set"]);
    EntitySetFactory* entitySetFactory = generateEntitySetFactory(
        (*simConfig)["entity_set_factory"]); 
    Goals* goals = generateGoals(
        (*simConfig)["goals"]);
    PedestrianDynamicsModel* pedestrianDynamicsModel = generatePedDynamicsModel(
        (*simConfig)["pedestrian_dynamics_model"]);
    SimulationOutputHandler* outputHandler = generateOutputHandler(
        (*simConfig)["simulation_output_handler"]);
    
    SIM_PARAMS* simulationParams = new SIM_PARAMS;

    populateEntitySets(pedestrianSet, obstacleSet, simulationParams, 
        inputDataLoader, entitySetFactory, (*simConfig)["entity_set_factory"]);

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
        outputDataWriter, (*simConfig)["output_data_writer"]);
    configureOutputHandler(
        outputHandler, pedestrianSet, outputDataWriter, 
        &simulation, (*simConfig)["simulation_output_handler"]);

    simulation.setSimulationOutputHandler(outputHandler);
    simulation.run();

    writeTrajectoryToFile(outputDataWriter, (*simConfig)["output_data_writer"]);
    
    delete simConfig;
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