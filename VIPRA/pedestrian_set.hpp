#include "type_definitions.hpp"
#include <vector>
#include <string>
#include <math.h>

class PedestrianSet
{
    public:
        PedestrianSet();

        //TODO this method isnt used? -- why?
        FLOATING_NUMBER calculateDistance(int, int);

        //TODO xmlreader can keep track when reading then pass at end of reading
        //probably better than calling vector.size() -- what if data sets are huge? 
        int getNumPedestrians();

        FLOATING_NUMBER getSpeed(int);
        FLOATING_NUMBER getDesiredSpeed(int);
        FLOATING_NUMBER getMassKg(int);
        FLOATING_NUMBER getReactionTimeSeconds(int);

        //TODO make singular getters not have plural names       
        FLOATING_NUMBER getGoalXCoordinates(int);
        FLOATING_NUMBER getGoalYCoordinates(int);
 
        FLOATING_NUMBER getXCoordinate(int);
        FLOATING_NUMBER getYCoordinate(int);
        
        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();
        std::vector<std::string>* getTypes();

        void setNumPedestrians(int);
        void setSpeed(int, FLOATING_NUMBER);
        //TODO setters for desired speed, mass, reaction time??

        //TODO make singular setters not have plural names
        void setGoalXCoordinates(int, FLOATING_NUMBER);
        void setGoalYCoordinates(int, FLOATING_NUMBER);
        
        void setXCoordinate(int, FLOATING_NUMBER);
        void setYCoordinate(int, FLOATING_NUMBER);

        void setXCoordinates(std::vector<FLOATING_NUMBER>);
        void setYCoordinates(std::vector<FLOATING_NUMBER>);
        void setTypes(std::vector<std::string>);

    private:
        int numPedestrians;

        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimesSeconds;

        std::vector<FLOATING_NUMBER> goalXCoordinates;
        std::vector<FLOATING_NUMBER> goalYCoordinates;

        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
        std::vector<std::string> types;

        //TODO currently has no getters/setters
        std::vector<FLOATING_NUMBER> currentVelocityX;
        std::vector<FLOATING_NUMBER> currentVelocityY;
};
