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

int main() 
{
    Json::Reader reader;
    std::ifstream jsonFile("input_data/sim_options.json");

    reader.parse(jsonFile, jsonObj);

    std::string inputDataLoaderFunction = generateInputDataLoader();
    std::string outputDataWriterFunction = generateOutputDataWriter();

    std::string includes = generateIncludes();


    std::ofstream mainFile;
    mainFile.open("generated_main.cpp");
    mainFile 
        << includes
        << inputDataLoaderFunction 
        << outputDataWriterFunction
    
        << "\nint main() { " 
        << " return 0; }";

    mainFile.close();
    jsonFile.close();

    return 0;
}