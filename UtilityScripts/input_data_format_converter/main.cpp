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
    //int j = 0;

    while(std::getline(fileStream, line))
    {
        std::stringstream linestream(line);

        if(i >= 0)
        {
            std::string letter;
            double x;
            double y;
            double z;

            linestream >> letter >> x >> y >> z;

            xmlWriter.appendFloatAttributeToCurrentElement("x", x);
            xmlWriter.appendFloatAttributeToCurrentElement("y", y);
        }
        
        // if(j < 149)
        // {
        //     std::cout << i << " " << line << std::endl;
        // }
        
        i++;
        //j++;
        
        if(i == 144)
        {
            i = -2;
        }
    }

    xmlWriter.writeDocumentContents();
    fileStream.close();

    return 0;
}