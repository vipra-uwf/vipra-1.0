#ifndef XML_READER_HPP
#define XML_READER_HPP

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
#include "../goals/goal.hpp"

class XMLReader: public InputDataLoader
{
    private:
        Data* data;
        std::ifstream fileStream;      
        std::vector<char> fileContents;
        std::string rootNodeName;
        std::string dataNodeName;
        int numDataNodes;
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootNode;
        rapidxml::xml_node<>* dataNode;

        void openFile(std::string fileName);
        void readFile();
        void setRootNodeName(std::string rootNodeName);
        void setDataNodeName(std::string dataNodeName);
        void initializeRootNode();
        void initializeDataNode();
        void parseXMLDocument();

        FLOATING_NUMBER getFloatValue(
            rapidxml::xml_node<>* node, std::string attribute);
        std::string getStringValue(
            rapidxml::xml_node<>* node, std::string attribute);
		std::unordered_map<std::string, FLOATING_NUMBER> getSimulationParams(
            std::string parentNode); //clarify responsibility	


    public:
        XMLReader();
        virtual void storeData(Data* data);

        void extractFileData(
            std::string fileName, 
            std::string rootNodeName, 
            std::string dataNodeName);
        std::vector<FLOATING_NUMBER> getFloatDataSet(std::string attribute);
        std::vector<std::string> getStringDataSet(std::string attribute);
};

#endif
