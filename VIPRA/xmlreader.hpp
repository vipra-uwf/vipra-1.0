#ifndef XML_READER_HPP
#define XML_READER_HPP

//TODO: Refactor to use the Data object COMPLETE

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "rapidxml-1.13/rapidxml.hpp"
#include "input_data_loader.hpp"
#include "data.hpp"

class XMLReader: public InputDataLoader
{
    public:
        XMLReader();
        //XMLReader(std::string);
        void openFile(std::string);
        void setRootNodeName(std::string);
        void setParseNodeName(std::string);
        virtual void writeData(Data*);

    private:
        std::string fileName;
        std::string rootNodeName;
        std::string parseNodeName;
        Data* data;
       
        rapidxml::xml_document<> coordinateDocument;
        rapidxml::xml_node<> * documentRootNode;
        std::vector<char> fileContents;

        void readCoordinatesFile();
        void parseCoordinatesDocument();
        void storeData();
        void setDataCoordinates(rapidxml::xml_node<>*);
};

#endif
