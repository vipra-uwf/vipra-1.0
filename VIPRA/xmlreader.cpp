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
    storePassengerData();
    storeObstacleData();
}

void XMLReader::readCoordinatesFile()
{
    std::ifstream fileStream(this->fileName);
    std::vector<char> buffer((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    this->fileContents = buffer;
    std::cout << &this->fileContents[0] << std::endl;
}

void XMLReader::parseCoordinatesDocument()
{
   //this->coordinateDocument.parse<0>(&this->fileContents[0]);
   this->coordinateDocument.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&this->fileContents[0]);
}

void XMLReader::storePassengerData()
{
    this->documentRootNode = coordinateDocument.first_node("initial-locations");

    rapidxml::xml_node<>* passengerSetNode = this->documentRootNode->first_node("passenger-set");
    rapidxml::xml_node<>* passengerNode = passengerSetNode->first_node("passenger");

    while(passengerNode != 0)
    {
        std::string x = passengerNode->first_attribute("x")->value();
        std::string y = passengerNode->first_attribute("y")->value();

        double xCoordinate = std::stod(x);
        double yCoordinate = std::stod(y);

        std::pair<double, double> coordinatePair(xCoordinate, yCoordinate);
        this->passengerCoordinates.push_back(coordinatePair);

        passengerNode = passengerNode->next_sibling();
    }
}

void XMLReader::storeObstacleData()
{
    this->documentRootNode = coordinateDocument.first_node("initial-locations");

    rapidxml::xml_node<>* obstacleSetNode = this->documentRootNode->first_node("obstacle-set");
    rapidxml::xml_node<>* obstacleNode = obstacleSetNode->first_node("obstacle");

    while(obstacleNode != 0)
    {
        std::string x = obstacleNode->first_attribute("x")->value();
        std::string y = obstacleNode->first_attribute("y")->value();

        double xCoordinate = std::stod(x);
        double yCoordinate = std::stod(y);

        std::pair<double, double> coordinatePair(xCoordinate, yCoordinate);
        this->obstacleCoordinates.push_back(coordinatePair);

        obstacleNode = obstacleNode->next_sibling();
    }
}

std::vector<std::pair<double, double>> XMLReader::getPassengerCoordinates()
{
    return this->passengerCoordinates;
}

std::vector<std::pair<double, double>> XMLReader::getObstacleCoordinates()
{
    return this->obstacleCoordinates;
}
