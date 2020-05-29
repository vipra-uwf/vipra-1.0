#include "type_definitions.hpp"
#include <vector>

class PedestrianSet{
    public:
        PedestrianSet();
        void addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate);
        int getNumPedestrians();
        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();
        /*std::vector<FLOATING_NUMBER>* getDesiredVelocities();
        std::vector<FLOATING_NUMBER>* getXVelocityDirection();
        std::vector<FLOATING_NUMBER>* getYVelocityDirection();
        std::vector<FLOATING_NUMBER>* getMasses_kg();
        std::vector<FLOATING_NUMBER>* getPropulsionForces();*/

    private:
        int numPedestrians;
        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
        /*std::vector<FLOATING_NUMBER> desiredVelocities;
        std::vector<FLOATING_NUMBER> xVelocityDirection;
        std::vector<FLOATING_NUMBER> yVelocityDirection;
        std::vector<FLOATING_NUMBER> masses_kg;
        std::vector<FLOATING_NUMBER> propulsionForces;*/
};