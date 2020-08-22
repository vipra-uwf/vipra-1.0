#ifndef XML_READER_HPP
#define XML_READER_HPP

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
        std::string rootNodeName;
        std::string dataNodeName;
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootNode;
        rapidxml::xml_node<>* dataNode;

        void openFile(std::string fileName);
        void readFile();
        void initializeTraversalNodes();
        void parseXMLDocument();

    public:
		
        virtual ENTITY_SET getInputEntities();

        void extractFileData(
            std::string fileName, 
            std::string rootNodeName);
};

#endif
