
#include "../_pch/pch.hpp"
#include "../configuration/configuration_reader.hpp"

void setFiles(int, char const*[]);

std::string generateGetFiles();
std::string generateIncludes();
std::string generateFunctionDeclarations();
std::string generateObjectFunction(const std::string& className, const std::string& type);
std::string generateFunctionOptions(const std::string& type);
std::string generateExtractConfigMap();
std::string generateMain();

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
};

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

  mainFile << includes_Str << functionDecls_Str << getInputFiles_Str << mainFunction_Str
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
  for (const auto& include : includes) {
    generatedIncludes += "#include \"" + include + "\"\n";
  }
  return generatedIncludes;
}

std::string
generateFunctionDeclarations() {
  std::string generatedDeclarations =
      "\nCONFIG_MAP* extractConfigMap(std::string name);"
      "\nvoid getInputFiles(int argc, const char** argv);";

  for (const auto& [type, className] : TYPES) {
    generatedDeclarations += className + "* generate" + className +
                             "(std::string id, CONFIG_MAP* configMap);\n";
  }

  return generatedDeclarations;
}

std::string
generateObjectFunction(const std::string& className, const std::string& type) {
  std::string generatedFunction = "\n" + className + "* generate" + className +
                                  "(std::string id, CONFIG_MAP* configMap)\n"
                                  "{\n";

  generatedFunction += generateFunctionOptions(type);

  return generatedFunction;
}

std::string
generateFunctionOptions(const std::string& type) {
  std::string generatedFunction{""};
  for (const auto& option : jsonObj[type]) {
    if (option["compiled"]) {
      generatedFunction += "\n\tif(id==\"" + option["id"].asString() + "\"){\n\t\t" +
                           option["className"].asString() + "* " +
                           option["name"].asString() + " = new " +
                           option["className"].asString() + "();\n\t\t" +
                           option["name"].asString() + "->configure(*configMap);" +
                           "\n\t\treturn " + option["name"].asString() + ";" + "\n\t}";
      includes.emplace_back(option["includePath"].asString());
    }
  }

  generatedFunction += "\n\treturn nullptr;\n}";
  return generatedFunction;
}

std::string
generateExtractConfigMap() {
  return {"\nCONFIG_MAP* extractConfigMap(std::string name)"
          "\n{"
          "\n\tCONFIG_MAP* configMap = new CONFIG_MAP;"
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
  std::string mainFunction =
      "\nJson::Value simulationJsonConfig;"
      "\nJson::Value moduleParams;"
      "\nint main(int argc, const char **argv) {"
      "\n\tgetInputFiles(argc, argv);"
      "\n\tConfigurationReader configurationReader;"
      "\n\tsimulationJsonConfig = configurationReader.getConfiguration(configFile);"
      "\n\tmoduleParams = configurationReader.getConfiguration(paramsFile);";

  for (const auto& [type, className] : TYPES) {
    mainFunction +=
        "\n\tCONFIG_MAP* " + type + "Config =  extractConfigMap(\"" + type + "\");";
  }

  for (const auto& [type, className] : TYPES) {
    mainFunction += "\n\t" + className + "* " + type + " = generate" + className +
                    "(simulationJsonConfig[\"" + type + "\"].asString(), " + type +
                    "Config);";
  }

  mainFunction += outputSetup();

  mainFunction += runSim();

  mainFunction += cleanup();

  mainFunction += "\n}";

  return mainFunction;
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
          "\n\t\tstd::cerr << \"Invalid inputs\";\n"
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
  return "\n\tsimulation->run(*pedestrian_dynamics_model,"
         "*human_behavior_model,"
         "*goals,"
         "*pedestrian_set,"
         "*obstacle_set,"
         "*output_data_writer,"
         "*simulation_output_handler,"
         "*clock);"
         "\n\toutput_data_writer->writeToDocument();";
}

std::string
outputSetup() {
  return "\n\toutput_data_writer->initializeOutputFile(outputFile);";
}