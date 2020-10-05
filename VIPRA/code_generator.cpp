#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "readers/json/json.h"

std::vector<std::string> includes;
Json::Value jsonObj;

std::string generateIncludes() 
{
    std::string generatedIncludes = "";

    for(int i = 0; i < includes.size(); ++i) 
    {
        generatedIncludes += "#include \"" + includes[i] + "\"\n"; 
    }

    return generatedIncludes;
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
            "\t\treturn " + jsonObj[optionsKey][i]["objectName"].asString() + 
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
        "\nInputDataLoader* generateDataLoader(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("input_data_loader");
    
    return generatedFunction;
}

std::string generateOutputDataWriter() 
{
    std::string generatedFunction = 
        "\nOutputDataWriter* generateDataWriter(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("output_data_writer");
    
    return generatedFunction;
}

std::string generateSimulationOutputHandler() 
{
    std::string generatedFunction = 
        "\nSimulationOutputHandler* generateOutputHandler(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("simulation_output_handler");
    
    return generatedFunction;
}

std::string generatePedestrianSet() 
{
    std::string generatedFunction = 
        "\nPedestrianSet* generatePedestrianSet(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("pedestrian_set");
    
    return generatedFunction;
}

std::string generateObstacleSet() 
{
    std::string generatedFunction = 
        "\nObstacleSet* generateObstacleSet(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("obstacle_set");
    
    return generatedFunction;
}

std::string generateEntitySetFactory() 
{
    std::string generatedFunction = 
        "\nEntitySetFactory* generateEntitySetFactory(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("entity_set_factory");
    
    return generatedFunction;
}

std::string generateGoals() 
{
    std::string generatedFunction = 
        "\nGoals* generateGoals(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("goals");
    
    return generatedFunction;
}

std::string generatePedestrianDynamicsModel() 
{
    std::string generatedFunction = 
        "\nPedestrianDynamicsModel* generatePedDynamicsModel(std::string type)\n"
        "{\n";

    generatedFunction += generateFunctionOptions("pedestrian_dynamics_model");
    
    return generatedFunction;
}

int main() 
{
    Json::Reader reader;
    std::ifstream jsonFile("input_data/sim_options.json");

    reader.parse(jsonFile, jsonObj);

    std::string inputDataLoaderFunction = generateInputDataLoader();
    std::string outputDataWriterFunction = generateOutputDataWriter();
    std::string simulationOutputHandlerFunction = generateSimulationOutputHandler();
    std::string pedestrianSetFunction = generatePedestrianSet();
    std::string obstacleSetFunction = generateObstacleSet();
    std::string entitySetFactoryFunction = generateEntitySetFactory();
    std::string goalsFunction = generateGoals();
    std::string pedestrianDynamicsModel = generatePedestrianDynamicsModel();

    std::string includes = generateIncludes();


    std::ofstream mainFile;
    mainFile.open("generated_main.cpp");
    mainFile 
        << includes
        << inputDataLoaderFunction 
        << outputDataWriterFunction
        << simulationOutputHandlerFunction
        << pedestrianSetFunction
        << obstacleSetFunction
        << entitySetFactoryFunction
        << goalsFunction
        << pedestrianDynamicsModel
    
        << "\nint main() { " 
        << " return 0; }";

    mainFile.close();
    jsonFile.close();

    return 0;
}