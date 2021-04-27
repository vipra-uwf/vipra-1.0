#include "visualization_input_json_reader.hpp"

std::vector<ENTITY_SET> VisualizationInputJSONReader::getInputEntities()
{
    std::vector<ENTITY_SET> inputData;
    std::string currentTimestepID;
    Json::Value currentTimestep;
    Json::Value currentPedestrian;
    std::string key;
    std::string value;
    
    for(unsigned int i = 0; i < this->jsonDocument.size(); i++)
    {   
        currentTimestepID = std::to_string(i);
        currentTimestep = this->jsonDocument.get(currentTimestepID, 0);
        inputData.push_back(std::vector<std::unordered_map<std::string, std::string>>(currentTimestep.size()));
        
        for(unsigned int j = 0; j < currentTimestep.size(); j++)
        {
            currentPedestrian = currentTimestep[j];
            inputData[i].push_back(std::unordered_map<std::string, std::string>(currentPedestrian.size()));

            for (unsigned int k = 0; k < currentPedestrian.size(); k++) {
                key = currentPedestrian.getMemberNames()[k];
                value = currentPedestrian.get(key, 0).asString();
                inputData[i][j][key] = value;
            }
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