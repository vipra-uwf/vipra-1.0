#ifndef INPUT_XML_READER_HPP
#define INPUT_XML_READER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <unordered_map>

#include "input_data_loader.hpp"
#include "../type_definitions.hpp"
#include "../rapidxml/rapidxml.hpp"
#include "../simulation/data.hpp"
#include "../dimensions.hpp"

class InputXMLReader: public InputDataLoader
{
    private:
        std::ifstream fileStream;      
        std::vector<char> fileContents;
        std::string rootElementName;
        std::string dataElementName;
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootElement;
        rapidxml::xml_node<>* traversalElement;

        void openFile(std::string fileName);
        void readFile();
        void initializeTraversalElement();
        void parseXMLDocument();

    public:
		
        virtual ENTITY_SET getInputEntities();

        virtual void extractFileData(
            std::string fileName, 
            std::string rootElementName);
};

#endif
