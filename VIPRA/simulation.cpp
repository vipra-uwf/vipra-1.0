#include "simulation.hpp"


Simulation::Simulation()
{
    std::cout << "Simulation object created" << std::endl;
}

void Simulation::read_coordinates_file(std::string xml_file)
{
    std::cout << xml_file << std::endl;

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node;

    std::ifstream coordinate_file(xml_file);
    std::vector<char> buffer((std::istreambuf_iterator<char>(coordinate_file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    std::cout << &buffer[0] << std::endl;

    doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&buffer[0]);


    root_node = doc.first_node("initial-locations");
    rapidxml::xml_node<>* passenger_set_node = root_node->first_node("passenger-set");


    // std::string type =  passenger_set_node->first_node("passenger")->first_attribute("type")->value();
    // std::string x_coordinate = passenger_set_node->first_node("passenger")->first_attribute("x")->value();
    // std::string y_coordinate = passenger_set_node->first_node("passenger")->first_attribute("y")->value();

    //std::cout << "Type: " << type << " | x = " << x_coordinate << " | y = " << y_coordinate << std::endl;

    // for(rapidxml::xml_node<> * passenger_set_node = root_node->first_node("passenger-set"); passenger_set_node; passenger_set_node->next_sibling())
    // {
    //     std::cout << passen
    // }


    //
    // for(rapidxml::xml_node<>* passenger_set_node = root_node->first_node("passenger-set"); passenger_set_node; passenger_set_node->next_sibling())
    // {
    //
    //     std::string type =  passenger_set_node->first_node("passenger")->first_attribute("type")->value();
    //     std::string x_coordinate = passenger_set_node->first_node("passenger")->first_attribute("x")->value();
    //     std::string y_coordinate = passenger_set_node->first_node("passenger")->first_attribute("y")->value();
    //
    //     std::cout << "Type: " << type << " | x = " << x_coordinate << " | y = " << y_coordinate << std::endl;
    // }
    //


    while(passenger_set_node != 0)
    {
        std::string type =  passenger_set_node->first_node("passenger")->first_attribute("type")->value();
        std::string x_coordinate = passenger_set_node->first_node("passenger")->first_attribute("x")->value();
        std::string y_coordinate = passenger_set_node->first_node("passenger")->first_attribute("y")->value();

        std::cout << "Type: " << type << " | x = " << x_coordinate << " | y = " << y_coordinate << std::endl;

        passenger_set_node = passenger_set_node->next_sibling();

    }


}
