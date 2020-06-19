#ifndef OUTPUT_DATA_WRITER_HPP 
#define OUTPUT_DATA_WRITER_HPP 

#include <string>

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"

class OutputDataWriter
{
    public:
        virtual void writeData(Data* data) = 0;
        virtual void writeFloatData(std::string, FLOATING_NUMBER) = 0;
        virtual void writeStringData(std::string, std::string) = 0;
};

#endif