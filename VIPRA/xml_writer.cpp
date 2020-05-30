#include "xml_writer.hpp"

XMLWriter::XMLWriter()
{

}

void XMLWriter::writeData(Data* data)
{
    std::cout  << "writing data" << std::endl;

    rapidxml::xml_node<>* declarationNode = this->document.allocate_node(rapidxml::node_declaration);
    declarationNode->append_attribute(this->document.allocate_attribute("version", "1.0"));
    declarationNode->append_attribute(this->document.allocate_attribute("encoding", "utf-8"));
    this->document.append_node(declarationNode);

    this->rootNode = this->document.allocate_node(rapidxml::node_element, "passenger-set");
    this->document.append_node(rootNode);

    this->dataNode = this->document.allocate_node(rapidxml::node_element, "passenger");
    this->dataNode->append_attribute(this->document.allocate_attribute("x", "5.2"));
    this->dataNode->append_attribute(this->document.allocate_attribute("y", "1.7"));

    this->rootNode->append_node(dataNode);

    this->dataNode = this->document.allocate_node(rapidxml::node_element, "passenger");
    this->dataNode->append_attribute(this->document.allocate_attribute("x", "4.1"));
    this->dataNode->append_attribute(this->document.allocate_attribute("y", "7.8"));

    this->rootNode->append_node(dataNode);

    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), this->document, 0);

    // std::cout << this->document;


    this->fileStream.open("passengerwritten.xml");
    this->fileStream << this->document;

    this->fileStream.close();
    this->document.clear();

}