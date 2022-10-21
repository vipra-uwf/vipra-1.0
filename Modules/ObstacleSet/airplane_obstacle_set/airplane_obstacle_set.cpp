#include "airplane_obstacle_set.hpp"

void AirplaneObstacleSet::initialize(const ENTITY_SET& MapType)
{
    this->objects = MapType;
}

void AirplaneObstacleSet::configure(const CONFIG_MAP& configMap) override
{
    configurationMap = configMap;
}

void AirplaneObstacleSet::addObjects(const std::string& type, const std::vector<Dimensions>& locations) override
{
    this->objects[type] = locations;
}

void AirplaneObstacleSet::setObstacleCoords(const std::vector<Dimensions>& coordinates) override
{
    this->objects["obstacles"] = coordinates;
}

int  AirplaneObstacleSet::getNumObstacles() const noexcept override
{
    return this->objects["obstacles"].size();
}

const std::vector<Dimensions>& AirplaneObstacleSet::getObstacleCoordinates() const noexcept override
{
    return this->objects["obstacles"];
}

const DimVector& AirplaneObstacleSet::NearestObstacle(const Dimensions coordinates, const Dimensions velocity)
{
    int min_index = 0;
    for(i = 0; i < objects["obstacles"].size(); i++)
    {
        if(coordinates.distanceTo(objects["obstacles"][i]) < coordinates.distanceTo(objects["obstacles"][min_index]))
            min_index = i;
    }

    return &objects["obstacles"][min_index];
}

const DimVector& AirplaneObstacleSet::NearestObstacle(PedestrianSet PedSet)
{
    Dimensions coordinates = PedSet.getPedestrianCoords;
    int min_index = 0;
    for(i = 0; i < objects["obstacles"].size(); i++)
    {
        if(coordinates.distanceTo(objects["obstacles"][i]) < coordinates.distanceTo(objects["obstacles"][min_index]))
            min_index = i;
    }

    return &objects["obstacles"][min_index];
}


const std::vector<Dimensions>& AirplaneObstacleSet::getObjectsofType(const std::string& type) const noexcept override
{
    return objects[type];  
}


const std::vector<std::string>& AirplaneObstacleSet::getObjectTypes() const noexcept override
{
    std::vector<std::string> mapKeys;
    for(auto mapIterator: objects)
    {
        mapKeys.push_back(mapIterator.first);
    }

    return mapKeys;

}

const Dimensions AirplaneObstacleSet::getDimensions() const noexcept override
{
    FLOATING_NUMBER maxX = 0, maxY = 0, maxZ = 0;
    for(auto mapIterator: objects)
    {
        for(int i = 0; i < mapIterator.second.size(); i++)
        {
            Dimensions coordinates = mapIterator.second[i];

            if(coordinates.axis[0] > maxX)
                maxX = coordinates.axis[0];
            if(coordinates.axis[1] > maxY)
                maxX = coordinates.axis[1];
            if(coordinates.axis[2] > maxZ)
                maxX = coordinates.axis[2];

        }
    }
    Dimensions returnDimension(maxX, maxY, maxZ);

    return returnDimension;

}

const FLOATING_NUMBER AirplaneObstacleSet::rayHit(Dimensions point1, Dimensions point2) const noexcept override
{
    FLOATING_NUMBER dirRatioL, dirRatioM, dirRatioN;
    dirRatioL = point2.axis[0] - point1.axis[0];
    dirRatioM = point2.axis[1] - point1.axis[1];
    dirRatioN = point2.axis[2] - point1.axis[2];

    for(int i = 0; i < objects["obstacles"].size(); i++)
    {
        Dimensions coordinates = objects["obstacles"][i];

        FLOATING_NUMBER xRatio = (coordinates.axis[0] - point1.axis[0])/dirRatioL;
        FLOATING_NUMBER yRatio = (coordinates.axis[1] - point1.axis[1])/dirRatioM;
        FLOATING_NUMBER zRatio = (coordinates.axis[2] - point1.axis[2])/dirRatioN;

        if(xRatio == yRatio && yRatio == zRatio)
        {
            return coordinates.distanceTo(point1);
        }
    }

    return -1;
} 