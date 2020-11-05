#include "xmlconverter.hpp"

// XMLConverter xmlConverter;
// xmlConverter.convertToXML("coord_A320_144.d_coordinates.txt", 13);
// xmlConverter.convertToXML("coord_A320_144.d_coordinates.txt", 16);

//only set up to convert original CALM coord_*_*.d_coordinates.txt files
void XMLConverter::convertCoordFileToXML(std::string fileName, int flag)
{
    this->fileStream.open(fileName);
    std::string line;    
    int i = 1;

    if(flag == 13)
    {
        this->xmlWriter.configureXMLDocumentStructure(
            "a320_144_pedestrians.xml", 
            "pedestrian-set", "pedestrian", "1.0", "utf-8");
    }
    else if(flag == 16) 
    {
        this->xmlWriter.configureXMLDocumentStructure(
            "a320_144_obstacles.xml", 
            "obstacle-set", "obstacle", "1.0", "utf-8");
    }    
    
    while(std::getline(this->fileStream, line))
    {
        std::stringstream linestream(line);

        //to ignore the first 2 model parameter lines
        if(i > 2)
        {
            int indicator;
            double x;
            double y;

            linestream >> indicator >> x >> y;

            if(indicator == flag)
            {
                this->xmlWriter.appendFloatAttributeToCurrentElement("x", x);
                this->xmlWriter.appendFloatAttributeToCurrentElement("y", y);
                this->xmlWriter.appendFloatAttributeToCurrentElement("mass", 1);
                this->xmlWriter.appendFloatAttributeToCurrentElement("reaction_time", 0.4);
                this->xmlWriter.appendFloatAttributeToCurrentElement("desired_speed", 1);
            }
        }
        i++;
    }

    this->xmlWriter.writeDocumentContents();
    this->fileStream.close();
}
