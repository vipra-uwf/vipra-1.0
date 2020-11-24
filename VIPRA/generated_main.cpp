#include "readers/input_xml_reader.hpp"
#include "writers/xml_writer.hpp"
#include "writers/timestep_output_handler.hpp"
#include "entity_sets/calm_pedestrian_set.hpp"
#include "entity_sets/airplane_obstacle_set.hpp"
#include "entity_sets/factory/calm_entity_set_factory.hpp"
#include "goals/calm_goals.hpp"
#include "models/calm_pedestrian_model.hpp"

CONFIG_MAP* extractConfigMap(std::string objectName);
InputDataLoader* generateDataLoader(std::string type, CONFIG_MAP* configMap);
OutputDataWriter* generateDataWriter(std::string type, CONFIG_MAP* configMap);
SimulationOutputHandler* generateOutputHandler(std::string type, CONFIG_MAP* configMap);
PedestrianSet* generatePedestrianSet(std::string type, CONFIG_MAP* configMap);
ObstacleSet* generateObstacleSet(std::string type, CONFIG_MAP* configMap);
EntitySetFactory* generateEntitySetFactory(std::string type, CONFIG_MAP* configMap);
Goals* generateGoals(std::string type, CONFIG_MAP* configMap);
PedestrianDynamicsModel* generatePedestrianDynamicsModel(std::string type, CONFIG_MAP* configMap);

void populateEntitySets(
	InputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,
	PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParameters,
	std::string pedestrianSetFilePath, std::string obstacleSetFilePath, std::string simulationParametersFilePath,
	CONFIG_MAP* pedestrianConfigMap, CONFIG_MAP* obstacleConfigMap, CONFIG_MAP* simulationParametersConfigMap);

//TODO this will change when the InputJSONReader is finished -- Alex
#include "readers/json/json.h"
Json::Value simulationJsonConfig;

int main()
{
	Json::CharReaderBuilder jsonReader;
	std::ifstream jsonFile("input_data/sim_config.json");
	std::string errors;

	if(Json::parseFromStream(jsonReader, jsonFile, &simulationJsonConfig, &errors))
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
			simulationJsonConfig["input_data_loader"]["type"].asString(),
			inputDataLoaderConfig);

		OutputDataWriter* outputDataWriter = generateDataWriter(
			simulationJsonConfig["output_data_writer"]["type"].asString(),
			outputDataWriterConfig);

		PedestrianSet* pedestrianSet = generatePedestrianSet(
			simulationJsonConfig["pedestrian_set"]["type"].asString(),
			pedestrianSetConfig);

		ObstacleSet* obstacleSet = generateObstacleSet(
			simulationJsonConfig["obstacle_set"]["type"].asString(),
			obstacleSetConfig);

		EntitySetFactory* entitySetFactory = generateEntitySetFactory(
			simulationJsonConfig["entity_set_factory"]["type"].asString(),
			entitySetFactoryConfig);

		Goals* goals = generateGoals(
			simulationJsonConfig["goals"]["type"].asString(),
			goalsConfig);

		PedestrianDynamicsModel* pedestrianDynamicsModel = generatePedestrianDynamicsModel(
			simulationJsonConfig["pedestrian_dynamics_model"]["type"].asString(),
			pedestrianDynamicsModelConfig);

		SimulationOutputHandler* outputHandler = generateOutputHandler(
			simulationJsonConfig["simulation_output_handler"]["type"].asString(),
			simulationOutputHandlerConfig);

		SIM_PARAMS* simulationParameters = new SIM_PARAMS;

		populateEntitySets(
			inputDataLoader, entitySetFactory,
			pedestrianSet, obstacleSet, simulationParameters,
			simulationJsonConfig["pedestrian_set"]["inputFilePath"].asString(),
			simulationJsonConfig["obstacle_set"]["inputFilePath"].asString(),
			simulationJsonConfig["simulation_parameters"]["inputFilePath"].asString(),
			pedestrianSetConfig, obstacleSetConfig, simulationParametersConfig);

		Data data;
		data.setPedestrianSet(pedestrianSet);
		data.setObstacleSet(obstacleSet);
		data.setSimulationParams(simulationParameters);

		goals->setData(&data);
		pedestrianDynamicsModel->setData(&data);
		pedestrianDynamicsModel->setGoals(goals);
		goals->determinePedestrianGoals();
		pedestrianDynamicsModel->initialize();

		Simulation simulation(pedestrianDynamicsModel);

		outputDataWriter->initializeOutputFile(
			simulationJsonConfig["output_data_writer"]["outputFilePath"].asString());

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
		delete simulationParameters;
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
		CalmPedestrianSet* calmPedestrianSet = new CalmPedestrianSet;
		calmPedestrianSet->configure(configMap);
		return calmPedestrianSet;
	}

	return nullptr;
}

ObstacleSet* generateObstacleSet(std::string type, CONFIG_MAP* configMap)
{
	if(type == "airplane")
	{
		AirplaneObstacleSet* airplaneObstacleSet = new AirplaneObstacleSet;
		airplaneObstacleSet->configure(configMap);
		return airplaneObstacleSet;
	}

	return nullptr;
}

EntitySetFactory* generateEntitySetFactory(std::string type, CONFIG_MAP* configMap)
{
	if(type == "calm")
	{
		CalmEntitySetFactory* calmEntitySetFactory = new CalmEntitySetFactory;
		calmEntitySetFactory->configure(configMap);
		return calmEntitySetFactory;
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

PedestrianDynamicsModel* generatePedestrianDynamicsModel(std::string type, CONFIG_MAP* configMap)
{
	if(type == "calm")
	{
		CalmPedestrianModel* calmPedestrianModel = new CalmPedestrianModel;
		calmPedestrianModel->configure(configMap);
		return calmPedestrianModel;
	}

	return nullptr;
}

void populateEntitySets(
	InputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,
	PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParameters,
	std::string pedestrianSetFilePath, std::string obstacleSetFilePath, std::string simulationParametersFilePath,
	CONFIG_MAP* pedestrianConfigMap, CONFIG_MAP* obstacleConfigMap, CONFIG_MAP* simulationParametersConfigMap)
{
	inputDataLoader->extractFileData(pedestrianSetFilePath, pedestrianConfigMap);
	ENTITY_SET pedestrianInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populatePedestrianSet(pedestrianInputFileData, pedestrianSet);

	inputDataLoader->extractFileData(obstacleSetFilePath, obstacleConfigMap);
	ENTITY_SET obstacleInputFileData = inputDataLoader->getInputEntities();
	entitySetFactory->populateObstacleSet(obstacleInputFileData, obstacleSet);

	inputDataLoader->extractFileData(simulationParametersFilePath, simulationParametersConfigMap);
	ENTITY_SET simulationParametersFilePathData = inputDataLoader->getInputEntities();
	entitySetFactory->populateSimulationParams(simulationParametersFilePathData, simulationParameters);
}

CONFIG_MAP* extractConfigMap(std::string objectName)
{
	CONFIG_MAP* configMap = new CONFIG_MAP;

	for(unsigned int i = 0; i < simulationJsonConfig[objectName]["configuration"].size(); i++)
	{
		std::string attribute = simulationJsonConfig[objectName]["configuration"].getMemberNames()[i];
		std::string value = simulationJsonConfig[objectName]["configuration"][attribute].asString();
		(*configMap)[attribute] = value;
	}

	return configMap;
}