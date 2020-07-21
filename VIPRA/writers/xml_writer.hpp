#ifndef XML_WRITER_HPP
#define XML_WRITER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

#include "output_data_writer.hpp"
#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_print.hpp"
#include "../simulation/data.hpp"

class XMLWriter: public OutputDataWriter
{
    private:
        Data* data;
        std::ofstream fileStream;
        std::string rootNodeName;
        std::string dataNodeName;
        int numDataNodes;
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootNode;
        rapidxml::xml_node<>* currentNode;

        void openFile(std::string fileName);
        void initializeXMLDeclaration(
            std::string versionNum, std::string encodingType);
        void initializeRootNode();
        void initializeDataNodes();
        void generateDataNode();
 
        void appendDataNodeAttribute(
            rapidxml::xml_node<>* node, std::string key, std::string value);
        void writeFloatDataSet(
            std::string key, std::vector<FLOATING_NUMBER> dataSet);
        void writeStringDataSet(
            std::string key, std::vector<std::string> dataSet);
        
        void setRootNodeName(std::string rootNodeName);
        void setDataNodeName(std::string dataNodeName);
        void setData(Data* initialData);
        void setNumDataNodes(int numDataNodes);
              
    public:
        XMLWriter();
        void configureXMLDocumentStructure(
            std::string fileName, 
            std::string rootNodeName, std::string dataNodeName, 
            std::string versionNum, std::string encodingType);
        virtual void writeData(Data* data);
        virtual void writeFloatData(std::string key, FLOATING_NUMBER value);
        virtual void writeStringData(std::string key, std::string value);
        void writeDocumentContents();
};

#endif
