#include "PedestrianLoader/calm_config_writer/calm_config_writer.hpp"

void CalmPedestrianConfigWriter::configure(const VIPRA::Config::Map& configMap) {
    spdlog::info("CalmPedestrianConfigWriter: Configuring Calm Config Writer");
    pedData.desiredSpeedMin = configMap["desiredSpeedMin"].asFloat();
    pedData.desiredSpeedMax = configMap["desiredSpeedMax"].asFloat();
    spdlog::info("CalmPedestrianConfigWriter: Done Configuring Calm Config Writer");
}

void CalmPedestrianConfigWriter::initialize() {}

std::string CalmPedestrianConfigWriter::buildPedestrians(const std::string& filePath) {
    spdlog::info("CalmConfigWriter: Writing Pedestrian Config");

    Json::Value             jsonDocument;
    Json::CharReaderBuilder jsonReader;
    std::ifstream           inputFileStream;
    std::ofstream           outputFileStream;
    std::string             errors;
    

    inputFileStream.open(filePath);
    if(!inputFileStream.is_open()) {
        PedestrianConfigWriterException::Throw("Unable To Open Map File: " + filePath + "\n");
    }
    
    if(!Json::parseFromStream(jsonReader, inputFileStream, &jsonDocument, &errors)) {
        inputFileStream.close();
        spdlog::error("CalmPedestrianConfigWriter: Jsoncpp unable to parse file");
        PedestrianConfigWriterException::Throw("Unable To Parse Map File: " + filePath + "\n");
    }
    inputFileStream.close();

    std::string newFilePath = filePath.substr(0, filePath.size() - 5) + "Generated.pmap";
    try {
        spdlog::info("CalmPedestrianConfigWriter: Parsed JSON, Building New Config");
        
        outputFileStream.open(newFilePath);

        const unsigned int numPedestrians = jsonDocument["pedestrians"].size();

        calculateDesiredSpeeds(numPedestrians);

        for(unsigned int i = 0; i < numPedestrians; i++) {
            jsonDocument["pedestrians"][i]["desiredSpeed"] = pedData.desiredSpeeds[i];
        }

        Json::StreamWriterBuilder styledWriter;

        styledWriter["commentStyle"] = "None";
        styledWriter["indentation"] = "   ";
        styledWriter["precision"] = 6;
        std::string jsonString = Json::writeString(styledWriter, jsonDocument);
        outputFileStream << jsonString;
        outputFileStream.close();

        std::vector<float> desiredSpeed = std::vector<float>();                         

    
    } catch(const std::exception& ex) {
        spdlog::debug("CalmPedestrianConfigWriter: Error Building Json, Error: {}", ex.what());
        outputFileStream.close();
        PedestrianConfigWriterException::Throw("Unable to write json file: " + filePath + "2\n");
    }


    spdlog::info("CalmPedestrianConfigWriter: Done Writing Pedestrian Config");
    return newFilePath;
}

void CalmPedestrianConfigWriter::calculateDesiredSpeeds(const unsigned int numPedestrians) {
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(pedData.desiredSpeedMin, pedData.desiredSpeedMax);
    
    for(unsigned int i = 0; i < numPedestrians; i++) {
        pedData.desiredSpeeds.push_back(distribution(generator));
    }
}