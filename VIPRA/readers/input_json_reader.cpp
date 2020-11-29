#include "input_json_reader.hpp"

ENTITY_SET InputJSONReader::getInputEntities()
{
    ENTITY_SET inputData;

    /*
        convert this->jsonDocument to ENTITY_SET
    *
    */

//    Json::Value root = this->jsonDocument;
    
    for(int i = 0; i < this->jsonDocument.size(); i++)
    {
        std::cout << this->jsonDocument[i]["x"] << std::endl;
    }

//    for(Json::Value::const_iterator itr = root.begin(); itr != root.end(); itr++)
//    {
//     //    Json::Value value = *itr;

//        std::cout << itr.key() << std::endl;


//    }

    // for(int i = 0; i < this->jsonDocument.size(); ++i)
    // {
    //     std::cout << this->jsonDocument.getMemberNames()[i] << std::endl;

    //     std::cout << std::endl;
    // }

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