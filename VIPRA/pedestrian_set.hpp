#include "type_definitions.hpp"
#include <vector>
#include <string>

class PedestrianSet{
    public:
        PedestrianSet();
        void addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate);

        void setSpeed(int, FLOATING_NUMBER);
        void setPropulsionForces(int, FLOATING_NUMBER);
        void setRepulsionForces(int, FLOATING_NUMBER);
        void calculateAim(int);

        int getNumPedestrians();
        FLOATING_NUMBER getDesiredSpeed();
        FLOATING_NUMBER getMassKg();
        FLOATING_NUMBER getReactionTime();

        std::vector<std::string>* getAims();
        std::vector<FLOATING_NUMBER>* getNearestNeighborX();
        std::vector<FLOATING_NUMBER>* getNearestNeighborY();

        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();

        std::vector<FLOATING_NUMBER>* getSpeeds();
        std::vector<FLOATING_NUMBER>* getPropulsionForces();
        std::vector<FLOATING_NUMBER>* getRepulsionForces();

    private:
        int numPedestrians;
        FLOATING_NUMBER desiredSpeed;
        FLOATING_NUMBER massKg;
        FLOATING_NUMBER reactionTime;

        std::vector<std::string> aims; //vector of aim strings used to determine the aim of the pedestrian such as down to isle or up to isle or in isle
        std::vector<FLOATING_NUMBER>nearestNeighborX;
        std::vector<FLOATING_NUMBER>nearestNeighborY;


        std::vector<FLOATING_NUMBER> goalXCoordinates;
        std::vector<FLOATING_NUMBER> goalYCoordinates;

        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;

        std::vector<FLOATING_NUMBER> speeds;
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
};
