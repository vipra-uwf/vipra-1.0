#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

#include "../type_definitions.hpp"

class PedestrianSet
{
    private:
        int numPedestrians;
        int numDimensions;

        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;

        std::vector<std::vector<FLOATING_NUMBER>> goalCoordinates;

        std::vector<std::vector<FLOATING_NUMBER>> pedestrianCoordinates;

        //TODO currently has no getters/setters
        std::vector<std::vector<FLOATING_NUMBER>> currentVelocitys;

    public:
        PedestrianSet();

        void initializeSpeeds();

        int getNumPedestrians();
        int getNumDimensions();

        FLOATING_NUMBER getSpeed(int);
        FLOATING_NUMBER getMassKg(int);
      
        FLOATING_NUMBER getGoalCoordinate(int, int);
 
        FLOATING_NUMBER getPedestrianCoordinate(int, int);
        
        std::vector<std::vector<FLOATING_NUMBER>>* getPedestrianCoordinates();

        void setNumDimensions(int);

        void setNumPedestrians(int);
        void setSpeed(int, FLOATING_NUMBER);

        void setGoalCoordinate(int, int, FLOATING_NUMBER);
        
        void setPedestrianCoordinate(int, int, FLOATING_NUMBER);

        void setPedestrianCoordinates(std::vector<FLOATING_NUMBER>);
        void setMassesKg(std::vector<FLOATING_NUMBER>);

};

#endif
