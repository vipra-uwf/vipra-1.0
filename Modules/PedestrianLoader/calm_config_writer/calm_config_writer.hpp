#ifndef CALM_CONFIG_WRITER_HPP
#define CALM_CONFIG_WRITER_HPP

#include "config_writer/config_writer.hpp"
#include "jsoncpp/json/json.h"
#include <random>
#include <spdlog/spdlog.h>

struct CalmPedestrianBuilderData : public VIPRA::PedestrianBuilderData{
    CalmPedestrianBuilderData()
        : VIPRA::PedestrianBuilderData{}, desiredSpeedMin{}, desiredSpeedMax{}, desiredSpeeds{}, distribution{} {}

    float desiredSpeedMin;
    float desiredSpeedMax;
    std::vector<float> desiredSpeeds;
    std::string distribution;
};

class CalmPedestrianConfigWriter : public PedestrianConfigWriter {

    public: 
        void configure(const VIPRA::Config::Map& configMap) override;
        void initialize() override;
        std::string buildPedestrians(const std::string& filePath) override;
    private:
        void calculateDesiredSpeeds(const unsigned int numPedestrians);
        CalmPedestrianBuilderData pedData;
      

};


#endif