#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>

#include "rapidxml-1.13/rapidxml.hpp"
#include "readerinterface.hpp"

class XMLReader: public ReaderInterface
{
    public:
        XMLReader();
        XMLReader(std::string);
        virtual void readData();
        virtual std::vector<std::string> getPassengerTypes();
        virtual std::vector<std::pair<double, double>> getPassengerCoordinates();
        virtual std::vector<std::pair<double, double>> getObstacleCoordinates();

    private:
        std::string fileName;
        std::vector<std::string> passengerTypes;
        std::vector<std::pair<double, double>> passengerCoordinates;
        std::vector<std::pair<double, double>> obstacleCoordinates;

        rapidxml::xml_document<> coordinateDocument;
        rapidxml::xml_node<> * documentRootNode;
        std::vector<char> fileContents;

        void readCoordinatesFile();
        void parseCoordinatesDocument();
        void storePassengerData();
        void storeObstacleData();


};

#endif
