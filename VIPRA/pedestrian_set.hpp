#include "type_definitions.hpp"
#include <vector>
#include <string>
#include <math.h>

class PedestrianSet{
    public:
        PedestrianSet();
        void addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate);

        void setSpeed(int, FLOATING_NUMBER);
        void setPropulsionForces(int, FLOATING_NUMBER);
        void setRepulsionForces(int, FLOATING_NUMBER);
        //void calculateAim();
        void calculateNearestNeighbor();
        FLOATING_NUMBER calculateDistance(int, int);

        int getNumPedestrians();
        



        int getNearestNeighbor(int i);
        FLOATING_NUMBER getDesiredSpeed(int i);
        FLOATING_NUMBER getMassKg(int i);
        FLOATING_NUMBER getReactionTimeSeconds(int i);

        FLOATING_NUMBER getXCoordinate(int i);
        FLOATING_NUMBER getYCoordinate(int i);

        FLOATING_NUMBER getSpeed(int i);
        FLOATING_NUMBER getPropulsionForce(int i);
        FLOATING_NUMBER getRepulsionForce(int i);

    private:
        int numPedestrians;
        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimesSeconds;

        std::vector<int> nearestNeighbors; //move to the specific model

        //intermediate goals are here, completion of goals determined in goal class
            //intermediate goals should be able to be used in place of aims
        std::vector<FLOATING_NUMBER> goalXCoordinates;
        std::vector<FLOATING_NUMBER> goalYCoordinates;

        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;

        //add currentVelocities (vectors)
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        //forces and types of forces are model dependent, need to refactor (tbd)
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
};
