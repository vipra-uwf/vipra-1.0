#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/simulation/simulation/simulation.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/simulation/data/data.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/simulation/clock/clock.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/configuration/configuration_reader.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/humanbehavior/human_behavior_model.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/calm_entity_set_factory/calm_entity_set_factory.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/inputdataloader/input_json_reader/input_json_reader.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/outputdatawriter/json_timestep_writer/json_timestep_writer.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/outputdatawriter/json_writer/json_writer.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/calm_goals/calm_goals.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/simulationoutputhandler/timestep_console_logger/timestep_console_logger.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/Base/simulationoutputhandler/timestep_output_handler/timestep_output_handler.hpp"
#include "C:\Users\Goode\Documents\VIPRA\vipra\VIPRA_DEV/calm_pedestrian_model/calm_pedestrian_model.hpp"

CONFIG_MAP* extractConfigMap(std::string name);
void getInputFiles(int argc, const char** argv);Simulation* generateSimulation(std::string id, CONFIG_MAP* configMap);
Data* generateData(std::string id, CONFIG_MAP* configMap);
Clock* generateClock(std::string id, CONFIG_MAP* configMap);
ConfigurationReader* generateConfigurationReader(std::string id, CONFIG_MAP* configMap);
HumanBehaviorModel* generateHumanBehaviorModel(std::string id, CONFIG_MAP* configMap);
EntitySetFactory* generateEntitySetFactory(std::string id, CONFIG_MAP* configMap);
ObstacleSet* generateObstacleSet(std::string id, CONFIG_MAP* configMap);
PedestrianSet* generatePedestrianSet(std::string id, CONFIG_MAP* configMap);
InputDataLoader* generateInputDataLoader(std::string id, CONFIG_MAP* configMap);
OutputDataWriter* generateOutputDataWriter(std::string id, CONFIG_MAP* configMap);
Goals* generateGoals(std::string id, CONFIG_MAP* configMap);
SimulationOutputHandler* generateSimulationOutputHandler(std::string id, CONFIG_MAP* configMap);
PedestrianDynamicsModel* generatePedestrianDynamicsModel(std::string id, CONFIG_MAP* configMap);

std::string paramsFile;
std::string configFile;
std::string pedestrianFile;
std::string obstacleFile;
std::string outputFile;
void getInputFiles(int argc, const char** argv){
	if(argc > 6 || argc < 6){
		std::cerr << "Invalid inputs";

		exit(1);
	}
	configFile=argv[1];
	paramsFile=argv[2];
	pedestrianFile=argv[3];
	obstacleFile=argv[4];
	outputFile=argv[5];
}
Json::Value simulationJsonConfig;

Json::Value moduleParams;

int main(int argc, const char **argv)
{
	getInputFiles(argc, argv);
	ConfigurationReader configurationReader;
	configurationReader.readJsonConfiguration(configFile);
	simulationJsonConfig = configurationReader.getJsonObject();
	configurationReader.readJsonConfiguration(paramsFile);
	moduleParams = configurationReader.getJsonObject();
	CONFIG_MAP* simulationConfig =  extractConfigMap("simulation");
	CONFIG_MAP* dataConfig =  extractConfigMap("data");
	CONFIG_MAP* clockConfig =  extractConfigMap("clock");
	CONFIG_MAP* configuration_readerConfig =  extractConfigMap("configuration_reader");
	CONFIG_MAP* human_behavior_modelConfig =  extractConfigMap("human_behavior_model");
	CONFIG_MAP* entity_set_factoryConfig =  extractConfigMap("entity_set_factory");
	CONFIG_MAP* obstacle_setConfig =  extractConfigMap("obstacle_set");
	CONFIG_MAP* pedestrian_setConfig =  extractConfigMap("pedestrian_set");
	CONFIG_MAP* input_data_loaderConfig =  extractConfigMap("input_data_loader");
	CONFIG_MAP* output_data_writerConfig =  extractConfigMap("output_data_writer");
	CONFIG_MAP* goalsConfig =  extractConfigMap("goals");
	CONFIG_MAP* simulation_output_handlerConfig =  extractConfigMap("simulation_output_handler");
	CONFIG_MAP* pedestrian_dynamics_modelConfig =  extractConfigMap("pedestrian_dynamics_model");
	Simulation* simulation = generateSimulation(simulationJsonConfig["simulation"]["id"].asString(), simulationConfig);
	Data* data = generateData(simulationJsonConfig["data"]["id"].asString(), dataConfig);
	Clock* clock = generateClock(simulationJsonConfig["clock"]["id"].asString(), clockConfig);
	ConfigurationReader* configuration_reader = generateConfigurationReader(simulationJsonConfig["configuration_reader"]["id"].asString(), configuration_readerConfig);
	HumanBehaviorModel* human_behavior_model = generateHumanBehaviorModel(simulationJsonConfig["human_behavior_model"]["id"].asString(), human_behavior_modelConfig);
	EntitySetFactory* entity_set_factory = generateEntitySetFactory(simulationJsonConfig["entity_set_factory"]["id"].asString(), entity_set_factoryConfig);
	ObstacleSet* obstacle_set = generateObstacleSet(simulationJsonConfig["obstacle_set"]["id"].asString(), obstacle_setConfig);
	PedestrianSet* pedestrian_set = generatePedestrianSet(simulationJsonConfig["pedestrian_set"]["id"].asString(), pedestrian_setConfig);
	InputDataLoader* input_data_loader = generateInputDataLoader(simulationJsonConfig["input_data_loader"]["id"].asString(), input_data_loaderConfig);
	OutputDataWriter* output_data_writer = generateOutputDataWriter(simulationJsonConfig["output_data_writer"]["id"].asString(), output_data_writerConfig);
	Goals* goals = generateGoals(simulationJsonConfig["goals"]["id"].asString(), goalsConfig);
	SimulationOutputHandler* simulation_output_handler = generateSimulationOutputHandler(simulationJsonConfig["simulation_output_handler"]["id"].asString(), simulation_output_handlerConfig);
	PedestrianDynamicsModel* pedestrian_dynamics_model = generatePedestrianDynamicsModel(simulationJsonConfig["pedestrian_dynamics_model"]["id"].asString(), pedestrian_dynamics_modelConfig);

#ifdef DEBUG_OUTPUT
std::cout << reading obstacledata << std::endl;
#endif
	input_data_loader->extractFileData(obstacleFile, nullptr);
	ENTITY_SET obstacleData = input_data_loader->getInputEntities();

#ifdef DEBUG_OUTPUT
std::cout << done reading << std::endl;
#endif
	entity_set_factory->populateObstacleSet(obstacleData, obstacle_set);

#ifdef DEBUG_OUTPUT
std::cout << populated obstacleset << std::endl;
#endif

#ifdef DEBUG_OUTPUT
std::cout << reading pedestriandata << std::endl;
#endif
	input_data_loader->extractFileData(pedestrianFile, nullptr);
	ENTITY_SET pedestrianData = input_data_loader->getInputEntities();

#ifdef DEBUG_OUTPUT
std::cout << done reading << std::endl;
#endif
	entity_set_factory->populatePedestrianSet(pedestrianData, pedestrian_set);

#ifdef DEBUG_OUTPUT
std::cout << populated pedestrianset << std::endl;
#endif
	data->setPedestrianSet(pedestrian_set);
	data->setObstacleSet(obstacle_set);

	goals->setData(data);
	goals->addExitGoals(*obstacle_set);
	pedestrian_dynamics_model->setData(data);
	pedestrian_dynamics_model->setGoals(goals);
	goals->determinePedestrianGoals();
	pedestrian_dynamics_model->initialize();
	human_behavior_model->setData(data);
	simulation->setData(data);
	simulation->setPedestrianModel(pedestrian_dynamics_model);
	simulation->setHumanBehaviorModel(human_behavior_model);

#ifdef DEBUG_OUTPUT
std::cout << setting up output << std::endl;
#endif
	output_data_writer->initializeOutputFile(outputFile);
	simulation_output_handler->setOutputDataWriter(output_data_writer);
	simulation_output_handler->setPedestrianSet(pedestrian_set);
	simulation_output_handler->setSimulation(simulation);

	simulation->setSimulationOutputHandler(simulation_output_handler);

#ifdef DEBUG_OUTPUT
std::cout << done setting up output << std::endl;
#endif

#ifdef DEBUG_OUTPUT
std::cout << running simulation << std::endl;
#endif
	simulation->run();
	delete input_data_loader;
	delete output_data_writer;
	delete pedestrian_set;
	delete obstacle_set;
	delete entity_set_factory;
	delete goals;
	delete pedestrian_dynamics_model;
	delete human_behavior_model;
	delete simulation_output_handler;
	delete input_data_loaderConfig;
	delete output_data_writerConfig;
	delete pedestrian_setConfig;
	delete obstacle_setConfig;
	delete entity_set_factoryConfig;
	delete goalsConfig;
	delete pedestrian_dynamics_modelConfig;
	delete human_behavior_modelConfig;
	delete simulation_output_handlerConfig;
}
Simulation* generateSimulation(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating simulation << std::endl;
#endif
	if(id=="QQgWGHtxsVWT1jIEXbxjKG1HA3iqI0"){
		Simulation* simulation = new Simulation();
		simulation->configure(configMap);
		return simulation;
	}
	return nullptr;
}
Data* generateData(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating data << std::endl;
#endif
	if(id=="MJk1zG6WMVTwUT82QroZXohn3gnfT4"){
		Data* data = new Data();
		data->configure(configMap);
		return data;
	}
	return nullptr;
}
Clock* generateClock(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating clock << std::endl;
#endif
	if(id=="NUpICP9g2eBe9GGYBXmx1jofH9TC7k"){
		Clock* clock = new Clock();
		clock->configure(configMap);
		return clock;
	}
	return nullptr;
}
ConfigurationReader* generateConfigurationReader(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating configuration_reader << std::endl;
#endif
	if(id=="5E4V21CyOwU5iMBfH97qlFDn6DlAlf"){
		ConfigurationReader* configuration_reader = new ConfigurationReader();
		configuration_reader->configure(configMap);
		return configuration_reader;
	}
	return nullptr;
}
HumanBehaviorModel* generateHumanBehaviorModel(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating human_behavior_model << std::endl;
#endif
	if(id=="e3y1yG6PSjrWzsptf6jHdfBElwFugQ"){
		HumanBehaviorModel* human_behavior_model = new HumanBehaviorModel();
		human_behavior_model->configure(configMap);
		return human_behavior_model;
	}
	return nullptr;
}
EntitySetFactory* generateEntitySetFactory(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating entity_set_factory << std::endl;
#endif
	if(id=="h6fJTJdM5L9q8wjXEvN6Cq8D14MUeX"){
		CalmEntitySetFactory* calm_entity_set_factory = new CalmEntitySetFactory();
		calm_entity_set_factory->configure(configMap);
		return calm_entity_set_factory;
	}
	return nullptr;
}
ObstacleSet* generateObstacleSet(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating obstacle_set << std::endl;
#endif
	if(id=="MTpemEr4jv5XTvgwO7q54Qco97Pnt4"){
		AirplaneObstacleSet* airplane_obstacle_set = new AirplaneObstacleSet();
		airplane_obstacle_set->configure(configMap);
		return airplane_obstacle_set;
	}
	return nullptr;
}
PedestrianSet* generatePedestrianSet(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating pedestrian_set << std::endl;
#endif
	if(id=="jLcPe7ZP8G15AFH5vPb6Wz2DrIVT94"){
		CalmPedestrianSet* calm_pedestrian_set = new CalmPedestrianSet();
		calm_pedestrian_set->configure(configMap);
		return calm_pedestrian_set;
	}
	return nullptr;
}
InputDataLoader* generateInputDataLoader(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating input_data_loader << std::endl;
#endif
	if(id=="bQIGJDQw0Fgqo4oC3lH7mQerFGTQry"){
		InputJSONReader* input_json_reader = new InputJSONReader();
		input_json_reader->configure(configMap);
		return input_json_reader;
	}
	return nullptr;
}
OutputDataWriter* generateOutputDataWriter(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating output_data_writer << std::endl;
#endif
	if(id=="esBm2A3I0yIbGvzW5bLY0yKHJTzVCj"){
		JSONTimestepWriter* json_timestep_writer = new JSONTimestepWriter();
		json_timestep_writer->configure(configMap);
		return json_timestep_writer;
	}

#ifdef DEBUG_OUTPUT
std::cout << generating output_data_writer << std::endl;
#endif
	if(id=="f8qt7eLCczzFMjToJBsA5qYUz1A8E6"){
		JSONWriter* json_writer = new JSONWriter();
		json_writer->configure(configMap);
		return json_writer;
	}
	return nullptr;
}
Goals* generateGoals(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating goals << std::endl;
#endif
	if(id=="Xz59g1o8HcsnMJlKaiYw00wZ19rB7P"){
		CalmGoals* calm_goals = new CalmGoals();
		calm_goals->configure(configMap);
		return calm_goals;
	}
	return nullptr;
}
SimulationOutputHandler* generateSimulationOutputHandler(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating simulation_output_handler << std::endl;
#endif
	if(id=="RfH40LtLJjHOlPIEeTj0i6ghBygQsZ"){
		TimestepConsoleLogger* timestep_console_logger = new TimestepConsoleLogger();
		timestep_console_logger->configure(configMap);
		return timestep_console_logger;
	}

#ifdef DEBUG_OUTPUT
std::cout << generating simulation_output_handler << std::endl;
#endif
	if(id=="0bQVYYyskvxYq6YW4J67z73UB6GbnU"){
		TimestepOutputHandler* timestep_output_handler = new TimestepOutputHandler();
		timestep_output_handler->configure(configMap);
		return timestep_output_handler;
	}
	return nullptr;
}
PedestrianDynamicsModel* generatePedestrianDynamicsModel(std::string id, CONFIG_MAP* configMap)
{


#ifdef DEBUG_OUTPUT
std::cout << generating pedestrian_dynamics_model << std::endl;
#endif
	if(id=="VbGjNW5NCkOmKAxvFmz5KwUV2zz469"){
		CalmPedestrianModel* calm_pedestrian_model = new CalmPedestrianModel();
		calm_pedestrian_model->configure(configMap);
		return calm_pedestrian_model;
	}
	return nullptr;
}
CONFIG_MAP* extractConfigMap(std::string name)
{
	CONFIG_MAP* configMap = new CONFIG_MAP;

#ifdef DEBUG_OUTPUT
std::cout << "extracting config map:" + name << std::endl;
#endif
	for(unsigned int i = 0; i < moduleParams[name]["params"].size(); i++)
	{
		std::string attribute = moduleParams[name]["params"].getMemberNames()[i];
		std::string value = moduleParams[name]["params"][attribute].asString();

		std::cout << "ATTRIBUTE: " << attribute << " : " << value << '\n';

		(*configMap)[attribute] = value;
	}

	return configMap;
}