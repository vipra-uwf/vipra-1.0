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
    if(this->fileStream.fail()){
        throw std::runtime_error("Unable to Open Configuration File: " + fileName);
    }
}

void ConfigurationReader::parseFile()
{
    if(!Json::parseFromStream(this->jsonReader, this->fileStream, &this->jsonDocument, &this->errors))
    {
		std::cout << "Error parsing JSON: " << errors << std::endl;
    }
}

void ConfigurationReader::configure(CONFIG_MAP* config){
    
}