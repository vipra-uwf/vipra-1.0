#include "simulation.hpp"


Simulation::Simulation()
{
    std::cout << "Simulation object created" << std::endl;
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
        std::string x_coordinate = passenger_node->first_attribute("x")->value();
        std::string y_coordinate = passenger_node->first_attribute("y")->value();

        std::cout << "Type: " << type << " | x = " << x_coordinate << " | y = " << y_coordinate << std::endl;

        passenger_node = passenger_node->next_sibling();
    }

    rapidxml::xml_node<>* obstacle_set_node = root_node->first_node("obstacle-set");
    rapidxml::xml_node<>* obstacle_node = obstacle_set_node->first_node("obstacle");

    while(obstacle_node != 0)
    {
        std::string x_coordinate = obstacle_node->first_attribute("x")->value();
        std::string y_coordinate = obstacle_node->first_attribute("y")->value();

        std::cout << "x = " << x_coordinate << " | y = " << y_coordinate << std::endl;

        obstacle_node = obstacle_node->next_sibling();
    }

}
