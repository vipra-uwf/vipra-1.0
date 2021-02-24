#include "json_writer.hpp"

JSONWriter::JSONWriter()
{
    
}

void JSONWriter::configure(CONFIG_MAP *configMap)
{
    
}

void JSONWriter::initializeOutputFile(std::string outputFilePath)
{
    openFile(outputFilePath);

}

void JSONWriter::appendFloatAttributeToCurrentElement(
    std::string key, FLOATING_NUMBER value)
{
    this->currentElement[key] = value;
}

void JSONWriter::appendStringAttributeToCurrentElement(
    std::string key, std::string value)
{
    this->currentElement[key] = value;
}

void JSONWriter::writeToDocument(Data *data)
{
    this->document.append(this->currentElement);

    //Why do we need these? We do these in the next function -Liam    
    // this->fileStream << this->document;
    // this->fileStream.close();
    this->currentElement.clear();
}

void JSONWriter::writeDocumentContentsToFile()
{
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void JSONWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}