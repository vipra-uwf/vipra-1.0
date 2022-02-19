#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../configuration/configuration_reader.hpp"

std::vector<std::string> includes;
Json::Value jsonObj;
std::string configID;

std::string getConfigID(int, char**);
std::string generateIncludes();
std::string generateFunctionDeclarations();
std::string generateFunctionOptions(std::string optionsKey);
std::string generateInputDataLoader();
std::string generateOutputDataWriter();
std::string generateSimulationOutputHandler();
std::string generatePedestrianSet();
std::string generateObstacleSet();
std::string generateEntitySetFactory();
std::string generateGoals();
std::string generatePedestrianDynamicsModel();
std::string generateHumanBehaviorModel();
std::string generatePopulateEntitySets();
std::string generateExtractConfigMap();
std::string generateMain();

int main(int argc, char *argv[]) 
{

    configID = getConfigID(argc, argv);

    ConfigurationReader configurationReader;
	configurationReader.readJsonConfiguration("input_data/"+configID+"/config_"+configID+".json");
	jsonObj = configurationReader.getJsonObject();

    std::string functionDeclarations = generateFunctionDeclarations();
    std::string inputDataLoaderFunction = generateInputDataLoader();
    std::string outputDataWriterFunction = generateOutputDataWriter();
    std::string simulationOutputHandlerFunction = generateSimulationOutputHandler();
    std::string pedestrianSetFunction = generatePedestrianSet();
    std::string obstacleSetFunction = generateObstacleSet();
    std::string entitySetFactoryFunction = generateEntitySetFactory();
    std::string goalsFunction = generateGoals();
    std::string pedestrianDynamicsModelFunction = generatePedestrianDynamicsModel();
    std::string humanBehaviorModelFunction = generateHumanBehaviorModel();
    std::string populateEntitySetsFunction = generatePopulateEntitySets();
    std::string extractConfigMapFunction = generateExtractConfigMap();
    std::string includes = generateIncludes();
    std::string mainFunction = generateMain();

    std::ofstream mainFile;
    mainFile.open("./../input_data/"+configID+"/generated_main.cpp");
    mainFile 
        << includes
        << functionDeclarations 
        << mainFunction
        << inputDataLoaderFunction 
        << outputDataWriterFunction
        << simulationOutputHandlerFunction
        << pedestrianSetFunction
        << obstacleSetFunction
        << entitySetFactoryFunction
        << goalsFunction
        << pedestrianDynamicsModelFunction
        << humanBehaviorModelFunction
        << populateEntitySetsFunction
        << extractConfigMapFunction;

    mainFile.close();

    return 0;
}

// TODO give proper errors when incorrect
std::string getConfigID(int argc, char *argv[]){

    if(argc > 2 || argc < 2){
        std::cerr << "Invalid inputs";
        exit(1);
    }

    return std::string(argv[1]);
}

std::string generateIncludes() 
{
    std::string generatedIncludes = "";

    includes.push_back("configuration/configuration_reader.hpp");

    for(long unsigned int i = 0; i < includes.size(); ++i) 
    {
        generatedIncludes += "#include \"" + includes[i] + "\"\n"; 
    }

    return generatedIncludes;
}

std::string generateFunctionDeclarations()
{
    std::string generatedDeclarations = 

    "\nCONFIG_MAP* extractConfigMap(std::string objectName);"
    "\nInputDataLoader* generateDataLoader(std::string type, CONFIG_MAP* configMap);"
    "\nOutputDataWriter* generateDataWriter(std::string type, CONFIG_MAP* configMap);"
    "\nSimulationOutputHandler* generateOutputHandler(std::string type, CONFIG_MAP* configMap);"
    "\nPedestrianSet* generatePedestrianSet(std::string type, CONFIG_MAP* configMap);"
    "\nObstacleSet* generateObstacleSet(std::string type, CONFIG_MAP* configMap);"
    "\nEntitySetFactory* generateEntitySetFactory(std::string type, CONFIG_MAP* configMap);"
    "\nGoals* generateGoals(std::string type, CONFIG_MAP* configMap);"
    "\nPedestrianDynamicsModel* generatePedestrianDynamicsModel(std::string type, CONFIG_MAP* configMap);"
    "\nHumanBehaviorModel* generateHumanBehaviorModel(std::string type, CONFIG_MAP* configMap);"
    "\n"
    "\nvoid populateEntitySets("
        "\n\tInputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,"
        "\n\tPedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParameters,"
        "\n\tstd::string pedestrianSetFilePath, std::string obstacleSetFilePath, std::string simulationParametersFilePath,"
        "\n\tCONFIG_MAP* pedestrianConfigMap, CONFIG_MAP* obstacleConfigMap, CONFIG_MAP* simulationParametersConfigMap);"
    "\n";

    return generatedDeclarations;
}

std::string generateFunctionOptions(std::string optionsKey)
{
    std::string generatedFunction = "";

    for(unsigned int i = 0; i < jsonObj[optionsKey].size(); ++i) 
    {
        if(i == 0) 
        {
            generatedFunction += 
                "\tif(type == \"" + 
                jsonObj[optionsKey][i]["type"].asString() +
                std::string("\")\n");
        }
        else 
        {
            generatedFunction += 
                "\telse if(type == \"" + 
                jsonObj[optionsKey][i]["type"].asString() +
                std::string("\")\n");
        }

        generatedFunction += 
            "\t{\n"
            "\t\t" +
            jsonObj[optionsKey][i]["className"].asString() + "* " +
            jsonObj[optionsKey][i]["objectName"].asString() + " = new " + 
            jsonObj[optionsKey][i]["className"].asString() + ";\n" +
            "\t\t" + jsonObj[optionsKey][i]["objectName"].asString() + 
            "->configure(configMap);" +
            "\n\t\treturn " + jsonObj[optionsKey][i]["objectName"].asString() + 
            ";\n"
            "\t}\n";

        includes.push_back(jsonObj[optionsKey][i]["includePath"].asString());
    }

    generatedFunction += "\n\treturn nullptr;"
                        "\n}\n";

    return generatedFunction;
}

std::string generateInputDataLoader() 
{
    std::string generatedFunction = 
        "\nInputDataLoader* generateDataLoader(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("input_data_loader");
    
    return generatedFunction;
}

std::string generateOutputDataWriter() 
{
    std::string generatedFunction = 
        "\nOutputDataWriter* generateDataWriter(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("output_data_writer");
    
    return generatedFunction;
}

std::string generateSimulationOutputHandler() 
{
    std::string generatedFunction = 
        "\nSimulationOutputHandler* generateOutputHandler(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("simulation_output_handler");
    
    return generatedFunction;
}

std::string generatePedestrianSet() 
{
    std::string generatedFunction = 
        "\nPedestrianSet* generatePedestrianSet(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("pedestrian_set");
    
    return generatedFunction;
}

std::string generateObstacleSet() 
{
    std::string generatedFunction = 
        "\nObstacleSet* generateObstacleSet(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("obstacle_set");
    
    return generatedFunction;
}

std::string generateEntitySetFactory() 
{
    std::string generatedFunction = 
        "\nEntitySetFactory* generateEntitySetFactory(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("entity_set_factory");
    
    return generatedFunction;
}

std::string generateGoals() 
{
    std::string generatedFunction = 
        "\nGoals* generateGoals(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("goals");
    
    return generatedFunction;
}

std::string generatePedestrianDynamicsModel() 
{
    std::string generatedFunction = 
        "\nPedestrianDynamicsModel* generatePedestrianDynamicsModel(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("pedestrian_dynamics_model");
    
    return generatedFunction;
}

std::string generateHumanBehaviorModel()
{
    std::string generatedFunction =
        "\nHumanBehaviorModel* generateHumanBehaviorModel(std::string type, CONFIG_MAP* configMap)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("human_behavior_model");

    return generatedFunction;
}

std::string generatePopulateEntitySets() 
{
    std::string generatedFunction = 
    "\nvoid populateEntitySets("
    "\n\tInputDataLoader* inputDataLoader, EntitySetFactory* entitySetFactory,"
    "\n\tPedestrianSet* pedestrianSet, ObstacleSet* obstacleSet, SIM_PARAMS* simulationParameters,"
    "\n\tstd::string pedestrianSetFilePath, std::string obstacleSetFilePath, std::string simulationParametersFilePath,"
    "\n\tCONFIG_MAP* pedestrianConfigMap, CONFIG_MAP* obstacleConfigMap, CONFIG_MAP* simulationParametersConfigMap"
    ")"
    
    "\n{"
        "\n\tinputDataLoader->extractFileData(pedestrianSetFilePath, pedestrianConfigMap);"
        "\n\tENTITY_SET pedestrianInputFileData = inputDataLoader->getInputEntities();"
        "\n\tentitySetFactory->populatePedestrianSet(pedestrianInputFileData, pedestrianSet);\n"

        "\n\tinputDataLoader->extractFileData(obstacleSetFilePath, obstacleConfigMap);"
        "\n\tENTITY_SET obstacleInputFileData = inputDataLoader->getInputEntities();"
        "\n\tentitySetFactory->populateObstacleSet(obstacleInputFileData, obstacleSet);\n"

        "\n\tinputDataLoader->extractFileData(simulationParametersFilePath, simulationParametersConfigMap);"
        "\n\tENTITY_SET simulationParametersFilePathData = inputDataLoader->getInputEntities();"
        "\n\tentitySetFactory->populateSimulationParams(simulationParametersFilePathData, simulationParameters);\n"
    "}\n";

    return generatedFunction;
}

std::string generateExtractConfigMap()
{
    std::string generatedFunction = 
    
    "\nCONFIG_MAP* extractConfigMap(std::string objectName)"
    "\n{"
        "\n\tCONFIG_MAP* configMap = new CONFIG_MAP;"
        "\n"
        "\n\tfor(unsigned int i = 0; i < simulationJsonConfig[objectName][\"configuration\"].size(); i++)"
        "\n\t{"
            "\n\t\tstd::string attribute = simulationJsonConfig[objectName][\"configuration\"].getMemberNames()[i];"
            "\n\t\tstd::string value = simulationJsonConfig[objectName][\"configuration\"][attribute].asString();"
            "\n\t\t(*configMap)[attribute] = value;"
        "\n\t}"
        "\n"
        "\n\treturn configMap;"
    "\n}";

    return generatedFunction;
}

std::string generateMain() 
{
    std::string generatedFunction = 

    "\nJson::Value simulationJsonConfig;\n"
    "\nint main()"
    "\n{"
        "\n\tConfigurationReader configurationReader;"
        "\n\tconfigurationReader.readJsonConfiguration(\"input_data/sim_config.json\");"
        "\n\tsimulationJsonConfig = configurationReader.getJsonObject();"
        "\n"
            "\n\tCONFIG_MAP* inputDataLoaderConfig = extractConfigMap(\"input_data_loader\");"
            "\n\tCONFIG_MAP* outputDataWriterConfig = extractConfigMap(\"output_data_writer\");"
            "\n\tCONFIG_MAP* simulationOutputHandlerConfig = extractConfigMap(\"simulation_output_handler\");"
            "\n\tCONFIG_MAP* pedestrianSetConfig = extractConfigMap(\"pedestrian_set\");" 
            "\n\tCONFIG_MAP* obstacleSetConfig = extractConfigMap(\"obstacle_set\");" 
            "\n\tCONFIG_MAP* simulationParametersConfig = extractConfigMap(\"simulation_parameters\");"
            "\n\tCONFIG_MAP* entitySetFactoryConfig = extractConfigMap(\"entity_set_factory\");" 
            "\n\tCONFIG_MAP* goalsConfig = extractConfigMap(\"goals\");" 
            "\n\tCONFIG_MAP* pedestrianDynamicsModelConfig = extractConfigMap(\"pedestrian_dynamics_model\");"
            "\n\tCONFIG_MAP* humanBehaviorModelConfig = extractConfigMap(\"human_behavior_model\");"
            "\n"
            "\n\tInputDataLoader* inputDataLoader = generateDataLoader("
                "\n\t\tsimulationJsonConfig[\"input_data_loader\"][\"type\"].asString(),"
                "\n\t\tinputDataLoaderConfig);"
            "\n"
            "\n\tOutputDataWriter* outputDataWriter = generateDataWriter("
                "\n\t\tsimulationJsonConfig[\"output_data_writer\"][\"type\"].asString(),"
                "\n\t\toutputDataWriterConfig);"
            "\n"
            "\n\tPedestrianSet* pedestrianSet = generatePedestrianSet("
                "\n\t\tsimulationJsonConfig[\"pedestrian_set\"][\"type\"].asString(),"
                "\n\t\tpedestrianSetConfig);"
            "\n"
            "\n\tObstacleSet* obstacleSet = generateObstacleSet("
                "\n\t\tsimulationJsonConfig[\"obstacle_set\"][\"type\"].asString(),"
                "\n\t\tobstacleSetConfig);"
            "\n"
            "\n\tEntitySetFactory* entitySetFactory = generateEntitySetFactory("
                "\n\t\tsimulationJsonConfig[\"entity_set_factory\"][\"type\"].asString(),"
                "\n\t\tentitySetFactoryConfig);"
            "\n"
            "\n\tGoals* goals = generateGoals("
                "\n\t\tsimulationJsonConfig[\"goals\"][\"type\"].asString(),"
                "\n\t\tgoalsConfig);"
            "\n"
            "\n\tPedestrianDynamicsModel* pedestrianDynamicsModel = generatePedestrianDynamicsModel("
                "\n\t\tsimulationJsonConfig[\"pedestrian_dynamics_model\"][\"type\"].asString()," 
                "\n\t\tpedestrianDynamicsModelConfig);"
            "\n"
            "\n\tHumanBehaviorModel* humanBehaviorModel = generateHumanBehaviorModel("
                "\n\t\tsimulationJsonConfig[\"human_behavior_model\"][\"type\"].asString(),"
                "\n\t\thumanBehaviorModelConfig);"
            "\n"
            "\n\tSimulationOutputHandler* outputHandler = generateOutputHandler("
                "\n\t\tsimulationJsonConfig[\"simulation_output_handler\"][\"type\"].asString(),"
                "\n\t\tsimulationOutputHandlerConfig);"
            
            "\n"
            "\n\tSIM_PARAMS* simulationParameters = new SIM_PARAMS;"
            "\n"
            "\n\tpopulateEntitySets("
                "\n\t\tinputDataLoader, entitySetFactory,"
                "\n\t\tpedestrianSet, obstacleSet, simulationParameters,"
                "\n\t\tsimulationJsonConfig[\"pedestrian_set\"][\"inputFilePath\"].asString(),"
                "\n\t\tsimulationJsonConfig[\"obstacle_set\"][\"inputFilePath\"].asString()," 
                "\n\t\tsimulationJsonConfig[\"simulation_parameters\"][\"inputFilePath\"].asString(),"
                "\n\t\tpedestrianSetConfig, obstacleSetConfig, simulationParametersConfig);"
            "\n"
            "\n\tData data;"
            "\n\tdata.setPedestrianSet(pedestrianSet);"
            "\n\tdata.setObstacleSet(obstacleSet);"
            "\n\tdata.setSimulationParams(simulationParameters);"
            "\n"
            "\n\tgoals->setData(&data);"
            "\n\tpedestrianDynamicsModel->setData(&data);"
            "\n\tpedestrianDynamicsModel->setGoals(goals);"
            "\n\tgoals->determinePedestrianGoals();"
            "\n\tpedestrianDynamicsModel->initialize();"

            "\n"
            "\n\thumanBehaviorModel->setData(&data);"
            "\n"

            "\n"
            "\n\tSimulation simulation(pedestrianDynamicsModel, humanBehaviorModel);"
            "\n\tsimulation.setData(&data);"
            "\n\tsimulation.initialize();"
            
            "\n"
            "\n\toutputDataWriter->initializeOutputFile("
                "\n\t\tsimulationJsonConfig[\"output_data_writer\"][\"outputFilePath\"].asString());"
            
            "\n"
            "\n\toutputHandler->setOutputDataWriter(outputDataWriter);"
            "\n\toutputHandler->setPedestrianSet(pedestrianSet);"
            "\n\toutputHandler->setSimulation(&simulation);"
            "\n"
            "\n\tsimulation.setSimulationOutputHandler(outputHandler);"
            "\n\tsimulation.run();"
            "\n"
            "\n\toutputDataWriter->writeDocumentContentsToFile();"
            "\n"
            "\n\tdelete inputDataLoader;"
            "\n\tdelete outputDataWriter;"
            "\n\tdelete pedestrianSet;"
            "\n\tdelete obstacleSet;"
            "\n\tdelete simulationParameters;"
            "\n\tdelete entitySetFactory;"
            "\n\tdelete goals;"
            "\n\tdelete pedestrianDynamicsModel;"
            "\n\tdelete humanBehaviorModel;"
            "\n\tdelete outputHandler;"
            "\n"
            "\n\tdelete inputDataLoaderConfig;"
            "\n\tdelete outputDataWriterConfig;"
            "\n\tdelete simulationOutputHandlerConfig;"
            "\n\tdelete pedestrianSetConfig;"
            "\n\tdelete obstacleSetConfig;"
            "\n\tdelete simulationParametersConfig;"
            "\n\tdelete entitySetFactoryConfig;"
            "\n\tdelete goalsConfig;"
            "\n\tdelete pedestrianDynamicsModelConfig;"
            "\n\tdelete humanBehaviorModelConfig;"
        "\n"
        "\n\treturn 0;"
    "\n}";

    return generatedFunction;
}