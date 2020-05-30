#ifndef XML_READER_HPP
#define XML_READER_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

#include "type_definitions.hpp"
#include "rapidxml-1.13/rapidxml.hpp"
#include "input_data_loader.hpp"
#include "data.hpp"

class XMLReader: public InputDataLoader
{
    public:
        XMLReader();
        
        void extractFileData(std::string, std::string, std::string);
        virtual void storeData(Data*);
       
    private:
        Data* data;
        std::ifstream fileStream;      
        std::vector<char> fileContents;
        std::string rootElement;
        std::string parseElement;
   
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootNode;
        rapidxml::xml_node<>* dataNode;

        void openFile(std::string);
        void setRootElement(std::string);
        void setParseElement(std::string);
        void readFile();
        void parseXMLDocument();

        void setData(Data*);
        void initializeTraversalNodes();
        FLOATING_NUMBER getNodeAttributeValue(rapidxml::xml_node<>*, std::string); //probably change to return any type
};

#endif
