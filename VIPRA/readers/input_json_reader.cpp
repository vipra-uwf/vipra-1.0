#include "input_json_reader.hpp"

ENTITY_SET InputJSONReader::getInputEntities()
{
    ENTITY_SET inputData;

    for(unsigned int i = 0; i < this->jsonDocument.size(); i++)
    {
        inputData.push_back(std::unordered_map<std::string, std::string>());

        for(unsigned int j = 0; j < this->jsonDocument[i].size(); j++)
        {
            std::string key = this->jsonDocument[i].getMemberNames()[j];
            std::string value = this->jsonDocument[i][this->jsonDocument[i].getMemberNames()[j]].asString();

            inputData[i][key] = value;
        } 
    }
    
    return inputData;
}

void InputJSONReader::configure(CONFIG_MAP* configMap)
{

}

void InputJSONReader::extractFileData(std::string fileName, CONFIG_MAP* configMap)
{
    //TODO dr eddy thinks openFile and parseFile should be in configure
    //TODO but fileName isnt a part of config maps -- Alex
    openFile(fileName);
    parseFile();
}

void InputJSONReader::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void InputJSONReader::parseFile()
{
    if(!Json::parseFromStream(this->jsonReader, this->fileStream, &this->jsonDocument, &this->errors))
    {
		std::cout << "Error parsing JSON: " << errors << std::endl;
    }
}