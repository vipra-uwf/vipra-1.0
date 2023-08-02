#ifndef PARALLEL_MAIN_HPP
#define PARALLEL_MAIN_HPP
// NOLINTBEGIN (rolland) No point in linting generated code : ignoring (all) 
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/human_behavior/human_behavior_model.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/Modules/PedestrianLoader/json_pedestrian_loader/json_pedestrian_loader.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/simulation/simulation.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/configuration/configuration_reader.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/Modules/ObstacleSet/passenger_vehicle_obstacle_set/passenger_vehicle_obstacle_set.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/Modules/PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/output_data_writer/json_timestep_writer/json_timestep_writer.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/output_data_writer/json_writer/json_writer.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/Modules/MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/policy_model/policy_model.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/Modules/Goals/calm_goals/calm_goals.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/simulation_output_handler/timestep_console_logger/timestep_console_logger.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/VIPRA/Base/simulation_output_handler/timestep_output_handler/timestep_output_handler.hpp"
#include "/home/rolland/Documents/VIPRA/vipra/Modules/PedestrianDynamicsModel/calm_pedestrian_model/calm_pedestrian_model.hpp"
#include <spdlog/spdlog.h>
#include <memory>

#include <clock/clock.hpp>
#include <definitions/config_map.hpp>

VIPRA::CONFIG::Map extractConfigMap(std::string name);std::unique_ptr<HumanBehaviorModel> generateHumanBehaviorModel(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<PedestrianLoader> generatePedestrianLoader(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<Simulation> generateSimulation(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<ConfigurationReader> generateConfigurationReader(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<ObstacleSet> generateObstacleSet(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<PedestrianSet> generatePedestrianSet(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<OutputDataWriter> generateOutputDataWriter(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<MapLoader> generateMapLoader(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<PolicyModel> generatePolicyModel(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<Goals> generateGoals(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<SimulationOutputHandler> generateSimulationOutputHandler(const std::string& id, const VIPRA::CONFIG::Map& configMap);
std::unique_ptr<PedestrianDynamicsModel> generatePedestrianDynamicsModel(const std::string& id, const VIPRA::CONFIG::Map& configMap);

std::string configFile;
std::string minConfigFile;
std::string maxConfigFile;
std::string pedestrianFile;
std::string obstacleFile;
std::string outputFile;
VIPRA::Clock<VIPRA::milli> timer;
void getInputFiles(int argc, char** argv);
void getInputFiles(int argc, char** argv){
	if(argc > 8 || argc < 8){
		std::cerr << "Invalid inputs: Usage: *Config Path* *Params Path* *Pedestrians path* *Obstacle Path* *Output Path*\n";

		exit(1);
	}
	configFile=argv[2];
	minConfigFile=argv[3];
	maxConfigFile=argv[4];
	pedestrianFile=argv[5];
	obstacleFile=argv[6];
	outputFile=argv[7];
}
VIPRA::CONFIG::Map simulationJsonConfig;
VIPRA::CONFIG::Map moduleParams;
void parallel_main(const VIPRA::CONFIG::Map& simconfig, const VIPRA::CONFIG::Map& moduleparams) {
	simulationJsonConfig = simconfig;
	moduleParams = moduleparams;
#ifndef NDEBUG
	spdlog::set_level(spdlog::level::debug);
	spdlog::info("Set Logging Level To Debug");
#endif
	VIPRA::CONFIG::Map human_behavior_modelConfig =  extractConfigMap("human_behavior_model");
	VIPRA::CONFIG::Map pedestrian_loaderConfig =  extractConfigMap("pedestrian_loader");
	VIPRA::CONFIG::Map simulationConfig =  extractConfigMap("simulation");
	VIPRA::CONFIG::Map configuration_readerConfig =  extractConfigMap("configuration_reader");
	VIPRA::CONFIG::Map obstacle_setConfig =  extractConfigMap("obstacle_set");
	VIPRA::CONFIG::Map pedestrian_setConfig =  extractConfigMap("pedestrian_set");
	VIPRA::CONFIG::Map output_data_writerConfig =  extractConfigMap("output_data_writer");
	VIPRA::CONFIG::Map map_loaderConfig =  extractConfigMap("map_loader");
	VIPRA::CONFIG::Map policy_modelConfig =  extractConfigMap("policy_model");
	VIPRA::CONFIG::Map goalsConfig =  extractConfigMap("goals");
	VIPRA::CONFIG::Map simulation_output_handlerConfig =  extractConfigMap("simulation_output_handler");
	VIPRA::CONFIG::Map pedestrian_dynamics_modelConfig =  extractConfigMap("pedestrian_dynamics_model");
	std::unique_ptr<HumanBehaviorModel> human_behavior_model = generateHumanBehaviorModel(simulationJsonConfig["modules"]["human_behavior_model"].asString(), human_behavior_modelConfig);
	std::unique_ptr<PedestrianLoader> pedestrian_loader = generatePedestrianLoader(simulationJsonConfig["modules"]["pedestrian_loader"].asString(), pedestrian_loaderConfig);
	std::unique_ptr<Simulation> simulation = generateSimulation(simulationJsonConfig["modules"]["simulation"].asString(), simulationConfig);
	std::unique_ptr<ConfigurationReader> configuration_reader = generateConfigurationReader(simulationJsonConfig["modules"]["configuration_reader"].asString(), configuration_readerConfig);
	std::unique_ptr<ObstacleSet> obstacle_set = generateObstacleSet(simulationJsonConfig["modules"]["obstacle_set"].asString(), obstacle_setConfig);
	std::unique_ptr<PedestrianSet> pedestrian_set = generatePedestrianSet(simulationJsonConfig["modules"]["pedestrian_set"].asString(), pedestrian_setConfig);
	std::unique_ptr<OutputDataWriter> output_data_writer = generateOutputDataWriter(simulationJsonConfig["modules"]["output_data_writer"].asString(), output_data_writerConfig);
	std::unique_ptr<MapLoader> map_loader = generateMapLoader(simulationJsonConfig["modules"]["map_loader"].asString(), map_loaderConfig);
	std::unique_ptr<PolicyModel> policy_model = generatePolicyModel(simulationJsonConfig["modules"]["policy_model"].asString(), policy_modelConfig);
	std::unique_ptr<Goals> goals = generateGoals(simulationJsonConfig["modules"]["goals"].asString(), goalsConfig);
	std::unique_ptr<SimulationOutputHandler> simulation_output_handler = generateSimulationOutputHandler(simulationJsonConfig["modules"]["simulation_output_handler"].asString(), simulation_output_handlerConfig);
	std::unique_ptr<PedestrianDynamicsModel> pedestrian_dynamics_model = generatePedestrianDynamicsModel(simulationJsonConfig["modules"]["pedestrian_dynamics_model"].asString(), pedestrian_dynamics_modelConfig);spdlog::info( "Generating Modules");
spdlog::info( "Initializing Map Loader");

	map_loader->initialize();
	spdlog::info( "Loading Map");

	auto map = map_loader->loadMap(obstacleFile);
	spdlog::info( "Initializing Obstacle Set");

	timer.start();
	obstacle_set->initialize(std::move(map));
	auto stopTime = timer.stop(); spdlog::debug("Obstacle Set Initialization: {}", stopTime);
	spdlog::info( "Writing Pedestrian Config And Loading Pedestrians");

	timer.start();
	auto peds = pedestrian_loader->loadPedestrians(pedestrianFile);
	
	stopTime = timer.stop(); spdlog::debug("Loading Pedestrians: {}", stopTime);
	spdlog::info( "Initializing Pedestrian Set");

	timer.start();
	pedestrian_set->initialize(std::move(peds));
	
	stopTime = timer.stop(); spdlog::debug("Pedestrian Set Initialization: {}", stopTime);
	spdlog::info( "Initializing Goals");

	timer.start();
	goals->initialize(*obstacle_set, *pedestrian_set);
	
	stopTime = timer.stop(); spdlog::debug("Goals Initialization: {}", stopTime);
	spdlog::info( "Initializing Pedestrian Dynamics Model");

	timer.start();
	pedestrian_dynamics_model->initialize(*pedestrian_set, *obstacle_set, *goals);
	
	stopTime = timer.stop(); spdlog::debug("Pedestrian Model Initialization: {}", stopTime);
	spdlog::info( "Initializing Human Behavior Model");

	timer.start();
	human_behavior_model->initialize(*pedestrian_set, *obstacle_set, *goals);
	
	stopTime = timer.stop(); spdlog::debug("Behavior Model Initialization: {}", stopTime);
	spdlog::info( "Initializing Simulation");

	simulation->initialize();
	spdlog::info( "Setting Up Output Handlers");

	output_data_writer->initializeOutputFile(outputFile);
	simulation->run(*goals,*pedestrian_set,*obstacle_set,*pedestrian_dynamics_model,*human_behavior_model,*policy_model,*output_data_writer,*simulation_output_handler);
	output_data_writer->writeToDocument();
}
std::unique_ptr<HumanBehaviorModel> generateHumanBehaviorModel(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating human_behavior_model Implementation");

	if(id=="e3y1yG6PSjrWzsptf6jHdfBElwFugQ"){
		std::unique_ptr<HumanBehaviorModel> human_behavior_model = std::make_unique<HumanBehaviorModel>();
		spdlog::info( "Configuring human_behavior_model Module: ID: e3y1yG6PSjrWzsptf6jHdfBElwFugQ");

		human_behavior_model->configure(configMap);
		return human_behavior_model;
	}
	spdlog::error("No Valid Module of Type: human_behavior_modelWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<PedestrianLoader> generatePedestrianLoader(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating pedestrian_loader Implementation");

	if(id=="8oGawQjwJZutb4Us6lDU7R"){
		std::unique_ptr<JsonPedestrianLoader> json_pedestrian_loader = std::make_unique<JsonPedestrianLoader>();
		spdlog::info( "Configuring pedestrian_loader Module: ID: 8oGawQjwJZutb4Us6lDU7R");

		json_pedestrian_loader->configure(configMap);
		return json_pedestrian_loader;
	}
	spdlog::error("No Valid Module of Type: pedestrian_loaderWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<Simulation> generateSimulation(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating simulation Implementation");

	if(id=="QQgWGHtxsVWT1jIEXbxjKG1HA3iqI0"){
		std::unique_ptr<Simulation> simulation = std::make_unique<Simulation>();
		spdlog::info( "Configuring simulation Module: ID: QQgWGHtxsVWT1jIEXbxjKG1HA3iqI0");

		simulation->configure(configMap);
		return simulation;
	}
	spdlog::error("No Valid Module of Type: simulationWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<ConfigurationReader> generateConfigurationReader(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating configuration_reader Implementation");

	if(id=="5E4V21CyOwU5iMBfH97qlFDn6DlAlf"){
		std::unique_ptr<ConfigurationReader> configuration_reader = std::make_unique<ConfigurationReader>();
		spdlog::info( "Configuring configuration_reader Module: ID: 5E4V21CyOwU5iMBfH97qlFDn6DlAlf");

		configuration_reader->configure(configMap);
		return configuration_reader;
	}
	spdlog::error("No Valid Module of Type: configuration_readerWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<ObstacleSet> generateObstacleSet(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating obstacle_set Implementation");

	if(id=="MTpemEr4jv5XTvgwO7q54Qco97Pnt4"){
		std::unique_ptr<PassengerVehicleObstacleSet> passenger_vehicle_obstacle_set = std::make_unique<PassengerVehicleObstacleSet>();
		spdlog::info( "Configuring obstacle_set Module: ID: MTpemEr4jv5XTvgwO7q54Qco97Pnt4");

		passenger_vehicle_obstacle_set->configure(configMap);
		return passenger_vehicle_obstacle_set;
	}
	spdlog::error("No Valid Module of Type: obstacle_setWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<PedestrianSet> generatePedestrianSet(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating pedestrian_set Implementation");

	if(id=="jLcPe7ZP8G15AFH5vPb6Wz2DrIVT94"){
		std::unique_ptr<CalmPedestrianSet> calm_pedestrian_set = std::make_unique<CalmPedestrianSet>();
		spdlog::info( "Configuring pedestrian_set Module: ID: jLcPe7ZP8G15AFH5vPb6Wz2DrIVT94");

		calm_pedestrian_set->configure(configMap);
		return calm_pedestrian_set;
	}
	spdlog::error("No Valid Module of Type: pedestrian_setWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<OutputDataWriter> generateOutputDataWriter(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating output_data_writer Implementation");

	if(id=="esBm2A3I0yIbGvzW5bLY0yKHJTzVCj"){
		std::unique_ptr<JSONTimestepWriter> json_timestep_writer = std::make_unique<JSONTimestepWriter>();
		spdlog::info( "Configuring output_data_writer Module: ID: esBm2A3I0yIbGvzW5bLY0yKHJTzVCj");

		json_timestep_writer->configure(configMap);
		return json_timestep_writer;
	}spdlog::info( "Creating output_data_writer Implementation");

	if(id=="f8qt7eLCczzFMjToJBsA5qYUz1A8E6"){
		std::unique_ptr<JSONWriter> json_writer = std::make_unique<JSONWriter>();
		spdlog::info( "Configuring output_data_writer Module: ID: f8qt7eLCczzFMjToJBsA5qYUz1A8E6");

		json_writer->configure(configMap);
		return json_writer;
	}
	spdlog::error("No Valid Module of Type: output_data_writerWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<MapLoader> generateMapLoader(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating map_loader Implementation");

	if(id=="YKzTon61i8LuHr9l15mCY3"){
		std::unique_ptr<PointMapLoader> point_map_loader = std::make_unique<PointMapLoader>();
		spdlog::info( "Configuring map_loader Module: ID: YKzTon61i8LuHr9l15mCY3");

		point_map_loader->configure(configMap);
		return point_map_loader;
	}
	spdlog::error("No Valid Module of Type: map_loaderWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<PolicyModel> generatePolicyModel(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating policy_model Implementation");

	if(id=="6xc3IZPOYEcdNhPd8x1kWP"){
		std::unique_ptr<PolicyModel> policy_model = std::make_unique<PolicyModel>();
		spdlog::info( "Configuring policy_model Module: ID: 6xc3IZPOYEcdNhPd8x1kWP");

		policy_model->configure(configMap);
		return policy_model;
	}
	spdlog::error("No Valid Module of Type: policy_modelWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<Goals> generateGoals(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating goals Implementation");

	if(id=="Xz59g1o8HcsnMJlKaiYw00wZ19rB7P"){
		std::unique_ptr<CalmGoals> calm_goals = std::make_unique<CalmGoals>();
		spdlog::info( "Configuring goals Module: ID: Xz59g1o8HcsnMJlKaiYw00wZ19rB7P");

		calm_goals->configure(configMap);
		return calm_goals;
	}
	spdlog::error("No Valid Module of Type: goalsWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<SimulationOutputHandler> generateSimulationOutputHandler(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating simulation_output_handler Implementation");

	if(id=="RfH40LtLJjHOlPIEeTj0i6ghBygQsZ"){
		std::unique_ptr<TimestepConsoleLogger> timestep_console_logger = std::make_unique<TimestepConsoleLogger>();
		spdlog::info( "Configuring simulation_output_handler Module: ID: RfH40LtLJjHOlPIEeTj0i6ghBygQsZ");

		timestep_console_logger->configure(configMap);
		return timestep_console_logger;
	}spdlog::info( "Creating simulation_output_handler Implementation");

	if(id=="0bQVYYyskvxYq6YW4J67z73UB6GbnU"){
		std::unique_ptr<TimestepOutputHandler> timestep_output_handler = std::make_unique<TimestepOutputHandler>();
		spdlog::info( "Configuring simulation_output_handler Module: ID: 0bQVYYyskvxYq6YW4J67z73UB6GbnU");

		timestep_output_handler->configure(configMap);
		return timestep_output_handler;
	}
	spdlog::error("No Valid Module of Type: simulation_output_handlerWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
std::unique_ptr<PedestrianDynamicsModel> generatePedestrianDynamicsModel(const std::string& id, const VIPRA::CONFIG::Map& configMap)
{
spdlog::info( "Creating pedestrian_dynamics_model Implementation");

	if(id=="VbGjNW5NCkOmKAxvFmz5KwUV2zz469"){
		std::unique_ptr<CalmPedestrianModel> calm_pedestrian_model = std::make_unique<CalmPedestrianModel>();
		spdlog::info( "Configuring pedestrian_dynamics_model Module: ID: VbGjNW5NCkOmKAxvFmz5KwUV2zz469");

		calm_pedestrian_model->configure(configMap);
		return calm_pedestrian_model;
	}
	spdlog::error("No Valid Module of Type: pedestrian_dynamics_modelWas Chosen. Provided ID: {} ",  id); 
	exit(1);
	return nullptr;
}
VIPRA::CONFIG::Map extractConfigMap(std::string name)
{
	VIPRA::CONFIG::Map configMap;
	for(unsigned int i = 0; i < moduleParams[name].size(); i++)
	{
		auto attribute = moduleParams[name].getMemberNames()[i];
		auto value = moduleParams[name][attribute];
		configMap[attribute] = value;
	}

	return configMap;
}
#endif
// NOLINTEND
