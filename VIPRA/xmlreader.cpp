#include "xmlreader.hpp"

XMLReader::XMLReader()
{

}

XMLReader::XMLReader(std::string fileName)
{
    this->fileName = fileName;
}

void XMLReader::readData()
{
    readCoordinatesFile();
    parseCoordinatesDocument();
    storeData("passenger");
    storeData("obstacle");
}

void XMLReader::readCoordinatesFile()
{
    std::ifstream fileStream(this->fileName);
    std::vector<char> buffer((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    this->fileContents = buffer;
    //std::cout << &this->fileContents[0] << std::endl;
}

void XMLReader::parseCoordinatesDocument()
{
   //this->coordinateDocument.parse<0>(&this->fileContents[0]);
   this->coordinateDocument.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&this->fileContents[0]);
}

void XMLReader::storeData(std::string type)//does both passengers and obstacles 
{   
    this->documentRootNode = coordinateDocument.first_node("initial-locations");

    rapidxml::xml_node<>* setNode = this->documentRootNode->first_node((type + "-set").c_str());
    rapidxml::xml_node<>* node = setNode->first_node(type.c_str());

    while(node != 0)
    {
        std::string x = node->first_attribute("x")->value();
        std::string y = node->first_attribute("y")->value();

        double xCoordinate = std::stod(x);
        double yCoordinate = std::stod(y);

        if (type == "passenger"){
            this->xPedestrianCoordinates.push_back(xCoordinate);
            this->yPedestrianCoordinates.push_back(yCoordinate);
        }else if (type == "obstacle"){
            this->xObstacleCoordinates.push_back(xCoordinate);
            this->yObstacleCoordinates.push_back(yCoordinate);
        }

        node = node->next_sibling();
    }
}

std::vector<double> XMLReader::getXPedestrianCoordinates()
{
    return this->xPedestrianCoordinates;
}

std::vector<double> XMLReader::getYPedestrianCoordinates()
{
    return this->yPedestrianCoordinates;
}

std::vector<double> XMLReader::getXObstacleCoordinates()
{
    return this-> xObstacleCoordinates;
}

std::vector<double> XMLReader::getYObstacleCoordinates()
{
    return this->yObstacleCoordinates;
} 
