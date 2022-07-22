#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../configuration/configuration_reader.hpp"

void setFiles(int, char**);


std::string generateGetFiles();
std::string generateIncludes();
std::string generateFunctionDeclarations();
std::string generateObjectFunction(const std::string &className, const std::string &type);
std::string generateFunctionOptions(const std::string &type);
std::string generateExtractConfigMap();
std::string generateMain();

std::string generatePopulateObstacleSet();
std::string generatePopulatePedestrianSet();

std::string outputFile;
std::string optionsFile;
std::vector<std::string> includes;
Json::Value jsonObj;

const std::unordered_map<std::string, std::string> TYPES{
    {"pedestrian_dynamics_model", "PedestrianDynamicsModel"},
    {"goals", "Goals"},
    {"output_data_writer", "OutputDataWriter"},
    {"input_data_loader", "InputDataLoader"},
    {"simulation_output_handler", "SimulationOutputHandler"},
    {"pedestrian_set", "PedestrianSet"},
    {"obstacle_set", "ObstacleSet"},
    {"entity_set_factory", "EntitySetFactory"},
    {"human_behavior_model", "HumanBehaviorModel"},
    {"configuration_reader", "ConfigurationReader"},
    {"clock", "Clock"},
    {"data", "Data"},
    {"simulation", "Simulation"},
};

int main(int argc, char *argv[]) 
{

    setFiles(argc, argv);

    ConfigurationReader configurationReader;
	configurationReader.readJsonConfiguration(optionsFile);
	jsonObj = configurationReader.getJsonObject();

    std::string functionDeclarations = generateFunctionDeclarations();

    std::string objectFunctions{""};
    for(const auto &[type, className] : TYPES){
        objectFunctions += generateObjectFunction(className, type);
    }

    std::string includes = generateIncludes();
    std::string mainFunction = generateMain();
    std::string getInputFiles = generateGetFiles();
    std::string extractConfigMap = generateExtractConfigMap();


    std::ofstream mainFile;
    mainFile.open(outputFile);
    if(!mainFile.is_open()){
        std::cerr << "[ERROR] Unable to open output file\n";
        return -1;
    }
    
    mainFile
        << includes
        << functionDeclarations
        << getInputFiles
        << mainFunction
        << objectFunctions
        << extractConfigMap;

    mainFile.close();

    return 0;
}

void setFiles(int argc, char **argv){
    if(argc > 3 || argc < 3){
        std::cerr << "Usage: generate_main *output file* *options file*\n";
        exit(1);
    }

    outputFile = std::string(argv[1]);
    optionsFile = std::string(argv[2]);
}

std::string debugOutput(std::string message){
    return {
        "\n\n#ifdef DEBUG_OUTPUT"
        "\nstd::cout << \"" + message + "\" << std::endl;"
        "\n#endif"
    };
}

std::string generateIncludes()
{
    std::string generatedIncludes = "";
    for(const auto &include : includes) 
    {
        generatedIncludes += "#include \"" + include + "\"\n";
    }

    return generatedIncludes;
}

std::string generateObjectFunction(const std::string &className, const std::string &type){
    std::string generatedFunction = 
        "\n"+
        className+
        "* generate" + className + "(std::string id, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions(type);
    
    return generatedFunction;
}

std::string generateFunctionOptions(const std::string &type)
{
    std::string generatedFunction{""};
    for(const auto &option : jsonObj[type]){
        if(option["compiled"]){
            generatedFunction += 
            debugOutput("generating " + type) +
            "\n\tif(id==\"" + option["id"].asString() + "\"){\n\t\t" +
            option["className"].asString() + "* " +
            option["name"].asString() + " = new " +
            option["className"].asString() + "();\n\t\t" +
            option["name"].asString() + "->configure(configMap);" +
            "\n\t\treturn " + option["name"].asString() + ";"+
            "\n\t}";
            includes.emplace_back(option["includePath"].asString());
        }
    }

    generatedFunction += "\n\treturn nullptr;\n}";
    return generatedFunction;
}

std::string generateExtractConfigMap(){
    return {
    "\nCONFIG_MAP* extractConfigMap(std::string name)"
    "\n{"
        "\n\tCONFIG_MAP* configMap = new CONFIG_MAP;"
        +debugOutput("extracting config map:")+
        "\n\tfor(unsigned int i = 0; i < moduleParams[name][\"params\"].size(); i++)"
        "\n\t{"
            "\n\t\tstd::string attribute = moduleParams[name][\"params\"].getMemberNames()[i];"
            "\n\t\tstd::string value = moduleParams[name][\"params\"][attribute].asString();"
            "\n\tstd::cout << \"ATTRIBUTE: \" << attribute << \" : \" << value << \'\\n\';"
            "\n\t\t(*configMap)[attribute] = value;"
        "\n\t}"
        "\n"
        "\n\treturn configMap;"
    "\n}"
    };
}

std::string generateFunctionDeclarations()
{
    std::string generatedDeclarations = 
    "\nCONFIG_MAP* extractConfigMap(std::string name);"
    "\nvoid getInputFiles(int argc, const char** argv);";

    for(const auto &[type, className] : TYPES){
        generatedDeclarations += 
        className + "* generate" + className + "(std::string id, CONFIG_MAP* configMap);\n";
    }

    return generatedDeclarations;
}


// NOTE: extractFileData takes in a string and a config_map* but does nothing with the pointer, so it's a nullptr for now -RG
std::string generatePopulateObstacleSet(){
    return{
        debugOutput("reading obstacledata")+
        "\n\tinput_data_loader->extractFileData(obstacleFile, nullptr);"
        +debugOutput("getting input entities")+
        "\n\tENTITY_SET obstacleData = input_data_loader->getInputEntities();"
        +debugOutput("done reading")+
        "\n\tentity_set_factory->populateObstacleSet(obstacleData, obstacle_set);"
        +debugOutput("populated obstacleset")
    };
}

std::string generatePopulatePedestrianSet(){
    return{
        debugOutput("reading pedestriandata")+
        "\n\tinput_data_loader->extractFileData(pedestrianFile, nullptr);"
        +debugOutput("getting input entities")+
        "\n\tENTITY_SET pedestrianData = input_data_loader->getInputEntities();"
        +debugOutput("done reading")+
        "\n\tentity_set_factory->populatePedestrianSet(pedestrianData, pedestrian_set);"
        +debugOutput("populated pedestrianset")
    };
}

std::string outputSetup(){
    return {
        debugOutput("setting up output")+
        "\n\toutput_data_writer->initializeOutputFile(outputFile);"
        "\n\tsimulation_output_handler->setOutputDataWriter(output_data_writer);"
        "\n\tsimulation_output_handler->setPedestrianSet(pedestrian_set);"
        "\n\tsimulation_output_handler->setSimulation(simulation);"
        "\n"
        "\n\tsimulation->setSimulationOutputHandler(simulation_output_handler);"
        +debugOutput("done setting up output")
    };  
}

// TODO names are hard coded -RG
std::string setData(){
    return {
        "\n\tdata->setPedestrianSet(pedestrian_set);"
        "\n\tdata->setObstacleSet(obstacle_set);"
        "\n"
        "\n\tgoals->setData(data);"
        "\n\tgoals->addExitGoals(*obstacle_set);"
        "\n\tpedestrian_dynamics_model->setData(data);"
        "\n\tpedestrian_dynamics_model->setGoals(goals);"
        "\n\tgoals->determinePedestrianGoals();"
        "\n\tpedestrian_dynamics_model->initialize();"
        "\n\thuman_behavior_model->setData(data);"
        "\n\tsimulation->setData(data);"
        "\n\tsimulation->setPedestrianModel(pedestrian_dynamics_model);"
        "\n\tsimulation->setHumanBehaviorModel(human_behavior_model);"
    };
}

std::string generateGetFiles(){
    return {
    "\nstd::string paramsFile;"
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
    "\n}"
    };
}

std::string cleanup(){
    return {
        "\n\tdelete input_data_loader;"
        "\n\tdelete output_data_writer;"
        "\n\tdelete pedestrian_set;"
        "\n\tdelete obstacle_set;"
        "\n\tdelete entity_set_factory;"
        "\n\tdelete goals;"
        "\n\tdelete pedestrian_dynamics_model;"
        "\n\tdelete human_behavior_model;"
        "\n\tdelete simulation_output_handler;"
        "\n\tdelete input_data_loaderConfig;"
        "\n\tdelete output_data_writerConfig;"
        "\n\tdelete pedestrian_setConfig;"
        "\n\tdelete obstacle_setConfig;"
        "\n\tdelete entity_set_factoryConfig;"
        "\n\tdelete goalsConfig;"
        "\n\tdelete pedestrian_dynamics_modelConfig;"
        "\n\tdelete human_behavior_modelConfig;"
        "\n\tdelete simulation_output_handlerConfig;"
    };
}

std::string runSim(){
    return {
        debugOutput("running simulation")+
        "\n\tsimulation->run();"
        "\n\toutputDataWriter->writeDocumentContentsToFile();"
    };
}

std::string generateMain(){

    std::string mainFunction{""};

    mainFunction +=
        "\nJson::Value simulationJsonConfig;\n"
        "\nJson::Value moduleParams;\n"
        "\nint main(int argc, const char **argv)"
        "\n{"
        "\n\tgetInputFiles(argc, argv);"
        "\n\tConfigurationReader configurationReader;"
        "\n\tconfigurationReader.readJsonConfiguration(configFile);"
        "\n\tsimulationJsonConfig = configurationReader.getJsonObject();"
        "\n\tconfigurationReader.readJsonConfiguration(paramsFile);"
        "\n\tmoduleParams = configurationReader.getJsonObject();";

    for(const auto &[type, className] : TYPES){
        mainFunction +=
            "\n\tCONFIG_MAP* " + type + "Config =  extractConfigMap(\""+ type +"\");";
    }

    for(const auto &[type, className] : TYPES){
        mainFunction +=
            "\n\t" + className + "* " + type + " = generate" + className + "(simulationJsonConfig[\"" + type + "\"][\"id\"].asString(), " + type + "Config);";
    }

    mainFunction += 
        generatePopulateObstacleSet();

    mainFunction += 
        generatePopulatePedestrianSet();

    mainFunction +=
        setData();

    mainFunction +=
        outputSetup();

    mainFunction +=
        runSim();

    mainFunction +=
        cleanup();

    mainFunction +=
        "\n}";

    return mainFunction;
}
