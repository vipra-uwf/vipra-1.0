#ifndef XMLREADER_HPP
#define XMLREADER_HPP

//TODO: Refactor to use the Data object

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>

#include "rapidxml-1.13/rapidxml.hpp"
#include "input_data_loader.hpp"

class XMLReader: public InputDataLoader
{
    public:
        XMLReader();
        XMLReader(std::string);
 
        virtual void readData();
        virtual std::vector<double> getXPedestrianCoordinates();
        virtual std::vector<double> getYPedestrianCoordinates();
        virtual std::vector<double> getXObstacleCoordinates();
        virtual std::vector<double> getYObstacleCoordinates(); 
       

    private:
        std::string fileName;
       
        std::vector<double> xPedestrianCoordinates;
        std::vector<double> yPedestrianCoordinates;
        std::vector<double> xObstacleCoordinates;
        std::vector<double> yObstacleCoordinates;
       
        rapidxml::xml_document<> coordinateDocument;
        rapidxml::xml_node<> * documentRootNode;
        std::vector<char> fileContents;

        void readCoordinatesFile();
        void parseCoordinatesDocument();
        void storePassengerData();
        void storeObstacleData();


};

#endif
