#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <vector>
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class PedestrianSet
{
    public:
        virtual ~PedestrianSet() = default;
        
        virtual void configure(CONFIG_MAP* configMap) = 0;
        virtual void removePedestrian(int pedestrianIndex) = 0;
        virtual int getNumPedestrians() = 0;
        virtual std::vector<Dimensions>* getPedestrianCoordinates() = 0;
        virtual std::vector<Dimensions>* getGoalCoordinates() = 0;
        virtual std::vector<Dimensions>* getVelocities() = 0;
        virtual std::vector<FLOATING_NUMBER>* getSpeeds() = 0;

        virtual void setNumPedestrians(int numPedestrians) = 0;
        virtual void setPedestrianCoordinates(
            std::vector<Dimensions> coordinates) = 0;
        virtual void setGoalCoordinates(
            std::vector<Dimensions> goalCoordinates) = 0;
        virtual void setVelocities(
            std::vector<Dimensions> velocities) = 0;
        virtual void setSpeeds(
            std::vector<FLOATING_NUMBER> speedsMetersPerSecond) = 0;
        
        // virtual ~PedestrianSet();
};

#endif
