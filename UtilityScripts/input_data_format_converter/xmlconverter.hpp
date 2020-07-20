#ifndef XML_CONVERTER_HPP
#define XML_CONVERTER_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "./writers/xml_writer.hpp"

class XMLConverter
{
    private:
        std::ifstream fileStream; 
        XMLWriter xmlWriter;
    public:
        void convertToXML(std::string, int flag);
};

#endif
