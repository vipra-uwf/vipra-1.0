#include "xmlreader.hpp"

// XMLReader::XMLReader()
// {
// }

XMLReader::XMLReader(std::string fileName)
{
    this->fileName = fileName;
}

void XMLReader::readData()
{

}

std::vector<std::string> XMLReader::getPassengerTypes()
{
    return this->passengerTypes;
}

std::vector<std::pair<double, double>> XMLReader::getPassengerCoordinates()
{
    return this->passengerCoordinates;
}

std::vector<std::pair<double, double>> XMLReader::getObstacleCoordinates()
{
    return this->obstacleCoordinates;
}
