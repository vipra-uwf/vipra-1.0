#include "simulation.hpp"


Simulation::Simulation()
{

}

Simulation::Simulation(ReaderInterface* reader)
{
    this->passengerTypes = reader->getPassengerTypes();
    this->passengerCoordinates = reader->getPassengerCoordinates();
    this->obstacleCoordinates = reader->getObstacleCoordinates();
}

void Simulation::readCoordinatesFile(std::string xml_file)
{
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node;

    std::ifstream coordinate_file(xml_file);
    std::vector<char> buffer((std::istreambuf_iterator<char>(coordinate_file)), std::istreambuf_iterator<char>());

    doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&buffer[0]);

    root_node = doc.first_node("initial-locations");

    rapidxml::xml_node<>* passenger_set_node = root_node->first_node("passenger-set");
    rapidxml::xml_node<>* passenger_node = passenger_set_node->first_node("passenger");

    while(passenger_node != 0)
    {
        std::string type =  passenger_node->first_attribute("type")->value();
        std::string x = passenger_node->first_attribute("x")->value();
        std::string y = passenger_node->first_attribute("y")->value();

        this->passengerTypes.push_back(type);

        double x_coordinate = std::stod(x);
        double y_coordinate = std::stod(y);

        std::pair<double, double> coordinatePair(x_coordinate, y_coordinate);
        this->passengerCoordinates.push_back(coordinatePair);

        passenger_node = passenger_node->next_sibling();
    }

    rapidxml::xml_node<>* obstacle_set_node = root_node->first_node("obstacle-set");
    rapidxml::xml_node<>* obstacle_node = obstacle_set_node->first_node("obstacle");

    while(obstacle_node != 0)
    {
        std::string x = obstacle_node->first_attribute("x")->value();
        std::string y = obstacle_node->first_attribute("y")->value();

        double x_coordinate = std::stod(x);
        double y_coordinate = std::stod(y);

        std::pair<double, double> coordinatePair(x_coordinate, y_coordinate);
        this->obstacleCoordinates.push_back(coordinatePair);

        obstacle_node = obstacle_node->next_sibling();
    }

    coordinate_file.close();
}

void Simulation::printPassengerData()
{
    for(int i = 0; i < this->passengerCoordinates.size(); ++i)
    {
        std::cout << "Passenger " << i + 1 << " (" << this->passengerTypes[i] << ") ["
        << this->passengerCoordinates[i].first << ", " << this->passengerCoordinates[i].second << "]" << std::endl;
    }
}

void Simulation::printObstacleData()
{
    for(int i = 0; i < this->obstacleCoordinates.size(); ++i)
    {
        std::cout << "Obstacle " << i + 1 << " [" << this->obstacleCoordinates[i].first << ", "
        << this->obstacleCoordinates[i].second << "]" << std::endl;
    }
}
