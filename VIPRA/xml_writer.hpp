#ifndef XML_WRITER_HPP
#define XML_WRITER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "output_data_writer.hpp"
#include "data.hpp"

class XMLWriter: public OutputDataWriter
{
    public:
        XMLWriter();
        virtual void writeData(Data*);

    private:
        Data* data;
        std::ofstream fileStream;


        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* rootNode;
        rapidxml::xml_node<>* dataNode;
};


#endif