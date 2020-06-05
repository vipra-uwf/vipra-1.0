#include "type_definitions.hpp"
#include <vector>
#include <string>
#include <math.h>

class PedestrianSet{
    public:
        PedestrianSet();
        void addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate);

        void setGoalXCoordinates(int, FLOATING_NUMBER);
        void setGoalYCoordinates(int, FLOATING_NUMBER);

        void setSpeed(int, FLOATING_NUMBER);

        void setXCoordinates(std::vector<FLOATING_NUMBER>);
        void setYCoordinates(std::vector<FLOATING_NUMBER>);
        void setTypes(std::vector<std::string>);
        
        void setXCoordinate(int, FLOATING_NUMBER);
        void setYCoordinate(int, FLOATING_NUMBER);

        FLOATING_NUMBER calculateDistance(int, int);

        int getNumPedestrians();
        FLOATING_NUMBER getDesiredSpeed(int);
        FLOATING_NUMBER getMassKg(int);
        FLOATING_NUMBER getReactionTimeSeconds(int);

        FLOATING_NUMBER getGoalXCoordinates(int);
        FLOATING_NUMBER getGoalYCoordinates(int);
 
        FLOATING_NUMBER getXCoordinate(int);
        FLOATING_NUMBER getYCoordinate(int);
        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();
        std::vector<std::string>* getTypes();
        
        FLOATING_NUMBER getSpeed(int);

    private:
        int numPedestrians;

        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimesSeconds;

        //intermediate goals are here, completion of goals determined in goal class
            //intermediate goals should be able to be used in place of aims
        std::vector<FLOATING_NUMBER> goalXCoordinates;
        std::vector<FLOATING_NUMBER> goalYCoordinates;

        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
        std::vector<std::string> types;


        //add currentVelocities (vectors)
        std::vector<FLOATING_NUMBER> currentVelocityX;
        std::vector<FLOATING_NUMBER> currentVelocityY;

        std::vector<FLOATING_NUMBER> desiredSpeeds;
};
