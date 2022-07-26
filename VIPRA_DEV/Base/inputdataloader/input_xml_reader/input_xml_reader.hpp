#ifndef INPUT_XML_READER_HPP
#define INPUT_XML_READER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "../input_data_loader.hpp"
#include "../rapidxml/rapidxml.hpp"
#include "../definitions/dimensions.hpp"

class InputXMLReader: public InputDataLoader
{
    private:
        std::ifstream fileStream;      
        std::vector<char> fileContents;
        std::string parentElementName;
        std::string dataElementName;
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* parentElement;
        rapidxml::xml_node<>* traversalElement;

        void openFile(std::string fileName);
        void readFile();
        void initializeTraversalElement();
        void parseXMLDocument();

    public:
		
        virtual ENTITY_SET getInputEntities();
        virtual void configure(CONFIG_MAP* configMap);
        virtual void extractFileData(
            std::string fileName, 
            CONFIG_MAP* configMap);
};

#endif
