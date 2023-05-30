#ifndef CALM_CONFIG_WRITER_HPP
#define CALM_CONFIG_WRITER_HPP

#include <random>

#include <json/json.h>
#include <spdlog/spdlog.h>

#include <config_writer/config_writer.hpp>

struct CalmPedestrianBuilderData : public VIPRA::PedestrianBuilderData {
  float              desiredSpeedMin{};
  float              desiredSpeedMax{};
  std::vector<float> desiredSpeeds;
  std::string        distribution;
};

class CalmPedestrianConfigWriter : public PedestrianConfigWriter {

 public:
  void        configure(const VIPRA::CONFIG::Map&) override;
  void        initialize() override;
  std::string buildPedestrians(const std::string&) override;

 private:
  CalmPedestrianBuilderData pedData;
  VIPRA::size               seed;


  void calculateDesiredSpeeds(VIPRA::size numPedestrians);
};


#endif