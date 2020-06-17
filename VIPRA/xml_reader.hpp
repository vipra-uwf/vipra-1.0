#ifndef XML_READER_HPP
#define XML_READER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

#include "type_definitions.hpp"
#include "rapidxml-1.13/rapidxml.hpp"
#include "input_data_loader.hpp"
#include "data.hpp"

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

        void openFile(std::string);
        void readFile();
        void setRootElement(std::string);
        void setParseElement(std::string);
        void parseXMLDocument();

        FLOATING_NUMBER getFloatValue(rapidxml::xml_node<>*, std::string);
        std::string getStringValue(rapidxml::xml_node<>*, std::string);

        std::vector<FLOATING_NUMBER> getFloatDataSet(std::string);
        std::vector<std::string> getStringDataSet(std::string);

        void extractFileData(std::string, std::string, std::string);
        void initializeRootNode();
        void initializeDataNode();

    public:
        XMLReader();
        virtual void storeData(Data*);
};

#endif
