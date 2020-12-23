#include "json_writer.hpp"

JSONWriter::JSONWriter()
{
    this->parentElement = NULL;
    this->currentElement = NULL;
    this->defaultElement = NULL;
}

void JSONWriter::configure(CONFIG_MAP *configMap)
{
    setParentElementName((*configMap)["parentElementName"]);
    setChildElementName((*configMap)["childElementName"]);
}

void JSONWriter::initializeOutputFile(std::string outputFilePath)
{
    openFile(outputFilePath);
    initializeParentElement();
}

void JSONWriter::appendFloatAttributeToCurrentElement(
    std::string key, FLOATING_NUMBER value)
{
    Json::Value newElement;
    newElement[key] = value;
    this->currentElement = &newElement;
    this->parentElement->append(this->currentElement);
    
    // this->currentElement[key] = value;
    // this->parentElement->append(this->currentElement);
}

void JSONWriter::appendStringAttributeToCurrentElement(
    std::string key, std::string value)
{
    Json::Value newElement;
    newElement[key] = value;
    this->currentElement = &newElement;
    this->parentElement->append(this->currentElement);

    // this->currentElement[key] = value;
    // this->parentElement->append(this->currentElement);
}

void JSONWriter::writeToDocument(Data *data)
{
    this->fileStream << this->parentElement;
    this->fileStream.close();
    this->parentElement->clear();
}

void JSONWriter::writeDocumentContentsToFile()
{
    this->fileStream << this->parentElement;
    this->fileStream.close();
    this->parentElement->clear();
}

void JSONWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void JSONWriter::initializeParentElement()
{
    *this->parentElement = Json::arrayValue;
}

// void JSONWriter::initializeChildElements()
// {
    
// }

// void JSONWriter::setData(Data* initialData)
// {

// }

void JSONWriter::setParentElementName(std::string parentElementName)
{
    this->parentElementName = parentElementName;
}

void JSONWriter::setChildElementName(std::string childElementName)
{
    this->childElementName = childElementName;
}

// void JSONWriter::setNumChildElements(int numChildElements)
// {
//     this->numChildElements = numChildElements;
// }