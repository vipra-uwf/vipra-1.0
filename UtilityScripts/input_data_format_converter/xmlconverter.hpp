#ifndef XML_CONVERTER_HPP
#define XML_CONVERTER_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "../../VIPRA/writers/xml_writer.hpp"

class XMLConverter
{
    private:
        std::ifstream fileStream; 
        XMLWriter xmlWriter;
    public:
        void convertCoordFileToXML(std::string fileName, int flag);
};

#endif
