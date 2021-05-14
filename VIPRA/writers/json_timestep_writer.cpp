#include "json_timestep_writer.hpp"

JSONTimestepWriter::JSONTimestepWriter()
{
    this->index = 0;
    this->timestepID = 0;
}

void JSONTimestepWriter::configure(CONFIG_MAP *configMap)
{
    setParentElementName((*configMap)["parentElementName"]);
    setChildElementName((*configMap)["childElementName"]);
}

void JSONTimestepWriter::initializeOutputFile(std::string outputFilePath)
{
    openFile(outputFilePath);
}

void JSONTimestepWriter::appendFloatAttributeToCurrentElement(
    std::string key, FLOATING_NUMBER value)
{ 
    if (key == "NEW_TIMESTEP") {
        this->timestepID = value;
    }
    else {
        if (this->document[std::to_string(timestepID)].isNull()) {
            this->index = 0;
            this->document[std::to_string(timestepID)][this->index][key] = value;
        }
        else if (this->document[std::to_string(timestepID)][this->index][key].isNull()) {
            this->document[std::to_string(timestepID)][this->index][key] = value;
        }
        else {
            this->index++;
            this->document[std::to_string(timestepID)][this->index][key] = value;
        }
    }
}

void JSONTimestepWriter::appendStringAttributeToCurrentElement(
    std::string key, std::string value)
{
    if (this->document[std::to_string(timestepID)].isNull()) {
        this->index = 0;
        this->document[std::to_string(timestepID)][this->index][key] = value;
    }
    else if (this->document[std::to_string(timestepID)][this->index][key].isNull()) {
        this->document[std::to_string(timestepID)][this->index][key] = value;
    }
    else {
        this->index++;
        this->document[std::to_string(timestepID)][this->index][key] = value;
    }
}

void JSONTimestepWriter::writeToDocument(Data *data)
{
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void JSONTimestepWriter::writeDocumentContentsToFile()
{
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void JSONTimestepWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void JSONTimestepWriter::setParentElementName(std::string parentElementName)
{
    this->parentElementName = parentElementName;
}

void JSONTimestepWriter::setChildElementName(std::string childElementName)
{
    this->childElementName = childElementName;
}