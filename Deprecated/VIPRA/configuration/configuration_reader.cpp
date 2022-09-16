#include "configuration_reader.hpp"

void ConfigurationReader::readJsonConfiguration(std::string fileName)
{
    openFile(fileName);
    parseFile();
    this->fileStream.close();
}

Json::Value ConfigurationReader::getJsonObject()
{
    return this->jsonDocument;
}

void ConfigurationReader::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void ConfigurationReader::parseFile()
{
    if(!Json::parseFromStream(this->jsonReader, this->fileStream, &this->jsonDocument, &this->errors))
    {
		std::cout << "Error parsing JSON: " << errors << std::endl;
    }
}