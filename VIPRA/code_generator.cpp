#include <iostream>
#include <fstream>
#include <string>

#include "readers/json/json.h"

std::string generateIncludes() 
{
    std::string includes = "#include \"readers/input_xml_reader.hpp\"\n";
    return includes;
}

std::string generateDataLoader() 
{
    std::string method = "\nInputDataLoader* generateDataLoader(std::string type)\n"
                        "{\n"
                            "\tif(type == \"xml\")\n"
                            "\t{\n"
                                "\t\tInputXMLReader* inputXMLReader = new InputXMLReader;\n"
                                "\t\treturn inputXMLReader;\n"
                            "\t}\n"
                            "\telse if(type == \"json\")\n"
                            "\t{\n"
                                "\t\tInputJSONReader* inputJSONReader = new InputJSONReader;\n"
                                "\t\treturn inputJSONReader;\n"
                            "\t}\n"
                        "}\n";

    return method;
}

// OR SHOULD IT BE DONE THIS WAY?

std::string generateDataLoader1(std::string type) 
{
    std::string method = "\nInputDataLoader* generateDataLoader()\n"
                        "{\n";
    
    if(type == "\"xml\"")
    {
        method += "\tInputXMLReader* inputXMLReader = new InputXMLReader;\n"
                  "\treturn inputXMLReader;\n";
    }
    else if(type == "\"json\"")
    {
        method += "\tInputJSONReader* inputJSONReader = new InputJSONReader;\n"
                  "\treturn inputJSONReader;\n";
    }

    method += "}\n";

    return method;
}

int main() 
{
    Json::Value root;
    std::ifstream jsonFile("input_data/sim_config.json");
    jsonFile >> root;

    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";

    std::string inputDataLoader = Json::writeString(builder, root["input_data_loader"]);



    jsonFile.close();

    std::ofstream mainFile;
    mainFile.open("main1.cpp");
    mainFile 
        << generateIncludes()
        << generateDataLoader()
        << generateDataLoader1(inputDataLoader)


        << "\nint main() { " 

        << " return 0; }";

    mainFile.close();

    return 0;
}