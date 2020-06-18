#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

#include "type_definitions.hpp"

class PedestrianSet
{
    private:
        int numPedestrians;

        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;

        std::vector<FLOATING_NUMBER> goalXCoordinates;
        std::vector<FLOATING_NUMBER> goalYCoordinates;

        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
        std::vector<std::string> types;

        //TODO currently has no getters/setters
        std::vector<FLOATING_NUMBER> currentVelocityX;
        std::vector<FLOATING_NUMBER> currentVelocityY;

    public:
        PedestrianSet();

        void initializeSpeeds();

        int getNumPedestrians();

        FLOATING_NUMBER getSpeed(int);
        FLOATING_NUMBER getMassKg(int);
      
        FLOATING_NUMBER getGoalXCoordinate(int);
        FLOATING_NUMBER getGoalYCoordinate(int);
 
        FLOATING_NUMBER getXCoordinate(int);
        FLOATING_NUMBER getYCoordinate(int);
        
        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();
        std::vector<std::string>* getTypes();

        void setNumPedestrians(int);
        void setSpeed(int, FLOATING_NUMBER);

        void setGoalXCoordinate(int, FLOATING_NUMBER);
        void setGoalYCoordinate(int, FLOATING_NUMBER);
        
        void setXCoordinate(int, FLOATING_NUMBER);
        void setYCoordinate(int, FLOATING_NUMBER);

        void setXCoordinates(std::vector<FLOATING_NUMBER>);
        void setYCoordinates(std::vector<FLOATING_NUMBER>);
        void setTypes(std::vector<std::string>);
        void setMassesKg(std::vector<FLOATING_NUMBER>);

};

#endif
