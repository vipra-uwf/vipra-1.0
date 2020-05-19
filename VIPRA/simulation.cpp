#include "simulation.hpp"


Simulation::Simulation()
{

}

void Simulation::read_coordinates_file(std::string xml_file)
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

        this->passenger_types.push_back(type);

        double x_coordinate = std::stod(x);
        double y_coordinate = std::stod(y);

        std::pair<double, double> coordinate_pair(x_coordinate, y_coordinate);
        this->passenger_coordinates.push_back(coordinate_pair);

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

        std::pair<double, double> coordinate_pair(x_coordinate, y_coordinate);
        this->obstacle_coordinates.push_back(coordinate_pair);

        obstacle_node = obstacle_node->next_sibling();
    }

    coordinate_file.close();
}

void Simulation::print_passenger_data()
{
    for(int i = 0; i < this->passenger_coordinates.size(); ++i)
    {
        std::cout << "Passenger " << i + 1 << " (" << this->passenger_types[i] << ") ["
        << this->passenger_coordinates[i].first << ", " << this->passenger_coordinates[i].second << "]" << std::endl;
    }
}

void Simulation::print_obstacle_data()
{
    for(int i = 0; i < this->obstacle_coordinates.size(); ++i)
    {
        std::cout << "Obstacle " << i + 1 << " [" << this->obstacle_coordinates[i].first << ", "
        << this->obstacle_coordinates[i].second << "]" << std::endl;
    }
}
