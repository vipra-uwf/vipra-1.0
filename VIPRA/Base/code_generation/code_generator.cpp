
#include <string>

#include <unordered_map>

#include "configuration/configuration_reader.hpp"

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

std::string runSim();
std::string outputSetup();

bool                     requireCompiled = true;
std::string              outputFile;
std::string              optionsFile;
std::vector<std::string> includes;
VIPRA::Config::Map       jsonObj;

const std::unordered_map<std::string, std::string> TYPES{{"pedestrian_dynamics_model", "PedestrianDynamicsModel"},
                                                         {"goals", "Goals"},
                                                         {"output_data_writer", "OutputDataWriter"},
                                                         {"simulation_output_handler", "SimulationOutputHandler"},
                                                         {"pedestrian_set", "PedestrianSet"},
                                                         {"obstacle_set", "ObstacleSet"},
                                                         {"configuration_reader", "ConfigurationReader"},
                                                         {"clock", "Clock"},
                                                         {"simulation", "Simulation"},
                                                         {"policy_model", "PolicyModel"},
                                                         {"map_loader", "MapLoader"},
                                                         {"pedestrian_loader", "PedestrianLoader"},
                                                         {"human_behavior_model", "HumanBehaviorModel"},
                                                         {"configuration_writer", "PedestrianConfigWriter"}};

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

  mainFile << includes_Str << functionDecls_Str << getInputFiles_Str << mainFunction_Str << objectFunctions_Str
           << extractConfigMap_Str;

  mainFile.close();

  return 0;
}

void
setFiles(int argc, const char** argv) {
  if (argc > 4 || argc < 3) {
    std::cerr << "Usage: generate_main *output file* *options file*\n";
    exit(1);
  }

  outputFile = std::string(argv[1]);
  optionsFile = std::string(argv[2]);
  if (argc == 4) {
    requireCompiled = (strcmp(argv[3], "-noCompReq") != 0);
  }
}

std::string
generateIncludes() {
  std::string generatedIncludes = "";
  for (const auto& t : TYPES) {
    for (const auto& option : jsonObj[t.first]) {
      const auto& module = option["object"];
      if (!requireCompiled || module["compiled"]) {
        includes.emplace_back(option["dirPath"].asString() + "/" + module["name"].asString() + ".hpp");
      }
    }
  }

  for (const auto& include : includes) {
    generatedIncludes += "#include \"" + include + "\"\n";
  }

  generatedIncludes += "#include \"definitions/config_map.hpp\"\n";
  generatedIncludes += "#include <spdlog/spdlog.h>\n";
  generatedIncludes += "#include <memory>\n";
  return generatedIncludes;
}
std::string
generateFunctionDeclarations() {
  std::string generatedDeclarations = "\nVIPRA::Config::Map extractConfigMap(std::string name);";

  for (const auto& [type, className] : TYPES) {
    generatedDeclarations += "std::unique_ptr<" + className + "> generate" + className +
                             "(std::string id, const VIPRA::Config::Map& configMap);\n";
  }

  return generatedDeclarations;
}

std::string
generateObjectFunction(const std::string& className, const std::string& type) {
  std::string generatedFunction = "\nstd::unique_ptr<" + className + "> generate" + className +
                                  "(std::string id, const VIPRA::Config::Map& configMap)\n"
                                  "{\n";

  generatedFunction += generateFunctionOptions(type);

  return generatedFunction;
}

std::string
generateFunctionOptions(const std::string& type) {
  std::string generatedFunction{""};
  for (const auto& option : jsonObj[type]) {
    const auto& module = option["object"];
    if (!requireCompiled || module["compiled"]) {
      generatedFunction += Log("Creating " + type + " Implementation") + "\n\tif(id==\"" + module["id"].asString() +
                           "\"){\n\t\tstd::unique_ptr<" + module["className"].asString() + "> " + module["name"].asString() +
                           " = std::make_unique<" + module["className"].asString() + ">();\n\t\t" +
                           Log("Configuring " + type + " Module: ID: " + module["id"].asString()) + "\n\t\t" +
                           module["name"].asString() + "->configure(configMap);" + "\n\t\treturn " +
                           module["name"].asString() + ";" + "\n\t}";
    }
  }
  generatedFunction +=
      "\n\tthrow std::runtime_error(\"No Valid Module of Type: " + type + " Was Chosen. Provided ID: \" + id);";
  generatedFunction += "\n\treturn nullptr;\n}";
  return generatedFunction;
}

std::string
generateExtractConfigMap() {
  return {"\nVIPRA::Config::Map extractConfigMap(std::string name)"
          "\n{"
          "\n\tVIPRA::Config::Map configMap;"
          "\n\tfor(unsigned int i = 0; i < "
          "moduleParams[name].size(); i++)"
          "\n\t{"
          "\n\tauto attribute = moduleParams[name].getMemberNames()[i];"
          "\n\tauto value = moduleParams[name][attribute];"
          "\n\t\tconfigMap[attribute] = value;"
          "\n\t}"
          "\n"
          "\n\treturn configMap;"
          "\n}"};
}

std::string
generateMain() {
  std::string mainFunction = "";

  mainFunction += mainFunctionDefinition();
  mainFunction += "\n\#ifdef DEBUG_OUTPUT"
                  "\n\tspdlog::set_level(spdlog::level::debug);"
                  "\n\tspdlog::info(\"Set Logging Level To Debug\");"
                  "\n\#endif";
  mainFunction += makeModuleConfigs();
  mainFunction += generateModules();
  mainFunction += Log("Generating Modules");
  mainFunction += initializeModules();
  mainFunction += Log("Setting Up Output Handlers");
  mainFunction += outputSetup();
  mainFunction += runSim();
  mainFunction += "\n}";

  return mainFunction;
}

std::string
initializeModules() {
  //Call config writer before pedestrian loader
  return Log("Initializing Map Loader") + "\n\tmap_loader->initialize();\n\t" + Log("Loading Map") +
         "\n\tauto map = map_loader->LoadMap(obstacleFile);\n\t" + Log("Initializing Obstacle Set") +
         "\n\tobstacle_set->initialize(std::move(map));\n\t" + Log("Writing Pedestrian Config And Loading Pedestrians") +
         "\n\tauto peds = pedestrian_loader->LoadPedestrians(configuration_writer->buildPedestrians(pedestrianFile));\n\t" + Log("Initializing Pedestrian Set") +
         "\n\tpedestrian_set->initialize(std::move(peds));\n\t" + Log("Initializing Goals") +
         "\n\tgoals->initialize(*obstacle_set, *pedestrian_set);\n\t" + Log("Initializing Pedestrian Dynamics Model") +
         "\n\tpedestrian_dynamics_model->initialize(*pedestrian_set, *obstacle_set, *goals);\n\t" +
         Log("Initializing Human Behavior Model") +
         "\n\thuman_behavior_model->initialize(*pedestrian_set, *obstacle_set, *goals);\n\t" +
         Log("Initializing Simulation") + "\n\tsimulation->initialize();\n\t";
}

std::string
mainFunctionDefinition() {
  return "\nVIPRA::Config::Map simulationJsonConfig;"
         "\nVIPRA::Config::Map moduleParams;"
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
    str += "\n\tstd::unique_ptr<" + className + "> " + type + " = generate" + className +
           "(simulationJsonConfig[\"modules\"][\"" + type + "\"].asString(), " + type + "Config);";
  }

  return str;
}

std::string
makeModuleConfigs() {
  std::string str{""};
  for (const auto& [type, className] : TYPES) {
    str += "\n\tVIPRA::Config::Map " + type + "Config =  extractConfigMap(\"" + type + "\");";
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
          "void getInputFiles(int argc, const char** argv);"
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
  return "spdlog::info( \"" + message + "\");\n";
}