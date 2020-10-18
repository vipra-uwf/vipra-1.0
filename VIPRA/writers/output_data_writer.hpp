#ifndef OUTPUT_DATA_WRITER_HPP 
#define OUTPUT_DATA_WRITER_HPP 

#include <string>

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"

class OutputDataWriter
{
    public:
        virtual ~OutputDataWriter() = default;

        // TODO reconsider these method names .. writeData is vague.. why float and string write methods?
        virtual void writeData(Data* data) = 0;
        virtual void writeFloatData(std::string key, FLOATING_NUMBER value) = 0;
        virtual void writeStringData(std::string key, std::string value) = 0;
        virtual void configure(CONFIG_MAP* configMap) = 0; 
        virtual void initializeOutputFile(std::string outputFilePath) = 0;
        virtual void writeDocumentContentsToFile() = 0;
        
        // TODO virtual method for starting new element
        // TODO virtual method for closing the current element
};

#endif