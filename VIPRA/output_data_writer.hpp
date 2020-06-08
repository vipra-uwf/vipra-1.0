
#ifndef OUTPUT_DATA_WRITER_HPP 
#define OUTPUT_DATA_WRITER_HPP 

#include <vector> //TODO probably delete -- i dont know why this is here

#include "data.hpp"

class OutputDataWriter
{
    public:
        virtual void writeData(Data* data) = 0;
};

#endif