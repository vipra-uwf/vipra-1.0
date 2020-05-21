#include "xmlreader.hpp"

XMLReader::XMLReader()
{

}

XMLReader::XMLReader(std::string fileName)
{
    this->fileName = fileName;
}

void XMLReader::readData(Data* data)
{
    this->data = data;
    readCoordinatesFile();
    parseCoordinatesDocument();
    storeData("pedestrian");
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

        if (type == "pedestrian"){
            this->data->pushXPedestrianCoordinate(xCoordinate);
            this->data->pushYPedestrianCoordinate(yCoordinate);
        }else if (type == "obstacle"){
            this->data->pushXObstacleCoordinate(xCoordinate);
            this->data->pushYObstacleCoordinate(yCoordinate);
        }

        node = node->next_sibling();
    }
}
