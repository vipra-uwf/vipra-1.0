// #include "readers/input_xml_reader.hpp"
// #include "writers/xml_writer.hpp"
// #include "writers/timestep_output_handler.hpp"
// #include "entity_sets/calm_pedestrian_set.hpp"
// #include "entity_sets/obstacle_set.hpp"
// #include "entity_sets/calm_entity_set_factory.hpp"
// #include "goals/calm_goals.hpp"
// #include "models/calm_pedestrian_model.hpp"

// InputDataLoader* generateDataLoader(std::string type)
// {
// 	if(type == "xml")
// 	{
// 		InputXMLReader* inputXMLReader = new InputXMLReader;
// 		return inputXMLReader;
// 	}

// 	return nullptr;
// }

// OutputDataWriter* generateDataWriter(std::string type)
// {
// 	if(type == "xml")
// 	{
// 		XMLWriter* xmlWriter = new XMLWriter;
// 		return xmlWriter;
// 	}

// 	return nullptr;
// }

// SimulationOutputHandler* generateOutputHandler(std::string type)
// {
// 	if(type == "timestep")
// 	{
// 		TimestepOutputHandler* timestepOutputHandler = new TimestepOutputHandler;
// 		return timestepOutputHandler;
// 	}

// 	return nullptr;
// }

// PedestrianSet* generatePedestrianSet(std::string type)
// {
// 	if(type == "calm")
// 	{
// 		CalmPedestrianSet* calmPedSet = new CalmPedestrianSet;
// 		return calmPedSet;
// 	}

// 	return nullptr;
// }

// ObstacleSet* generateObstacleSet(std::string type)
// {
// 	if(type == "calm")
// 	{
// 		ObstacleSet* calmObsSet = new ObstacleSet;
// 		return calmObsSet;
// 	}

// 	return nullptr;
// }

// EntitySetFactory* generateEntitySetFactory(std::string type)
// {
// 	if(type == "calm")
// 	{
// 		CalmEntitySetFactory* calmSetFactory = new CalmEntitySetFactory;
// 		return calmSetFactory;
// 	}

// 	return nullptr;
// }

// Goals* generateGoals(std::string type)
// {
// 	if(type == "calm")
// 	{
// 		CalmGoals* calmGoals = new CalmGoals;
// 		return calmGoals;
// 	}

// 	return nullptr;
// }

// PedestrianDynamicsModel* generatePedDynamicsModel(std::string type)
// {
// 	if(type == "calm")
// 	{
// 		CalmPedestrianModel* calmPedModel = new CalmPedestrianModel;
// 		return calmPedModel;
// 	}

// 	return nullptr;
// }

// void populateEntitySets(
// 	PedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParams,
// 	InputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,
// 	std::string pedSetFile, std::string obsSetFile, std::string simParamsFile,
// 	std::string pedFileRootKey, std::string obsFileRootKey, std::string simParamsFileRootKey)
// {
// 	inputDataLoader->extractFileData(pedSetFile, pedFileRootKey);
// 	ENTITY_SET pedInputFileData = inputDataLoader->getInputEntities();
// 	entitySetFactory->populatePedestrianSet(pedInputFileData, pedestrianSet);

// 	inputDataLoader->extractFileData(obsSetFile, obsFileRootKey);
// 	ENTITY_SET obsInputFileData = inputDataLoader->getInputEntities();
// 	entitySetFactory->populateObstacleSet(obsInputFileData, obstacleSet);

// 	inputDataLoader->extractFileData(simParamsFile, simParamsFileRootKey);
// 	ENTITY_SET simParamsFileData = inputDataLoader->getInputEntities();
// 	entitySetFactory->populateSimulationParams(simParamsFileData, simulationParams);
// }

// int main() { return 0; }