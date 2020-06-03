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
        void calculateAim();
        void calculateNearestNeighbor();
        FLOATING_NUMBER calculateDistance(int, int);

        int getNumPedestrians();
        FLOATING_NUMBER getDesiredSpeed();
        FLOATING_NUMBER getMassKg();
        FLOATING_NUMBER getReactionTime();


        //update these to be based on an index instead of returning entire vectors
        std::vector<std::string>* getAims();
        std::vector<int>* getNearestNeighbor();

        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();
       
        std::vector<FLOATING_NUMBER>* getSpeeds();
        std::vector<FLOATING_NUMBER>* getPropulsionForces();
        std::vector<FLOATING_NUMBER>* getRepulsionForces();

    private:
        int numPedestrians;
        FLOATING_NUMBER desiredSpeed; //should this be just the vector?
        FLOATING_NUMBER massKg; //vector for all pedestrians
        FLOATING_NUMBER reactionTime; //vector for all pedestrians

        std::vector<std::string> aims; //get rid of this
        std::vector<int> nearestNeighbor; //move to the specific model

        //intermediate goals are here, completion of goals determined in goal class
            //intermediate goals should be able to be used in place of aims
        std::vector<FLOATING_NUMBER> goalXCoordinates;
        std::vector<FLOATING_NUMBER> goalYCoordinates;

        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;

        std::vector<FLOATING_NUMBER> speeds;

        //add currentVelocities (vectors)
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        //forces and types of forces are model dependent, need to refactor (tbd)
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
};
