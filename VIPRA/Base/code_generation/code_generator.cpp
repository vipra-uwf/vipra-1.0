
#include <string>

#include "configuration/configuration_reader.hpp"
#include "lumberjack/lumberjack.hpp"

void        setFiles(int, char const*[]);
std::string Log(const std::string& message);

std::string generateGetFiles();
std::string generateIncludes();
std::string generateFunctionDeclarations();
std::string generateObjectFunction(const std::string& className, const std::string& type);
std::string generateFunctionOptions(const std::string& type);
std::string generateExtractConfigMap();
std::string generateMain();
std::string initializeModules();

std::string mainFunctionDefinition();
std::string generateModules();
std::string makeModuleConfigs();

std::string generateLogger();

std::string cleanup();
std::string runSim();
std::string outputSetup();

std::string              outputFile;
std::string              optionsFile;
std::vector<std::string> includes;
Json::Value              jsonObj;

const std::unordered_map<std::string, std::string> TYPES{
    {"pedestrian_dynamics_model", "PedestrianDynamicsModel"},
    {"goals", "Goals"},
    {"output_data_writer", "OutputDataWriter"},
    {"input_data_loader", "InputDataLoader"},
    {"simulation_output_handler", "SimulationOutputHandler"},
    {"pedestrian_set", "PedestrianSet"},
    {"obstacle_set", "ObstacleSet"},
    {"human_behavior_model", "HumanBehaviorModel"},
    {"configuration_reader", "ConfigurationReader"},
    {"clock", "Clock"},
    {"simulation", "Simulation"},
    {"policy_model", "PolicyModel"},
    {"map_loader", "MapLoader"},
    {"pedestrian_loader", "PedestrianLoader"}};

int
main(int argc, char const* argv[]) {

  setFiles(argc, argv);

  ConfigurationReader configurationReader;
  jsonObj = configurationReader.getConfiguration(optionsFile);

  std::string functionDecls_Str = generateFunctionDeclarations();
  std::string objectFunctions_Str{""};
  for (const auto& [type, className] : TYPES) {
    objectFunctions_Str += generateObjectFunction(className, type);
  }

  std::string logger_Str = generateLogger();
  std::string includes_Str = generateIncludes();
  std::string mainFunction_Str = generateMain();
  std::string getInputFiles_Str = generateGetFiles();
  std::string extractConfigMap_Str = generateExtractConfigMap();

  std::ofstream mainFile;
  mainFile.open(outputFile);
  if (!mainFile.is_open()) {
    std::cerr << "[ERROR] Unable to open output file\n";
    return -1;
  }

  mainFile << includes_Str << logger_Str << functionDecls_Str << getInputFiles_Str << mainFunction_Str
           << objectFunctions_Str << extractConfigMap_Str;

  mainFile.close();

  return 0;
}

void
setFiles(int argc, const char** argv) {
  if (argc > 3 || argc < 3) {
    std::cerr << "Usage: generate_main *output file* *options file*\n";
    exit(1);
  }

  outputFile = std::string(argv[1]);
  optionsFile = std::string(argv[2]);
}

std::string
generateIncludes() {
  std::string generatedIncludes = "";
  for (const auto& t : TYPES) {
    for (const auto& option : jsonObj[t.first]) {
      const auto& module = option["object"];
      if (module["compiled"]) {
        includes.emplace_back(option["dirPath"].asString() + "/" + module["name"].asString() + ".hpp");
      }
    }
  }

  for (const auto& include : includes) {
    generatedIncludes += "#include \"" + include + "\"\n";
  }

  generatedIncludes += "#include \"lumberjack/lumberjack.hpp\"";
  return generatedIncludes;
}

std::string
generateLogger() {
  return "\nLJ::Logger<LJ::ConsoleLogger> simLogger{LJ::DEBUG};";
}

std::string
generateFunctionDeclarations() {
  std::string generatedDeclarations = "\nVIPRA::ConfigMap* extractConfigMap(std::string name);";

  for (const auto& [type, className] : TYPES) {
    generatedDeclarations +=
        className + "* generate" + className + "(std::string id, VIPRA::ConfigMap* configMap);\n";
  }

  return generatedDeclarations;
}

std::string
generateObjectFunction(const std::string& className, const std::string& type) {
  std::string generatedFunction = "\n" + className + "* generate" + className +
                                  "(std::string id, VIPRA::ConfigMap* configMap)\n"
                                  "{\n";

  generatedFunction += generateFunctionOptions(type);

  return generatedFunction;
}

std::string
generateFunctionOptions(const std::string& type) {
  std::string generatedFunction{""};
  for (const auto& option : jsonObj[type]) {
    const auto& module = option["object"];
    if (module["compiled"]) {
      generatedFunction += Log("Creating " + type + " Implementation") + "\n\tif(id==\"" +
                           module["id"].asString() + "\"){\n\t\t" + module["className"].asString() + "* " +
                           module["name"].asString() + " = new " + module["className"].asString() + "();" +
                           Log("Configuring " + type + " Module: ID: " + module["id"].asString()) + "\n\t\t" +
                           module["name"].asString() + "->configure(*configMap);" + "\n\t\treturn " +
                           module["name"].asString() + ";" + "\n\t}";
    }
  }

  generatedFunction += "\n\treturn nullptr;\n}";
  return generatedFunction;
}

std::string
generateExtractConfigMap() {
  return {"\nVIPRA::ConfigMap* extractConfigMap(std::string name)"
          "\n{"
          "\n\tVIPRA::ConfigMap* configMap = new VIPRA::ConfigMap;"
          "\n\tfor(unsigned int i = 0; i < "
          "moduleParams[name][\"params\"].size(); i++)"
          "\n\t{"
          "\n\t\tstd::string attribute = "
          "moduleParams[name][\"params\"].getMemberNames()[i];"
          "\n\t\tstd::string value = "
          "moduleParams[name][\"params\"][attribute].asString();"
          "\n\tstd::cout << \"ATTRIBUTE: \" << attribute << \" : \" << value "
          "<< \'\\n\';"
          "\n\t\t(*configMap)[attribute] = value;"
          "\n\t}"
          "\n"
          "\n\treturn configMap;"
          "\n}"};
}

std::string
generateMain() {
  std::string mainFunction = "";

  mainFunction += mainFunctionDefinition();
  mainFunction += makeModuleConfigs();
  mainFunction += generateModules();
  mainFunction += Log("Generating Modules");
  mainFunction += initializeModules();
  mainFunction += Log("Setting Up Output Handlers");
  mainFunction += outputSetup();
  mainFunction += runSim();
  mainFunction += Log("Simulation CleanUp");
  mainFunction += cleanup();
  mainFunction += "\n}";

  return mainFunction;
}

std::string
initializeModules() {
  return Log("Initializing Map Loader") + "\n\tmap_loader->initialize();" + Log("Initializing Obstacle Set") +
         "\n\tobstacle_set->initialize(map_loader->LoadMap(obstacleFile));" +
         Log("Initializing Pedestrian Set") +
         "\n\tpedestrian_set->initialize(input_data_loader->getInputEntities(pedestrianFile));" +
         Log("Initializing Goals") + "\n\tgoals->initialize(*obstacle_set, *pedestrian_set);" +
         Log("Initializing Human Behavior Model") +
         "\n\thuman_behavior_model->initialize(*obstacle_set, *pedestrian_set, *goals);" +
         Log("Initializing Pedestrian Dynamics Model") +
         "\n\tpedestrian_dynamics_model->initialize(*pedestrian_set, *obstacle_set, *goals);" +
         Log("Initializing Simulation") + "\n\tsimulation->initialize();";
}

std::string
mainFunctionDefinition() {
  return "\nJson::Value simulationJsonConfig;"
         "\nJson::Value moduleParams;"
         "\nint main(int argc, const char **argv) {"
         "\n\tgetInputFiles(argc, argv);"
         "\n\tConfigurationReader configurationReader;"
         "\n\tsimulationJsonConfig = configurationReader.getConfiguration(configFile);"
         "\n\tmoduleParams = configurationReader.getConfiguration(paramsFile);";
}

std::string
generateModules() {
  std::string str{""};
  for (const auto& [type, className] : TYPES) {
    str += "\n\t" + className + "* " + type + " = generate" + className +
           "(simulationJsonConfig[\"modules\"][\"" + type + "\"].asString(), " + type + "Config);";
  }

  return str;
}

std::string
makeModuleConfigs() {
  std::string str{""};
  for (const auto& [type, className] : TYPES) {
    str += "\n\tVIPRA::ConfigMap* " + type + "Config =  extractConfigMap(\"" + type + "\");";
  }

  return str;
}

std::string
generateGetFiles() {
  return {"\nstd::string paramsFile;"
          "\nstd::string configFile;"
          "\nstd::string pedestrianFile;"
          "\nstd::string obstacleFile;"
          "\nstd::string outputFile;"
          "\nvoid getInputFiles(int argc, const char** argv){"
          "\n\tif(argc > 6 || argc < 6){"
          "\n\t\tstd::cerr << \"Invalid inputs: Usage: *Config Path* *Params Path* *Pedestrians path* "
          "*Obstacle Path* *Output Path*\\n\";\n"
          "\n\t\texit(1);"
          "\n\t}"
          "\n\tconfigFile=argv[1];"
          "\n\tparamsFile=argv[2];"
          "\n\tpedestrianFile=argv[3];"
          "\n\tobstacleFile=argv[4];"
          "\n\toutputFile=argv[5];"
          "\n}"};
}

std::string
cleanup() {
  std::string cleanupStr{""};
  for (const auto& [type, className] : TYPES) {
    cleanupStr += "\n\tdelete " + type + ";\n\tdelete " + type + "Config;";
  }

  return cleanupStr;
}

std::string
runSim() {
  return "\n\tsimulation->run(*goals,"
         "*pedestrian_set,"
         "*obstacle_set,"
         "*pedestrian_dynamics_model,"
         "*human_behavior_model,"
         "*policy_model,"
         "*output_data_writer,"
         "*simulation_output_handler,"
         "*clock);"
         "\n\toutput_data_writer->writeToDocument();";
}

std::string
outputSetup() {
  return "\n\toutput_data_writer->initializeOutputFile(outputFile);";
}

std::string
Log(const std::string& message) {
  return "LJ::Debug(simLogger, \"" + message + "\");\n";
}