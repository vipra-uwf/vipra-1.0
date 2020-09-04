#ifndef OUTPUT_DATA_WRITER_HPP 
#define OUTPUT_DATA_WRITER_HPP 

#include <string>

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"

class OutputDataWriter
{
    public:
        virtual ~OutputDataWriter() = default;
        
        virtual void writeData(Data* data) = 0;
        virtual void writeFloatData(std::string key, FLOATING_NUMBER value) = 0;
        virtual void writeStringData(std::string key, std::string value) = 0;
};

#endif