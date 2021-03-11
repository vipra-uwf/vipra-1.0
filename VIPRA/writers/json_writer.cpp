#include "json_writer.hpp"

JSONWriter::JSONWriter()
{
    this->index = 0;
    // setParentElementName("pedestrian-set");
    // setChildElementName("pedestrian");
}

void JSONWriter::configure(CONFIG_MAP *configMap)
{
    setParentElementName((*configMap)["parentElementName"]);
    setChildElementName((*configMap)["childElementName"]);
}

void JSONWriter::initializeOutputFile(std::string outputFilePath)
{
    openFile(outputFilePath);
}

void JSONWriter::appendFloatAttributeToCurrentElement(
    std::string key, FLOATING_NUMBER value)
{
    if (this->elementArray[this->index][this->childElementName][key].isNull()) {
        this->elementArray[this->index][this->childElementName][key] = value;
    }
    else {
        this->index++;
        this->elementArray[this->index][this->childElementName][key] = value;
    }
}

void JSONWriter::appendStringAttributeToCurrentElement(
    std::string key, std::string value)
{
    if (this->elementArray[this->index][this->childElementName][key].isNull()) {
        this->elementArray[this->index][this->childElementName][key] = value;
    }
    else {
        this->index++;
        this->elementArray[this->index][this->childElementName][key] = value;
    }
}

void JSONWriter::writeToDocument(Data *data)
{
    this->document[this->parentElementName] = this->elementArray;
    
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void JSONWriter::writeDocumentContentsToFile()
{
    this->document[this->parentElementName] = this->elementArray;
    
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void JSONWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void JSONWriter::setParentElementName(std::string parentElementName)
{
    this->parentElementName = parentElementName;
}

void JSONWriter::setChildElementName(std::string childElementName)
{
    this->childElementName = childElementName;
}