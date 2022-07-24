#include "airplane_obstacle_set.hpp"

#include <iostream>

const std::vector<Dimensions> ObstacleSet::__empty__{};

AirplaneObstacleSet::AirplaneObstacleSet(): objects(), types(), aisles(), aislesSize(){}

void AirplaneObstacleSet::configure(CONFIG_MAP* configMap)
{

}

void AirplaneObstacleSet::setObstacleCoordinates(const std::vector<Dimensions>& coordinates){
    this->objects["obstacles"] = coordinates;
}

void AirplaneObstacleSet::setAisles(const std::vector<FLOATING_NUMBER>& aisles){
    this->aisles = aisles;
}

void AirplaneObstacleSet::setAislesSize(const std::vector<FLOATING_NUMBER>& aisles){
    this->aislesSize = aisles;
}

void AirplaneObstacleSet::addObjects(const std::string& type, const std::vector<Dimensions>& locations) {
    this->objects[type] = locations;
}

int AirplaneObstacleSet::getNumAisles() const noexcept {
    return this->aisles.size();
}

const std::vector<FLOATING_NUMBER>& AirplaneObstacleSet::getAisles() const noexcept {
    return this->aisles;
}

const std::vector<FLOATING_NUMBER>& AirplaneObstacleSet::getAislesSize() const noexcept {
    return this->aislesSize;
}

int AirplaneObstacleSet::getNumObstacles() const noexcept {
    return this->objects.at("obstacles").size();
}

const std::vector<Dimensions>& AirplaneObstacleSet::getObstacleCoordinates() const noexcept {
    return this->objects.at("obstacles");
}

const std::vector<Dimensions>& AirplaneObstacleSet::getObjectsofType(const std::string& type) const noexcept{
    if(this->objects.find(type) != this->objects.end()){
        return this->objects.at(type);
    }else{
        return __empty__;
    }
}

const std::vector<std::string>& AirplaneObstacleSet::getObjectTypes() const noexcept {
    return this->types;
}