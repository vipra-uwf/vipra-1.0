#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "readers/json/json.h"

// g++ code_generator.cpp readers/jsoncpp.cpp
// ./a.out

std::vector<std::string> includes;
Json::Value jsonObj;

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
std::string generatePopulateEntitySets();
std::string generateExtractConfigMap();
std::string generateMain();

int main() 
{
    // TODO to get rid of warnings, use CharReaderBuilder instead -- Alex (though this will change when InputJSONReader is finished)
    Json::Reader reader;
    std::ifstream jsonFile("input_data/sim_options.json");

    reader.parse(jsonFile, jsonObj);

    std::string functionDeclarations = generateFunctionDeclarations();
    std::string inputDataLoaderFunction = generateInputDataLoader();
    std::string outputDataWriterFunction = generateOutputDataWriter();
    std::string simulationOutputHandlerFunction = generateSimulationOutputHandler();
    std::string pedestrianSetFunction = generatePedestrianSet();
    std::string obstacleSetFunction = generateObstacleSet();
    std::string entitySetFactoryFunction = generateEntitySetFactory();
    std::string goalsFunction = generateGoals();
    std::string pedestrianDynamicsModelFunction = generatePedestrianDynamicsModel();
    std::string populateEntitySetsFunction = generatePopulateEntitySets();
    std::string extractConfigMapFunction = generateExtractConfigMap();
    std::string includes = generateIncludes();
    std::string mainFunction = generateMain();

    std::ofstream mainFile;
    mainFile.open("generated_main.cpp");
    // TODO need to make it so functions are declared before main for readability
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
        << populateEntitySetsFunction
        << extractConfigMapFunction;

    mainFile.close();
    jsonFile.close();

    return 0;
}

std::string generateIncludes() 
{
    std::string generatedIncludes = "";

    for(int i = 0; i < includes.size(); ++i) 
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

    for(int i = 0; i < jsonObj[optionsKey].size(); ++i) 
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

// TODO this will change when the InputJSONReader is finished -- Alex
std::string generateMain() 
{
    std::string generatedFunction = 

    "\n//TODO this will change when the InputJSONReader is finished -- Alex"
    "\n#include \"readers/json/json.h\""
    "\nJson::Value simulationJsonConfig;\n"
    "\nint main()"
    "\n{"
        "\n\tJson::CharReaderBuilder jsonReader;"
        "\n\tstd::ifstream jsonFile(\"input_data/sim_config.json\");"
        "\n\tstd::string errors;"
        "\n"
        "\n\tif(Json::parseFromStream(jsonReader, jsonFile, &simulationJsonConfig, &errors))"
        "\n\t{"
            "\n\t\tCONFIG_MAP* inputDataLoaderConfig = extractConfigMap(\"input_data_loader\");"
            "\n\t\tCONFIG_MAP* outputDataWriterConfig = extractConfigMap(\"output_data_writer\");"
            "\n\t\tCONFIG_MAP* simulationOutputHandlerConfig = extractConfigMap(\"simulation_output_handler\");"
            "\n\t\tCONFIG_MAP* pedestrianSetConfig = extractConfigMap(\"pedestrian_set\");" 
            "\n\t\tCONFIG_MAP* obstacleSetConfig = extractConfigMap(\"obstacle_set\");" 
            "\n\t\tCONFIG_MAP* simulationParametersConfig = extractConfigMap(\"simulation_parameters\");"
            "\n\t\tCONFIG_MAP* entitySetFactoryConfig = extractConfigMap(\"entity_set_factory\");" 
            "\n\t\tCONFIG_MAP* goalsConfig = extractConfigMap(\"goals\");" 
            "\n\t\tCONFIG_MAP* pedestrianDynamicsModelConfig = extractConfigMap(\"pedestrian_dynamics_model\");"
            "\n"
            "\n\t\tInputDataLoader* inputDataLoader = generateDataLoader("
                "\n\t\t\tsimulationJsonConfig[\"input_data_loader\"][\"type\"].asString(),"
                "\n\t\t\tinputDataLoaderConfig);"
            "\n"
            "\n\t\tOutputDataWriter* outputDataWriter = generateDataWriter("
                "\n\t\t\tsimulationJsonConfig[\"output_data_writer\"][\"type\"].asString(),"
                "\n\t\t\toutputDataWriterConfig);"
            "\n"
            "\n\t\tPedestrianSet* pedestrianSet = generatePedestrianSet("
                "\n\t\t\tsimulationJsonConfig[\"pedestrian_set\"][\"type\"].asString(),"
                "\n\t\t\tpedestrianSetConfig);"
            "\n"
            "\n\t\tObstacleSet* obstacleSet = generateObstacleSet("
                "\n\t\t\tsimulationJsonConfig[\"obstacle_set\"][\"type\"].asString(),"
                "\n\t\t\tobstacleSetConfig);"
            "\n"
            "\n\t\tEntitySetFactory* entitySetFactory = generateEntitySetFactory("
                "\n\t\t\tsimulationJsonConfig[\"entity_set_factory\"][\"type\"].asString(),"
                "\n\t\t\tentitySetFactoryConfig);"
            "\n"
            "\n\t\tGoals* goals = generateGoals("
                "\n\t\t\tsimulationJsonConfig[\"goals\"][\"type\"].asString(),"
                "\n\t\t\tgoalsConfig);"
            "\n"
            "\n\t\tPedestrianDynamicsModel* pedestrianDynamicsModel = generatePedestrianDynamicsModel("
                "\n\t\t\tsimulationJsonConfig[\"pedestrian_dynamics_model\"][\"type\"].asString()," 
                "\n\t\t\tpedestrianDynamicsModelConfig);"
            "\n"
            "\n\t\tSimulationOutputHandler* outputHandler = generateOutputHandler("
                "\n\t\t\tsimulationJsonConfig[\"simulation_output_handler\"][\"type\"].asString(),"
                "\n\t\t\tsimulationOutputHandlerConfig);"
            
            "\n"
            "\n\t\tSIM_PARAMS* simulationParameters = new SIM_PARAMS;"
            "\n"
            "\n\t\tpopulateEntitySets("
                "\n\t\t\tinputDataLoader, entitySetFactory,"
                "\n\t\t\tpedestrianSet, obstacleSet, simulationParameters,"
                "\n\t\t\tsimulationJsonConfig[\"pedestrian_set\"][\"inputFilePath\"].asString(),"
                "\n\t\t\tsimulationJsonConfig[\"obstacle_set\"][\"inputFilePath\"].asString()," 
                "\n\t\t\tsimulationJsonConfig[\"simulation_parameters\"][\"inputFilePath\"].asString(),"
                "\n\t\t\tpedestrianSetConfig, obstacleSetConfig, simulationParametersConfig);"
            "\n"
            "\n\t\tData data;"
            "\n\t\tdata.setPedestrianSet(pedestrianSet);"
            "\n\t\tdata.setObstacleSet(obstacleSet);"
            "\n\t\tdata.setSimulationParams(simulationParameters);"
            "\n"
            "\n\t\tgoals->setData(&data);"
            "\n\t\tpedestrianDynamicsModel->setData(&data);"
            "\n\t\tpedestrianDynamicsModel->setGoals(goals);"
            "\n\t\tgoals->determinePedestrianGoals();"
            "\n\t\tpedestrianDynamicsModel->initialize();"
            
            "\n"
            "\n\t\tSimulation simulation(pedestrianDynamicsModel);"
            
            "\n"
            "\n\t\toutputDataWriter->initializeOutputFile("
                "\n\t\t\tsimulationJsonConfig[\"output_data_writer\"][\"outputFilePath\"].asString());"
            
            "\n"
            "\n\t\toutputHandler->setOutputDataWriter(outputDataWriter);"
            "\n\t\toutputHandler->setPedestrianSet(pedestrianSet);"
            "\n\t\toutputHandler->setSimulation(&simulation);"
            "\n"
            "\n\t\tsimulation.setSimulationOutputHandler(outputHandler);"
            "\n\t\tsimulation.run();"
            "\n"
            "\n\t\toutputDataWriter->writeDocumentContentsToFile();"
            "\n"
            "\n\t\tdelete inputDataLoader;"
            "\n\t\tdelete outputDataWriter;"
            "\n\t\tdelete pedestrianSet;"
            "\n\t\tdelete obstacleSet;"
            "\n\t\tdelete simulationParameters;"
            "\n\t\tdelete entitySetFactory;"
            "\n\t\tdelete goals;"
            "\n\t\tdelete pedestrianDynamicsModel;"
            "\n\t\tdelete outputHandler;"
            "\n"
            "\n\t\tdelete inputDataLoaderConfig;"
            "\n\t\tdelete outputDataWriterConfig;"
            "\n\t\tdelete simulationOutputHandlerConfig;"
            "\n\t\tdelete pedestrianSetConfig;"
            "\n\t\tdelete obstacleSetConfig;"
            "\n\t\tdelete simulationParametersConfig;"
            "\n\t\tdelete entitySetFactoryConfig;"
            "\n\t\tdelete goalsConfig;"
            "\n\t\tdelete pedestrianDynamicsModelConfig;"
        "\n\t}"
        "\n\telse"
        "\n\t{"
            "\n\t\tstd::cout << \"Error parsing JSON: \" << errors << std::endl;"
        "\n\t}"
        "\n"
        "\n\treturn 0;"
    "\n}";

    return generatedFunction;
}