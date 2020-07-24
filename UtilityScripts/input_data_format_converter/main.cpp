#include <fstream>
#include <iostream>
#include <string>

#include "../../VIPRA/writers/xml_writer.hpp"

// g++ main.cpp ../../VIPRA/writers/xml_writer.cpp ../../VIPRA/simulation/data.cpp ../../VIPRA/entity_sets/obstacle_set.cpp

int main()
{
    std::ifstream fileStream; 
    XMLWriter xmlWriter;

    xmlWriter.configureXMLDocumentStructure(
        "pedestrian_animfile.xml", 
        "pedestrian-set", "pedestrian", "1.0", "utf-8");

    fileStream.open("animfile.xyz");
    std::string line;

    int i = -2;

    while(std::getline(fileStream, line))
    {
        std::stringstream linestream(line);

        // std::cout << line << std::endl;

        if(i >= 0)
        {
            std::string letter;
            double x;
            double y;
            double z;

            linestream >> letter >> x >> y >> z;

            xmlWriter.writeFloatData("x", x);
            xmlWriter.writeFloatData("y", y);
        }

        if(i == 143)
        {
            i = -2;
        }

        i++;
    }

    xmlWriter.writeDocumentContents();
    fileStream.close();

    return 0;
}