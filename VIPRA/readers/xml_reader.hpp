#ifndef XML_READER_HPP
#define XML_READER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <unordered_map>

#include "input_data_loader.hpp"
#include "../type_definitions.hpp"
#include "../rapidxml/rapidxml.hpp"
#include "../simulation/data.hpp"
#include "../dimensions.hpp"

class XMLReader: public InputDataLoader
{
    private:
        Data* data;
        std::ifstream fileStream;      
        std::vector<char> fileContents;
        std::string rootElement;
        std::string parseElement;

        int numEntities;
   
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootNode;
        rapidxml::xml_node<>* dataNode;

        void openFile(std::string fileName);
        void readFile();
        void setRootElement(std::string rootElement);
        void setParseElement(std::string parseElement);
        void parseXMLDocument();

        FLOATING_NUMBER getFloatValue(
            rapidxml::xml_node<>* node, std::string attribute);
        std::string getStringValue(
            rapidxml::xml_node<>* node, std::string attribute);

 
		std::unordered_map<std::string, FLOATING_NUMBER> getSimulationParams(
            std::string parentNode); //clarify responsibility	

        void initializeRootNode();
        void initializeDataNode();

    public:
        XMLReader();
        virtual void storeData(Data* data);

        void extractFileData(
            std::string fileName, 
            std::string rootElement, 
            std::string parseElement);
        std::vector<FLOATING_NUMBER> getFloatDataSet(std::string attribute);
        std::vector<std::string> getStringDataSet(std::string attribute);
};

#endif
