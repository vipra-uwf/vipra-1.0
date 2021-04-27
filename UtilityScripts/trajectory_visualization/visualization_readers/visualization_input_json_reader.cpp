#include "visualization_input_json_reader.hpp"

ENTITY_SET VisualizationInputJSONReader::getInputEntities()
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

void VisualizationInputJSONReader::configure(CONFIG_MAP* configMap)
{

}

void VisualizationInputJSONReader::extractFileData(std::string fileName, CONFIG_MAP* configMap)
{
    openFile(fileName);
    parseFile();
    this->fileStream.close();
}

void VisualizationInputJSONReader::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void VisualizationInputJSONReader::parseFile()
{
    if(!Json::parseFromStream(this->jsonReader, this->fileStream, &this->jsonDocument, &this->errors))
    {
		std::cout << "Error parsing JSON: " << errors << std::endl;
    }
}